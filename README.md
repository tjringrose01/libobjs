# libobjs

Reusable C++ object models (addressing, identity, invoices, payments, and utility types).

## Dependencies

- C++17 compiler (`g++` or `clang++`)
- CMake `>= 3.16`
- Conan 2.x

Project package requirements are defined in [`conanfile.txt`](conanfile.txt):
- `gtest/1.16.0`
- `cxxopts/3.2.0`

## Build

```bash
conan profile detect --force
conan install . --output-folder=build --build=missing
cmake --preset conan-release
cmake --build --preset conan-release -j4
```

## Test

```bash
ctest --test-dir build/Release --output-on-failure
```

## Binaries

Primary binaries are emitted into `build/Release/bin/`, including:
- `libobjs`
- `dates`
- `cautil`
- `file`
- `*_gtest` test executables

## Domain Models

Existing and newly-added modeling classes include:
- `Quote`, `QuoteItem`, `Invoice`, `InvoiceItem`
- `Payment`, `PaymentSchedule`, `Receipt`
- `TaxRule`, `TaxProfile`, `LedgerEntry`
- `Refund`, `CreditMemo`, `InvoiceWorkflow`
- `PurchaseOrder`, `BankAccount`, `Money`
- `Asset`, `AssetType`, `AssetModel`, `AssetEvent`, `Assignment`
- `Department`, `Location`, `Vendor`, `Warranty`, `MaintenancePlan`
- `WorkOrder`, `InspectionRecord`, `Incident`, `DisposalRecord`
- `DepreciationProfile`, `AuditSession`, `AuditResult`
- `CustomFieldDefinition`, `CustomFieldValue`, `DocumentAttachment`

## Standards

### Formatting Standards

- Use LF line endings, UTF-8, final newline, and no trailing whitespace (`.editorconfig`).
- Use 4-space indentation; do not use tabs.
- Format C++ with the repository `.clang-format` (LLVM-based, C++17, 100-column limit).
- Keep `CMakeLists.txt` lists and target blocks vertically aligned and consistently indented.

### Coding Standards

- Target C++17 (`set(CMAKE_CXX_STANDARD 17)`).
- Compile with warnings enabled (`-Wall -Wextra -Wpedantic` or MSVC `/W4`).
- Avoid `using namespace ...` in headers.
- Prefer `const` references for non-trivial input parameters to avoid unnecessary copies.
- Keep interfaces explicit and strongly typed (for example, `std::string` instead of project aliases in public APIs).

### Documentation Standards

- Documentation must be Doxygen compatible.
- Every `.hpp` and `.cpp` file must start with a file-level Doxygen block.
- Use `sources/SSN.cpp` as the baseline style for source documentation depth and structure.
- File-level source comments must state: file/class responsibility, project/license context, and any domain references or rules that explain validation behavior.
- All Classes and enums in headers must include `@brief` comments.
- All Constructors and methods in headers must include `@brief`, plus `@param`, `@return`, and `@throws` when applicable.
- Source (`.cpp`) implementations must document constructor intent and method behavior with Doxygen blocks, including validation rationale for non-obvious rules.
- Comments should explain intent and constraints, not restate obvious code line-by-line.
- Keep docs in sync with behavior changes (constructor semantics, return formats, validation rules).
- Use Markdown for repository documentation; avoid embedded HTML tags for code blocks and links.
- Update this README when build, test, or dependency workflow changes.

### Verification Commands

```bash
cmake --preset conan-release
cmake --build --preset conan-release -j4
ctest --test-dir build/Release --output-on-failure
```
