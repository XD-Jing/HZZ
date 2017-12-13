file(REMOVE_RECURSE
  "../x86_64-slc6-gcc62-opt/include/llvv"
  "../x86_64-slc6-gcc62-opt/include/llvv"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/llvvHeaderInstall.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
