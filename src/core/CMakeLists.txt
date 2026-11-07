# Module: core
# Public functions declared in include/cylph.h, implemented here.

target_sources(cylph PRIVATE core.c)

# --- Tests ---
add_executable(test_core tests/test_core.c)

target_link_libraries(test_core PRIVATE
    cylph
    unity
)

add_test(NAME core COMMAND test_core)