

CC=g++
obj=main.o

tm:$(obj)
	$(CC) -o tm $(obj)

$(obj):%.o:%.cc
	$(CC) -c $< -o $@

clean:
	-rm *.exe $(obj)

