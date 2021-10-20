#! /bin/bash

array=($(ls /bin | tr '[:upper:]' '[:lower:]' | cut -c1))
size=${#array[@]}
alphabets=()
frequency=()
for letter in {a..z};
do
	count=0
	for(( i=0; i < ${#array[@]} ; i++ ))
	do
		if [ ${array[$i]} = $letter ]; then
			count=$(($count + 1))			
		fi
	done
	alphabets[$index]=$letter
	frequency[$index]=$count
	index=$(( $index + 1 ))
done

for(( j=0;j<26;j++ ))
do
	echo "${alphabets[$j]}  ${frequency[$j]}"
done

