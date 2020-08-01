# Expects to be executed insided isolated mini-cross development environment
#
# @see mc.yaml
.PHONY: all
all: clean native windows


.PHONY: clean
clean:
	@if [ -d 'build-native' ]; then		\
		rm -rf 'build-native';		\
	fi

	@if [ -d 'build-windows' ]; then	\
		rm -rf 'build-windows';		\
	fi

	@mkdir 'build-native'
	@mkdir 'build-windows'


.PHONY: native
native:
	cmake -B 'build-native' -S '.'
	make -C 'build-native'
	make -C 'build-native' test



.PHONY: windows
windows:
	cmake -B 'build-windows' -S '.' -DCMAKE_TOOLCHAIN_FILE='cmake/mingw-w64-x86_64.cmake'
	make -C 'build-windows'
	make -C 'build-windows' test

