#!/bin/bash

#do not modify the above line
#   *.cpp = compile all cpp files in the directory

g++ -c *.cpp
g++ gameoflife.o main.o -o GoL
./GoL

rm *.o

# clean
# rm *.o = remove all object files

# ignore the text below this line
#  LocalWords:  chmod MPs src scr javac classpath args gcc
