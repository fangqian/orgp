CPP = g++

DODEBUG       = -g -ggdb
WARNING       = -Wall
OPTIMIZE      = -O0

LIB = -lncurses

CPP_FLAGS = $(WARNING) $(OPTIMIZE) $(LIB)

ORGP_SRC = orgp/main.cpp orgp/scan.cpp orgp/org.cpp

ORGP = $(ORGPSRC:.cpp=.o)


.PHONY: all

%.o : %.cpp
	$(CPP) -c $<

all: 
	mkdir -p bin
	$(CPP) -o bin/orgp $(CPP_FLAGS) $(ORGP_SRC)

install:
	install bin/orgp /usr/local/bin/

uninstall:
	rm /usr/local/bin/orgp

clean:
	rm -rf bin/orgp orgp/*.o
