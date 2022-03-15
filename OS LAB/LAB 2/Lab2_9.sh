
#!/bin/bash 
echo "Enter file name"
read file
if [ -f "$file" ] 
then 
  echo "$file found." 

awk 'NF>0{print $NF}' $file 

elif [ -f "$file.txt" ] 
then 
  echo "$file found." 

awk 'NF>0{print $NF}' $file.txt 

else 

echo "$file not found." 

fi
