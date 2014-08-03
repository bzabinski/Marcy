CC = gcc

SOURCEDIR = src
OBJDIR = obj
BINDIR = bin
INCLUDEDIR = $(SOURCEDIR)/include

CFLAGS = -std=c11 -g -Wall -I$(INCLUDEDIR)

LIBS = -lm -lcurl -ljansson

TARGET = Marcy

_SRC = Marcy.c Torus.c Interface.c  REST.c JSON.c
SRC = $(patsubst %,$(SOURCEDIR)/%,$(_SRC))

_DEPS = Cells.h  Config.h  Interface.h   MyMath.h  Neighborhoods.h  REST.h  Torus.h JSON.h
DEPS = $(patsubst %,$(INCLUDEDIR)/%,$(_DEPS))

_OBJ =  Marcy.o Torus.o Interface.o  REST.o JSON.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

default: $(BINDIR)/$(TARGET)

$(OBJDIR)/%.o: $(SOURCEDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BINDIR)/$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o *~ core $(INCLUDEDIR)/*~ $(BINDIR)/$(TARGET) 
