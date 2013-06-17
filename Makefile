CC           = gcc
FLAGS        = # -std=gnu99 -Iinclude
CFLAGS       = -fPIC -g #-pedantic -Wall -Wextra -ggdb3
LDFLAGS      = -shared
DEBUGFLAGS   = -O0 -D _DEBUG
RELEASEFLAGS = -O2 -D NDEBUG -combine -fwhole-program

HASH         = hash
STATIC_LIB   = ../C_linked_list/linked_list.a
STATIC_LIB_2 = ../C_binary_tree/binary_tree.a
SOURCES      = hash.c hash_test.c
HEADERS      = hash.h
OBJECTS      = $(SOURCES:.c=.o)

all: $(HASH)

$(HASH):  $(OBJECTS) $(STATIC_LIB) $(STATIC_LIB_2)
	$(CC) -o $(HASH) $(OBJECTS) $(STATIC_LIB) $(STATIC_LIB_2)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(HASH)
