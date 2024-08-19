#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

const static int MAX_ARGUMENTS = 15;
const static size_t NUMBER_OF_DICE = 7;

enum DIE_TYPE {
	DIE4 = 4, DIE6 = 6, DIE8 = 8,  
	DIE10 = 10, DIE12 = 12, DIE20 = 20, 
	DIE100 = 100
};

int random_int(int max) { return ((double)rand()/RAND_MAX) * max; }

void process_arguments(int argc, char *argv[], int* dice_to_roll) {
	int index = 1; 
	while(index < argc) {
		string result = (string) argv[index];
		char *output;
		int next = (int) strtol(argv[index+1], &output, 10);
		if(*output) { printf("error with %d\n", index); }
		if(result == "-d4") { dice_to_roll[0] = next; }
		if(result == "-d6") { dice_to_roll[1] = next; }
		if(result == "-d8") { dice_to_roll[2] = next; }
		if(result == "-d10") { dice_to_roll[3] = next; }
		if(result == "-d12") { dice_to_roll[4] = next; }
		if(result == "-d20") { dice_to_roll[5] = next; }
		if (result == "-d100") { dice_to_roll[6] = next; }
		index += 2;
	}
	return;
}

int roll_dice(DIE_TYPE type, int number_of_times) {
	int total = 0;
	for(int i = number_of_times; i > 0; i--) {
		int roll = random_int(type);
		total += roll;
		cout << roll << ((i == 1) ? " " : ", ");
	}
	cout << "total for d" << type << ": " << total << endl;
	return total;
}

void complete_roll_dice(int* dice_to_roll) {
	int index = 0;
	int total = 0;
	while(index < NUMBER_OF_DICE) {
		int number_to_roll = dice_to_roll[index];
		if(number_to_roll == 0) { 
			index ++;
			continue; 
		}
		switch (index) {
		case 0:
			total += roll_dice(DIE4, number_to_roll);
			break;
		case 1:
			total += roll_dice(DIE6, number_to_roll);
			break;
		case 2:
			total += roll_dice(DIE8, number_to_roll);
			break;
		case 3:
			total += roll_dice(DIE10, number_to_roll);
			break;
		case 4:
			total += roll_dice(DIE12, number_to_roll);
			break;
		case 5:
			total += roll_dice(DIE20, number_to_roll);
			break;
		case 6:
			total += roll_dice(DIE100, number_to_roll);
			break;
		default:
			printf("error\n");
			break;
		}
		index++;
	}
	cout << "total roll: " << total << "\n" << endl;
}

int main(int argc, char *argv[]) {
	if(argc <= 1 || argc > MAX_ARGUMENTS) {
		printf("need dice to roll");
		return 1;
	}
	int dice_to_roll[NUMBER_OF_DICE]{0};
	process_arguments(argc, argv, dice_to_roll);
	complete_roll_dice(dice_to_roll);
}
