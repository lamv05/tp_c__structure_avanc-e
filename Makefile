all:exe

exe : main.c
	gcc main.c -o exe

clear: 
	rm -f exe
