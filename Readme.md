## wip-on-1000-10-8-for-LLVM-7.1.1

Version 2.0.3

* This adds support for the 'zippered' platform type.  It is sufficient to
consume the SDKs for Darwin18/MacOS10.14 and Darwin19/MacOS10.15.

* The library version now reflects the TAPI edition, rather than the LLVM
version it was built on top of.

## wip-on-1000-10-8-for-llvm-7-1

This is based off the Xcode 10 tapi sources (1000.10.8) but to build on top
of LLVM 7.1, rather than llvm-swift.

## tapi-201-for-llvm-7-1-with-emuTLS

This is a branch for building toolchains based on GCC when the emulatedTLS
has been split into a CRT (e.g. https://github.com/iains/gcc-8-branch.git)

This branch has been tested with LLVM 7.1 with some additions to support
older Darwin versions (https://github.com/iains/LLVM-7-branch.git).

It builds automatically (using the branch mentioned) when this repo is cloned
to the same level as the LLVM monorepo clone.

Building outside this context hasn't been tried.

# on-700rc2

So I tried this on top of the 7.0.0rc2 sources with the changes here.

plus:

a) Add the ObjcMetadata library from Apple clang-800.0.42.1
b) symlink tapi into clang/tools/tapi
c) add  to clang/tools/CMakeLists.txt

    add_llvm_external_project(tapi tapi)

currently, 13 tests fail (and the inputs for IVarTest and Simple have to be
commented out to get the build to run).

# TAPI

TAPI is a **T**ext-based **A**pplication **P**rogramming **I**nterface. It
replaces the Mach-O Dynamic Library Stub files in Apple's SDKs to reduce the SDK
size even further.

The text-based dynamic library stub file format (.tbd) is a human readable and
editable YAML text file. The _TAPI_ projects uses the _LLVM_ YAML parser to read
those files and provides this functionality to the linker as a dynamic library.


## Building TAPI

*   Create a source directory <src_dir>.
*   Clone the **LLVM** source code for the `swift-4.2-branch` from
    [GitHub Apple/swift-llvm](https://github.com/apple/swift-llvm) into the
    <src_dir>/llvm directory.

    `git clone git@github.com:apple/swift-llvm.git llvm -b swift-4.2-branch`

*   Clone the **CLANG** source code for the `swift-4.2-branch` from
    [GitHub Apple/swift-clang](https://github.com/apple/swift-clang) into the
    <src_dir>/clang directory.

    `git clone git@github.com:apple/swift-clang.git clang -b swift-4.2-branch`

*   Place the content of this tar archive into the <src_dir>/tapi directory.

*   Create a separate build directory and configure the project with CMake:
    ```
    cmake -G Ninja -C <src_dir>/tapi/cmake/caches/apple-tapi.cmake
          -DCMAKE_INSTALL_PREFIX=<install_dir> <src_dir>/llvm
    ```

*   The CMake cache file defines most of the settings for you, such as enabling
    LTO. It also specifies the distribution components to include all the
    targets needed for TAPI.

*   To build and install the **TAPI** project invoke:
    ```
    ninja install-distribution
    ```
    in the build directory.
