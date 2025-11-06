include(FetchContent)

# ---------------------------------------------------------------------------
# GLFW
# ---------------------------------------------------------------------------
FetchContent_Declare(
		glfw
		GIT_REPOSITORY https://github.com/glfw/glfw.git
		GIT_TAG latest
		GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(glfw)

# ---------------------------------------------------------------------------
# ImGui
# ---------------------------------------------------------------------------
FetchContent_Declare(
		imgui
		GIT_REPOSITORY https://github.com/ocornut/imgui.git
		GIT_TAG master
		GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(imgui)

add_library(imgui_lib
		${imgui_SOURCE_DIR}/imgui.cpp
		${imgui_SOURCE_DIR}/imgui_draw.cpp
		${imgui_SOURCE_DIR}/imgui_tables.cpp
		${imgui_SOURCE_DIR}/imgui_widgets.cpp
		${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
		${imgui_SOURCE_DIR}/backends/imgui_impl_wgpu.cpp
)
target_include_directories(imgui_lib PUBLIC
		${imgui_SOURCE_DIR}
		${imgui_SOURCE_DIR}/backends
)
target_link_libraries(imgui_lib PUBLIC glfw)

# ---------------------------------------------------------------------------
# WebGPU (static link)
# Thanks to the Élie Michel
# ---------------------------------------------------------------------------

if (NOT TARGET webgpu)
		FetchContent_Declare(
				webgpu-backend-wgpu-static
				GIT_REPOSITORY https://github.com/eliemichel/WebGPU-distribution
				GIT_TAG wgpu-static-v0.19.4.1
		)
		FetchContent_MakeAvailable(webgpu-backend-wgpu-static)
endif()