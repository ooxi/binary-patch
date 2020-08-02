#ifndef HEADER_BINARY_PATCH_MAC
#define HEADER_BINARY_PATCH_MAC


#include <array>


namespace binary_patch {

	class Mac final {
	private:
		std::array<char, 6> mac;

	public:
		explicit Mac(std::array<char, 6> mac);

		std::array<char, 6> const& getMac() const;
	};
}


#endif
