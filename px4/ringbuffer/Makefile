
CXX=g++
CXXFLAGS=
TARG=buffer
OBJ=main.o ringbuffer.o

all:$(OBJ)
	$(CXX) $(OBJ) -o $(TARG)

%.o:%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	-rm *.exe $(OBJ)


