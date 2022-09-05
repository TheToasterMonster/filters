add_executable("Filters"
  "src/Color.cpp"
  "src/Color.h"
  "src/Filters.h"
  "src/Image.cpp"
  "src/Image.h"
  "src/Main.cpp"
)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
  set_target_properties("Filters" PROPERTIES
    OUTPUT_NAME "Filters"
    ARCHIVE_OUTPUT_DIRECTORY "/Users/frankqiang/dev/Filters/bin/Debug-macosx-x86_64/Filters"
    LIBRARY_OUTPUT_DIRECTORY "/Users/frankqiang/dev/Filters/bin/Debug-macosx-x86_64/Filters"
    RUNTIME_OUTPUT_DIRECTORY "/Users/frankqiang/dev/Filters/bin/Debug-macosx-x86_64/Filters"
  )
endif()
target_include_directories("Filters" PRIVATE
  $<$<CONFIG:Debug>:/Users/frankqiang/dev/Filters/src>
)
target_compile_definitions("Filters" PRIVATE
  $<$<CONFIG:Debug>:DEBUG>
)
target_link_directories("Filters" PRIVATE
)
target_link_libraries("Filters"
)
target_compile_options("Filters" PRIVATE
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-m64>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-g>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-m64>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-g>
  $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-std=c++17>
)
if(CMAKE_BUILD_TYPE STREQUAL Debug)
  set_target_properties("Filters" PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    POSITION_INDEPENDENT_CODE False
    INTERPROCEDURAL_OPTIMIZATION False
  )
endif()
if(CMAKE_BUILD_TYPE STREQUAL Release)
  set_target_properties("Filters" PROPERTIES
    OUTPUT_NAME "Filters"
    ARCHIVE_OUTPUT_DIRECTORY "/Users/frankqiang/dev/Filters/bin/Release-macosx-x86_64/Filters"
    LIBRARY_OUTPUT_DIRECTORY "/Users/frankqiang/dev/Filters/bin/Release-macosx-x86_64/Filters"
    RUNTIME_OUTPUT_DIRECTORY "/Users/frankqiang/dev/Filters/bin/Release-macosx-x86_64/Filters"
  )
endif()
target_include_directories("Filters" PRIVATE
  $<$<CONFIG:Release>:/Users/frankqiang/dev/Filters/src>
)
target_compile_definitions("Filters" PRIVATE
  $<$<CONFIG:Release>:NDEBUG>
)
target_link_directories("Filters" PRIVATE
)
target_link_libraries("Filters"
)
target_compile_options("Filters" PRIVATE
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:C>>:-m64>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:C>>:-O2>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-m64>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-O2>
  $<$<AND:$<CONFIG:Release>,$<COMPILE_LANGUAGE:CXX>>:-std=c++17>
)
if(CMAKE_BUILD_TYPE STREQUAL Release)
  set_target_properties("Filters" PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    POSITION_INDEPENDENT_CODE False
    INTERPROCEDURAL_OPTIMIZATION False
  )
endif()