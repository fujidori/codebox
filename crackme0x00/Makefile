CC=gcc
CFLAGS=
LDFLAGS=
TARGET=crackme0x00

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)

# .SUFFIXES: .c .o
# .c.o:
# 	$(CC) $(CFLAGS) -c $< -o $@
