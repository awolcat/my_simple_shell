#!/usr/bin/bash

git clone https://github.com/awolcat/my_simple_shell

if [ -e my_simple_shell ]; then
	gcc -Wall -Werror -Wextra -std=gnu89 -pedantic -o hsh my_simple_shell/*.c
	rm my_simple_shell/*.c my_simple_shell/main.h
	mv my_simple_shell/hsh /opt/hsh
	ln -s /opt/hsh /usr/local/bin/hsh
	rm -f my_simple_shell/hsh
	rm hsh
	echo "Install Success!"	
else
	echo "Something went wrong"
	echo "Check that you are connected to the internet"
fi
