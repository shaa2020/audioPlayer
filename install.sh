#!/bin/bash

user=$UID

if [[ $user -ne 0 ]]; then
	echo "You are not root priviledged please use 'sude su' and try again"
else
	echo "You have root access cool!"
	sudo apt-get install libopenal-dev -y
	sudo apt-get install libsdl-sound1.2-dev -y
	sudo apt-get install  libmyth-dev -y
	make install
fi