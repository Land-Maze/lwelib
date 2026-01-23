cmake_minimum_required(VERSION 4.0)
project(
		LWELibrary
		DESCRIPTION "A library for Learning With Errors (LWE) cryptographic schemes such as Modular LWE and Ring LWE."
		VERSION 0.1.0
		LANGUAGES CXX C
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

include(cmake/Dependencies.cmake)

add_subdirectory(core)
add_subdirectory(crypto)
add_subdirectory(benchmark)