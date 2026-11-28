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

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --- Library target -----------------------------------------------------------
# Sources are added by each module via target_sources() in src/<module>/CMakeLists.txt.
add_library(cylph)

target_include_directories(cylph PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# --- Tests --------------------------------------------------------------------
include(CTest)
enable_testing()

# Unity test framework (simple, header-only style, zero system deps).
include(FetchContent)

FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG        v2.6.0
)
FetchContent_MakeAvailable(unity)

# --- Modules ------------------------------------------------------------------
add_subdirectory(src/core)