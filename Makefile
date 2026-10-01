.PHONY: all clean run

all:
	cmake -S . -B build
	cmake --build build
run:
	./build/bin/main
clean:
	rm -rf build