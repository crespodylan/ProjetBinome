CC = gcc
CFLAGS = -W -Wall -g -I Headers
LDFLAGS = 
 
SRC = $(wildcard ./Code/*.c)
OBJS = $(SRC:.c=.o)
AOUT = Sudoku
 
all : $(AOUT) 
 
Sudoku : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean :
	@rm *.o
cleaner : clean
	@rm $(AOUT)
