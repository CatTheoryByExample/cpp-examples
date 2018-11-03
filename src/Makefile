CC=gcc
CPPFLAGS=-g -O0 -std=c++17 -I/opt/local/include
LDFLAGS=-lstdc++ -lm -lpthread
CPPSOURCES=$(wildcard ./*.cpp)

CPPEXECUTABLES=$(CPPSOURCES:.cpp=)
EXECUTABLES=$(CPPEXECUTABLES)

all: $(EXECUTABLES)

.cpp:
	$(CC) $(CPPFLAGS) $< -o $@ $(LDFLAGS)

clean:
	for exe in $(EXECUTABLES) ; do \
		rm -rf $$exe ; \
	done
	rm -rf *~ *.dSYM
