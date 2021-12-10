#!/bin/bash

clang++ test.cpp -o "test"
./test
diff ft.txt  std.txt


while ( diff ft.txt std.txt > diff_log && ((c<1000)) ) do
	./test
	(( c+=1 ))
	clear
	echo "$c / 1000"
done

# diff  --old-line-format='%L' --unchanged-line-format=  --new-line-format= <(sort A) <(sort B)

# rm ft.txt std.txt "test"