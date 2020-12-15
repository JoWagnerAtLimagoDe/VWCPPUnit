cmake_minimum_required(VERSION 3.1...3.14)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(FirstDemo)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_SOURCE_DIR}/src)

## Testing.
if(${CMAKE_VERSION} VERSION_LESS 3.11)
  # Enable ExternalProject CMake module
  include(ExternalProject)

  # Download and install GoogleTest
  ExternalProject_Add(
    googletest
    URL https://github.com/google/googletest/archive/master.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/googletest
    # Disable install step
    INSTALL_COMMAND ""
    )

  # Get GTest source and binary directories from CMake project
  ExternalProject_Get_Property(googletest source_dir binary_dir)

else()
  include(FetchContent)

  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    # GIT_TAG        release-1.8.0
    )

  FetchContent_GetProperties(googletest)
  if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
  endif()

endif()

## Targets.
add_executable(first_demo FirstDemo/FirstDemo.cpp FirstDemo/stack.cpp)


# include(CTest)  # Testing an-/ausschaltbar per config.
                # Muss auf oberster Ebene sein.
# enable_testing()  # explizit aktiviert.

## Test targets.
# add_test(NAME AdditionTest)


macro(package_add_test TESTNAME)
  add_executable(${TESTNAME} ${ARGN})
  target_link_libraries(${TESTNAME} gtest gmock gtest_main)
  add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
  set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(emptyStackTest FirstDemoTest/test.cpp FirstDemoTest/pch.cpp FirstDemo/stack.cpp)
package_add_test(emptyStackTestF FirstDemoTest/testF.cpp FirstDemoTest/pch.cpp FirstDemo/stack.cpp)
