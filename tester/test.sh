#!/bin/bash

clang++ test.cpp -o "test"
./test 5
diff ft.txt  std.txt

((x+=5))
while ( ((x<=640)) ) do
((c*=0))
	while ( diff ft.txt std.txt > diff_log && ((c<50)) ) do
		./test $x
		(( c+=1 ))
		clear
		echo "test random insert/erase"
		echo "$c / 50 > test $x"
	done
((x*=2))
done


# diff  --old-line-format='%L' --unchanged-line-format=  --new-line-format= <(sort A) <(sort B)

# rm ft.txt std.txt "test"