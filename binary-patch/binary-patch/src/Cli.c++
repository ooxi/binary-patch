#include <binary-patch/Cli.h++>

#include <binary-patch/Key.h++>
#include <binary-patch/Mac.h++>
#include <binary-patch/Options.h++>
#include <cxxopts.hpp>
#include <filesystem>


using binary_patch::Cli;
using binary_patch::Key;
using binary_patch::Mac;
using binary_patch::Options;





Options Cli::parse(int argc, char** argv) {
	cxxopts::Options options{"binary-patch"};

	options.add_options()
		("key-hex", "Key in hex notation", cxxopts::value<std::string>())
		("mac-hex", "Mac in hex notation", cxxopts::value<std::string>())
		("input-file", "Input file", cxxopts::value<std::string>())
		("replacement-file", "Input file", cxxopts::value<std::string>())
		("output-directory", "Output directory", cxxopts::value<std::string>())
	;

	auto const result = options.parse(argc, argv);

	auto const key = Key::parseHex(result["key-hex"].as<std::string>());
	auto const mac = Mac::parseHex(result["mac-hex"].as<std::string>());
	auto const inputFile = std::filesystem::path(result["input-file"].as<std::string>());
	auto const replacementFile = std::filesystem::path(result["replacement-file"].as<std::string>());
	auto const outputDirectory = std::filesystem::path(result["output-directory"].as<std::string>());

	return Options{key, mac, inputFile, replacementFile, outputDirectory};
}
