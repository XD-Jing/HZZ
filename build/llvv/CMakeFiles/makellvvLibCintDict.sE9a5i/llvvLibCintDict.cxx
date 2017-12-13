// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME llvvLibCintDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "llvv/aFactor.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_aFactor(void *p = 0);
   static void *newArray_aFactor(Long_t size, void *p);
   static void delete_aFactor(void *p);
   static void deleteArray_aFactor(void *p);
   static void destruct_aFactor(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::aFactor*)
   {
      ::aFactor *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::aFactor >(0);
      static ::ROOT::TGenericClassInfo 
         instance("aFactor", ::aFactor::Class_Version(), "llvv/aFactor.h", 7,
                  typeid(::aFactor), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::aFactor::Dictionary, isa_proxy, 4,
                  sizeof(::aFactor) );
      instance.SetNew(&new_aFactor);
      instance.SetNewArray(&newArray_aFactor);
      instance.SetDelete(&delete_aFactor);
      instance.SetDeleteArray(&deleteArray_aFactor);
      instance.SetDestructor(&destruct_aFactor);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::aFactor*)
   {
      return GenerateInitInstanceLocal((::aFactor*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::aFactor*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr aFactor::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *aFactor::Class_Name()
{
   return "aFactor";
}

//______________________________________________________________________________
const char *aFactor::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::aFactor*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int aFactor::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::aFactor*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *aFactor::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::aFactor*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *aFactor::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::aFactor*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void aFactor::Streamer(TBuffer &R__b)
{
   // Stream an object of class aFactor.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(aFactor::Class(),this);
   } else {
      R__b.WriteClassBuffer(aFactor::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_aFactor(void *p) {
      return  p ? new(p) ::aFactor : new ::aFactor;
   }
   static void *newArray_aFactor(Long_t nElements, void *p) {
      return p ? new(p) ::aFactor[nElements] : new ::aFactor[nElements];
   }
   // Wrapper around operator delete
   static void delete_aFactor(void *p) {
      delete ((::aFactor*)p);
   }
   static void deleteArray_aFactor(void *p) {
      delete [] ((::aFactor*)p);
   }
   static void destruct_aFactor(void *p) {
      typedef ::aFactor current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::aFactor

namespace {
  void TriggerDictionaryInitialization_libllvvLib_Impl() {
    static const char* headers[] = {
"llvv/aFactor.h",
0
    };
    static const char* includePaths[] = {
"/atlas/data19/liji/HZZ/source/llvv",
"/atlas/data19/liji/HZZ/source/llvv",
"/atlas/data19/liji/HZZ/source/llvv",
"/atlas/data19/liji/HZZ/source/llvv",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/RootCore/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/RootCore/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/D3PDTools/EventLoop",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/D3PDTools/RootCoreUtils",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/D3PDTools/SampleHandler",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthToolSupport/AsgTools",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/xAODRootAccessInterfaces",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/xAODRootAccess",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthContainers",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthContainersInterfaces",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/AthLinksSA",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Control/CxxUtils",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODCore",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODEventFormat",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/D3PDTools/AnaAlgorithm",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODEventInfo",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODMuon",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODBase",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODCaloEvent",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include/eigen3",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Calorimeter/CaloGeoHelpers",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/DetectorDescription/GeoPrimitives",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include/eigen3",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/EventPrimitives",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include/eigen3",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODPrimitives",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODTracking",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include/eigen3",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/MuonSpectrometer/MuonIdHelpers",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODJet",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODBTagging",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODPFlow",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/Event/xAOD/xAODTrigger",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/D3PDTools/EventLoopAlgs",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/src/PhysicsAnalysis/D3PDTools/MultiDraw",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/../../../../AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/RootCore/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBase/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/RootCore/include",
"/cvmfs/atlas.cern.ch/repo/sw/software/21.2/AnalysisBaseExternals/21.2.10/InstallArea/x86_64-slc6-gcc62-opt/include",
"/atlas/data19/liji/HZZ/build/llvv/CMakeFiles/makellvvLibCintDict.sE9a5i/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libllvvLib dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$llvv/aFactor.h")))  aFactor;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libllvvLib dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#ifndef HAVE_PRETTY_FUNCTION
  #define HAVE_PRETTY_FUNCTION 1
#endif
#ifndef HAVE_64_BITS
  #define HAVE_64_BITS 1
#endif
#ifndef __IDENTIFIER_64BIT__
  #define __IDENTIFIER_64BIT__ 1
#endif
#ifndef ATLAS
  #define ATLAS 1
#endif
#ifndef ROOTCORE
  #define ROOTCORE 1
#endif
#ifndef XAOD_STANDALONE
  #define XAOD_STANDALONE 1
#endif
#ifndef XAOD_ANALYSIS
  #define XAOD_ANALYSIS 1
#endif
#ifndef ROOTCORE_RELEASE_SERIES
  #define ROOTCORE_RELEASE_SERIES 25
#endif
#ifndef PACKAGE_VERSION
  #define PACKAGE_VERSION "llvv-00-00-00"
#endif
#ifndef PACKAGE_VERSION_UQ
  #define PACKAGE_VERSION_UQ llvv-00-00-00
#endif
#ifndef USE_CMAKE
  #define USE_CMAKE 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "llvv/aFactor.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"aFactor", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libllvvLib",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libllvvLib_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T, typename BASE> class DataVector;", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libllvvLib_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libllvvLib() {
  TriggerDictionaryInitialization_libllvvLib_Impl();
}
