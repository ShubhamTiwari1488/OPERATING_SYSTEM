#!/bin/bash
a=$1
b=$2
echo "FirstArgument=$a and LastArgument=$b"
rem=`expr $a % $b`
if [ $rem -eq 0 ]
then echo "Div=`expr $a / $b`"
elif [  $rem -ne 0  -a `expr $b % 5` -eq 0 ]
then echo "Mul=`expr $a \* $b`"
elif [ $a -gt $b ]
then echo "Diff=`expr $a \- $b`"
else echo "Sum=`expr $a \+ $b`"
fi
