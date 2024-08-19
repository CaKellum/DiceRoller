#include <cstdlib>
#include <cstdio>
#include <iostream>
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

int random_int(int max) { return ((double)rand()/RAND_MAX) * max; }

void process_arguments(int argc, char *argv[], int* dice_to_roll) {
	// this is set to one to account for the program argument
	int index = 1; 
	while(index < argc) {
		string result = (string) argv[index];
		char *output;
		int next = (int) strtol(argv[index+1], &output, 10);
		if(*output) {
			printf("error with %d\n", index);
		}
		printf("next to place is %d, with %s\n", next, argv[index]);
		if(result == "-d4") { dice_to_roll[0] = next; }
		if(result == "-d6") { dice_to_roll[1] = next; }
		if(result == "-d8") { dice_to_roll[2] = next; }
		if(result == "-d10") { dice_to_roll[3] = next; }
		if(result == "-d10p") { dice_to_roll[4] = next; }
		if(result == "-d12") { dice_to_roll[5] = next; }
		if(result == "-d20") { dice_to_roll[6] = next; }
		if (result == "-d100") { dice_to_roll[7] = next; }
		index += 2;
	}
	return;
}

int roll_dice(DIE_TYPE type, int number_of_times) {
	int total = 0;
	for(int i = number_of_times; i > 0; i--) {
		int roll = random_int(type);
		total += roll;
		cout << ((type == DIE10_PERCENT) ? (roll * 10) : roll) << ((i == 1) ? " " : ", ") << endl;
	}
	cout << "total for d" << type << ": " << ((type == DIE10_PERCENT) ? (total * 10) : total) << "\n" << endl;
	return type == DIE10_PERCENT ? total * 10 : total;
}

void complete_roll_dice(int* dice_to_roll) {
	int index = 0;
	int total = 0;
	while(index < 8) {
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
			total += roll_dice(DIE10_PERCENT, number_to_roll);
			break;
		case 5:
			total += roll_dice(DIE12, number_to_roll);
			break;
		case 6:
			total += roll_dice(DIE20, number_to_roll);
			break;
		case 7:
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
	int dice_to_roll[] = {0, 0, 0, 0, 0, 0, 0, 0};
	// process argv
	process_arguments(argc, argv, dice_to_roll);
	complete_roll_dice(dice_to_roll);
}
