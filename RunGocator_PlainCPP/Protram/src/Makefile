CC=gcc
OPT = -O0
DEPFLAGS=-MP -MD
WARNINGS=-Wall 
CFLAGS=$(WARNINGS) -g $(OPT) $(DEPFLAGS)

BINARY=startup
CODEDIRS=.
# INCDIRS=./include
LIBDIRS=../../lib/linux_x64d

INCDIRS=../../GoSdk/ ../../Platform/kApi/


CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
OBJECTS=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

.PHONY: all clean 
all: $(BINARY) 

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^ -L$(LIBDIRS) -lGoSdk -lkApi
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<  $(foreach D,$(INCDIRS),-I$(D))
	
clean:
	rm $(BINARY) *.o *.d
