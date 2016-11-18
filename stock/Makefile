# 
CC=g++
obj=main.o date.o daily_record.o fund.o gardener.o
target=stock

$(target):$(obj)
	$(CC) $(CXX_FLAGS) $(obj) -o $(target)

$(obj):%.o:%.cc
	$(CC) $(CXX_FLAGS) -c $< -o $@

clean:
	-rm *.exe
	-rm $(obj)
