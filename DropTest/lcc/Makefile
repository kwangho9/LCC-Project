# Wedit Makefile for project DropTest
SRCDIR=c:\users\khjung\documents\lcc\droptest
CFLAGS=-I"c:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	resources.res \
	drop_test.obj \
	draganddrop.obj

LIBS=
EXE=droptest.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\droptest.exe $(OBJS) $(LIBS)

# Build resources.res
RESOURCES_RC=\

resources.res:	$(RESOURCES_RC) $(SRCDIR)\resources.rc
	$(LCCROOT)\bin\lrc.exe -I$(SRCDIR) -I"c:\lcc\include"  $(SRCDIR)\resources.rc

# Build drop_test.c
DROP_TEST_C=\
	$(SRCDIR)\resource.h\

drop_test.obj: $(DROP_TEST_C) $(SRCDIR)\drop_test.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\drop_test.c

# Build draganddrop.c
DRAGANDDROP_C=\
	$(SRCDIR)\DragAndDrop.h\
	$(SRCDIR)\resource.h\

draganddrop.obj: $(DRAGANDDROP_C) $(SRCDIR)\draganddrop.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\draganddrop.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\droptest.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) droptest.exe
