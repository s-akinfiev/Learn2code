#! /bin/bash

ptf="$1"
#echo $ptf
nf=$(basename $ptf)

if [[ -f "$nf" && $nf =~ \.log$ ]]
	then
	
	#echo "Файл существует и похож на лог-файл"
	#Порядок, в котором выводим статистику: количество уникальных строк, кол-во уникальный файлов, количество изменений (уникальные хэши - 1)
	
	c_lines=$(wc -l $nf | awk '{print $1}')
	c_files=$(cat $nf | awk '{print $1}' | xargs basename | sort | uniq | wc -l | awk '{print $1}')
	c_chang=$(cat $nf | awk '{print $8}' | uniq | expr $(wc -l) - 1)
	
	echo "$c_lines $c_files $c_chang"

else
	echo "Нет такого файла или это не лог-файл"
fi