# Wedit Makefile for project asc2bin
SRCDIR=c:\users\khjung\documents\lcc\asc2bin
CFLAGS=-I"c:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	asc2bin.obj

LIBS=
EXE=asc2bin.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\asc2bin.exe $(OBJS) $(LIBS)

# Build asc2bin.c
ASC2BIN_C=\

asc2bin.obj: $(ASC2BIN_C) $(SRCDIR)\asc2bin.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\asc2bin.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\asc2bin.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) asc2bin.exe
