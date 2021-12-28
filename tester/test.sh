#!/bin/bash

clang++ test1_insert_rand_erase_rand.cpp -o "test1_insert_rand_erase_rand"
./test1_insert_rand_erase_rand 5
diff ft.txt  std.txt

d=40
((x+=5))
while ( ((x<=640)) ) do
((c*=0))
	while ( diff ft.txt std.txt > diff_log && ((c<$d)) ) do
		./test1_insert_rand_erase_rand $x
		(( c+=1 ))
		clear
		echo "TEST 1"
		echo "insert_rand_erase_rand.cpp"
		echo "test random insert/erase"
		echo "$c / $d > test $x"
	done
((x*=2))
done

echo "leaks 2000 : "
leaks -atExit -- ./test1_insert_rand_erase_rand 2000
