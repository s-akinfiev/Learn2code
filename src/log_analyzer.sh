#! /bin/bash

ptf="$1"
echo $ptf
nf=$(basename $ptf)

if [[ -f "$nf" && $nf =~ \.log$ ]]
then
echo "файл существует"
echo "$(wc -l $nf | awk '{print $1}') $(cat $nf | awk '{print $1}' | uniq | wc -l | awk '{print $1}') $(cat $nf | awk '{print $8}' | uniq | expr $(wc -l) - 1)"
else
echo "нет такого файла или это не лог-файл"
fi