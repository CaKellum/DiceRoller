default: build

build: clean
	clang++ -std=c++20 ./src/*.cpp -o diceroller

clean: 
	rm -rf diceroller

