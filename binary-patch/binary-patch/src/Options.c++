#include <binary-patch/Options.h++>

#include <binary-patch/Entry.h++>
#include <binary-patch/Key.h++>
#include <binary-patch/Mac.h++>
#include <filesystem>
#include <utility>


using binary_patch::Entry;
using binary_patch::Key;
using binary_patch::Mac;
using binary_patch::Options;





Options::Options(
	Key key,
	Mac mac,
	std::filesystem::path inputFile,
	std::filesystem::path outputDirectory
) :
	key{std::move(key)},
	mac{std::move(mac)},
	inputFile{std::move(inputFile)},
	outputDirectory{std::move(outputDirectory)}
{}


Key const& Options::getKey() const {
	return key;
}


Mac const& Options::getMac() const {
	return mac;
}


std::filesystem::path Options::getInputFile() const {
	return inputFile;
}


std::filesystem::path Options::getOutputDirectory() const {
	return outputDirectory;
}
