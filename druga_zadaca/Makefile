SRC=$(wildcard src/*c)
OBJ=$(patsubst %c, %o, $(SRC))
INC=inc/

CFLAGS=-I $(INC)
EXE=exesrc/app.elf

.SECONDARY:

all: $(EXE)

%.elf: $(OBJ)
	gcc $(OBJ) -o $@

%.o: %.c
	gcc -c $< -I -lm inc/ -o $@

clean:
	rm -f $(OBJ) $(EXE)
