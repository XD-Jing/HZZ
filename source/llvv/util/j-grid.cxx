#include <EventLoop/DirectDriver.h>
#include <EventLoop/Job.h>
#include <llvv/aFactor.h>
#include <TSystem.h>
#include <SampleHandler/ScanDir.h>
#include <xAODRootAccess/Init.h>
#include <AsgTools/MessageCheck.h>
#include <EventLoopAlgs/NTupleSvc.h>
#include <EventLoop/OutputStream.h>
#include <SampleHandler/ToolsDiscovery.h>
#include "EventLoopGrid/PrunDriver.h"

void ATestRun (const std::string& submitDir, const std::string& dataset_in, const std::string& dataset_out)
{
    // Set up the job for xAOD access:
    xAOD::Init().ignore();

    // create a new sample handler to describe the data files we use
    SH::SampleHandler sh;

    // scan for datasets in the given directory
    // this works if you are on lxplus, otherwise you'd want to copy over files
    // to your local machine and use a local path.  if you do so, make sure
    // that you copy all subdirectories and point this to the directory
    // containing all the files, not the subdirectories.


    //SH::scanRucio (sh, "data16_13TeV.periodAllYear.physics_Main.PhysCont.DAOD_ZMUMU.repro21_v01/");
    SH::scanRucio (sh, dataset_in);

    // set the name of the tree in our files
    // in the xAOD the TTree containing the EDM containers is "CollectionTree"
    sh.setMetaString ("nc_tree", "CollectionTree");

    // further sample handler configuration may go here

    // print out the samples we found
    sh.print ();

    // this is the basic description of our job
    EL::Job job;
    job.sampleHandler (sh); // use SampleHandler in this job
    //job.options()->setDouble (EL::Job::optMaxEvents, 10); // for testing purposes, limit to run over the first 500 events only!

    // define an output and an ntuple associated to that output
    EL::OutputStream output  ("output");
    job.outputAdd (output);
    EL::NTupleSvc *ntuple = new EL::NTupleSvc ("output");
    job.algsAdd (ntuple);

    // add our algorithm to the job
    aFactor *alg = new aFactor;

    // set the name of the algorithm (this is the name use with
    // messages)
    alg->SetName ("AnalysisAlg");

    // later on we'll add some configuration options for our algorithm that go here

    job.algsAdd (alg);

    alg->outputName = "output"; // give the name of the output to our algorithm

    // make the driver we want to use:
    // this one works by running the algorithm directly:
    EL::PrunDriver driver;
    if ( dataset_out.empty()) driver.options()->setString("nc_outputSampleName", "user.liji.test.%in:name[2]%.%in:name[6]%");
    else driver.options()->setString("nc_outputSampleName", dataset_out);

    // we can use other drivers to run things on the Grid, with PROOF, etc.

    // process the job using the driver
    driver.submitOnly (job, submitDir);
}

int main (int argc, char* argv[])
{
    // set the return type and reporting category for ANA_CHECK
    using namespace asg::msgUserCode;
    ANA_CHECK_SET_TYPE (int);

    // Take the submit directory from the input if provided:
    std::string submitDir = "submitDir";
    std::string dataset_out = "";
    std::string dataset_in= "";
    for (int i = 1;i < argc; i++){
        if (strcmp(argv[i], "--dir")==0) submitDir = argv[i+1];
        if (strcmp(argv[i], "--dataset")==0) dataset_in = argv[i+1];
        if (strcmp(argv[i], "--out")==0) dataset_out = argv[i+1];
        if (strcmp(argv[i], "--help")==0) {
            std::cout << "j.grid usage:"<<std::endl;
            std::cout << "   --dir [submitDir] "<<std::endl;
            std::cout << "   --dataset [dataset] "<<std::endl;
            std::cout << "   --out [dataset output] "<<std::endl;
            std::cout << "   --help "<<std::endl;

            return 0;
        }
    }


    // Set up the job for xAOD access:
    ANA_CHECK (xAOD::Init());

    // call our actual job-submission code
    ATestRun (submitDir, dataset_in, dataset_out);

    return 0;
}
