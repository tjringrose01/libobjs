cmake_minimum_required(VERSION 3.5)
project(orch
        VERSION 0.1
        DESCRIPTION "Collection of libraries to define the world in C++"
        LANGUAGES CXX
        )

# this is for our testing framework
# we don't add REQUIRED because it's just for testing
find_package(GTest)

if(GTEST_FOUND)
  add_executable(unit_tests test/unit_tests.cpp src/PhoneNumber.hpp src/PhoneNumber.cpp)
  target_compile_features(unit_tests PRIVATE cxx_std_20)

  # we add this define to prevent collision with the main
  # this might be better solved by not adding the source with the main to the
  # testing target
  target_compile_definitions(unit_tests PUBLIC UNIT_TESTS)

  # this allows us to use our executable as a link library
  # therefore we can inherit all compiler options and library dependencies
  set_target_properties(unit_tests PROPERTIES ENABLE_EXPORTS on)

  #target_include_directories(test PRIVATE ${YOUR_DIRECTORY})

  target_link_libraries(unit_tests PUBLIC
    ${GTEST_BOTH_LIBRARIES}
  )

  target_include_directories(unit_tests PUBLIC
    ${GTEST_INCLUDE_DIRS} # doesn't do anything on Linux
    "../src"
  )
endif()