CC = clang
FLG = -std=c11 -Wall

DBGD = DEBUG/
SRCD = linked_list/
LIBSD = $(SRCD)libs/

DBG = $(wildcard $(DBGD)*.c)
DBGLB = $(DBG:.c=.h)
SRC = $(wildcard $(SRCD)*.c)
LIBS = $(wildcard $(LIBSD)*.h)

all: build

build: main.c $(DBG) $(DBGLB) $(SRC) $(LIBS)
	@echo "Compilando Executável..."
	@$(CC) $(FLG) main.c $(DBG) $(SRC) -o $@
	@echo "\tPronto"