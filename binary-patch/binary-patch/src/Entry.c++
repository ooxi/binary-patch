#include <binary-patch/Entry.h++>

#include <binary-patch/Key.h++>
#include <binary-patch/Mac.h++>
#include <cstdint>
#include <sstream>
#include <string>
#include <utility>


using binary_patch::Entry;
using binary_patch::Key;
using binary_patch::Mac;


Entry::Entry(Key key, Mac mac)
:	key{std::move(key)},
	mac{std::move(mac)}
{}


Key const& Entry::getKey() const {
	return key;
}


Mac const& Entry::getMac() const {
	return mac;
}


std::string Entry::getName() const {
	std::stringstream ss;

	ss << "KEY = ";

	for (auto const k : getKey().getKey()) {
		ss << std::hex << static_cast<std::uint32_t>(k);
	}

	ss << ", MAC = ";

	for (auto const m : getMac().getMac()) {
		ss << std::hex << static_cast<std::uint32_t>(m);
	}

	return ss.str();
}
