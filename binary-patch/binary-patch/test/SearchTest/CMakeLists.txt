# binary-patch / binary-patch / test / SearchTest
project("${PROJECT_NAME}-SearchTest" CXX)
add_executable("${PROJECT_NAME}")


target_sources(
	"${PROJECT_NAME}"
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/SearchTest.c++"
)


target_link_libraries(
	"${PROJECT_NAME}"
	PRIVATE
		binary-patch::defaults
)


add_test(
	NAME "${PROJECT_NAME}"
	COMMAND "${PROJECT_NAME}"
)
