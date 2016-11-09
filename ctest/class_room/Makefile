

CC=gcc

cms: class_room.o main.o
	$(CC) class_room.o main.o -o cms

main.o: main.c
	$(CC) -c main.c

class_room.o: class_room.c
	$(CC) -c class_room.c

.PHONY:clean
	rm cms *.o
