#include "cylph.h"

#include <stdint.h>
#include <stdlib.h>

/* Internal layout of an Array. Hidden from the users of the library. */
struct Array {
    double *data;    /* elements stored in a heap-allocated block */
    size_t length;   /* number of elements currently in the array */
    size_t capacity; /* number of elements the block can hold */
};

Array *array_create(size_t length) {
    Array *a = malloc(sizeof(Array));
    if (a == NULL) {
        return NULL;
    }

    /* Allocate at least one slot, so that data is never NULL. */
    size_t capacity = (length > 0) ? length : 1;

    /* calloc sets every element to 0. */
    a->data = calloc(capacity, sizeof(double));
    if (a->data == NULL) {
        free(a);
        return NULL;
    }

    a->length = length;
    a->capacity = capacity;
    return a;
}

void array_free(Array *a) {
    if (a == NULL) {
        return;
    }
    free(a->data);
    free(a);
}

size_t array_length(const Array *a) {
    return a->length;
}

int array_get(const Array *a, size_t index, double *out) {
    if (index >= a->length) {
        return -1;
    }
    *out = a->data[index];
    return 0;
}

int array_set(Array *a, size_t index, double value) {
    if (index >= a->length) {
        return -1;
    }
    a->data[index] = value;
    return 0;
}

int array_append(Array *a, double value) {
    if (a->length == a->capacity) {
        /* Refuse to grow if doubling the block size would overflow. */
        if (a->capacity > SIZE_MAX / 2 / sizeof(double)) {
            return -1;
        }
        size_t new_capacity = a->capacity * 2;

        /* Use a temporary pointer: if realloc fails, a->data is still valid. */
        double *new_data = realloc(a->data, new_capacity * sizeof(double));
        if (new_data == NULL) {
            return -1;
        }
        a->data = new_data;
        a->capacity = new_capacity;
    }

    a->data[a->length] = value;
    a->length++;
    return 0;
}
