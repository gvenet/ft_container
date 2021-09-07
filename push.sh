#! /bin/bash
cd tester
make fclean
cd ..
make fclean
git add .
git commit -m "1"
git push