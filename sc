#!/bin/bash
x=0
m=9
last=3
key=module_
while [ $x -lt $last ]
do
	echo $x greets
	mkdir $key$m/ex0$x
	touch $key$m/ex0$x/main.cpp
	touch $key$m/ex0$x/Makefile
	x=$(($x+1))
done