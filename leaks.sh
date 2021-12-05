#! /bin/bash
make && leaks -atExit -- ./bin/ft_containers
