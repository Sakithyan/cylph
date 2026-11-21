#include "cylph.h"

#include <stdlib.h>

int cylph_version_major(void) { return 0; }
int cylph_version_minor(void) { return 1; }
int cylph_version_patch(void) { return 0; }

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