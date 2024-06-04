#! /bin/bash

echo "Какой файл?"
read ptf

if [ -f "$ptf" ]
then
echo "файл существует"
echo "Что меняем?"
read quar
echo "На что меняем?"
read subs
sed -i '' 's/'$quar'/'$subs'/g' $ptf
echo "$(stat -f "%R - %z - %Sm" -t "%Y-%m-%d %H:%M" $ptf) $(shasum -a 256 $ptf | awk '{print $1}') - sha256" >> files.log
else
echo "нет такого файла"
fi
