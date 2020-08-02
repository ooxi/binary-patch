#ifndef HEADER_BINARY_PATCH_KEY
#define HEADER_BINARY_PATCH_KEY


#include <array>


namespace binary_patch {

	class Key final {
	private:
		std::array<char, 16> key;

	public:
		explicit Key(std::array<char, 16> key);

		std::array<char, 16> const& getKey() const;
	};
}


#endif
