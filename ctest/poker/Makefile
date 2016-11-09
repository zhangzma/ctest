#

CC=g++
CXXFLAGS=
OBJ=poker.o player.o deal_card.o


all: deal

deal:$(OBJ)
	$(CC) $(OBJ) -o deal

$(OBJ):%.o:%.cpp
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ) deal.exe
