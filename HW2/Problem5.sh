#! /bin/bash


function dfs(){
  if [ -f "$1" ]; then
    size=`du -b "$1" | cut -f1`
    if [ $size -eq 0 ]; then
      rm $1
    fi
  fi
  if [ ! -d "$1" ]; then
    return
  else 
    if [ `ls "$1" | wc -l` -eq 0 ]; then
    return 
    else
      local i
      local array=("$1"/*)
      for i in "${array[@]}"; do
        dfs "$i"
      done
    fi
  fi
}

dfs $1