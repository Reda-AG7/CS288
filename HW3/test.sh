#! /bin/bash


myInfo=`ls -l "$1"`
#echo "$myInfo"
echo "owner argument : $2"
firstSub=`echo "$myInfo" | grep -o "^.\{10\}"`
permissions="${firstSub:1}"
remaining="${myInfo:11}"
#echo "permissions : $permissions"
#echo "permission : $remaining"
id=`echo "$remaining" | grep -o "^[0-9]\{1,\}"`
#echo "id : $id"
#echo ${#id}
length=${#id}
remaining="${remaining:$length+1}"
#echo "$remaining"
owner=`echo "$remaining" | grep -o "^[a-zA-Z0-9]\{1,\}"`
#echo "owner : $owner"
length=${#owner}
remaining="${remaining:$length+1}"
#echo "remaining : $remaining"
group=`echo "$remaining" | grep -o "^[a-zA-Z0-9]\{1,\}"`
#echo "group : $owner"
length=${#group}
remaining="${remaining:$length+1}"
#echo "remaining : $remaining"
size=`echo "$remaining" | grep -o "^[0-9]\{1,\}"`
#echo "size : $size"
length=${#size}
remaining="${remaining:$length+1}"
#echo "remaining : $remaining"
fileName=`echo "$remaining" | grep -o "[a-zA-Z0-9\.]\{1,\}$"`
#echo $fileName
length=${#remaining}
length2=${#fileName}
lastMod="${remaining:0:$length-$length2}"
#echo "$lastMod"
echo "owner found : $owner"
if [ "$owner" = "$2" ];then
	echo "${permissions:0:1} ${permissions:3:1} ${permissions:6:1}"
	if [ "${permissions:0:1}" = "r" -a "${permissions:3:1}" = "r" -a  "${permissions:6:1}" = "r" ];then
		echo "fileName : $fileName"
		echo "permissions : $permissions"
		echo "last modification/date : $lastMod"
	fi 

fi
