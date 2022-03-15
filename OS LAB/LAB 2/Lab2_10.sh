
echo "Enter your choice: 
1-List Files 
2-Create Directory 
3-Change Directory 
4-Remove Directory 
5-Create File 
6-Copy File 
7-Remove File"

read choice 
if [ $choice -eq 1 ] 
then 
   ls 
   
elif [ $choice -eq 2 ] 

then 
  echo "Enter the folder name" 
  read folder 
  mkdir $folder 
  
elif [ $choice -eq 3 ] 
then 
  echo "Enter directory" 
  read dir 
  cd $dir
  present=$(pwd) 
  echo "The present directory is : $present" 
  
elif [ $choice -eq 4 ] 
then 
echo "Enter the directory to be removed"
read dir 
rm -d $dir 
elif [ $choice -eq 5 ] 
then 
  echo "Enter filename" 
  read filename 
  echo "Enter filetype" 
  read filetype 
  gedit $filename.$filetype 
  
elif [ $choice -eq 6 ] 
then 
  echo "Enter filename to copy" 
  read filename 
  echo "Enter destination" 
  read destination 
  cp $filename $destination
   
elif [ $choice -eq 7 ] 
then 
  echo "Enter filename to be removed" 
  read filename 
  rm $filename 
else 
  echo "Wrong Input" 
  
fi
