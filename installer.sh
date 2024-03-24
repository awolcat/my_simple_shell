#!/usr/bin/bash

if [ -e my_simple_shell ]; then
	gcc -Wall -Werror -Wextra -std=gnu89 -pedantic -o hsh my_simple_shell/*.c
	rm my_simple_shell/*.c my_simple_shell/main.h
	mv my_simple_shell/hsh /opt/hsh
	ln -s /opt/hsh /usr/local/bin/hsh
	rm -f my_simple_shell/hsh
	rm hsh
	echo "Install Success!"	
else
	echo "Error :("
	echo "Ensure you cloned my_simple_shell and try again."
fi
