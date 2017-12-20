#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "UserAnalysis::llvvLib" for configuration "RelWithDebInfo"
set_property(TARGET UserAnalysis::llvvLib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(UserAnalysis::llvvLib PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libllvvLib.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libllvvLib.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS UserAnalysis::llvvLib )
list(APPEND _IMPORT_CHECK_FILES_FOR_UserAnalysis::llvvLib "${_IMPORT_PREFIX}/lib/libllvvLib.so" )

# Import target "UserAnalysis::j.local" for configuration "RelWithDebInfo"
set_property(TARGET UserAnalysis::j.local APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(UserAnalysis::j.local PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/j.local"
  )

list(APPEND _IMPORT_CHECK_TARGETS UserAnalysis::j.local )
list(APPEND _IMPORT_CHECK_FILES_FOR_UserAnalysis::j.local "${_IMPORT_PREFIX}/bin/j.local" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
