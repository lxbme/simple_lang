cmake_minimum_required(VERSION 3.27)

project(simple_lang)

include_directories(Include)

add_subdirectory(LangKernel)
add_subdirectory(Tests)

set(CMAKE_C_STANDARD 11)

