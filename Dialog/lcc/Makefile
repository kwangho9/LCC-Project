# Wedit Makefile for project dialog
SRCDIR=c:\users\khjung\documents\lcc\dialog
CFLAGS=-I"C:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	dialog.res \
	dialog.obj

LIBS=
EXE=dialog.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem windows -o $(SRCDIR)\lcc\dialog.exe $(OBJS) $(LIBS)

# Build dialog.res
DIALOG_RC=\
	$(SRCDIR)\dialogres.h\

dialog.res:	$(DIALOG_RC) $(SRCDIR)\dialog.rc
	$(LCCROOT)\bin\lrc.exe -I$(SRCDIR) -I"C:\lcc\include"  $(SRCDIR)\dialog.rc

# Build dialog.c
DIALOG_C=\
	c:\lcc\include\_syslist.h\
	c:\lcc\include\safelib.h\
	c:\lcc\include\string.h\
	c:\lcc\include\safelib.h\
	c:\lcc\include\win.h\
	c:\lcc\include\limits.h\
	c:\lcc\include\stdarg.h\
	c:\lcc\include\ctype.h\
	c:\lcc\include\basetsd.h\
	$(SRCDIR)\dialogres.h\

dialog.obj: $(DIALOG_C) $(SRCDIR)\dialog.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\dialog.c

link:
	$(LINKER)  -subsystem windows -o $(SRCDIR)\lcc\dialog.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) dialog.exe
