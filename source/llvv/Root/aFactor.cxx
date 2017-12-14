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


//EL::StatusCode aFactor :: exeMuon()
//{
//    ANA_CHECK_SET_TYPE (EL::StatusCode);
//
//    const xAOD::MuonContainer *muons = nullptr;
//    ANA_CHECK (evtStore()->retrieve (muons, "Muons"));
//
//    for ( auto muon : *muons) {
//        ANA_MSG_INFO ("execute(): original muon pt =" << ((muon)->pt() * 0.001) << " GeV");
//    }
//
//    return EL::StatusCode::SUCCESS;
//
//}

EL::StatusCode aFactor::cutLepton()
{
    ANA_CHECK_SET_TYPE (EL::StatusCode);

    const xAOD::TruthParticleContainer* TruthElectrons = nullptr;
    ANA_CHECK( evtStore()->retrieve( TruthElectrons, "TruthElectrons"));

    for ( auto truthElectron : *TruthElectrons){
        int status = truthElectron->status();
        int PDG = truthElectron->pdgId();
        int barcode = truthElectron->barcode();
        bool ProdVx = truthElectron->hasProdVtx();
        bool DecayVx = truthElectron->hasDecayVtx();
        TLorentzVector p4 = truthElectron->p4();

        const xAOD::TruthParticle* parPart = truthElectron->parent();
        int PDGpar = -1, statuspar = -1;
        if (parPart){
            PDGpar = parPart->pdgId();
            statuspar = parPart->status();
        }
        if (fabs(PDG)==11 && status==1){// && barcode<=200000){
            ANA_MSG_INFO("electron E = "<< p4.E() << "parent:" << PDGpar << ProdVx << DecayVx << " "<< truthElectron->nParents());
        }
    }

    const xAOD::TruthParticleContainer* TruthMuons = nullptr;
    ANA_CHECK( evtStore()->retrieve( TruthMuons, "TruthMuons"));

    for ( auto truthMuon : *TruthMuons){
        int status = truthMuon->status();
        int PDG = truthMuon->pdgId();
        int barcode = truthMuon->barcode();
        TLorentzVector p4 = truthMuon->p4();

        const xAOD::TruthParticle* parPart = truthMuon->parent();
        int PDGpar = -1, statuspar = -1;
        if (parPart){
            PDGpar = parPart->pdgId();
            statuspar = parPart->status();
        }

        if (fabs(PDG)==13 && status==1 && barcode<=200000){
            ANA_MSG_INFO("muon E = "<< p4.E() << "parent:" << PDGpar );
        }
    }

    const xAOD::TruthParticleContainer* TruthNeutrinos = nullptr;
    ANA_CHECK( evtStore()->retrieve( TruthNeutrinos, "TruthNeutrinos"));
    return EL::StatusCode::SUCCESS;

}

//EL::StatusCode aFactor :: exeDeepCopy()
//{
//    // An xAOD container is always described by two objects. An "interface container" that you interact with, and an auxiliary store object that holds all the data.
//    ANA_CHECK_SET_TYPE (EL::StatusCode);
//
//    // Retrieve input jet container
//    xAOD::JetContainer *jets = nullptr;
//    ANA_CHECK (evtStore()->retrieve (jets, "AntiKt4EMTopoJets"));
//
//    auto goodJets = std::make_unique<xAOD::JetContainer>();
//    auto goodJetsAux = std::make_unique<xAOD::AuxContainerBase>();
//    goodJets->setStore (goodJetsAux.get());
//
//    for (auto jet: *jets){
//        if (jet->pt() < 50e03) continue;
//
//        xAOD::Jet *goodJet = new xAOD::Jet();
//        goodJets->push_back (goodJet);
//        *goodJet = *jet;
//    }
//
//    ANA_CHECK (evtStore()->record (goodJets.release(), "GoodJets"));
//    ANA_CHECK (evtStore()->record (goodJetsAux.release(), "GoodJetsAux."));
//
//    return EL::StatusCode::SUCCESS;
//}
//
//
//
//EL::StatusCode aFactor :: exeShallowCopy()
//{
//    ANA_CHECK_SET_TYPE (EL::StatusCode);
//
//    const xAOD::JetContainer *jets = nullptr;
//    ANA_CHECK (evtStore()->retrieve (jets, "AntiKt4EMTopoJets"));
//
//    auto shallowCopy = xAOD::shallowCopyContainer (*jets);
//    std::unique_ptr<xAOD::JetContainer> shallowJets (shallowCopy.first);
//    std::unique_ptr<xAOD::ShallowAuxContainer> shallowAux (shallowCopy.second);
//
//    double newPt;
//    for (auto jetSC : *shallowCopy.first) {
//        newPt = jetSC->pt() * (10);
//
//        xAOD::JetFourMom_t newp4 (newPt, jetSC->eta(), jetSC->phi(), jetSC->m());
//        jetSC->setJetP4 (newp4);
//    }
//
//    ANA_MSG_INFO ("shallow copy");
//
//    ANA_CHECK (evtStore()->record (shallowJets.release(), "AntiKt4EMTopoJets"));
//    ANA_CHECK (evtStore()->record (shallowAux.release(), "AntiKt4EMTopoJetsAux."));
//
//    return EL::StatusCode::SUCCESS;
//}



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
