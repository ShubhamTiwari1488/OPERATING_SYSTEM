#!/bin/sh

num1=20.3
num2=10

res=`echo $num1 + $num2 | bc`

echo "Sum of $num1 and $num2 is = $res"
