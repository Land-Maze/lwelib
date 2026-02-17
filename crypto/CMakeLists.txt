file(GLOB CRYPTO_SOURCES "src/*.c")
file(GLOB CRYPTO_HEADERS "include/*.h")

add_library(mlwe-fast SHARED ${CRYPTO_SOURCES})

target_include_directories(mlwe-fast
		PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
		PRIVATE
		core
)

set_target_properties(mlwe-fast PROPERTIES
		POSITION_INDEPENDENT_CODE ON
		C_VISIBILITY_PRESET hidden
		VISIBILITY_INLINES_HIDDEN ON
)