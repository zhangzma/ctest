

CC=g++
obj=main.o tm.o

tm:$(obj)
	$(CC) -o tm $(obj)

$(obj):%.o:%.cc
	$(CC) -c $< -o $@

clean:
	-rm *.exe $(obj)

