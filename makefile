CC = gcc
FLG = -std=c11 -Wall

SRCD = linked_list/
LIBSD = $(SRCD)libs/

SRC = $(wildcard $(SRCD)*.c)
LIBS = $(wildcard $(LIBSD)*.h)

all: build

build: main.c $(SRC) $(LIBS)
	@echo "Compilando Executável..."
	@$(CC) $(FLG) main.c $(SRC) -o $@
	@echo "\tPronto"