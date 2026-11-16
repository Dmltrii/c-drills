# c-drills

Embedded-oriented C11 / C++20 drills: bit manipulation, memory and pointers, data structures without dynamic allocation. Each exercise has GoogleTest tests and runs under ASan + UBSan.

## Requirements

CMake ≥ 3.20, Ninja, a C11/C++20 compiler (clang or gcc), GoogleTest.

- macOS: `brew install cmake ninja googletest`
- Debian/Ubuntu: `sudo apt install cmake ninja-build g++ libgtest-dev`

## Build and test

```bash
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

## Exercises

| Week.day | Exercise | Language | Mode | Time | Notes |
|---|---|---|---|---|---|
| 5.1 | [popcount three ways](w05d1_popcount/) | C11 | regular | 30 min | clang does not check sign conversion in compound assignment (`count += n & 1`), gcc does — hence the explicit cast `(int)(n & 1u)` |
| 5.2 | [in-place matrix transpose, three signatures](w05d2_matrix/) | C11 | regular | 60 min | `int m[][N]` and `int (*m)[N]` are the same parameter type, so the function bodies are identical. A test shows array decay: `sizeof` is 64 bytes in the test, 8 inside the function |