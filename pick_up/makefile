

cc=g++
cxxflag= -std=c++11
obj=main.o UserInfo.o

test:$(obj)
	$(cc) $(cxxflag) -o test $(obj)


main.o:UserInfo.h	
UserInfo.o:UserInfo.h

clean:
	rm test $(obj)
