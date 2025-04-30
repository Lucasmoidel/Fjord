all: compile run
compile:
	-mkdir build
	cd build && cmake .. && make -j4 && cp ../example/keyMap.json .	
run:
	cd build && ./example
clean:
	clear
	-rm -r build
	make