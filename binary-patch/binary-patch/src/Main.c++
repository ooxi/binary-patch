#include <binary-patch/Main.h++>

#include <binary-patch/BinaryPatcher.h++>
#include <binary-patch/EntryParser.h++>
#include <binary-patch/Entry.h++>
#include <binary-patch/Options.h++>
#include <filesystem>
#include <fstream>
#include <ooxi/exception/Exception.h++>
#include <vector>


using binary_patch::BinaryPatcher;
using binary_patch::EntryParser;
using binary_patch::Entry;
using binary_patch::Main;
using binary_patch::Options;





/* @see https://stackoverflow.com/a/18816228
 * @author fsenart
 * @author jrok
 */
static std::vector<char> readFile(std::filesystem::path file) {
	std::ifstream ifs{file, std::ios::ate | std::ios::binary | std::ios::in};
	std::streamsize const size = ifs.tellg();
	std::vector<char> buffer(size);

	ifs.seekg(0, std::ios::beg);

	if (!ifs.read(buffer.data(), size)) {
		THROW(	FailedReadingFileException,
			"Failed reading file"
		);
	}

	return buffer;
}


void Main::run(Options const& options) {

	/* Prepare input file by scanning for key and mac
	 */
	BinaryPatcher const binaryPatcher{
		readFile(options.getInputFile()),
		Entry{options.getKey(), options.getMac()}
	};

	auto const replacements = EntryParser::parse(
		options.getReplacementFile()
	);


	/* Automatically create output directory, if it does not exist
	 */
	auto const outputDirectory = options.getOutputDirectory();

	if (!std::filesystem::exists(outputDirectory)) {
		std::filesystem::create_directories(outputDirectory);
	}


	/* Execute replacements
	 */
	for (auto const& replacement : replacements) {
		auto const outputName = options.getInputFile().filename().string() + " (" + replacement.getName() + ")";
		auto const outputFile = outputDirectory / outputName;

		auto const& patched = binaryPatcher.patch(replacement);

		std::ofstream ofs{outputFile, std::ios::binary | std::ios::out};
		ofs.write(patched.data(), patched.size());
	}
}
