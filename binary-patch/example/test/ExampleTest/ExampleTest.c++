#include <binary-patch/example/Add.h++>
#include <cstdlib>



int main() {
	int const expected = 5;
	int const actual = binary_patch::example::add(2, 3);

	if (expected != actual) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
