cmake_minimum_required(VERSION 3.5)
project(libobjs
        VERSION 0.1
        DESCRIPTION "Collection of libraries to define the world in C++"
        LANGUAGES CXX
        )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(INCLUDE_DIR ${CMAKE_BINARY_DIR}/include)

add_library(objs SHARED
	sources/Dt.cpp
	sources/PhoneNumber.cpp
	sources/CurrencyAmount.cpp
	sources/EmailAddress.cpp
	sources/Address.cpp
	sources/Person.cpp
	sources/SSN.cpp
)
target_include_directories(objs PRIVATE ${INCLUDE_DIR})

### dates executable
add_executable(dates test/dates.cpp include/Dt.hpp)
target_link_libraries(dates PUBLIC objs)
target_include_directories(dates PUBLIC ${INCLUDE_DIR})

### cautil executable
add_executable(cautil test/cautil.cpp include/CurrencyAmount.hpp)
target_link_libraries(cautil PUBLIC objs)
target_include_directories(cautil PUBLIC ${INCLUDE_DIR})

### libojs executable
add_executable(libobjs test/libobjs.cpp
	include/Dt.hpp
	include/PhoneNumber.hpp
	include/CurrencyAmount.hpp
	include/EmailAddress.hpp
	include/Address.hpp
	include/Person.hpp
	include/SSN.hpp
	)
target_link_libraries(libobjs PUBLIC objs)
target_include_directories(libobjs PUBLIC ${INCLUDE_DIR})

# this is for our testing framework
# we don't add REQUIRED because it's just for testing
find_package(GTest)

if(GTEST_FOUND)
	add_executable(unit_tests test/unit_tests.cpp include/PhoneNumber.hpp include/Dt.hpp)
  #target_compile_features(unit_tests PRIVATE cxx_std_20)

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
    objs
  )

  target_include_directories(unit_tests PUBLIC
    ${GTEST_INCLUDE_DIRS} # doesn't do anything on Linux
    ${INCLUDE_DIR}
  )
endif()
