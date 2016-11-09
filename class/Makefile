
CC  = gcc
OBJ = main.o student.o class_room.o

cms: $(OBJ)
	$(CC) $(OBJ) -o cms

main.o:main.c
	$(CC) -c main.c -o main.o

student.o:student.c
	$(CC) -c student.c -o student.o

class_room.o:class_room.c
	$(CC) -c class_room.c -o class_room.o

clean:
	rm *.o cms.exe

