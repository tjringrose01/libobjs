cmake_minimum_required(VERSION 3.5)
project(orch
        VERSION 0.1
        DESCRIPTION "Collection of libraries to define the world in C++"
        LANGUAGES CXX
        )
add_executable(unit_tests test/unit_tests.cpp src/PhoneNumber.h src/PhoneNumber.cpp)
target_compile_features(unit_tests PRIVATE cxx_std_20)