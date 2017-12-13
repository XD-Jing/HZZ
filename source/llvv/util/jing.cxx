#include <EventLoop/DirectDriver.h>
#include <EventLoop/Job.h>
#include <llvv/aFactor.h>
#include <TSystem.h>
#include <SampleHandler/ScanDir.h>
#include <xAODRootAccess/Init.h>
#include <AsgTools/MessageCheck.h>
#include <EventLoopAlgs/NTupleSvc.h>
#include <EventLoop/OutputStream.h>

void ATestRun (const std::string& submitDir)
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

    // use SampleHandler to scan all of the subdirectories of a directory for particular MC single file:
    const char* inputFilePath = gSystem->ExpandPathName ("/afs/cern.ch/work/l/liji/aaa/");
    //const char* inputFilePath = gSystem->ExpandPathName ("$ALRB_TutorialData/r9315/");
    SH::ScanDir().filePattern("AOD.11182705._000001.pool.root.1").scan(sh,inputFilePath);


    // set the name of the tree in our files
    // in the xAOD the TTree containing the EDM containers is "CollectionTree"
    sh.setMetaString ("nc_tree", "CollectionTree");

    // further sample handler configuration may go here

    // print out the samples we found
    sh.print ();

    // this is the basic description of our job
    EL::Job job;
    job.sampleHandler (sh); // use SampleHandler in this job
    job.options()->setDouble (EL::Job::optMaxEvents, 10); // for testing purposes, limit to run over the first 500 events only!

    // define an output and an ntuple associated to that output
    EL::OutputStream output  ("myOutput");
    job.outputAdd (output);
    EL::NTupleSvc *ntuple = new EL::NTupleSvc ("myOutput");
    job.algsAdd (ntuple);

    // add our algorithm to the job
    aFactor *alg = new aFactor;

    // set the name of the algorithm (this is the name use with
    // messages)
    alg->SetName ("AnalysisAlg");

    // later on we'll add some configuration options for our algorithm that go here

    job.algsAdd (alg);

    alg->outputName = "myOutput"; // give the name of the output to our algorithm

    // make the driver we want to use:
    // this one works by running the algorithm directly:
    EL::DirectDriver driver;
    // we can use other drivers to run things on the Grid, with PROOF, etc.

    // process the job using the driver
    driver.submit (job, submitDir);
}

int main (int argc, char* argv[])
{
    // set the return type and reporting category for ANA_CHECK
    using namespace asg::msgUserCode;
    ANA_CHECK_SET_TYPE (int);

    // Take the submit directory from the input if provided:
    std::string submitDir = "submitDir";
    if( argc == 2 ) submitDir = argv[1];
    if (argc > 2)
    {
        ANA_MSG_ERROR ("don't know what to do with extra arguments, aborting");
        return -1;
    }

    // Set up the job for xAOD access:
    ANA_CHECK (xAOD::Init());

    // call our actual job-submission code
    ATestRun (submitDir);

    return 0;
}
