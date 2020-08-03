#include <binary-patch/Mac.h++>

#include <array>
#include <binary-patch/HexUtil.h++>
#include <ooxi/exception/Exception.h++>
#include <string_view>
#include <utility>


using binary_patch::HexUtil;
using binary_patch::Mac;





Mac::Mac(std::array<char, 6> mac) : mac{std::move(mac)} {
}


std::array<char, 6> const& Mac::getMac() const {
	return mac;
}


Mac Mac::parseHex(std::string_view macHex) {
	if ((6 * 2) != macHex.length()) {
		THROW(	IllegalHexMacLengthException,
			"Hex representation of mac must be exactly 12 characters"
		);
	}

	return Mac{{
		HexUtil::parse(macHex[ 0], macHex[ 0 + 1]),
		HexUtil::parse(macHex[ 2], macHex[ 2 + 1]),
		HexUtil::parse(macHex[ 4], macHex[ 4 + 1]),
		HexUtil::parse(macHex[ 6], macHex[ 6 + 1]),
		HexUtil::parse(macHex[ 8], macHex[ 8 + 1]),
		HexUtil::parse(macHex[10], macHex[10 + 1]),
	}};
}
