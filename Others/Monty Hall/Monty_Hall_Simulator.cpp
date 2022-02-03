#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	srand(time(NULL));

	int monty_sum = 0;
	int dont_change_sum = 0;
	int test_case = 0;
	char simul_on;
	cout << "simulation counts : ";
	cin >> test_case;
	cout << "check every simulations? (y/n) ";
	cin >> simul_on;
	for(int i = 0; i < test_case; i++){
		int chosen_door = rand() % 3;
		int correct_door = rand() % 3;
		if (simul_on == 'y')
			cout << "TEST CASE " << i + 1 << " Car is in " << (char)(correct_door + 'A') << " and my choice is " << (char)(chosen_door + 'A') << "\n";
		if (correct_door == chosen_door){
			if (simul_on == 'y')
				cout << "Monty-Hall X and got correct\n";
			dont_change_sum += 1;
		}
		else{
			if (simul_on == 'y')
				cout << "Monty-Hall X and got wrong\n";
		}
		if (correct_door == chosen_door){ // When you choose the coorect one at the first time -> you will never be able to win
			if (simul_on == 'y')
				cout << "Monty-Hall and got wrong\n";
			continue;
		}
		else if (correct_door != chosen_door){ // When you choose the wrong one at the first time -> you will get it for sure when you change
			if (simul_on == 'y')
				cout << "Monty-Hall and got right\n";
			monty_sum += 1;
		}
		// Since there is 1/3 possibility to win at the first time, possibility to get the prize is 2/3
	}
	cout << "\nmonty possibility is : " << ((double)monty_sum / (double)test_case) * (double)100 << "%" << "\ndon't change possibility is : " << ((double)dont_change_sum / (double)test_case) * (double)100 << "%" << "\n";
}