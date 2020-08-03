#include <binary-patch/Key.h++>
#include <cstdlib>


using binary_patch::Key;





int main() {
	Key const expected{{
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
		'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
	}};
	Key const actual = Key::parseHex(
		"61" "62" "63" "64" "65" "66" "67" "68"
		"69" "6A" "6B" "6C" "6D" "6E" "6F" "70"
	);

	if (expected.getKey() != actual.getKey()) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
