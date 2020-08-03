#ifndef HEADER_BINARY_PATCH_OPTIONS
#define HEADER_BINARY_PATCH_OPTIONS


#include <binary-patch/Key.h++>
#include <binary-patch/Mac.h++>
#include <filesystem>


namespace binary_patch {

	class Options final {
	private:
		Key key;
		Mac mac;
		std::filesystem::path inputFile;
		std::filesystem::path replacementFile;
		std::filesystem::path outputDirectory;

	public:
		explicit Options(
			Key key,
			Mac mac,
			std::filesystem::path inputFile,
			std::filesystem::path replacementFile,
			std::filesystem::path outputDirectory
		);

		Key const& getKey() const;
		Mac const& getMac() const;
		std::filesystem::path getInputFile() const;
		std::filesystem::path getReplacementFile() const;
		std::filesystem::path getOutputDirectory() const;
	};
}


#endif
