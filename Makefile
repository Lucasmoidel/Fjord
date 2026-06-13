all: compile run
clean: del compile run
compile:
	-mkdir build
	cd build && cmake .. && make -j$(nproc) SYSTEM=linux-egl && cp ../example/keyMap.json .	
run:
	cd build && ./example
del:
	clear
	-rm -r build