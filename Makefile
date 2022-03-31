CC=gcc
CFLAGS=-c -Wall -Werror -g

unit_test01: unit_test01.o main_mem.o
	$(CC) -o unit_test01 unit_test01.o main_mem.o

unit_test01.o: unit_test01.c main_mem.h
	$(CC) $(CFLAGS) unit_test01.c

main_mem.o: main_mem.c main_mem.h
	$(CC) $(CFLAGS)  main_mem.c

clean:
	rm -f *.o 

