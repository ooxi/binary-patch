# binary-patch / binary-patch / test / BinaryPatcherTest
project("${PROJECT_NAME}-BinaryPatcherTest" CXX)
add_executable("${PROJECT_NAME}")


target_sources(
	"${PROJECT_NAME}"
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/BinaryPatcherTest.c++"
)


target_link_libraries(
	"${PROJECT_NAME}"
	PUBLIC
		binary-patch::binary-patch
	PRIVATE
		binary-patch::defaults
)


add_test(
	NAME "${PROJECT_NAME}"
	COMMAND "${PROJECT_NAME}"
)
