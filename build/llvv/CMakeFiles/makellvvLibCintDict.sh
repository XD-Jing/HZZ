set -e
tmpdir=`mktemp -d makellvvLibCintDict.XXXXXX`
cd ${tmpdir}
/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/bin/rootcling -f llvvLibCintDict.cxx -s libllvvLib.so -rml libllvvLib.so -rmf llvvLib.dsomap -c -DHAVE_PRETTY_FUNCTION -DHAVE_64_BITS -D__IDENTIFIER_64BIT__ -DATLAS -DROOTCORE -DXAOD_STANDALONE -DXAOD_ANALYSIS -DROOTCORE_RELEASE_SERIES=25 -DPACKAGE_VERSION=\"llvv-00-00-00\" -DPACKAGE_VERSION_UQ=llvv-00-00-00 -DUSE_CMAKE -I"/atlas/data19/liji/HZZ/source/llvv" -I"/atlas/data19/liji/HZZ/source/llvv" -I"/atlas/data19/liji/HZZ/source/llvv" -I"/atlas/data19/liji/HZZ/source/llvv" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/RootCore/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/RootCore/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/D3PDTools/EventLoop" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/D3PDTools/RootCoreUtils" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/D3PDTools/SampleHandler" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthToolSupport/AsgTools" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/xAODRootAccessInterfaces" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/xAODRootAccess" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthContainers" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthContainersInterfaces" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthLinksSA" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/CxxUtils" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODCore" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODEventFormat" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/D3PDTools/AnaAlgorithm" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODEventInfo" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODMuon" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODBase" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODCaloEvent" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include/eigen3" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Calorimeter/CaloGeoHelpers" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/DetectorDescription/GeoPrimitives" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include/eigen3" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/EventPrimitives" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include/eigen3" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODPrimitives" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODTracking" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include/eigen3" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/MuonSpectrometer/MuonIdHelpers" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODJet" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODBTagging" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODPFlow" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODTrigger" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/D3PDTools/EventLoopAlgs" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/D3PDTools/MultiDraw" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODTruth" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/RootCore/include" -I"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/RootCore/include" "llvv/Counting.h" "llvv/aFactor.h" "Root/LinkDef.h"
/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Cmake/3.8.1/Linux-x86_64/bin/cmake -E copy llvvLibCintDict.cxx  "/atlas/data19/liji/HZZ/build/llvv/CMakeFiles/llvvLibCintDict.cxx"
/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Cmake/3.8.1/Linux-x86_64/bin/cmake -E copy llvvLib.dsomap "/atlas/data19/liji/HZZ/build/llvv/CMakeFiles/llvvLib.dsomap"
/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Cmake/3.8.1/Linux-x86_64/bin/cmake -E copy libllvvLib_rdict.pcm "/atlas/data19/liji/HZZ/build/x86_64-slc6-gcc62-opt/lib/libllvvLib_rdict.pcm"
