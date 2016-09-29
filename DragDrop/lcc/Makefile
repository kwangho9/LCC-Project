# Wedit Makefile for project dragdrop
SRCDIR=c:\users\khjung\documents\lcc\dragdrop
CFLAGS=-I"C:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	dragdrop.res \
	dragdrop.obj

LIBS=
EXE=dragdrop.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem windows -o $(SRCDIR)\lcc\dragdrop.exe $(OBJS) $(LIBS)

# Build dragdrop.res
DRAGDROP_RC=\
	$(SRCDIR)\dragdropres.h\

dragdrop.res:	$(DRAGDROP_RC) $(SRCDIR)\dragdrop.rc
	$(LCCROOT)\bin\lrc.exe -I$(SRCDIR) -I"C:\lcc\include"  $(SRCDIR)\dragdrop.rc

# Build dragdrop.c
DRAGDROP_C=\
	c:\lcc\include\_syslist.h\
	c:\lcc\include\safelib.h\
	c:\lcc\include\string.h\
	c:\lcc\include\safelib.h\
	c:\lcc\include\win.h\
	c:\lcc\include\limits.h\
	c:\lcc\include\stdarg.h\
	c:\lcc\include\ctype.h\
	c:\lcc\include\basetsd.h\
	$(SRCDIR)\dragdropres.h\

dragdrop.obj: $(DRAGDROP_C) $(SRCDIR)\dragdrop.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\dragdrop.c

link:
	$(LINKER)  -subsystem windows -o $(SRCDIR)\lcc\dragdrop.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) dragdrop.exe
