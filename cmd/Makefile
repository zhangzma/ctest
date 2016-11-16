
CC=g++

target=nsp
obj=about.o arg_parse.o cmd.o main.o


all:$(target)
$(target):$(obj)
	$(CC) $(obj) -o $(target)

$(obj):%.o:%.cc
	$(CC) -c $< -o $@

clean:
	-rm *.o *.exe
