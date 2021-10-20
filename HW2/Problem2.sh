#! /bin/bash

function reverse(){
  array=$1
  size=${#array[@]}
  reversedArray=()
  for(( i=$(($size - 1 ));i>=0;i--)); do
    reversedArray[$(($size - 1 - $i))]=${array[$i]}
  done
}

if [ -d $1 ]; then
  ls $1 > store.txt
  input="./store.txt"
  array=()
  count=0
  while IFS= read -r line; do
    array+=("$line")
    count=$(($count + 1))
  done < "$input"
  reverse $array
  #echo "${reversedArray[@]}"
  #echo "nb of lines : " $count
  #echo "size of array : " ${#reversedArray[@]}
  for(( i=0;i<$size;i++)); do
    echo "${reversedArray[$i]}"
  done
else echo "$1 : is not a directory"
fi
