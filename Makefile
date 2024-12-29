all: compile run
compile:
	-mkdir build
	cd build && cmake .. && make -j4 && cp ../example/keyMap.json .	
run:
	cd build && ./example
install: compile
	echo copy lib file
	sudo cp build/libFjord.a /usr/local/lib
	echo make dir
	-sudo rm /usr/include/fjord -r
	-sudo mkdir /usr/include/fjord
	-sudo mkdir /usr/include/fjord/dat
	-sudo mkdir /usr/include/fjord/node
	echo copy header
	sudo cp lib/*.h /usr/include/fjord/
	sudo cp lib/dat/*.h /usr/include/fjord/dat/
	sudo cp lib/node/*.h /usr/include/fjord/node/
clean:
	-rm -r build
	make