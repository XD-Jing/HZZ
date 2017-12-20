#include <TLorentzVector.h>
#include <TFile.h>
#include <xAODRootAccess/TEvent.h>
#include <AsgTools/MessageCheck.h>
#include <xAODEventInfo/EventInfo.h>
#include <xAODMuon/MuonContainer.h>
#include <xAODMuon/MuonContainer.h>
#include <xAODJet/JetContainer.h>
#include <xAODCore/AuxContainerBase.h>
#include <xAODCore/ShallowCopy.h>
#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <llvv/aFactor.h>

#include <xAODTruth/TruthEvent.h>
#include <xAODTruth/TruthEventContainer.h>
#include <xAODTruth/TruthParticle.h>
#include <xAODTruth/TruthParticleContainer.h>
#include <xAODTruth/TruthParticle.h>
#include <xAODTruth/TruthParticleContainer.h>

#include <vector>
using namespace std;

int aFactor::count = 0;
float aFactor::total_cutflow  = 0.0;
float aFactor::passLep_cutflow = 0.0;
float aFactor::passM2l_cutflow = 0.0;
float aFactor::passJet_cutflow = 0.0;

// this is needed to distribute the algorithm to the workers
ClassImp(aFactor)

aFactor :: aFactor ()
{
    // Here you put any code for the base initialization of variables,
    // e.g. initialize all pointers to 0.  Note that you should only put
    // the most basic initialization here, since this method will be
    // called on both the submission and the worker node.  Most of your
    // initialization code will go into histInitialize() and
    // initialize().
}



EL::StatusCode aFactor :: setupJob (EL::Job& job)
{
    // Here you put code that sets up the job on the submission object
    // so that it is ready to work with your algorithm, e.g. you can
    // request the D3PDReader service or add output files.  Any code you
    // put here could instead also go into the submission script.  The
    // sole advantage of putting it here is that it gets automatically
    // activated/deactivated when you add/remove the algorithm from your
    // job, which may or may not be of value to you.

    // let's initialize the algorithm to use the xAODRootAccess package
    job.useXAOD ();

    return EL::StatusCode::SUCCESS;
}



EL::StatusCode aFactor :: histInitialize ()
{
    // Here you do everything that needs to be done at the very
    // beginning on each worker node, e.g. create histograms and output
    // trees.  This method gets called before any input files are
    // connected.

    // get the output file, create a new TTree and connect it to that output
    // define what braches will go in that tree
    //xAOD::TEvent *m_event = wk()->xaodEvent();
    //std::cout << "events:"<<m_event->getEntries()<<std::endl;

    TFile *outputFile = wk()->getOutputFile (outputName);
    tree = new TTree ("tree", "tree");
    tree->SetDirectory (outputFile);
    tree->Branch ("EventNumber", &EventNumber);
    tree->Branch ("onshell", &onshell);
    tree->Branch ("passLep", &passLep);
    tree->Branch ("passM2l", &passM2l);
    tree->Branch ("passJet", &passJet);
    tree->Branch ("weight", &weight);
    tree->Branch ("mZ1", &mZ1);
    tree->Branch ("mZ2", &mZ2);
    tree->Branch ("lepplus_pt", &lepplus_pt);
    tree->Branch ("lepplus_eta", &lepplus_eta);
    tree->Branch ("lepplus_phi", &lepplus_phi);
    tree->Branch ("lepminus_pt", &lepminus_pt);
    tree->Branch ("lepminus_eta", &lepminus_eta);
    tree->Branch ("lepminus_phi", &lepminus_phi);
    tree->Branch ("event_type", &event_type);
    tree->Branch ("leading_pt_lep", &leading_pt_lep);
    tree->Branch ("subleading_pt_lep", &subleading_pt_lep);
    tree->Branch ("leading_pt_jet", &leading_pt_jet);
    tree->Branch ("subleading_pt_jet", &subleading_pt_jet);
    tree->Branch ("leading_eta_jet", &leading_eta_jet);
    tree->Branch ("subleading_eta_jet", &subleading_eta_jet);
    return EL::StatusCode::SUCCESS;
}

