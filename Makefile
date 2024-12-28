all: build run
build:
	mkdir build
	cd build && cmake .. && make -j4 && cp ../example/keyMap.json .	
run:
	cd build && ./example
install: build
	echo copy lib file
	sudo cp build/libFjord.a /usr/local/lib
	echo make dir
	sudo rm /usr/include/fjord -r
	sudo mkdir /usr/include/fjord
	echo copy header
	sudo cp lib/Fjord.h /usr/include/fjord/
clean:
	rm -r build