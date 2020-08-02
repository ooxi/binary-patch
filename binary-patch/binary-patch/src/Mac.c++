#include <binary-patch/Mac.h++>

#include <array>
#include <utility>


using binary_patch::Mac;





Mac::Mac(std::array<char, 6> mac) : mac{std::move(mac)} {
}


std::array<char, 6> const& Mac::getMac() const {
	return mac;
}
