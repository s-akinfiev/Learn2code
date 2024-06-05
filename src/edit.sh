#! /bin/bash

#echo "Какой файл?"
#read ptf

ptf=$1
quar=$2
subs=$3

nf=$(basename $ptf)
echo $nf

if [ -f "$nf" ]

then
echo "файл существует"
#echo "Что меняем?"
#read quar
#echo "На что меняем?"
#read subs
sed -i '' 's/'$quar'/'$subs'/g' $nf
echo "$(realpath $nf) $( stat -f " - %z - %Sm" -t "%Y-%m-%d %H:%M" $nf) - $(shasum -a 256 $nf | awk '{print $1}') - sha256" >> files.log

else
echo "Нет такого файла"
fi