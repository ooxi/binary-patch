# binary-patch / example / test / CxxOptsTest
project("${PROJECT_NAME}-CxxOptsTest" CXX)
add_executable("${PROJECT_NAME}")


target_sources(
	"${PROJECT_NAME}"
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/CxxOptsTest.c++"
)


target_link_libraries(
	"${PROJECT_NAME}"
	PUBLIC
		cxxopts::cxxopts
	PRIVATE
		binary-patch::defaults
)


add_test(
	NAME "${PROJECT_NAME}"
	COMMAND "${PROJECT_NAME}"
)
