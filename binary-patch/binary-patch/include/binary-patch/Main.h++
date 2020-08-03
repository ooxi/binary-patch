#ifndef HEADER_BINARY_PATCH_MAIN
#define HEADER_BINARY_PATCH_MAIN


#include <binary-patch/Options.h++>


namespace binary_patch {

	class Main final {
	public:
		static void run(Options const& options);

	private:
		explicit Main() = delete;
	};
}


#endif
