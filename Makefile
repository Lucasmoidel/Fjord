all: build
build:
	gcc lib/*.cpp -o libFjod.so -c
	gcc libFjod.so example/*.cpp -o example/game.o -Wall

clean:
	rm libFjod.so example/game.o