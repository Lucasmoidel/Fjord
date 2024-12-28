all: build run
build:
	mkdir build
	cd build && cmake .. && make -j4 && cp ../example/keyMap.json .	
run:
	cd build && ./example
install: build
	echo instyle------------------------------------------------------------------------------------------------
clean:
	rm -r build