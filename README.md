# C++20 Bazel Template with bzlmod

A modern C++20 project template using Bazel with bzlmod for dependency management.

## Prerequisites

- Bazel 9.0.0 or later
- A C++20 compatible compiler (GCC 11+, Clang 14+, or MSVC 19.29+)

## Project Structure

```
.
├── MODULE.bazel      # bzlmod dependency configuration
├── .bazelrc          # Bazel build configuration (C++20 flags)
├── .bazelversion     # Bazel version specification
├── src/
│   ├── BUILD.bazel   # Build rules for source files
│   ├── main.cpp      # Application entry point
│   ├── greeting.h    # Header with C++20 features
│   └── greeting.cpp  # Implementation file
└── tests/
    ├── BUILD.bazel   # Build rules for tests
    └── greeting_test.cpp  # Catch2 unit tests
```

## Building

```bash
# Build the main application
bazel build //src:main

# Build with macOS configuration
bazel build //src:main --config=macos

# Build with Linux configuration
bazel build //src:main --config=linux
```

## Running

```bash
# Run the main application
bazel run //src:main
```

## Testing

```bash
# Run all tests
bazel test //tests:all

# Run a specific test
bazel test //tests:greeting_test
```

## C++20 Features Demonstrated

- **Concepts**: Type constraints with `requires` expressions
- **Ranges**: Pipeline-style data transformations
- **`std::format`**: Type-safe string formatting (compiler support varies)
- **`constexpr` improvements**: Compile-time string operations
- **`[[nodiscard]]`**: Attribute for return value checking
- **`std::string_view`**: Non-owning string references

## Dependencies

Managed via bzlmod in `MODULE.bazel`:

- `rules_cc`: C++ build rules for Bazel
- `platforms`: Platform definitions for cross-compilation support
- `catch2`: Catch2 testing framework for unit tests
