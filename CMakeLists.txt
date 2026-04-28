cmake_minimum_required(VERSION 3.16)

project(
    libobjs
    VERSION 0.1
    DESCRIPTION "Collection of libraries to define the world in C++"
    LANGUAGES CXX
)

include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

option(LIBOBJS_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)

if(MSVC)
    add_compile_options(/W4)
    if(LIBOBJS_WARNINGS_AS_ERRORS)
        add_compile_options(/WX)
    endif()
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
    if(LIBOBJS_WARNINGS_AS_ERRORS)
        add_compile_options(-Werror)
    endif()
endif()

add_subdirectory(sources)

add_executable(dates test/dates.cpp include/Dt.hpp)
target_link_libraries(dates PUBLIC objs)
target_include_directories(dates PUBLIC "${INCLUDE_DIR}")

add_executable(cautil test/cautil.cpp include/CurrencyAmount.hpp)
target_link_libraries(cautil PUBLIC objs)
target_include_directories(cautil PUBLIC "${INCLUDE_DIR}")

add_executable(
    libobjs
    test/libobjs.cpp
    include/Dt.hpp
    include/PhoneNumber.hpp
    include/CurrencyAmount.hpp
    include/EmailAddress.hpp
    include/Address.hpp
    include/Person.hpp
    include/SSN.hpp
    include/Company.hpp
    include/InvoiceItem.hpp
    include/Payment.hpp
    include/QuoteItem.hpp
    include/Quote.hpp
    include/TaxRule.hpp
    include/TaxProfile.hpp
    include/LedgerEntry.hpp
    include/Refund.hpp
    include/CreditMemo.hpp
    include/PurchaseOrder.hpp
    include/BankAccount.hpp
    include/Receipt.hpp
    include/Money.hpp
    include/PaymentSchedule.hpp
    include/InvoiceWorkflow.hpp
    include/AssetType.hpp
    include/AssetModel.hpp
    include/Location.hpp
    include/Department.hpp
    include/Vendor.hpp
    include/Asset.hpp
    include/Assignment.hpp
    include/AssetEvent.hpp
    include/MaintenancePlan.hpp
    include/WorkOrder.hpp
    include/InspectionRecord.hpp
    include/Warranty.hpp
    include/DocumentAttachment.hpp
    include/Incident.hpp
    include/DepreciationProfile.hpp
    include/DisposalRecord.hpp
    include/AuditResult.hpp
    include/AuditSession.hpp
    include/CustomFieldDefinition.hpp
    include/CustomFieldValue.hpp
)
target_link_libraries(libobjs PUBLIC objs)
target_include_directories(libobjs PUBLIC "${INCLUDE_DIR}")

add_subdirectory(test)
