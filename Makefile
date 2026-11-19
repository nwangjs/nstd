.PHONY: build test format

build:
	cmake -S . -B build
	cmake --build build

test: build
	./build/nstd_tests

format:
	clang-format -i include/nstd/*.hpp tests/*.cpp
