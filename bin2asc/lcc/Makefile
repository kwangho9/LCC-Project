# Wedit Makefile for project bin2asc
SRCDIR=c:\users\khjung\documents\lcc\bin2asc
CFLAGS=-I"c:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	bin2asc.obj

LIBS=
EXE=bin2asc.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\bin2asc.exe $(OBJS) $(LIBS)

# Build bin2asc.c
BIN2ASC_C=\

bin2asc.obj: $(BIN2ASC_C) $(SRCDIR)\bin2asc.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\bin2asc.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\bin2asc.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) bin2asc.exe
