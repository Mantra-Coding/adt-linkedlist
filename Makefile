default: install clean

install: item.o list.o
	echo "Build finished"

item.o: item.h item.c
	gcc -c -Wall item.c

list.o: list.h list.c item.h
	gcc -c -Wall list.c

clean:
	rm -rf list.o item.o
