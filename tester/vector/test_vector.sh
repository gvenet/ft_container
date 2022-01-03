#!/bin/bash
GRN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
ENDC="\033[0m"

CHECK_MARK="${GRN}\xE2\x9C\x94${ENDC}"
ERROR_MARK="${RED}\xE2\x9C\x96${ENDC}"

echo -e "${GRN}TEST_VECTOR_FUNCTIONS${ENDC}"

n=1
while ( ((n<10)) ) do 
	id=$(find . -name  "test${n}_*")
	./func.sh $id
	if [[ $? -ne 0 ]]; then
		echo "exit"
		exit 1
	fi
	((n+=1))
done
