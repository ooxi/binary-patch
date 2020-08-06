SET DIRECTORY=%~dp0
SET BINARY_PATCH=%directory:~0,-1%/../build-windows/binary-patch/binary-patch/executable/binary-patch-binary-patch-executable.exe

%BINARY_PATCH%								^
	--key-hex		4b4559214b4559214b4559214b455921	^
	--mac-hex		4d41434d4143				^
	--input-file		%DIRECTORY%/input-file.txt		^
	--replacement-file	%DIRECTORY%/replacement-file.csv	^
	--output-directory	%DIRECTORY%/actual-output-directory
