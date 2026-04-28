
find_package(cxxopts REQUIRED)
find_package(GTest REQUIRED)

enable_testing()
include(GoogleTest)

add_executable(file file.cpp)
target_link_libraries(file PRIVATE objs cxxopts::cxxopts)
target_include_directories(file PRIVATE ../include)

function(add_libobjs_gtest target_name)
    add_executable("${target_name}" "${target_name}.cpp")
    target_link_libraries("${target_name}" PRIVATE objs GTest::gtest_main)
    target_include_directories("${target_name}" PRIVATE ../include)
    gtest_discover_tests("${target_name}")
endfunction()

add_libobjs_gtest(Company_gtest)
add_libobjs_gtest(AssetManagement_gtest)
add_libobjs_gtest(CurrencyAmount_gtest)
add_libobjs_gtest(DomainModels_gtest)
add_libobjs_gtest(Dt_gtest)
add_libobjs_gtest(EmailAddress_gtest)
add_libobjs_gtest(File_gtest)
add_libobjs_gtest(Invoice_gtest)
add_libobjs_gtest(Payment_gtest)
add_libobjs_gtest(PhoneNumber_gtest)
