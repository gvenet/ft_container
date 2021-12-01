#!/bin/bash

clang++ main.cpp -o main
leaks -atExit -- ./main
