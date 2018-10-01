cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0054 NEW) 
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
 
FILE(GLOB plugin_src "src/")

message("Plugin sources: ${plugin_src}")

FOREACH(subdir ${plugin_src})
	ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()

