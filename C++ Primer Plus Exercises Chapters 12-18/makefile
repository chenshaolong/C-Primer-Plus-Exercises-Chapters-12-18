# all:
#	g++ main.cpp method.cpp -o a.out


CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp method.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=a.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

