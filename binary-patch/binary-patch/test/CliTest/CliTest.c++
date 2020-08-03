#include <binary-patch/Cli.h++>
#include <binary-patch/Key.h++>
#include <binary-patch/Mac.h++>
#include <binary-patch/Options.h++>
#include <cstdlib>
#include <cstring>
#include <filesystem>


using binary_patch::Cli;
using binary_patch::Key;
using binary_patch::Mac;
using binary_patch::Options;





int main() {

	Key const expectedKey{{
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
		'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
	}};
	Mac const expectedMac{{
		'a', 'b', 'c', 'd', 'e', 'f'
	}};
	std::filesystem::path expectedInputFile{"./my-input-file"};
	std::filesystem::path expectedReplacementFile{"./my-replacement-file"};
	std::filesystem::path expectedOutputDirectory{"./my-output-directory"};


	/* @warning Memory leak accepted
	 */
	char* argv[] = {
		strdup("cli.exe"),
		strdup("--key-hex"),		strdup(	"61" "62" "63" "64" "65" "66" "67" "68"
							"69" "6A" "6B" "6C" "6D" "6E" "6F" "70"),
		strdup("--mac-hex"),		strdup("61" "62" "63" "64" "65" "66"),
		strdup("--input-file"),		strdup("./my-input-file"),
		strdup("--replacement-file"),	strdup("./my-replacement-file"),
		strdup("--output-directory"),	strdup("./my-output-directory"),
	};
	int argc = sizeof(argv) / sizeof(argv[0]);


	Options const options = Cli::parse(argc, argv);

	if (expectedKey.getKey() != options.getKey().getKey()) {
		return EXIT_FAILURE;
	}
	if (expectedMac.getMac() != options.getMac().getMac()) {
		return EXIT_FAILURE;
	}
	if (expectedInputFile != options.getInputFile()) {
		return EXIT_FAILURE;
	}
	if (expectedReplacementFile != options.getReplacementFile()) {
		return EXIT_FAILURE;
	}
	if (expectedOutputDirectory != options.getOutputDirectory()) {
		return EXIT_FAILURE;
	}


	return EXIT_SUCCESS;
}
