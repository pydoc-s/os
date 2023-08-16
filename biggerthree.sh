echo "Enter 3 no.s:"
read a b c
if [ $a -gt $b ] && [ $a -gt $c ]
then 
echo "$a  is big"
else if [ $b -gt $c ]
then
echo "$b is big"
else
echo "$c is big"
fi
fi