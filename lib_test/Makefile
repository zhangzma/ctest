C=gcc
CFLAG=
OBJ=guess_test.o guess_base.o



.PHONY: clean test all
all: test

test:$(OBJ)
	$(C) $(CFLAG) $(OBJ) -o test

guess_base.o:guess_base.c my_math.h
	$(C) $(CFLAG) -c guess_base.c -o guess_base.o

guess_test.o:guess_test.c my_math.h
	$(C) $(CFLAG) -c guess_test.c -o guess_test.o


clean:
	$(RM) -rf *.o *.exe


