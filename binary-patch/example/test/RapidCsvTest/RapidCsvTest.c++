#include <cstdlib>
#include <rapidcsv.h>
#include <string>
#include <vector>


int main() {
	using v = std::vector<std::string>;

	rapidcsv::Document doc{"test.csv"};

	auto const macs = doc.GetColumn<std::string>("MAC");
	auto const keys = doc.GetColumn<std::string>("KEY");

	if (macs != v{"AABBCCDDEEFF", "FFEEDDCCBBAA"}) {
		return EXIT_FAILURE;
	}

	if (keys != v{"00112233445566778899AABBCCDDEEFF", "FFEEDDCCBBAA99887766554433221100"}) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
