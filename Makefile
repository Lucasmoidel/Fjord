all: build run
build:
	mkdir build
	cd build && cmake .. && make -j4 && cp ../example/keyMap.json .	
run:
	cd build && ./example
install: build
	sudo cp build libFjord.a /usr/local/lib
	sudo mkdir /usr/include/fjord
	sudo cp lib/fjordusr.h /usr/include/fjord/fjord.h
clean:
	rm -r build