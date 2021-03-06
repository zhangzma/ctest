# template
CXX = g++
CXX_FLAGS = -Wall -g -DDEBUG

.PHONY:clean all

all:$(TARGET)

$(TARGET):$(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o:%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	-rm -rf $(OBJ) *.exe *.o
