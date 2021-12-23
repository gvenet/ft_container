#!/bin/bash

clang++ test.cpp -o "test"
./test
diff ft.txt  std.txt


while ( diff ft.txt std.txt > diff_log && ((c<50)) ) do
	./test
	(( c+=1 ))
	clear
	echo "$c / 50"
done

# diff  --old-line-format='%L' --unchanged-line-format=  --new-line-format= <(sort A) <(sort B)

# rm ft.txt std.txt "test"