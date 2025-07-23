#!/bin/bash
x=0
m=4
mlast=10
last=3
key=module_
src="$key"4/ex00/Makefile
while [ $m -lt $mlast ]
do
	x=0
	if [ $x -eq 0 ] && [ $m -eq 0 ]
	then
		x=1
	fi
	while [ $x -lt $last ]
	do
		echo mod $m ex $x src: $src
		cp $src $key$m/ex0$x/Makefile
		x=$(($x+1))
	done
	if [ $m -eq 1 ]
	then
		while [ $x -lt 7 ]
		do
			echo mod $m ex $x src: $src
			cp $src $key$m/ex0$x/Makefile
			x=$(($x+1))
		done
	fi
	m=$(($m+1))
done