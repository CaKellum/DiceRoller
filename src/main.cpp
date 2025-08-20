#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Die { D4 = 4, D6 = 6, D8 = 8, D10 = 10, D12 = 12, D20 = 20, D100 = 100 };

struct DieToRoll {
  Die die;
  int amount;

  int roll() { return ((double)rand() / RAND_MAX) * (this->die); }

public:
  DieToRoll(Die die, int amount) {
    this->amount = amount < 0 ? 0 : amount;
    this->die = die;
  }

  vector<int> resolve() {
    vector<int> results;
    for (int i{0}; i < amount; i++) {
      int res = this->roll();
      results.push_back(res);
    }
    return results;
  }
};

Die str_to_die(string die_str) {
  if (die_str.compare("-d4") == 0) {
    return Die::D4;
  }
  if (die_str.compare("-d6") == 0) {
    return Die::D6;
  }
  if (die_str.compare("-d8") == 0) {
    return Die::D8;
  }
  if (die_str.compare("-d10") == 0) {
    return Die::D10;
  }
  if (die_str.compare("-d12") == 0) {
    return Die::D12;
  }
  if (die_str.compare("-d20") == 0) {
    return Die::D20;
  }
  if (die_str.compare("-d100") == 0) {
    return Die::D100;
  }
  return Die::D6;
}

string die_to_string(Die die) {
  switch (die) {
  case Die::D4:
    return "D4";
    break;
  case Die::D6:
    return "D6";
    break;
  case Die::D8:
    return "D8";
    break;
  case Die::D10:
    return "D10";
    break;
  case Die::D12:
    return "D12";
    break;
  case Die::D20:
    return "D20";
    break;
  case Die::D100:
    return "D100";
    break;
  }
  return "unknown";
}

int print_rolls(vector<int> results) {
  int total;
  cout << "rolls: ";
  for (auto i{results.begin()}; i != results.end(); ++i) {
    cout << " [" << *i << "] ";
    total += *i;
  }
  cout << "\ntotal: " << total << endl;
  return total;
}

int main(int argc, char *argv[]) {
  int total;
  for (int i{1}; i < argc; i += 2) {
    Die die = str_to_die(argv[i]);
    int amount = atoi(argv[i + 1]);
    DieToRoll roll = DieToRoll(die, amount);
    cout << die_to_string(roll.die) << ":" << endl;
    total += print_rolls(roll.resolve());
    cout << endl;
  }
  // more than one die type selected
  if (argc > 3)
    cout << "Grand total: " << total << endl;
  return 0;
}
