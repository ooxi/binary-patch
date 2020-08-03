#include <binary-patch/EntryParser.h++>

#include <binary-patch/Entry.h++>
#include <binary-patch/Key.h++>
#include <binary-patch/Mac.h++>
#include <cstddef>
#include <filesystem>
#include <ooxi/exception/Exception.h++>
#include <rapidcsv.h>
#include <vector>


using binary_patch::EntryParser;
using binary_patch::Entry;
using binary_patch::Key;
using binary_patch::Mac;





std::vector<Entry> EntryParser::parse(std::filesystem::path file) {
	std::vector<Entry> entries;

	rapidcsv::Document const document{file.string()};
	auto const keyColumnIdx = document.GetColumnIdx("KEY");
	auto const macColumnIdx = document.GetColumnIdx("MAC");

	if (-1 == keyColumnIdx) {
		THROW(	MissingKeyColumnException,
			"Missing key column"
		);
	}
	if (-1 == macColumnIdx) {
		THROW(	MissingMacColumnException,
			"Missing mac column"
		);
	}

	/* @warning Do _not_ add a newline at the end of the replacement CSV
	 *
	 * @see https://github.com/d99kris/rapidcsv/issues/55
	 */
	auto const keys = document.GetColumn<std::string>(keyColumnIdx);
	auto const macs = document.GetColumn<std::string>(macColumnIdx);

	if (keys.size() != macs.size()) {
		THROW(	ExpectedNumberOfKeysAndNumberOfMacsToMatchException,
			"Expected number of keys and number of macs to match"
		);
	}

	for (std::size_t idx = 0; idx < keys.size(); ++idx) {
		auto const key = Key::parseHex(keys.at(idx));
		auto const mac = Mac::parseHex(macs.at(idx));

		entries.emplace_back(key, mac);
	}

	return entries;
}
