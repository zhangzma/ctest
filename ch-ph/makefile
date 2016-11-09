
CC=g++
OBJ=main.o

.PHONY:all

all:test

test:$(OBJ)
	$(CC) -o test $(OBJ)

main.o:main.cc
	$(CC) -o main.o -c main.cc



.PHONY: clean
clean:
	-rm -rf *.exe $(OBJ)
