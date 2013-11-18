LIB = lsleep

LUA = lua
LUAV = 5.2
SRC=./src
LOCAL=$(MEDIA_CIRCUS_PREFIX)
INCLUDE= $(LOCAL)/include

CC = gcc -c 
LN = gcc -O 
ARCHBITS64 = -m64
DEBUG = -g

INSTALL_TOP= $(MEDIA_CIRCUS_PREFIX)
INSTALL_BIN= $(INSTALL_TOP)/bin
INSTALL_INC= $(INSTALL_TOP)/include
INSTALL_LIB= $(INSTALL_TOP)/libraries
INSTALL_MAN= $(INSTALL_TOP)/docs/$(LUA)/man/man1
INSTALL_LMOD= $(INSTALL_TOP)/libraries/$(LUA)/$(LUAV)
INSTALL_CMOD= $(INSTALL_TOP)/libraries/$(LUA)/$(LUAV)

CFLAGS = -O2 -Wall $(ARCHBITS) -I$(INSTALL_INC) 

LFLAGS =  -fpic -L$(INSTALL_LIB) -I$(INSTALL_INC) -undefined dynamic_lookup

CORE_O = 
LIB_SRC = $(LIB).c
LIB_O  = $(LIB).o
LIB_T  = $(LIB).so
 

$(LIB): $(LIB_O)
	$(LN) $(LFLAGS) $(LIB_O) -o $(LIB_T)

$(LIB_O): $(LIB).c
	$(CC) $(CFLAGS) $(LIB_SRC)