EL::StatusCode aFactor :: fileExecute ()
{
    // Here you do everything that needs to be done exactly once for every
    // single file, e.g. collect a list of all lumi-blocks processed
    return EL::StatusCode::SUCCESS;
}


EL::StatusCode aFactor :: changeInput (bool /*firstFile*/)
{
    // Here you do everything you need to do when we change input files,
    // e.g. resetting branch addresses on trees.  If you are using
    // D3PDReader or a similar service this method is not needed.
    return EL::StatusCode::SUCCESS;
}



EL::StatusCode aFactor :: initialize ()
{
    // Here you do everything that you need to do after the first input
    // file has been connected and before the first event is processed,
    // e.g. create additional histograms based on which variables are
    // available in the input files.  You can also create all of your
    // histograms and trees in here, but be aware that this method
    // doesn't get called if no events are processed.  So any objects
    // you create here won't be available in the output if you have no
    // input events.

    // cut flow counting

    ANA_MSG_INFO ("in initialize");
    return EL::StatusCode::SUCCESS;
}


EL::StatusCode aFactor :: variableInit(){
    onshell = false;
    passLep = false;
    passM2l = false;
    passJet = false;
    event_type = -1;
    weight = 1.0;
    mZ1 = -1.;
    mZ2 = -1.;
    lepplus_pt = -999.;
    lepplus_eta = -999.;
    lepplus_phi = -999.;
    lepminus_pt = -999.;
    lepminus_eta = -999.;
    lepminus_phi = -999.;
    leading_pt_lep = -999.;
    subleading_pt_lep = -999.;
    leading_pt_jet = -999.;
    subleading_pt_jet = -999.;
    leading_eta_jet = -999.;
    subleading_eta_jet = -999.;
    return EL::StatusCode::SUCCESS;

}

EL::StatusCode aFactor :: execute ()
{
    // Here you do everything that needs to be done on every single
    // events, e.g. read input variables, apply cuts, and fill
    // histograms and trees.  This is where most of your actual analysis
    // code will go.
    // set type of return code you are expecting
    // (add to top of each function once)
    ANA_CHECK_SET_TYPE (EL::StatusCode);

    count ++;

    if (count % 100 ==0) ANA_MSG_INFO ("Event: " << count );
    ANA_CHECK ( variableInit());
    ANA_CHECK (exeEventInfo());
    ANA_CHECK (cutLepton());

    tree->Fill();
    return EL::StatusCode::SUCCESS;
}


EL::StatusCode aFactor :: exeEventInfo()
{
    ANA_CHECK_SET_TYPE (EL::StatusCode);

    // retrieve the eventInfo object from the event store
    const xAOD::EventInfo *eventInfo = nullptr;
    ANA_CHECK (evtStore()->retrieve (eventInfo, "EventInfo"));
    EventNumber = eventInfo->eventNumber();
    isMC = eventInfo->eventType( xAOD::EventInfo::IS_SIMULATION );
    vector<float> vw;
    vw = eventInfo->mcEventWeights();
    weight = vw.size()>0?vw[0]:1.0;

    // print out run and event number from retrieved object
    //ANA_MSG_INFO ("in execute, runNumber = " << eventInfo->runNumber() << ", eventNumber = " << eventInfo->eventNumber() << ", isMC = " << isMC);

    return EL::StatusCode::SUCCESS;
}

