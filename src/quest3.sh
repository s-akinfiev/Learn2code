#! /bin/bash
cd ~/sc21/T01D01-1/src
mkdir door_management_files/door_configuration door_management_files/door_map door_management_files/door_logs
mv *.conf door_management_files/door_configuration/
mv *.log door_management_files/door_logs/
mv door_map_1.1 door_management_files/door_map/
chmod 777 ai_door_control.sh