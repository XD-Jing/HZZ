#include <TLorentzVector.h>
#include <TFile.h>
#include <AsgTools/MessageCheck.h>
#include <xAODEventInfo/EventInfo.h>
#include <xAODMuon/MuonContainer.h>
#include <xAODMuon/MuonContainer.h>
//#include <xAODJet/JetContainer.h>
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
    TFile *outputFile = wk()->getOutputFile (outputName);
    tree = new TTree ("tree", "tree");
    tree->SetDirectory (outputFile);
    tree->Branch ("EventNumber", &EventNumber);
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

    ANA_MSG_INFO ("in initialize");
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

    ANA_CHECK (exeEventInfo());
    ANA_CHECK (cutLepton());
    //ANA_CHECK (exeMuon());
    //ANA_CHECK (exeShallowCopy());

    //ANA_MSG_INFO ("in execute");

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

    // print out run and event number from retrieved object
    ANA_MSG_INFO ("in execute, runNumber = " << eventInfo->runNumber() << ", eventNumber = " << eventInfo->eventNumber() << ", isMC = " << isMC);

    return EL::StatusCode::SUCCESS;
}

EL::StatusCode aFactor::cutLepton()
{
    ANA_CHECK_SET_TYPE (EL::StatusCode);

    vector<TLorentzVector> vp4e, vp4m, vp4n;
    vp4e.clear();
    vp4m.clear();
    vp4n.clear();

    const xAOD::TruthParticleContainer* TruthElectrons = nullptr;
    ANA_CHECK( evtStore()->retrieve( TruthElectrons, "TruthElectrons"));
    const xAOD::TruthParticleContainer* TruthMuons = nullptr;
    ANA_CHECK( evtStore()->retrieve( TruthMuons, "TruthMuons"));
    const xAOD::TruthParticleContainer* TruthNeutrinos = nullptr;
    ANA_CHECK( evtStore()->retrieve( TruthNeutrinos, "TruthNeutrinos"));
    const xAOD::TruthParticleContainer* TruthPhotons = nullptr;
    ANA_CHECK( evtStore()->retrieve( TruthPhotons, "TruthPhotons"));
    const xAOD::TruthEventContainer* TruthEvtContainer= nullptr;
    ANA_CHECK( evtStore()->retrieve( TruthEvtContainer, "TruthEvents"));

    for ( auto trPart : *TruthElectrons){
        int status = trPart->status();
        int PDG = trPart->pdgId();
        int barcode = trPart->barcode();
        TLorentzVector p4 = trPart->p4();

        if (fabs(PDG)==11 && status==1 && barcode<=200000){
            vp4e.push_back(p4);
            //ANA_MSG_INFO("electron E = "<< p4.E() << "parent:" << PDGpar << ProdVx << DecayVx << " "<< truthElectron->nParents());
        }
    }

    for ( auto trPart : *TruthMuons){
        int status = trPart->status();
        int PDG = trPart->pdgId();
        int barcode = trPart->barcode();
        TLorentzVector p4 = trPart->p4();

        if (fabs(PDG)==13 && status==1 && barcode<=200000){
            //ANA_MSG_INFO("muon E = "<< p4.E() << "parent:" << PDGpar );
            vp4m.push_back(p4);
        }
    }

    for ( auto trPart : *TruthNeutrinos){
        int status = trPart->status();
        int PDG = trPart->pdgId();
        int barcode = trPart->barcode();
        TLorentzVector p4 = trPart->p4();

        if ((fabs(PDG)==12 || fabs(PDG)==14) && status ==1){
            vp4n.push_back(p4);
        }
    }

    for ( auto trEvtItr: *TruthEvtContainer){
        int nTruPart = trEvtItr->nTruthParticles();
        ANA_MSG_INFO("number of TruthParticles: " << nTruPart );
        for (int j=0; j<nTruPart; j++){
            const xAOD::TruthParticle* trPart = trEvtItr->truthParticle(j);
            if (!trPart) continue;
            int status = trPart->status();
            int PDG = trPart->pdgId();
            bool ProdVx = trPart->hasProdVtx();
            bool DecayVx = trPart->hasDecayVtx();
            int barcode = trPart->barcode();
            TLorentzVector p4 = trPart->p4();

            size_t nParents = trPart->nParents();
            const xAOD::TruthParticle* parPart = trPart->parent();
            int PDGpar = -1, statuspar = -1;
            TLorentzVector p4par(0,0,0,0);
            if (parPart){
                PDGpar = parPart->pdgId();
                statuspar = parPart->status();
                p4par = parPart->p4();
            }

            //ANA_MSG_INFO("Part " << j<< " status " << status<< " pdg "<< PDG<< " father "<< PDGpar);
            if (status ==1 && fabs(PDG)==11) ANA_MSG_INFO("Part " << j<< " status " << status<< " pdg "<< PDG<< " father "<< PDGpar);
        }
    }

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
