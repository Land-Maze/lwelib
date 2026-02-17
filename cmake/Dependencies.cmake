include(FetchContent)

# ---------------------------------------------------------------------------
# EXAMPLE FOR FUTURE
# ---------------------------------------------------------------------------
#FetchContent_Declare(
#		glfw
#		GIT_REPOSITORY https://github.com/glfw/glfw.git
#		GIT_TAG latest
#		GIT_SHALLOW TRUE
#)
#FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
		Catch2
		GIT_REPOSITORY https://github.com/catchorg/Catch2.git
		GIT_TAG        v3.4.0
		GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(Catch2)