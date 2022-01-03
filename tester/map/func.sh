#!/bin/bash

GRN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
ENDC="\033[0m"

CHECK_MARK="${GRN}\xE2\x9C\x94${ENDC}"
ERROR_MARK="${RED}\xE2\x9C\x96${ENDC}"

BIN=$(echo $1 | awk '{print substr ($0, 3, 5)}')

clang++ -fsanitize=address $1 -o $BIN
./$BIN
echo -ne "$1\r"
if (diff ft.txt std.txt > diff_log) then
	echo -e "$1 ${CHECK_MARK}"
else
	echo -e "$1 ${ERROR_MARK}"
	exit 1
fi
clang++ $1 -o $BIN

