# binary-patch / example / test / RapidCsvTest
project("${PROJECT_NAME}-RapidCsvTest" CXX)
add_executable("${PROJECT_NAME}")


target_sources(
	"${PROJECT_NAME}"
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/RapidCsvTest.c++"
)


target_link_libraries(
	"${PROJECT_NAME}"
	PUBLIC
		binary-patch::rapidcsv
	PRIVATE
		binary-patch::defaults
)


configure_file(
	"${CMAKE_CURRENT_LIST_DIR}/test.csv"
	"${CMAKE_CURRENT_BINARY_DIR}/test.csv"
	COPYONLY
)


add_test(
	NAME "${PROJECT_NAME}"
	COMMAND "${PROJECT_NAME}"
)
