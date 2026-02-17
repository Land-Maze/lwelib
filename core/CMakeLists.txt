file(GLOB_RECURSE FILES_SRC CONFIGURE_DEPENDS
		"${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

add_library(core ${FILES_SRC})

target_include_directories(core PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(core PUBLIC)