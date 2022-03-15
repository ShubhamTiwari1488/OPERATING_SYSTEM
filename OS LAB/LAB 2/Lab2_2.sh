
# WRITE A SHELL PROGRAM THAT MULTIPLY TWO NUMBERS USING COMMAND LINE ARGUMENTS

#!/bin/sh

read num1
read num2

res=`expr $num1 \* $num2`

echo "Result is = $res"

