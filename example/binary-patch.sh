#!/bin/bash

DIRECTORY=`dirname "$(readlink -f "$0")"`
BINARY_PATCH="${DIRECTORY}/../build-native/binary-patch/binary-patch/executable/binary-patch-binary-patch-executable"

if [ ! -f "${BINARY_PATCH}" ]; then
	(>&2 echo "Missing binary-patch executable \`${BINARY_PATCH}', maybe compilation did not run?")
	exit 1
fi

if [ -d "${DIRECTORY}/actual-output-directory" ]; then
	rm -rf "${DIRECTORY}/actual-output-directory"
fi

"${BINARY_PATCH}"							\
	--key-hex		'4b4559214b4559214b4559214b455921'	\
	--mac-hex		'4d41434d4143'				\
	--input-file		"${DIRECTORY}/input-file.txt"		\
	--replacement-file	"${DIRECTORY}/replacement-file.csv"	\
	--output-directory	"${DIRECTORY}/actual-output-directory"

ACTUAL_CHECKSUM=`cd "${DIRECTORY}/actual-output-directory" && sha512sum * | sort`
EXPECTED_CHECKSUM=`cd "${DIRECTORY}/expected-output-directory" && sha512sum * | sort`

if [ "${EXPECTED_CHECKSUM}" != "${ACTUAL_CHECKSUM}" ]; then
	(>&2 echo -e "Expected\n\n${EXPECTED_CHECKSUM}\n\nbut received\n\n${ACTUAL_CHECKSUM}")
	exit 1
fi

