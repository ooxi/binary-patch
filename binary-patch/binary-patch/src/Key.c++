#include <binary-patch/Key.h++>

#include <array>
#include <binary-patch/HexUtil.h++>
#include <ooxi/exception/Exception.h++>
#include <string_view>
#include <utility>


using binary_patch::Key;





Key::Key(std::array<char, 16> key) : key{std::move(key)} {
}


std::array<char, 16> const& Key::getKey() const {
	return key;
}


Key Key::parseHex(std::string_view keyHex) {
	if ((16 * 2) != keyHex.length()) {
		THROW(	IllegalHexKeyLengthException,
			"Hex representation of key must be exactly 32 characters"
		);
	}

	return Key{{
		HexUtil::parse(keyHex[ 0], keyHex[ 0 + 1]),
		HexUtil::parse(keyHex[ 2], keyHex[ 2 + 1]),
		HexUtil::parse(keyHex[ 4], keyHex[ 4 + 1]),
		HexUtil::parse(keyHex[ 6], keyHex[ 6 + 1]),
		HexUtil::parse(keyHex[ 8], keyHex[ 8 + 1]),
		HexUtil::parse(keyHex[10], keyHex[10 + 1]),
		HexUtil::parse(keyHex[12], keyHex[12 + 1]),
		HexUtil::parse(keyHex[14], keyHex[14 + 1]),
		HexUtil::parse(keyHex[16], keyHex[16 + 1]),
		HexUtil::parse(keyHex[18], keyHex[18 + 1]),
		HexUtil::parse(keyHex[20], keyHex[20 + 1]),
		HexUtil::parse(keyHex[22], keyHex[22 + 1]),
		HexUtil::parse(keyHex[24], keyHex[24 + 1]),
		HexUtil::parse(keyHex[26], keyHex[26 + 1]),
		HexUtil::parse(keyHex[28], keyHex[28 + 1]),
		HexUtil::parse(keyHex[30], keyHex[30 + 1]),
	}};
}
