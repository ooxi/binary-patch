#include <algorithm>
#include <array>
#include <cstdlib>
#include <vector>


int main() {
	std::vector<char> const haystack{
		'a', 'b', 'c', 'd', 'd',
		'a', 'b', 'c', 'd', 'd',
		'a', 'b', 'c'
	};
	std::array<char, 3> const needle{'a', 'b', 'c'};

	auto const first = std::search(
		std::begin(haystack), std::end(haystack),
		std::begin(needle), std::end(needle)
	);
	auto const second = std::search(
		first + 1, std::end(haystack),
		std::begin(needle), std::end(needle)
	);
	auto const third = std::search(
		second + 1, std::end(haystack),
		std::begin(needle), std::end(needle)
	);

	auto const expectedFirst = std::begin(haystack) + 0;
	auto const expectedSecond = std::begin(haystack) + 5;
	auto const expectedThird = std::begin(haystack) + 10;

	if (expectedFirst != first) {
		return EXIT_FAILURE;
	}
	if (expectedSecond != second) {
		return EXIT_FAILURE;
	}
	if (expectedThird != third) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
