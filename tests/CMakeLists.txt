add_executable(test_array test_array.c)
target_link_libraries(test_array PRIVATE cylph)
add_test(NAME test_array COMMAND test_array)