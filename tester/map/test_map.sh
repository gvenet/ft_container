#!/bin/bash

GRN="\033[1;32m"
RED="\033[1;31m"
BLUE="\033[1;34m"
ENDC="\033[0m"

CHECK_MARK="${GRN}\xE2\x9C\x94${ENDC}"
ERROR_MARK="${RED}\xE2\x9C\x96${ENDC}"

echo -e "${GRN}TEST_MAP_FUNCTIONS${ENDC}"

#=======================  MAP  =======================================
clang++ -fsanitize=address test1_insert_rand_erase_rand.cpp -o "test1"
./test1 5
diff ft.txt  std.txt

d=10
((x+=5))

echo "./test1_insert_rand_erase_rand.cpp"
while ( ((x<=640)) ) do
((c*=0))
	while ( diff ft.txt std.txt > diff_log && ((c<$d)) ) do
		./test1 $x
		(( c+=1 ))
		echo -ne "  $c / $d > $x\r" 
	done
	if (diff ft.txt std.txt > diff_log) then
		echo -e "    $x ${CHECK_MARK}                    "
	else
		echo -e "    $x ${ERROR_MARK}                    "
		exit 1
	fi
((x*=2))
done
clang++ test1_insert_rand_erase_rand.cpp -o "test1"

n=2
while ( ((n<10)) ) do 
	id=$(find . -name  "test${n}_*")
	./func.sh $id
	if [[ $? -ne 0 ]]; then
		echo "exit"
		exit 1
	fi
	((n+=1))
done


echo -e "${GRN}\nTEST_MAP_LEAKS${ENDC}"
n=1
while ( ((n<10)) ) do
	./leaks.sh "test$n"
	((n+=1))
done
rm test1 test2 test3 test4 test5 test6 test7 test8 test9 std.txt ft.txt diff_log



echo -e "${GRN}\nTEST_MAP_SPEED${ENDC}"
echo "./test0_map_speed_insert_access.cpp"
echo

clang++ test0_map_speed_insert_access.cpp -o map_speed

./map_speed 100000 0 0
./map_speed 100000 100000 0
./map_speed 100000 0 100000
./map_speed 100000 100000 100000
./map_speed 1000000 1000000 0

rm map_speed
