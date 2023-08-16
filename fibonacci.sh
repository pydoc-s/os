echo "Enter limit"
read limit
n1=0
n2=1
var=0
echo "Series:"
echo $n1
echo $n2
while [ $var -lt `expr $limit - 2` ]
do 
n3=`expr $n1 + $n2`
n1=$n2
n2=$n3
var=`expr $var + 1`
echo $n2
done