#include <binary-patch/HexUtil.h++>
#include <cstdint>
#include <cstdlib>


using binary_patch::HexUtil;





int main() {
	std::uint8_t const expected{0xAB};
	std::uint8_t const actual = HexUtil::parse('A', 'B');

	if (expected != actual) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
