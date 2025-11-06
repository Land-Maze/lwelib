file(GLOB_RECURSE FILES_SRC CONFIGURE_DEPENDS
		"${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(gfx ${FILES_SRC})

target_include_directories(gfx PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

# WebGPU blackbox
target_link_libraries(gfx PRIVATE webgpu)
target_copy_webgpu_binaries(gfx)

target_link_libraries(gfx PUBLIC)