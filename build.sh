#!/bin/bash
echo $(pwd)

which clang > /dev/null
if [ $? -eq 0 ]; then
	echo "using clang"
	clang++ ./src/*.cpp -o DiceRoller
else
	which gcc > /dev/null
	if [ $? -eq 0 ]; then
		echo "using GCC"
		g++ ./src/*.cpp -o DiceRoller
	fi
fi
