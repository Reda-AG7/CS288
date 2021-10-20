#! /bin/bash

array=($@)
size=${#array[@]}


for(( i=1;i<$size;i++ )); do
  j=$(( $i - 1 ));
  temp=${array[$i]}
  while [ $j -ge 0 -a ${array[$j]} -gt $temp ]; do
    array[$(( $j + 1 ))]=${array[$j]}
    j=$(( $j - 1 ))
  done
  j=$(( $j + 1 ))
  array[$j]=$temp
done
# Display
for i in "${array[*]}"; do
  echo $i
done
