all: compile run
compile:
	-mkdir build
	cd build && cmake .. && make -j$(nproc) && cp ../example/keyMap.json .	
run:
	cd build && ./example
clean:
	-rm -r build
	make -j$(nproc)