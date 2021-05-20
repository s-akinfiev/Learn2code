#!/bin/bash

count=0

echo 'Здравствуйте! Вы запустили модуль ИИ, контролирующий все двери комплекса.'
echo 'Загрузка необходимых файлов с данными...'
cd door_managment_files
echo
echo
echo '-------------------------------------' 
echo 'Загрузка файлов конфигурации дверей...'
echo
cd door_configuration
for file in `find . -maxdepth 1 -type f -name "*.conf"`
do
   wc -l $file;
   stat -c %s $file;
   cat $file;
   count=$[ $count + 1 ]
done
cd ..
echo
echo
echo '-------------------------------------' 
echo 'Загрузка карты дверей...'
echo
cd door_map
cat door_map_1.1
if [ $? -eq 0 ]; then
  count=$[ $count + 1 ]
fi
cd ..
echo
echo  
echo '-------------------------------------' 
echo 'Чтение логов дверей...'
echo
cd door_logs
for file in `find . -maxdepth 1 -type f -name "*.log"`
do
   wc -l $file;
   stat -c %s $file;
   cat $file;
   count=$[ $count + 1 ]
done

echo
echo 'Предупреждение: если в процессе загрузки были обнаружены ошибки, модуль не сможет работать правильно.'

echo $count
cd ..
if [ $count -eq 34 ]; then
  ./ai_door_control.sh &
fi