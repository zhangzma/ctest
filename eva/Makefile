
CC=g++
obj=lib_test.o eva_random.o

lib_test:$(obj)
	$(CC) -o lib_test $(obj)

lib_test.o:lib_test.c
	$(CC) -o lib_test.o -c lib_test.c

eva_random.o:eva_random.cpp
	$(CC) -o eva_random.o -c eva_random.cpp


.PHONY:clean

clean:
	rm -rf *.o *.exe

