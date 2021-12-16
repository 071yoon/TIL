#include <stdio.h>
#include <algorithm>
#include <math.h>

int main(){
	double w[2] =  {0};
	double b = 0;
	double err[100][2] = {0};
	int err_true[100] = {0};
	int cnt;
	double learning_rate = 0;

	printf("w : ");
	scanf("%lf %lf", &w[0], &w[1]);
	printf("b : ");
	scanf("%lf", &b);
	printf("error counts : ");
	scanf("%d", &cnt);
	double sum1 = 0;
	double sum2 = 0;
	double err_sum = 0;
	for(int i = 0; i < cnt; i++){
		double tmp1 = 0;
		double tmp2 = 0;
		printf("err %d : ", i);
		scanf("%lf %lf", &err[i][0], &err[i][1]);
		tmp1 += err[i][0];
		tmp2 += err[i][1];
		printf("err true %d : ", i);
		scanf("%d", &err_true[i]);
		tmp1 *= err_true[i];
		tmp2 *= err_true[i];
		sum1 += tmp1;
		sum2 += tmp2;
		err_sum += err_true[i];
	}
	printf("learning rate : ");
	scanf("%lf", &learning_rate); 
	printf("new w :\n%f\n%f\n", w[0] + learning_rate * sum1, w[1] + learning_rate * sum2);
	printf("new b : %f\n", b + learning_rate * (err_sum));
	printf("d(x) = %fx1 + %fx2 + %f", w[0] + learning_rate * sum1, w[1] + learning_rate * sum2, b + learning_rate * (err_sum));
}