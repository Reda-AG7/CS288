#! /bin/bash

if [ -d $1 ]; then
	echo '"directory"'
else 
	size=`du -b $1 | cut -f1`
	if [ $size -gt 1048576 ]; then
    echo '"large file"'
  elif [ $size -le 1048576 -a $size -gt 102400 ]; then
    echo '"medium file"'
  else echo '"small file"'
  fi
fi
