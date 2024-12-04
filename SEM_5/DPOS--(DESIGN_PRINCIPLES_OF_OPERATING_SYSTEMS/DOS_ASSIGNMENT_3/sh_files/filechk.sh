if [ $# -ne 2 ]; then
	echo "Please provide 2 files"
	exit 1
fi
f1=$1
f2=$2
if cmp -s "$f1" "$f2"; then
	echo "Files $f1 and $f2 have same content"
	rm "$f2"
	echo "$f2 is deleted"
else 
	echo "Files $f1 and $f2 have different content"
fi
