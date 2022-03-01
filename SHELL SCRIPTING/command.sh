#!/bin/sh

sum=`echo $1 + $2 | bc`

diff=`echo $1 - $2 | bc`

div=`echo $1 \/ $2 | bc`

mult=`echo $1 \* $2 | bc`

echo "Sum = $sum"
echo "Difference = $diff"
echo "Division = $div"
echo "Multiplication = $mult"
