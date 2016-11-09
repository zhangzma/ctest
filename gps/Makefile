# gps
CXX = g++
CXX_FLAGS = -Wall -g

TARGET = gps
OBJ = main.o point.o


.PHONY:clean all

all:$(TARGET)

$(TARGET):$(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o:%.cc
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	-rm -rf $(OBJ) *.exe

