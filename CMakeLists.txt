# CMakeLists.txt
cmake_minimum_required(VERSION 3.24)
project(add-nbo)
add_executable(add-nbo add-nbo.cpp)

set_target_properties(add-nbo PROPERTIES RUNTIME_OUTPUT_DIRECTORY
	${CMAKE_SOURCE_DIR})
	