EL::StatusCode aFactor::cutLepton()
{
    ANA_CHECK_SET_TYPE (EL::StatusCode);

    vector<TLorentzVector> vp4n, vp4l, vp4j;
    vector<float> vcharge;
    int n_e=0, n_m=0, n_ne=0, n_nm=0;
    vp4l.clear();
    vp4n.clear();
    vcharge.clear();
    vp4j.clear();

    const xAOD::TruthEventContainer* TruthEvtContainer= nullptr;
    ANA_CHECK( evtStore()->retrieve( TruthEvtContainer, "TruthEvents"));

    for ( auto trEvtItr: *TruthEvtContainer){
        int nTruPart = trEvtItr->nTruthParticles();
        //ANA_MSG_INFO("number of TruthParticles: " << nTruPart );
        for (int j=0; j<nTruPart; j++){
            const xAOD::TruthParticle* trPart = trEvtItr->truthParticle(j);
            if (!trPart) continue;
            //int status = trPart->status();
            int PDG = trPart->pdgId();
            //bool ProdVx = trPart->hasProdVtx();
            //bool DecayVx = trPart->hasDecayVtx();
            //int barcode = trPart->barcode();
            float charge = trPart->charge();
            TLorentzVector p4 = trPart->p4();

            //size_t nParents = trPart->nParents();
            const xAOD::TruthParticle* parPart = trPart->parent();
            //int PDGpar = -1;
            int statuspar = -1;
            //TLorentzVector p4par(0,0,0,0);
            if (parPart){
                //PDGpar = parPart->pdgId();
                statuspar = parPart->status();
                //p4par = parPart->p4();
            }

            if (statuspar==62 && fabs(PDG)==11) {
                vp4l.push_back(p4);
                n_e++;
                vcharge.push_back(charge);
            }
            if (statuspar==62 && fabs(PDG)==13){
                vp4l.push_back(p4);
                n_m++;
                vcharge.push_back(charge);
            }
            if (statuspar==62 && fabs(PDG)==12){
                vp4n.push_back(p4);
                n_ne++;
            }
            if (statuspar==62 && fabs(PDG)==14){
                vp4n.push_back(p4);
                n_nm++;
            }
        }
    }

    if (vp4l.size()==2){
        if (vcharge[0]>0 && vcharge[1]<0){
            lepplus_pt= vp4l[0].Pt();
            lepplus_eta = vp4l[0].Eta();
            lepplus_phi= vp4l[0].Phi();
            lepminus_pt= vp4l[1].Pt();
            lepminus_eta = vp4l[1].Eta();
            lepminus_phi= vp4l[1].Phi();
        }else{
            lepplus_pt= vp4l[1].Pt();
            lepplus_eta = vp4l[1].Eta();
            lepplus_phi= vp4l[1].Phi();
            lepminus_pt= vp4l[0].Pt();
            lepminus_eta = vp4l[0].Eta();
            lepminus_phi= vp4l[0].Phi();
        }
        mZ1 = (vp4l[0]+vp4l[1]).M();
        if (vp4l[0].Pt()>vp4l[1].Pt()) {
            leading_pt_lep = vp4l[0].Pt();
            subleading_pt_lep = vp4l[1].Pt();
        }else{
            leading_pt_lep = vp4l[1].Pt();
            subleading_pt_lep = vp4l[0].Pt();
        }
    }

    if (vp4n.size()==2) mZ2 = (vp4n[0]+vp4n[1]).M();

    if (mZ1 > 66.e3 && mZ1 < 116.e3 && mZ2 > 66.e3 && mZ2 < 116.e3) {
        onshell = true;
        total_cutflow += weight;
    }
    if (mZ1 > 76.e3 && mZ1 < 106.e3) {
        passM2l = true;
        if (onshell) {
            passM2l_cutflow += weight;
        }

    }

    if (n_e==2 && n_ne==2) event_type = 0;
    else if(n_e==2 && n_nm==2) event_type = 1;
    else if (n_m==2 && n_ne==2) event_type = 2;
    else if (n_m==2 && n_nm==2) event_type = 3;

    if (leading_pt_lep > 30.e3 && subleading_pt_lep > 20.e3) {
        passLep = true;
        if (passM2l && onshell) {
            passLep_cutflow += weight;
        }
    }

    const xAOD::JetContainer* TruthJets= nullptr;
    ANA_CHECK( evtStore()->retrieve( TruthJets, "AntiKt4TruthJets"));

    for ( auto trJet: *TruthJets){
        vp4j.push_back(trJet->p4());
    }

    if (vp4l.size()==2){
        for (int i=0;i<(int)vp4j.size();i++){
            if (vp4j[i].DeltaR(vp4l[0]) < 0.2){
                vp4j.erase(vp4j.begin()+i);
                i--;
            }
        }
        for (int i=0;i<(int)vp4j.size();i++){
            if (vp4j[i].DeltaR(vp4l[1]) < 0.2){
                vp4j.erase(vp4j.begin()+i);
                i--;
            }
        }
    }

    int leading_index_jet = -1;
    int subleading_index_jet = -1;
    leading_pt_jet = -999.;
    subleading_pt_jet = -999.;
    float pt_tmp;
    if (vp4j.size() <2) {
        passJet = false;
        return EL::StatusCode::SUCCESS;
    }
    for (int i=0;i<(int)vp4j.size();i++){
        pt_tmp = vp4j[i].Pt();
        if (pt_tmp>leading_pt_jet && pt_tmp>subleading_pt_jet){
            leading_pt_jet = pt_tmp;
            leading_index_jet = i;
        }else if (pt_tmp<leading_pt_jet && pt_tmp > subleading_pt_jet){
            subleading_pt_jet = pt_tmp;
            subleading_index_jet = i;
        }
    }

    leading_eta_jet = vp4j[leading_index_jet].Eta();
    subleading_eta_jet = vp4j[subleading_index_jet].Eta();

    if (leading_pt_jet > 60.e3 && subleading_pt_jet > 40.e3) {
        passJet = true;
        if (passM2l && passLep && onshell) {
            passJet_cutflow += weight;
        }
    }

    //std::cout << onshell<<passM2l<<passLep<<passJet<<std::endl;
    return EL::StatusCode::SUCCESS;
}


