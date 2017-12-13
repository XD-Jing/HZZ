#ifndef llvv_aFactor_H
#define llvv_aFactor_H

#include <EventLoop/Algorithm.h>
#include <TTree.h>

class aFactor : public EL::Algorithm
{
    // put your configuration variables here as public variables.
    // that way they can be set directly from CINT and python.
public:
    // float cutValue;



    // variables that don't get filled at submission time should be
    // protected from being send from the submission node to the worker
    // node (done by the //!)
public:
    // Tree *myTree; //!
    // TH1 *myHist; //!

    // defining the output file name and tree that we will put in the output ntuple, also the one branch that will be in that tree 
    std::string outputName;
    TTree *tree; //!
    int EventNumber; //!


    // this is a standard constructor
    aFactor ();

    // these are the functions inherited from Algorithm
    virtual EL::StatusCode setupJob (EL::Job& job);
    virtual EL::StatusCode fileExecute ();
    virtual EL::StatusCode histInitialize ();
    virtual EL::StatusCode changeInput (bool firstFile);
    virtual EL::StatusCode initialize ();
    virtual EL::StatusCode execute ();
    virtual EL::StatusCode postExecute ();
    virtual EL::StatusCode finalize ();
    virtual EL::StatusCode histFinalize ();

    EL::StatusCode exeEventInfo();
    EL::StatusCode exeMuon();
    EL::StatusCode exeDeepCopy();
    EL::StatusCode exeShallowCopy();
    // this is needed to distribute the algorithm to the workers
    ClassDef(aFactor, 1);
};

#endif
