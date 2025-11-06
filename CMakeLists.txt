cmake_minimum_required(VERSION 4.0)
project(
		LatticeViz
		VERSION 0.1.0
		LANGUAGES CXX
)

add_executable(${PROJECT_NAME} src/main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
		CXX_STANDARD 17
		CXX_STANDARD_REQUIRED ON
		CXX_EXTENSIONS OFF
		COMPILE_WARNING_AS_ERROR ON
		CMAKE_CXX_FLAGS_DEBUG "-g -O0"
		CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG"
)

include(cmake/Dependencies.cmake)

add_subdirectory(core)
add_subdirectory(crypto)
add_subdirectory(gfx)

target_link_libraries(${PROJECT_NAME} PRIVATE core crypto gfx)

if (MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

if (XCODE)
	set_target_properties(App PROPERTIES
			XCODE_GENERATE_SCHEME ON
			XCODE_SCHEME_ENABLE_GPU_FRAME_CAPTURE_MODE "Metal"
	)
endif()