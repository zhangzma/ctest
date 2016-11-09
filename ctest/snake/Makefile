#

CC=g++
OBJ=main.o apple.o game_board.o point.o

snake: $(OBJ)
	$(CC) $(OBJ) -o snake

main.o: main.cpp
	$(CC) -c main.cpp -o main.o

apple.o: apple.cpp
	$(CC) -c apple.cpp -o apple.o

game_board.o: game_board.cpp
	$(CC) -c game_board.cpp -o game_board.o

point.o: point.cpp
	$(CC) -c point.cpp -o point.o

clean:
	rm -rf *.o *.exe

