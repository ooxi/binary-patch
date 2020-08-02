#ifndef HEADER_BINARY_PATCH_ENTRY
#define HEADER_BINARY_PATCH_ENTRY


#include <binary-patch/Key.h++>
#include <binary-patch/Mac.h++>
#include <string>


namespace binary_patch {

	class Entry final {
	private:
		Key key;
		Mac mac;

	public:
		explicit Entry(Key key, Mac mac);

		Key const& getKey() const;
		Mac const& getMac() const;
	};
}


#endif
