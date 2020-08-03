#include <binary-patch/HexUtil.h++>

#include <cstdint>
#include <ooxi/exception/Exception.h++>


using binary_patch::HexUtil;





/*static*/ std::uint8_t parseNibble(char hexNibble) {
	switch (hexNibble) {
		case '0':	return 0x0;
		case '1':	return 0x1;
		case '2':	return 0x2;
		case '3':	return 0x3;
		case '4':	return 0x4;
		case '5':	return 0x5;
		case '6':	return 0x6;
		case '7':	return 0x7;
		case '8':	return 0x8;
		case '9':	return 0x9;
		case 'A':	[[fallthrough]];
		case 'a':	return 0xA;
		case 'B':	[[fallthrough]];
		case 'b':	return 0xB;
		case 'C':	[[fallthrough]];
		case 'c':	return 0xC;
		case 'D':	[[fallthrough]];
		case 'd':	return 0xD;
		case 'E':	[[fallthrough]];
		case 'e':	return 0xE;
		case 'F':	[[fallthrough]];
		case 'f':	return 0xF;
	}

	THROW(	IllegalHexNibbleCharacterException,
		"Illegal hex nibble character"
	);
}


char HexUtil::parse(char hexFirstNibble, char hexSecondNibble) {
	auto const firstNibble = parseNibble(hexFirstNibble);
	auto const secondNibble = parseNibble(hexSecondNibble);

	return (firstNibble << 4) | secondNibble;
}
