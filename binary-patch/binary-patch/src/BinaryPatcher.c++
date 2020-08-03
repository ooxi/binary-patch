#include <binary-patch/BinaryPatcher.h++>

#include <algorithm>
#include <array>
#include <binary-patch/Entry.h++>
#include <cstddef>
#include <utility>
#include <vector>


using binary_patch::BinaryPatcher;
using binary_patch::Entry;





template<std::size_t needleLength>
static std::vector<std::vector<char>::iterator> find(
			std::vector<char>& haystack,
			std::array<char, needleLength> needle
		) {

	std::vector<std::vector<char>::iterator> result;

	auto const first = std::begin(haystack);
	auto const last = std::end(haystack);

	auto const firstS = std::begin(needle);
	auto const lastS = std::end(needle);

	for (	auto found = std::search(first, last, firstS, lastS);
		found != last;
		found = std::search(found + 1, last, firstS, lastS)
	) {
		result.push_back(found);
	}

	return result;
}


BinaryPatcher::BinaryPatcher(
	std::vector<char> haystack,
	Entry const& needle
) :
	original{std::move(haystack)},
	keys{find(this->original, needle.getKey().getKey())},
	macs{find(this->original, needle.getMac().getMac())}
{}


std::vector<char> const& BinaryPatcher::patch(Entry const& entry) const {
	auto const& key = entry.getKey().getKey();
	auto const& mac = entry.getMac().getMac();

	for (auto const& pos : keys) {
		std::copy(std::begin(key), std::end(key), pos);
	}

	for (auto const& pos : macs) {
		std::copy(std::begin(mac), std::end(mac), pos);
	}

	return original;
}
