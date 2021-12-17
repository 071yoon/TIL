#include <stdio.h>
#include <algorithm>
#include <numeric>
#include <math.h>

int main(){
	double w1[100][2] = {0};
	double w2[100][2] = {0};
	double w1_avg[2] = {0};
	double w2_avg[2] = {0};
	double w1_cov[2][2] = {0};
	double w2_cov[2][2] = {0};
	int cnt = 0;
	double tmp = 0;

	printf("input data : ");
	scanf("%d", &cnt);
	printf("w1's x : ");
	for(int i = 0; i < cnt; i++){
		scanf("%lf", &w1[i][0]);
		tmp += w1[i][0];
	}
	w1_avg[0] = tmp / cnt;
	tmp = 0;
	printf("w1's y : ");
	for(int i = 0; i < cnt; i++){
		scanf("%lf", &w1[i][1]);
		tmp += w1[i][1];
	}
	w1_avg[1] = tmp / cnt;
	tmp = 0;
	printf("w2's x : ");
	for(int i = 0; i < cnt; i++){
		scanf("%lf", &w2[i][0]);
		tmp += w2[i][0];
	}
	w2_avg[0] = tmp / cnt;
	tmp = 0;
	printf("w2's y : ");
	for(int i = 0; i < cnt; i++){
		scanf("%lf", &w2[i][1]);
		tmp += w2[i][1];
	}
	w2_avg[1] = tmp / cnt;
	tmp = 0;
	printf("u1 : \n%f\n%f\n", w1_avg[0], w1_avg[1]);
	printf("u2 : \n%f\n%f\n", w2_avg[0], w2_avg[1]);
	for(int i = 0; i < cnt ; i++){
		tmp += pow((w1[i][0] - w1_avg[0]),2);
	}
	w1_cov[0][0] = tmp/(cnt - 1);
	tmp = 0;
	for(int i = 0; i < cnt ; i++){
		tmp += pow((w1[i][1] - w1_avg[1]),2);
	}
	w1_cov[1][1] = tmp/(cnt - 1);
	tmp = 0;
	for(int i = 0; i < cnt ; i++){
		tmp += pow((w2[i][0] - w2_avg[0]),2);
	}
	w2_cov[0][0] = tmp/(cnt - 1);
	tmp = 0;
	for(int i = 0; i < cnt ; i++){
		tmp += pow((w2[i][1] - w2_avg[1]),2);
	}
	w2_cov[1][1] = tmp/(cnt - 1);
	tmp = 0;
	printf("sig w1 \n %f %f \n %f %f\n", w1_cov[0][0], w1_cov[0][1], w1_cov[1][0], w1_cov[1][1]);
	printf("sig w2 \n %f %f \n %f %f\n", w2_cov[0][0], w2_cov[0][1], w2_cov[1][0], w2_cov[1][1]);
	double g1_x1_sq = 0;
	double g1_x2_sq = 0;
	double g1_x1 = 0;
	double g1_x2 = 0;
	double g1_c = 0;
	g1_x1_sq = (pow(w1_cov[0][0], -1) / 2) * -1;
	g1_x2_sq = (pow(w1_cov[1][1], -1) / 2) * -1;
	g1_x1 = w1_avg[0] * pow(w1_cov[0][0], -1);
	g1_x2 = w1_avg[1] * pow(w1_cov[1][1], -1);
	g1_c = ((w1_avg[0] * pow(w1_cov[0][0], -1) * w1_avg[0]) + (w1_avg[1] * pow(w1_cov[1][1],-1) * w1_avg[1]) + log(w1_cov[0][0] * w1_cov[1][1])) / 2 * -1;
	printf("g1(x) : %fx1_sq + %fx2_sq + %fx1 + %fx2 + %f + ln(Pw1)\n", g1_x1_sq, g1_x2_sq, g1_x1, g1_x2, g1_c);
	double g2_x1_sq = 0;
	double g2_x2_sq = 0;
	double g2_x1 = 0;
	double g2_x2 = 0;
	double g2_c = 0;
	g2_x1_sq = (pow(w2_cov[0][0], -1) / 2) * -1;
	g2_x2_sq = (pow(w2_cov[1][1], -1) / 2) * -1;
	g2_x1 = w2_avg[0] * pow(w2_cov[0][0], -1);
	g2_x2 = w2_avg[1] * pow(w2_cov[1][1], -1);
	g2_c = ((w2_avg[0] * pow(w2_cov[0][0], -1) * w2_avg[0]) + (w2_avg[1] * pow(w2_cov[1][1],-1) * w2_avg[1]) + log(w2_cov[0][0] * w2_cov[1][1])) / 2 * -1;
	printf("g2(x) : %fx1_sq + %fx2_sq + %fx1 + %fx2 + %f + ln(Pw2)\n", g2_x1_sq, g2_x2_sq, g2_x1, g2_x2, g2_c);
	printf("g12(x) : %fx1_sq + %fx2_sq + %fx1 + %fx2 + %f + ln(Pw1) - ln(Pw2)\n", g1_x1_sq - g2_x1_sq, g1_x2_sq - g2_x2_sq, g1_x1 - g2_x1, g1_x2 - g2_x2, g1_c - g2_c);

}