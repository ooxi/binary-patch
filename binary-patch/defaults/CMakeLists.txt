# binary-patch / defaults
project("binary-patch-defaults" CXX)
add_library("${PROJECT_NAME}" INTERFACE)
add_library("binary-patch::defaults" ALIAS "${PROJECT_NAME}")


target_compile_options(
	"${PROJECT_NAME}"
	INTERFACE
		-std=c++17

		-Wall
		-Wextra
		-Werror
		-pedantic

		-Wnon-virtual-dtor
		-Wcast-align
		-Wunused
		-Woverloaded-virtual
		-Wpedantic
		-Wdouble-promotion
		-Wformat=2
)
