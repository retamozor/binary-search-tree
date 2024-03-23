CC = g++

CFLAGS = -Wall -g

TARGET = main

all: build run

build: clean
	$(CC) $(CFLAGS) ./src/$(TARGET).cpp -o ./build/$(TARGET)

run:
	./build/$(TARGET)

clean:
	test -f ./build/main && rm ./build/main || echo "Already cleanned"

$(V).SILENT: 
