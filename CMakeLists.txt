cmake_minimum_required (VERSION 2.8.11)
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
	"tests/test_*.cpp"
)
file(GLOB TEST_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/tests 
	"tests/test_*.cpp"
)

#add_executable(test_mycalc code/test_mycalc.cpp code/mycalc.cpp code/mycalc.h)
foreach( testsourcefile ${TEST_FILES} )
	string( REPLACE ".cpp" "" testname ${testsourcefile} )
	add_executable( ${testname} ${USER_FILES} )
	target_link_libraries( ${testname} gtest_main )
	add_test(${testname} ${testname})
endforeach( testsourcefile ${TEST_FILES} )
ENABLE_TESTING()
