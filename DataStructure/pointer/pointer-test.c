#include <stdio.h>

int main(){
	int a = 10;
	int *b;
	b = &a;
	printf("%d\n", a);
	printf("%d\n", *b);
	*b += 1;
	printf("%d\n", a);
	printf("%d\n", *b);
}