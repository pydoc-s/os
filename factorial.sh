echo "Enter the number"
read n
fact=1
i=1
while [ $i -le $n ]
do
fact=`expr $i "*" $fact`
i=`expr $i + 1`
done
echo $fact