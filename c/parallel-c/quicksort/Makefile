CC 		= gcc
CFLAGS	= -g -Wall -O0
LIBS	= -lm -pthread
OBJS	= main.o quicksort.o
PROGRAM	= quicksort

.PHONY: all
all:		$(PROGRAM)

$(PROGRAM):     $(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $(PROGRAM)

.SUFFIXES: .c .o
.c.o:
		$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -f *.o *~ *.bak core gmon.out $(PROGRAM)

run:	$(PROGRAM)
		./$(PROGRAM)

