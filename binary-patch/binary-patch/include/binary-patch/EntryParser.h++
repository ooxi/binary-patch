#ifndef HEADER_BINARY_PATCH_ENTRY_PARSER
#define HEADER_BINARY_PATCH_ENTRY_PARSER


#include <binary-patch/Entry.h++>
#include <filesystem>
#include <vector>


namespace binary_patch {

	class EntryParser final {
	public:
		static std::vector<Entry> parse(std::filesystem::path file);

	private:
		explicit EntryParser() = delete;
	};
}


#endif
