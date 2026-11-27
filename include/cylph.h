#ifndef CYLPH_H
#define CYLPH_H

#include <stddef.h>

/*
 * Cylph: a NumPy-like library for C.
 * Public API will grow as features land (see issues #9 and beyond).
 */

/* Returns the library version as integers (major, minor, patch). */
int cylph_version_major(void);
int cylph_version_minor(void);
int cylph_version_patch(void);

/**
 * A dynamic one-dimensional array of doubles.
 *
 * The structure is opaque: its fields are hidden from the user, who only
 * manipulates it through the functions below.
 */
typedef struct Array Array;

/**
 * Creates a new array of the given length, with all elements set to 0.
 *
 * @param length Number of elements.
 * @return A new array, or NULL if the memory allocation fails.
 *         The array must be released with array_free().
 */
Array *array_create(size_t length);

/**
 * Releases all the memory used by an array.
 *
 * @param a The array to release.
 */
void array_free(Array *a);

/**
 * Returns the number of elements in an array.
 *
 * @param a The array (must not be NULL).
 * @return The number of elements.
 */
size_t array_length(const Array *a);

/**
 * Reads the element at the given index.
 *
 * @param a     The array (must not be NULL).
 * @param index Position of the element, starting at 0.
 * @param out   Receives the element (must not be NULL).
 * @return 0 on success, -1 if the index is out of range.
 */
int array_get(const Array *a, size_t index, double *out);

/**
 * Writes the element at the given index.
 *
 * @param a     The array (must not be NULL).
 * @param index Position of the element, starting at 0.
 * @param value The value to store.
 * @return 0 on success, -1 if the index is out of range.
 */
int array_set(Array *a, size_t index, double value);
#endif /* CYLPH_H */