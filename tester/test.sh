#!/bin/bash

clang++ test.cpp -o "test"
./test
diff ft.txt  std.txt
# rm ft.txt std.txt "test"