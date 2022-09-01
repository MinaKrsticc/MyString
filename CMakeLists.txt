project ( MyString ) # Mandatory .
cmake_minimum_required ( VERSION 3.2) # Mandatory .
set( CMAKE_CXX_STANDARD 11) # Use c ++11.
# tell cmake to output binaries here:
set( EXECUTABLE_OUTPUT_PATH ${ PROJECT_SOURCE_DIR }/bin)
set( LIBRARY_OUTPUT_PATH ${ PROJECT_SOURCE_DIR }/lib)
# tell cmake where to look for *.h files
include_directories (${ PROJECT_SOURCE_DIR }/src)
# create library " libtools "
add_library (tools src/tools.cpp)
# add executable main
add_executable (main src/ tools_main .cpp)
# tell the linker to bind these objects together
target_link_libraries (main tools)
