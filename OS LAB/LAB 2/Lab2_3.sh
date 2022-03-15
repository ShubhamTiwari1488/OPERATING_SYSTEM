
# WRITE A SHELL PROGRAM TO CHECK WHETHER A GIVEN NUMBER IS EVEN OR ODD

#!/bin/sh

read num1

if [ `expr $num1 % 2` == 0 ]
then 
	echo "It is even"

else 
  echo "It is odd"

fi
