#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	string tmp[15] = {"korea", "data", "Ahn", "quick", "sort", "university", "bubble", "algorithm", "computer", "recursive", "tree", "hash0", "chain", "stack", "queue"};
	sort(tmp, tmp + 15);
	for(int i = 0; i < 15; i++){
		cout << tmp[i] << " ";
	} 
}