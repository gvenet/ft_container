#!/bin/bash

GRN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
ENDC="\033[0m"

CHECK_MARK="${GRN}\xE2\x9C\x94${ENDC}"
ERROR_MARK="${RED}\xE2\x9C\x96${ENDC}"
LEAKS="leaks_test"

echo -n "$1_test_leaks ";
leaks -atExit -- ./$1 >$LEAKS
if [[ $? -ne 0 ]]; then
	echo -e "${ERROR_MARK}"
else
  echo -e "${CHECK_MARK}"
fi
rm leaks_test
