# Auto-discovered Exercise test targets

Each Exercise is built as a separate, non-default Catch2 executable discovered from the presence of one or more `*_test.cpp` files. This marker lets existing topic directories mix legacy material and Exercises while allowing all implementation and test sources in one Exercise directory to be aggregated automatically; every target depends on `basic` and participates in `xmake test` without requiring a shared `main.cpp` or manual include directories.

## Considered Options

Category-wide executables and manually edited runners were rejected because each new Exercise required build-script and `main.cpp` changes. A mandatory `solve(Input) -> Output` interface was rejected because it would replace native LeetCode APIs and impose artificial parsing on problems that do not define stream input. A centralized include directory was rejected because it separates a solution from its problem-oriented directory.

## Consequences

Exercise target names must be globally unique, normal `xmake` does not build them, and `xmake test` builds and runs all migrated Exercise Tests. Multiple `*_test.cpp` files in one directory form one executable. During incremental migration, legacy category targets must exclude `*_test.cpp` sources.
