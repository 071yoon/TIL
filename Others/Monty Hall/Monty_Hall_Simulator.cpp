#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	srand(time(NULL));

	int monty_sum = 0;
	int dont_change_sum = 0;
	for(int i = 0; i < 100000; i++){
		int chosen_door = rand() % 3;
		int correct_door = rand() % 3;

		cout << "Car is in " << (char)(correct_door + 'A') << " and my choice is " << (char)(chosen_door + 'A');
		if (correct_door == chosen_door){
			cout << " I haven't chnaged and got correct";
			dont_change_sum += 1;
		}
		if (correct_door == chosen_door){ // When you choose the coorect one at the first time -> you will never be able to win
			cout << " I have changed and got wrong\n";
			continue;
		}
		else if (correct_door != chosen_door){ // When you choose the wrong one at the first time -> you will get it for sure when you change
			cout << " I changed and got right\n";
			monty_sum += 1;
		}
		// Since there is 1/3 possibility to win at the first time, possibility to get the prize is 2/3
	}
	cout << "\nmonty possibility is : " <<(double)monty_sum / 1000 << "\ndon't change possibility is : " << (double)dont_change_sum / 1000<< "\n";
}