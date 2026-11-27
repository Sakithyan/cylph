# Module: array
# Public functions declared in include/cylph.h, implemented here.

target_sources(cylph PRIVATE array.c)

# --- Tests ---
add_executable(test_array tests/test_array.c)
target_link_libraries(test_array PRIVATE cylph)
add_test(NAME array COMMAND test_array)
