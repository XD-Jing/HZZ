# The name of the package:
atlas_subdir (llvv)

# Component(s) in the package:
atlas_add_root_dictionary (llvvLib
    llvvDictSource
    ROOT_HEADERS llvv/*.h Root/LinkDef.h
    EXTERNAL_PACKAGES ROOT )

# add the library itself:
atlas_add_library (llvvLib
    llvv/*.h llvv/*.ihh Root/*.cxx ${llvvDictSource}
    PUBLIC_HEADERS llvv
    INCLUDE_DIRS
    LINK_LIBRARIES EventLoop xAODEventInfo xAODMuon xAODJet xAODCore EventLoopAlgs
    PRIVATE_LINK_LIBRARIES )

# add the defined binaries:
atlas_add_executable (j.local util/j-local.cxx
    LINK_LIBRARIES llvvLib EventLoopAlgs EventLoop)

atlas_add_executable (j.grid util/j-grid.cxx
    LINK_LIBRARIES llvvLib EventLoopAlgs EventLoop EventLoopGrid)
