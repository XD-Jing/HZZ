#!/usr/bin/env bash


export working=$PWD
alias build="cmake --build ${working}/build"

if [ ! -d build ];then
    mkdir build
fi
cd ./build
if [ -e .asetup.save ];then
    asetup --restore
else
    asetup 21.2.13,AnalysisBase
fi
source ${AnalysisBase_PLATFORM}/setup.sh
cd ..

# tutorial data
#export ALRB_TutorialData=/afs/cern.ch/atlas/project/PAT/tutorial/cern-july2017/
