#ifndef HEADER_BINARY_PATCH_HEX_UTIL
#define HEADER_BINARY_PATCH_HEX_UTIL


namespace binary_patch {

	class HexUtil final {
	public:
		static char parse(char hexFirstNibble, char hexSecondNibble);

	private:
		explicit HexUtil() = delete;
	};
}


#endif
