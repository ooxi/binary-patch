#ifndef HEADER_BINARY_PATCH_CLI
#define HEADER_BINARY_PATCH_CLI


#include <binary-patch/Options.h++>


namespace binary_patch {

	class Cli final {
	public:
		static Options parse(int argc, char** argv);

	private:
		explicit Cli() = default;
	};
}


#endif
