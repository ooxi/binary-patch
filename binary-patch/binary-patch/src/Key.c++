#include <binary-patch/Key.h++>

#include <array>
#include <utility>


using binary_patch::Key;





Key::Key(std::array<char, 16> key) : key{std::move(key)} {
}


std::array<char, 16> const& Key::getKey() const {
	return key;
}
