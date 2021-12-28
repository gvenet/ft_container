#!/bin/bash

GRN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
ENDC="\033[0m"

CHECK_MARK="${GRN}\xE2\x9C\x94${ENDC}"
ERROR_MARK="${RED}\xE2\x9C\x96${ENDC}"

#TEST1 ==============================================================
clang++ test1_insert_rand_erase_rand.cpp -o "test1"
./test1 5
diff ft.txt  std.txt

d=5
((x+=5))

echo -e "${BLUE}MAP_TEST_1${ENDC}"
echo "test1_insert_rand_erase_rand.cpp"
while ( ((x<=640)) ) do
((c*=0))
	while ( diff ft.txt std.txt > diff_log && ((c<$d)) ) do
		./test1 $x
		(( c+=1 ))
		echo -ne "$c / $d > test $x\r" 
	done
	if (diff ft.txt std.txt > diff_log) then
		echo -e "test $x ${CHECK_MARK}                    "
	else
		echo -e "test $x ${ERROR_MARK}                    "
		exit 1
	fi
((x*=2))
done

echo -ne "leaks 2000 \r"
leaks -atExit -- ./test1 2000
echo -e "leaks 2000 ${CHECK_MARK}"

#TEST2 ======================================================================
echo -e "${BLUE}MAP_TEST_2${ENDC}"
clang++ test2_map_modifier.cpp -o "test2"
./test2
echo -ne "test2_map_modifier\r"
if (diff ft.txt std.txt > diff_log) then
	echo -e "test2_map_modifier ${CHECK_MARK}"
else
	echo -e "test2_map_modifier ${ERROR_MARK}"
	exit 1
fi

#TEST3 ======================================================================
echo -e "${BLUE}MAP_TEST_3${ENDC}"
clang++ test3_map_correction.cpp -o "test3"
./test3
echo -ne "test3_map_correction\r"
if (diff ft.txt std.txt > diff_log) then
	echo -e "test3_map_correction ${CHECK_MARK}"
else
	echo -e "test3_map_correction ${ERROR_MARK}"
	exit 1
fi

#TEST3 ======================================================================
echo -e "${BLUE}MAP_TEST_4${ENDC}"
clang++ test3_map_correction.cpp -o "test4"
./test4
echo -ne "test4_map_correction\r"
if (diff ft.txt std.txt > diff_log) then
	echo -e "test4_map_correction ${CHECK_MARK}"
else
	echo -e "test4_map_correction ${ERROR_MARK}"
	exit 1
fi
