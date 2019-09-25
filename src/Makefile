IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=../obj
# LDIR =../lib

# LIBS

_DEPS = pilha.hpp catch.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

TIC_T_TOE_MAIN = velha.o main.o
OBJ1 = $(patsubst %,$(ODIR)/%,$(TIC_T_TOE_MAIN))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main_tic_t_toe: $(OBJ1) 
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 