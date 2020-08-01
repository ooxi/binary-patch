# binary-patch / example
project("binary-patch-example" CXX)
add_library("${PROJECT_NAME}" STATIC)
add_library("binary-patch::example" ALIAS "${PROJECT_NAME}")


target_sources(
	"${PROJECT_NAME}"
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/src/Add.c++"
)


target_include_directories(
	"${PROJECT_NAME}"
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/include"
)


add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/test/ExampleTest")

