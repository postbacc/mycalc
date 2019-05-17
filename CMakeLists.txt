cmake_minimum_required (VERSION 2.8.11)

# set default build to debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Release or Debug" FORCE)
endif(NOT CMAKE_BUILD_TYPE)

# get folder name as project name
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
	message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
	message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
	${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

file(GLOB USER_FILES 
	"code/*.h"
	"code/*.cpp"
)
file(GLOB TEST_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} 
	"tests/test_*.cpp"
)

#add_executable(test_mycalc code/test_mycalc.cpp code/mycalc.cpp code/mycalc.h)
foreach( testsourcefile ${TEST_FILES} )
	string( REPLACE ".cpp" "" testname ${testsourcefile} )
	string( REPLACE "tests/" "" testname ${testname} )
	add_executable( ${testname} ${TEST_FILES} ${USER_FILES})
	target_link_libraries( ${testname} gtest_main )
	add_test(${testname} ${testname})
endforeach( testsourcefile ${TEST_FILES} )

# recreate a graded test for file with project name 
set( graded_test_name "tests/test_${ProjectId}.cpp")
add_executable( graded_test ${graded_test_name} ${USER_FILES} )
target_link_libraries( graded_test gtest_main )

ENABLE_TESTING()

# create an executable for main.cpp in app folder
add_executable( main "app/main.cpp" ${USER_FILES} )
