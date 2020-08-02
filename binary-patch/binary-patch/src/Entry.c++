#include <binary-patch/Entry.h++>

#include <binary-patch/Key.h++>
#include <binary-patch/Mac.h++>
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
