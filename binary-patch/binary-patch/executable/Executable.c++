#include <binary-patch/Cli.h++>
#include <binary-patch/Main.h++>
#include <cstdlib>


using binary_patch::Cli;
using binary_patch::Main;



int main(int argc, char** argv) {
	auto const options = Cli::parse(argc, argv);

	Main::run(options);

	return EXIT_SUCCESS;
}
