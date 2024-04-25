find_package(GTest REQUIRED)

enable_testing()

### Company Unit Testing
add_executable(Company_gtest Company_gtest.cpp)
target_link_libraries(Company_gtest objs GTest::gtest_main)
target_include_directories(Company_gtest PUBLIC ../include)

### CurrencyAmount Unit Testing
add_executable(CurrencyAmount_gtest CurrencyAmount_gtest.cpp)
target_link_libraries(CurrencyAmount_gtest objs GTest::gtest_main)
target_include_directories(CurrencyAmount_gtest PUBLIC ../include)

### Dt Unit Testing
add_executable(Dt_gtest Dt_gtest.cpp)
target_link_libraries(Dt_gtest objs GTest::gtest_main)
target_include_directories(Dt_gtest PUBLIC ../include)

### EmailAddress Unit Testing
add_executable(EmailAddress_gtest EmailAddress_gtest.cpp)
target_link_libraries(EmailAddress_gtest objs GTest::gtest_main)
target_include_directories(EmailAddress_gtest PUBLIC ../include)

### Invoice Unit Testing
add_executable(Invoice_gtest Invoice_gtest.cpp)
target_link_libraries(Invoice_gtest objs GTest::gtest_main)
target_include_directories(Invoice_gtest PUBLIC ../include)

### PhoneNumber Unit Testing
add_executable(PhoneNumber_gtest PhoneNumber_gtest.cpp)
target_link_libraries(PhoneNumber_gtest objs GTest::gtest_main)
target_include_directories(PhoneNumber_gtest PUBLIC ../include)

include(GoogleTest)

gtest_discover_tests(Company_gtest)
gtest_discover_tests(CurrencyAmount_gtest)
gtest_discover_tests(Dt_gtest)
gtest_discover_tests(EmailAddress_gtest)
gtest_discover_tests(Invoice_gtest)
gtest_discover_tests(PhoneNumber_gtest)
