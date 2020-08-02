#include <binary-patch/BinaryPatcher.h++>
#include <binary-patch/Entry.h++>
#include <binary-patch/Key.h++>
#include <binary-patch/Mac.h++>
#include <cstdlib>


using binary_patch::BinaryPatcher;
using binary_patch::Entry;
using binary_patch::Key;
using binary_patch::Mac;





int main() {
	std::vector<char> const haystack{
		'a', 'b', 'c', 'a', 'b', 'c', 'd', 'd',
		'a', 'b', 'c', 'a', 'b', 'c', 'd', 'd',
		'x', 'y', 'z', 'a', 'x', 'y', 'z', 'a',
		'x', 'y', 'z', 'a', 'x', 'y', 'z', 'a',
	};
	Entry const needle{
		Key{{	'x', 'y', 'z', 'a', 'x', 'y', 'z', 'a',
			'x', 'y', 'z', 'a', 'x', 'y', 'z', 'a',
		}},
		Mac{{	'a', 'b', 'c', 'a', 'b', 'c'
		}}
	};

	Entry const replacement{
		Key{{	'0', '0', '0', '0', '1', '1', '1', '1',
			'2', '2', '2', '2', '3', '3', '3', '3',
		}},
		Mac{{	'A', 'A', 'A', 'B', 'B', 'B'
		}}
	};
	std::vector<char> const expected{
		'A', 'A', 'A', 'B', 'B', 'B', 'd', 'd',
		'A', 'A', 'A', 'B', 'B', 'B', 'd', 'd',
		'0', '0', '0', '0', '1', '1', '1', '1',
		'2', '2', '2', '2', '3', '3', '3', '3',
	};

	BinaryPatcher const binaryPatcher{haystack, needle};
	auto const& actual = binaryPatcher.patch(replacement);

	if (expected != actual) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
