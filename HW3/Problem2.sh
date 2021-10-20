#! /bin/bash

origin="https://en.wikipedia.org/wiki/"
myData=("the" "of" "in" "and" "a")
frequency=()
declare -A  arr
for first in {A..Z};do
	for second in {A..Z};do
		temp="$origin$first$second"
		html_fileName="$first$second.html"
		wget $temp -O $html_fileName
		html2text $html_fileName >> total.txt
		rm $html_fileName 
	done
done

grep -o "[a-zA-Z]\+" total.txt | tr '[:upper:]' '[:lower:]' | sort | uniq -c | sort -rn | head -n 5
rm total.txt
