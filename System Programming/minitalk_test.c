#include <stdio.h>

int main(){
	unsigned int val = 50;
	printf("%u\n", val);
	val &= ~127;
	printf("%u\n", val);
}