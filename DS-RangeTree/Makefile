CC = g++
LINKER = g++
CFLAGS = -Wall -I /usr/include/c++/4.2.1
LDFLAGS = -I /usr/include/c++/4.2.1 -v
MAIN = main.cpp
EXE = a.out

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
DEPFILES = $(SOURCES:.cpp=.d)

all:$(EXE)

$(EXE):$(OBJECTS)
	$(LINKER) $(LDFLAGS) $(OBJECTS) -o $@

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

%.d: %.cpp
	$(CC) $(CFALGS) -MM $< | sed 's/^/$@ /' > $@

-include $(DEPFILES)

clean:
	rm $(EXE) $(OBJECTS)