EL::StatusCode aFactor :: postExecute ()
{
    // Here you do everything that needs to be done after the main event
    // processing.  This is typically very rare, particularly in user
    // code.  It is mainly used in implementing the NTupleSvc.
    return EL::StatusCode::SUCCESS;
}

EL::StatusCode aFactor :: finalize ()
{
    // This method is the mirror image of initialize(), meaning it gets
    // called after the last event has been processed on the worker node
    // and allows you to finish up any objects you created in
    // initialize() before they are written to disk.  This is actually
    // fairly rare, since this happens separately for each worker node.
    // Most of the time you want to do your post-processing on the
    // submission node after all your histogram outputs have been
    // merged.  This is different from histFinalize() in that it only
    // gets called on worker nodes that processed input events.

    std::cout << "total :" << total_cutflow<<std::endl;
    std::cout << "M2l   :" << passM2l_cutflow<<std::endl;
    std::cout << "Lep   :" << passLep_cutflow<<std::endl;
    std::cout << "Jet   :" << passJet_cutflow<<std::endl;
    std::cout << "A factor : "<< passJet_cutflow / total_cutflow<<std::endl;

    return EL::StatusCode::SUCCESS;
}



EL::StatusCode aFactor :: histFinalize ()
{
    // This method is the mirror image of histInitialize(), meaning it
    // gets called after the last event has been processed on the worker
    // node and allows you to finish up any objects you created in
    // histInitialize() before they are written to disk.  This is
    // actually fairly rare, since this happens separately for each
    // worker node.  Most of the time you want to do your
    // post-processing on the submission node after all your histogram
    // outputs have been merged.  This is different from finalize() in
    // that it gets called on all worker nodes regardless of whether
    // they processed input events.
    return EL::StatusCode::SUCCESS;
}


bool aFactor::CheckFromZ(const xAOD::TruthParticle* trPart, int PDG){
    const xAOD::TruthParticle *parent = trPart->parent();
    if (!parent) return false;
    if (parent->pdgId()==PDG) return CheckFromZ(parent, PDG);
    if (parent->pdgId()==23) return true;
    else return false;
}
