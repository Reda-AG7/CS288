#! /bin/bash

ownerId="$2"
function traverse(){
	if [ -f "$1" ];then
		myInfo=`ls -l "$1"`
		firstSub=`echo "$myInfo" | grep -o "^.\{10\}"`
		permissions="${firstSub:1}"
		remaining="${myInfo:11}"
		id=`echo "$remaining" | grep -o "^[0-9]\{1,\}"`
		length=${#id}
		remaining="${remaining:$length+1}"

		owner=`echo "$remaining" | grep -o "^[a-zA-Z0-9]\{1,\}"`

		length=${#owner}
		remaining="${remaining:$length+1}"

		group=`echo "$remaining" | grep -o "^[a-zA-Z0-9]\{1,\}"`

		length=${#group}
		remaining="${remaining:$length+1}"

		size=`echo "$remaining" | grep -o "^[0-9]\{1,\}"`

		length=${#size}
		remaining="${remaining:$length+1}"
		fileName=`echo "$remaining" | grep -o "[a-zA-Z0-9_/\.\-]\{1,\}$"`
		length=${#remaining}
		length2=${#fileName}
		lastMod="${remaining:0:$length-$length2}"
		filename=`echo "$fileName" | grep -o "[a-zA-Z0-9\.\-_]\{1,\}$"`

		if [ "$owner" = "$2" ];then
			if [ "${permissions:0:1}" = "r" -a "${permissions:3:1}" = "r" -a  "${permissions:6:1}" = "r" ];then
				echo "fileName : $filename"
				echo "permissions : $permissions"
				echo "last modification/date : $lastMod"
				echo
				echo
			fi		 

		fi
	fi
	if [ ! -d "$1" ];then
		return 
	else 
		if [ `ls "$1" | wc -l` -eq 0 ];then
			return
		else
			local array=("$1"/*)
			local it
			for it in "${array[@]}";do
				traverse "$it" "$ownerId"
			done
		fi
	fi
}


traverse "$1" "$2"
