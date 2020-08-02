#ifndef HEADER_BINARY_PATCH_BINARY_PATCHER
#define HEADER_BINARY_PATCH_BINARY_PATCHER


#include <binary-patch/Entry.h++>
#include <vector>


namespace binary_patch {

	class BinaryPatcher final {
	private:
		std::vector<char> original;
		std::vector<decltype(original)::iterator> keys;
		std::vector<decltype(original)::iterator> macs;

	public:
		explicit BinaryPatcher(
			std::vector<char> haystack,
			Entry const& needle
		);

		/* @warning Returned vector will only be valid until the next
		 *     invocation of {@link patch}!
		 */
		std::vector<char> const& patch(Entry const& replacement) const;
	};
}


#endif
