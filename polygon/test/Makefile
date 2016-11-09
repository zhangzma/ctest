

cc=g++
cxxflag= -std=c++11
obj=main.o AC_Point.o AC_Polygon.o

test:$(obj)
	$(cc) $(cxxflag) -o test $(obj)

main.o : main.cpp
	$(cc) $(cxxflag) -c main.cpp
AC_Polygon.o : AC_Polygon.cpp
	$(cc) $(cxxflag) -c AC_Polygon.cpp
AC_Point.o : AC_Point.cpp
	$(cc) $(cxxflag) -c AC_Point.cpp

clean:
	rm test $(obj)
