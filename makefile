CPPC=g++
INCLUDES=-I src/headers
OBJECTS=*.o
CPP=src/cpp/*.cpp
BINARY = Snake.exe

all: $(BINARY) clean

$(BINARY): $(OBJECTS)
	$(CPPC) -o $@ $^

$(OBJECTS): $(CPP)
	$(CPPC) -c $(INCLUDES) $^
clean:
	del $(OBJECTS)