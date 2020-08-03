# binary-patch / binary-patch / executable
project("binary-patch-binary-patch-executable" CXX)
add_executable("${PROJECT_NAME}")


target_sources(
	"${PROJECT_NAME}"
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/Executable.c++"
)


target_link_libraries(
	"${PROJECT_NAME}"
	PUBLIC
		binary-patch::binary-patch
	PRIVATE
		binary-patch::defaults
)
