#! /bin/bash

echo "Какой файл?"
read ptf
nf=$(basename $ptf)
echo $nf
if [ -f "$nf" ]
then
echo "файл существует"
echo "Что меняем?"
read quar
echo "На что меняем?"
read subs
sed -i '' 's/'$quar'/'$subs'/g' $nf
echo "$ptf $( stat -f " - %z - %Sm" -t "%Y-%m-%d %H:%M" $nf) - $(shasum -a 256 $nf | awk '{print $1}') - sha256" >> files.log
else
echo "нет такого файла"
fi