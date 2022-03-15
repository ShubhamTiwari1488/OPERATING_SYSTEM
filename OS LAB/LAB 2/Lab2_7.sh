echo "Enter the marks"
read num1

if [ $num1 -gt 89 ]
then 
  echo "Grade is O "
  
elif [ $num1 -gt 79 ]
then 
  echo "Grade is E "
  
elif [ $num1 -gt 69 ]
then 
  echo "Grade is A "
  
elif [ $num1 -gt 59 ]
then 
  echo "Grade is B "
  
else 
   echo "Grade is F "
   
fi 
