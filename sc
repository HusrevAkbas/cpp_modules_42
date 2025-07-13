#!/bin/bash
x=0
m=0
mlast=10
last=3
key=module_
src="$key"0/ex00/Makefile
while [ $m -lt $mlast ]
do
	x=0
	if [ $x -eq 0 ] && [ $m -eq 0 ]
	then
		x=1
	fi
	while [ $x -lt $last ]
	do
		echo mod $m ex $x greets $src
		diff $src $key$m/ex0$x/Makefile
		x=$(($x+1))
	done
	if [ $m -eq 1 ]
	then
		while [ $x -lt 7 ]
		do
			echo mod $m ex $x greets
			diff $src $key$m/ex0$x/Makefile
			x=$(($x+1))
		done
	fi
	m=$(($m+1))
done