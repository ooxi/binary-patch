#ifndef HEADER_BINARY_PATCH_MAC
#define HEADER_BINARY_PATCH_MAC


#include <array>
#include <string_view>


namespace binary_patch {

	class Mac final {
	private:
		std::array<char, 6> mac;

	public:
		explicit Mac(std::array<char, 6> mac);

		std::array<char, 6> const& getMac() const;

	public:
		static Mac parseHex(std::string_view macHex);
	};
}


#endif
