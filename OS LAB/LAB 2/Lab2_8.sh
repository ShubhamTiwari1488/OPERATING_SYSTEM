echo "Enter the row number: "
read row_number
row_number+="p"
sed -n $row_number $1 | cut -d " " -f 3- > temp.txt
total_marks=$(sed 's/ /+/g' temp.txt | bc)
aggregate_percentage=`expr $total_marks \* 100 `
aggregate_percentage=`expr $aggregate_percentage / 500`
echo "Total marks: " $total_marks
echo "Aggregate percentage: " $aggregate_percentage
rm temp.txt

