#include <binary-patch/Mac.h++>
#include <cstdlib>


using binary_patch::Mac;





int main() {
	Mac const expected{{
		'a', 'b', 'c', 'd', 'e', 'f'
	}};
	Mac const actual = Mac::parseHex(
		"61" "62" "63" "64" "65" "66"
	);

	if (expected.getMac() != actual.getMac()) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
