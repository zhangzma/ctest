
CXX=g++
OBJ=main.o eva_file.o eva_log.o eva_string.o eva_mutex.o
c
.PHONY: test

test:$(OBJ)
	$(CXX) -o test $(OBJ)

main.o eva_file.o eva_log.o eva_string.o eva_mutex.o : eva_std.hpp


.PHONY: clean
clean:
	rm test $(OBJ)

