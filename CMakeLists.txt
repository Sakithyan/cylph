cmake_minimum_required(VERSION 3.20)

project(cylph
    VERSION 0.1.0
    DESCRIPTION "A NumPy-like library for C"
    LANGUAGES C
)

# --- Language standard --------------------------------------------------------

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Export compile_commands.json (needed later for clang-tidy, see #4).
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --- Library target -----------------------------------------------------------

add_library(cylph
    src/cylph.c
)

target_include_directories(cylph PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# --- Tests --------------------------------------------------------------------

include(CTest)
enable_testing()

# The tests/ subdirectory will be added by issue #5 (Criterion framework):
# add_subdirectory(tests)