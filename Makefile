CC=clang
CFLAGS=-I.
SRC=main.c menu.c linked_list.c utils.c item.c
OBJ=main.o menu.o linked_list.o utils.o item.o
DEPS=linked_list.h menu.h utils.h defs.h item.h
BIN=app

all: $(BIN)
	
$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

clean:
	rm -r *.o $(BIN)
