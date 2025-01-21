all: compile run
compile:
	-mkdir build
	cd build && cmake .. && make -j4 && cp ../example/keyMap.json .	
run:
	cd build && ./example
install: compile
	echo copy lib file
	sudo cp build/libFjord.a /usr/lib
	echo make dir
	-sudo rm /usr/include/fjord -r
	-sudo mkdir /usr/include/fjord
	-sudo mkdir /usr/include/fjord/dat
	-sudo mkdir /usr/include/fjord/node
	-sudo mkdr /usr/include/fjord/node/physics
	echo copy header
	sudo cp lib/*.h /usr/include/fjord/
	sudo cp lib/dat/*.h /usr/include/fjord/dat/
	sudo cp lib/node/*.h /usr/include/fjord/node/
	sudo cp lib/node/*.h /usr/include/fjord/node/physics

clean:
	-rm -r build
	clear
	make