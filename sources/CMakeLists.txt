add_library(objs SHARED
    Dt.cpp
    PhoneNumber.cpp
    CurrencyAmount.cpp
    EmailAddress.cpp
    Address.cpp
    Person.cpp
    SSN.cpp
    Company.cpp
    InvoiceItem.cpp
    Invoice.cpp
    User.cpp
    Meal.cpp
    File.cpp
)

target_include_directories(objs PRIVATE
    "${CMAKE_CURRENT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}"
    ../include
)

