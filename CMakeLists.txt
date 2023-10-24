cmake_minimum_required(VERSION 3.0)
project(libobjs)

###############################################################################
## file globbing ##############################################################
###############################################################################

# these instructions search the directory tree when CMake is
# invoked and put all files that match the pattern in the variables
# `sources` and `data`
file(GLOB_RECURSE sources      src/*.cpp src/*.h)
file(GLOB_RECURSE sources_test test/*.cpp)
file(GLOB_RECURSE data         resources/*)

###############################################################################
## target definitions #########################################################
###############################################################################

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# add the data to the target, so it becomes visible in some IDE
#add_executable(libobjs ${sources} ${data})

# just for example add some compiler flags
#target_compile_options(libobjs PUBLIC -std=c++1y -Wall -Wfloat-conversion)

# this lets me include files relative to the root source directory with a <> pair
#target_include_directories(libobjs PUBLIC src)

# this copies all resource files in the build directory
# we need this, because we want to work with paths relative to the executable
file(COPY ${data} DESTINATION ${CMAKE_BINARY_DIR}/lib)

###############################################################################
## dependencies ###############################################################
###############################################################################

# this defines the variables Boost_LIBRARIES that contain all library names
# that we need to link to
#find_package(Boost 1.36.0 COMPONENTS filesystem system REQUIRED)

#target_link_libraries(example PUBLIC
#${Boost_LIBRARIES}
## here you can add any library dependencies
#)

###############################################################################
## testing ####################################################################
###############################################################################

# this is for our testing framework
# we don't add REQUIRED because it's just for testing
find_package(GTest)

if(GTEST_FOUND)
  add_executable(unit_tests ${sources_test} ${sources})

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

###############################################################################
## packaging ##################################################################
###############################################################################

# all install commands get the same destination. this allows us to use paths
# relative to the executable.
#install(TARGETS libobjs DESTINATION example_destination)
# this is basically a repeat of the file copy instruction that copies the
# resources in the build directory, but here we tell CMake that we want it
# in the package
install(DIRECTORY resources DESTINATION example_destination)

# now comes everything we need, to create a package
# there are a lot more variables you can set, and some
# you need to set for some package types, but we want to
# be minimal here
set(CPACK_PACKAGE_NAME "libobjs")
set(CPACK_PACKAGE_VERSION "1.0.0")

# we don't want to split our program up into several things
set(CPACK_MONOLITHIC_INSTALL 1)

# This must be last
include(CPack)
