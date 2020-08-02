# binary-patch / external / rapidcsv-csvm
project("binary-patch-rapidcsv" CXX)
add_library("${PROJECT_NAME}" INTERFACE)
add_library("binary-patch::rapidcsv" ALIAS "${PROJECT_NAME}")


target_include_directories(
	"${PROJECT_NAME}"
	INTERFACE
		"${CMAKE_CURRENT_LIST_DIR}/../rapidcsv/src"
)
