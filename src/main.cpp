#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

enum DIE_TYPE {
	DIE4 = 4,
	DIE6 = 6, 
	DIE8 = 8,  
	DIE10 = 10, 
	DIE10_PERCENT = 10,
	DIE12 = 12,
	DIE20 = 20, 
	DIE100 = 100
};

const int MAX_ARGUMENTS = 17;

const map<string, DIE_TYPE> die_description = {
	pair<string, DIE_TYPE>("-d4", DIE4),
	pair<string, DIE_TYPE>("-d6", DIE6),
	pair<string, DIE_TYPE>("-d8", DIE8),
	pair<string, DIE_TYPE>("-d10", DIE10),
	pair<string, DIE_TYPE>("-d10P", DIE10_PERCENT),
	pair<string, DIE_TYPE>("-d12", DIE12),
	pair<string, DIE_TYPE>("-d20", DIE20),
	pair<string, DIE_TYPE>("-d100", DIE100)
};

int random_int(int max) { return ((double)rand()/RAND_MAX) * max; }

void process_arguments(int argc, char *argv[]) {
	int index = 0; 
	while(index < argc) {
		string result = (string) argv[index];
		cout << "argument at " << index << ": " << result << endl;
		index ++;
	}
}

/**
 * Taking in arguments to allow for cli use of dice roller
 * with a use something like
 * "diceroller -d4 10 -d20 1"
 * */
int main(int argc, char *argv[]) {
	// returns error if there are no arguments used with the program
	if(argc <= 1 || argc > MAX_ARGUMENTS) {
		printf("need dice to roll");
		return 1;
	}
	// process argv
	process_arguments(argc, argv);
}
