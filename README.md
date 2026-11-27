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

Build instructions will be added once the build system is in place (see
issue #2).

## Running the tests

Test instructions will be added once the test framework is in place (see
issue #5).

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