all: compile run
clean: del compile run
compile:
	-mkdir build
	cd build && cmake .. && make -j6 SYSTEM=linux-egl && cp ../example/keyMap.json .	
run:
	cd build && ./example
del:
	clear
	-rm -r build