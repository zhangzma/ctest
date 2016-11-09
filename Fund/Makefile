# 
CC = g++
OBJ = fund.o bid.o main.o
BIN=fund

all:$(BIN)

$(BIN):$(OBJ)
	$(CC) $(OBJ) -o $(BIN)

$(OBJ): %.o:%.cpp
	$(CC) -c $(CXX_FLAGS) $< -o $@

clean:
	rm -rf $(OBJ) $(BIN).exe



