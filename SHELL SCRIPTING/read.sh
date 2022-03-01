#!/bin/sh

echo -n "Enter a value "

read num1

echo -n "\nEnter another value "

read num2

sum=`echo $num1 + $num2 | bc`

diff=`echo $num1 - $num2 | bc`

div=`echo $num1 \/ $num2 | bc`

mult=`echo $num1 \* $num2 | bc`

echo "Sum = $sum"
echo "Difference = $diff"
echo "Division = $div"
echo "Multiplication = $mult"
