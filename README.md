# Cylph

A NumPy-like library for C: multidimensional arrays, vectorized operations
and broadcasting. One call acts on the whole array, memory is managed for
you.

## Why Cylph

Writing numerical code in C usually means writing many loops and managing
`malloc` and `free` by hand. Cylph gives C the convenience of NumPy: you
create an array, you apply an operation on the whole array in one call,
and the memory is handled for you.

## Planned features

- Multidimensional arrays (`ndim`, `shape`, typed elements)
- Hidden memory management (no `malloc` / `free` for the user)
- Scalar operations on arrays (`A += 4`)
- Element-wise operations between arrays (`A = B + C`)
- Reductions along an axis (`sum`, `mean` with `axis`)
- Broadcasting between arrays of different shapes
- Debug printing (`array_print`)

## Build

Requirements:

- CMake 3.20 or newer
- A C11 compiler (GCC, Clang or MSVC)
- Git (CMake uses it to download the [Unity](https://github.com/ThrowTheSwitch/Unity)
  test framework during configuration)

From the root of the repository:

```sh
cmake -B build
cmake --build build
```

This builds the `cylph` library and the test executables in the `build/`
directory.

With a multi-configuration generator such as Visual Studio, also give the
configuration:

```sh
cmake --build build --config Debug
```

## Running the tests

After building:

```sh
ctest --test-dir build --output-on-failure
```

With a multi-configuration generator, add `-C Debug`:

```sh
ctest --test-dir build -C Debug --output-on-failure
```

Tests are written with Unity and live next to the code they check, in
`src/<module>/tests/` (for example `src/core/tests/test_core.c`). Each
module registers its tests with CTest in its own `src/<module>/CMakeLists.txt`.
The same commands run in the CI on every pull request (Ubuntu and Windows).

## Contributing

1. Pick an open issue and assign yourself.
2. Create a branch following the convention `type/N-short-description`
   (where `N` is the issue number).
3. Write the code and the tests in small, focused commits.
4. Open a pull request with a clear description and `Closes #N` in the
   body.
5. Wait for a review from another team member before merging.

## License

MIT. See the `LICENSE` file.