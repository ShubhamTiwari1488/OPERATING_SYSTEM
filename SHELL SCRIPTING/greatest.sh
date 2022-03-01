#!/bin/sh

echo -n "Enter two numbers "

read num1
read num2

if [ $num1 -eq  $num2 ]
then
	echo "Two numbers are equal"

elif [ $num1 -gt $num2 ]
then
	echo "$num1 is greater than $num2"

else
	echo "$num2 is greater than $num1"

fi
