echo "Filename : $3"
echo "First $1 line"
head -$1 $3
echo "Last $2 lines"
tail -$2 $3
