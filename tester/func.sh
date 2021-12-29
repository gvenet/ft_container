#!/bin/bash

GRN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
ENDC="\033[0m"

CHECK_MARK="${GRN}\xE2\x9C\x94${ENDC}"
ERROR_MARK="${RED}\xE2\x9C\x96${ENDC}"

ID=$1

clang++ $1 -o 
./id
echo -ne "$id\r"
if (diff ft.txt std.txt > diff_log) then
	echo -e "$id ${CHECK_MARK}"
else
	echo -e "$id ${ERROR_MARK}"
	exit 1
fi
