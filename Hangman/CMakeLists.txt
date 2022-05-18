cmake_minimum_required(VERSION 3.13)
project(Hangman)

set(CMAKE_CXX_STANDARD 14)

set(libcurl_INCLUDE_DIR "C:/Users/angry/CLionProjects/Hangman/curl-7.83.1_1-win64-mingw/curl-7.83.1-win64-mingw/include")
include_directories(${libcurl_INCLUDE_DIR})

add_executable(Hangman main.cpp functions.cpp functions.h)

target_link_libraries(Hangman C:/Users/angry/CLionProjects/Hangman/curl-7.83.1_1-win64-mingw/curl-7.83.1-win64-mingw/lib/libcurl.dll.a)
