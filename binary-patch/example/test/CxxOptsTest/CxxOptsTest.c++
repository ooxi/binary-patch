#include <cstdlib>
#include <cstring>
#include <cxxopts.hpp>





/* @see https://github.com/jarro2783/cxxopts#example
 */
int main() {
	cxxopts::Options options{"test", "A brief description"};

	options.add_options()
		("b,bar", "Param bar", cxxopts::value<std::string>())
		("d,debug", "Enable debugging", cxxopts::value<bool>()->default_value("false"))
		("f,foo", "Param foo", cxxopts::value<int>()->default_value("10"))
		("h,help", "Print usage")
	;

	/* @warning Memory leak accepted
	 */
	char* argv[] = {
		strdup("example.exe"),
		strdup("--debug"),
	};
	char** argv_ = argv;
	int argc = sizeof(argv) / sizeof(argv[0]);

	auto const result = options.parse(argc, argv_);
	bool const debug = result["debug"].as<bool>();

	if (!debug) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
