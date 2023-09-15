CC = gcc
LIBS = -ludev
CCFLAGS = -Werror -Wno-discarded-qualifiers -Wno-format-overflow

SRC := $(shell find ./../src/ -type f -name '*.c' ! -name 'main.c') 

all: test 

test:
	$(CC) $(CCFLAGS) -o $@ $(SRC) ./../../cst.c cst_example.c $(LIBS)
	./test

clean:
	rm test 

