#! /bin/bash
# clear
make && leaks -atExit -- ./bin/ft_containers
