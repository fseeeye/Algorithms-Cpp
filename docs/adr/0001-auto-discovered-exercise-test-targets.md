# Auto-discovered Exercise test targets

Each Exercise is built as a separate, non-default Catch2 executable discovered from the presence of one or more `*_test.cpp` files. A discovered Exercise is valid only when an `exercise.json` metadata file exists in the same directory, and metadata without a colocated Exercise Test is likewise invalid. These paired markers let existing topic directories mix legacy material and Exercises while allowing all implementation and test sources in one Exercise directory to be aggregated automatically; every target depends on `basic` and participates in `xmake test` without requiring a shared `main.cpp` or manual include directories.

## Considered Options

Category-wide executables and manually edited runners were rejected because each new Exercise required build-script and `main.cpp` changes. The repository explicitly rejects a universal `solve(Input) -> Output` interface because it would replace native problem APIs and impose artificial input/output modeling on Exercises whose natural contracts differ. A centralized include directory was rejected because it separates a solution from its problem-oriented directory.

## Consequences

Exercise target names must be globally unique, normal `xmake` does not build them, and `xmake test` builds and runs all migrated Exercise Tests. Multiple `*_test.cpp` files in one directory form one executable. During incremental migration, legacy category targets must exclude `*_test.cpp` sources.
