# binary-patch / example / test / ExampleTest
project("${PROJECT_NAME}-ExampleTest" CXX)
add_executable("${PROJECT_NAME}")


target_sources(
	"${PROJECT_NAME}"
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/ExampleTest.c++"
)


target_link_libraries(
	"${PROJECT_NAME}"
	PRIVATE
		binary-patch::example
	PRIVATE
		binary-patch::defaults
)


add_test(
	NAME "${PROJECT_NAME}"
	COMMAND "${PROJECT_NAME}"
)
