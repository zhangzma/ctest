
CC=g++
CXX_FLAGS=-Wall
OBJ=main.o ptl.o ptl_lidar.o

parse:$(OBJ)
	$(CC) -o parse $(OBJ)

$(OBJ):%.o:%.cc
	$(CC) -c $(CXX_FLAGS) $< -o $@

clean:
	-rm parse $(OBJ)


