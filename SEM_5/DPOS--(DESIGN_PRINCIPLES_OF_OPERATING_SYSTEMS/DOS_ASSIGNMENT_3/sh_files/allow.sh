echo "Enter the internal marks : "
read mark
echo "Enter the attendance percentage : "
read attendance
if [ $mark -ge 20 ] && [ $attendance -ge 75 ]; then
	echo "Allowed for semester"
else
	echo "Not allowed"
fi