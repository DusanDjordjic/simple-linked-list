CC=clang
CFLAGS=-I.
SRC=main.c menu.c
OBJ=main.o menu.o
DEPS=linked_list.h menu.h
BIN=app

all: $(BIN)
	
$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

clean:
	rm -r *.o $(BIN)
