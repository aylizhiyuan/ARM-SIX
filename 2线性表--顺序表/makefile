src = $(wildcard *.c)
obj = $(patsubst %.c,%.o,$(src))
target = main
all:$(obj)
	gcc $(obj) -o $(target) -Wall
%.o:%.c
	gcc -c $< -Wall 
.PHONY:clean all
clean:
	-rm -rf $(target) $(obj)
