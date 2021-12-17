#include <stdio.h>
#include <math.h>
#include <algorithm>
#define alpha 1

double sigmoid(double x, int flag){
	double ret;
	
	if (flag == 1) 
		ret = 1 / (1 + exp(x * -1 * alpha));
	else
		ret = (2 / (1 + exp(x * -1 * alpha))) - 1;
	return (ret);
}

double dx_sigmoid(double x, int flag){
	double ret;

	if (flag == 1)
		ret = alpha * (sigmoid(x, flag)) * (1 - sigmoid(x, flag));
	else
		ret = (alpha * (1 + sigmoid(x, flag)) * (1 - sigmoid(x , flag))) / 2;
	return (ret);
}


int main(){
	int d, p, m;
	double first_w[100][100] = {0};
	double second_w[100][100] = {0};
	double first_value[100] = {0};
	double second_value[100] = {0};
	double third_value[100] = {0};
	double true_class[100] = {0};
	double delta[100] = {0};
	double mew[100] = {0};
	double v_variance[100][100] = {0};
	double u_variance[100][100] = {0};
	double o_sum[100] = {0};
	double z_sum[100] = {0};
	double new_v[100][100] = {0};
	double new_u[100][100] = {0};
	double new_z[100] = {0};
	double new_o[100] = {0};


	printf("write d p m\n");
	scanf("%d %d %d", &d, &p, &m);
	first_value[0] = 1;
	second_value[0] = 1;
	printf("value of x : ");
	for (int i = 1; i <= d; i++){
		scanf("%lf", &first_value[i]);
	}
	printf("value of first w\n");
	for (int i = 0; i < p; i++){
		printf("first w %d : ", i);
		for (int j = 0; j < d + 1; j++){
			scanf("%lf", &first_w[i][j]);
		}
	}
	printf("value of second w\n");
	for (int i = 0; i < m; i++){
		printf("second w %d : ", i);
		for (int j = 0; j < p + 1; j++){
			scanf("%lf", &second_w[i][j]);
		}
	}
	printf("true class : ");
	for (int i = 0; i < m; i++){
		scanf("%lf", &true_class[i]);
	}
	int flag = 0;
	printf("if bi-sigmoid : 1, if not : 0 : ");
	scanf("%d", &flag);
	double learning_rate = 0;
	printf("learning rate : ");
	scanf("%lf", &learning_rate);
	for (int i = 0; i < p; i++){
		for (int j = 0; j < d + 1; j++){
			second_value[i + 1] += first_value[j] * first_w[i][j];
		}
	}
	for (int i = 1; i < p + 1; i++){
		printf("z_sum1 %d : %lf\n", i, second_value[i]);
		z_sum[i] = second_value[i];
	}
	for (int i = 1; i < p + 1; i++){
		second_value[i] = sigmoid(second_value[i], flag);
		printf("z%d : %lf\n", i, second_value[i]);
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < p + 1; j++){
			third_value[i + 1] += second_value[j] * second_w[i][j];
		}
	}
	for (int i = 1; i < m + 1; i++){
		printf("o_sum1 %d : %lf\n", i, third_value[i]);
		o_sum[i] = third_value[i];
	}
	for (int i = 1; i < m + 1; i++){
		third_value[i] = sigmoid(third_value[i], flag);
		printf("o%d : %lf\n", i, third_value[i]);
	}
	double error = 0;
	for (int i = 1; i < m + 1; i++){
		error += pow((true_class[i - 1] - third_value[i]), 2);
	}
	error /= 2;
	printf("error is %lf\n", error);

	for (int i = 1; i < p + 1; i++){
		delta[i] = (true_class[i - 1] - third_value[i]) * dx_sigmoid(o_sum[i], flag);
		printf("delta %d : %lf\n", i, delta[i]);
	}
	for (int i = 0; i < p + 1; i++){
		for (int j = 1; j < m + 1; j++){
			v_variance[i][j] = learning_rate * delta[j] * second_value[i];
			printf("v_variance %d %d : %lf\n", i, j, v_variance[i][j]);
		}
	}
	for (int i = 1; i < m + 1; i++){
		double summer = 0;

		for(int j = 0; j < p; j++){
			summer += delta[j + 1] * second_w[j][i];
		}
		mew[i] = dx_sigmoid(z_sum[i], flag) * summer;
		printf("mew %d : %lf\n", i, mew[i]);
	}
	for (int i = 0; i < d + 1; i++){
		for (int j = 1; j < p + 1; j++){
			u_variance[i][j] = learning_rate * mew[j] * first_value[i];
			printf("u_variance %d %d : %lf\n", i, j, u_variance[i][j]);
		}
	}

	printf("input opposite first_w\n");
	double new_first_w[100][100] = {0};
	for (int i = 0; i < d + 1; i++){
		for (int j = 1; j < p + 1; j++){
			scanf("%lf", &new_first_w[i][j]);
		}
	}
	printf("input opposite second_w\n");
	double new_second_w[100][100] = {0};
	for (int i = 0; i < p + 1; i++){
		for (int j = 1; j < m + 1; j++){
			scanf("%lf", &new_second_w[i][j]);
		}
	}
	for (int i = 0; i < p + 1; i++){
		for (int j = 1; j < m + 1; j++){
			new_v[i][j] = new_second_w[i][j] + v_variance[i][j];
			printf("new v %d%d is : %lf\n", i, j, new_v[i][j]);
		}
	}
	for (int i = 0; i < p + 1; i++){
		for (int j = 1; j < m + 1; j++){
			new_u[i][j] = new_first_w[i][j] + u_variance[i][j];
			printf("new u %d%d is : %lf\n", i, j, new_u[i][j]);
		}
	}



	for (int i = 0; i < p; i++){
		second_value[i + 1] = 0;
		for (int j = 0; j < d + 1; j++){
			second_value[i + 1] += first_value[j] * new_u[j][i + 1];
		}
	}
	for (int i = 1; i < p + 1; i++){
		printf("z_sum1 %d : %lf\n", i, second_value[i]);
		z_sum[i] = second_value[i];
	}
	for (int i = 1; i < p + 1; i++){
		second_value[i] = sigmoid(second_value[i], flag);
		printf("z%d : %lf\n", i, second_value[i]);
	}
	for (int i = 0; i < m; i++){
		third_value[i + 1] = 0;
		for (int j = 0; j < p + 1; j++){
			third_value[i + 1] += second_value[j] * new_v[j][i + 1];
		}
	}
	for (int i = 1; i < m + 1; i++){
		printf("o_sum1 %d : %lf\n", i, third_value[i]);
		o_sum[i] = third_value[i];
	}
	for (int i = 1; i < m + 1; i++){
		third_value[i] = sigmoid(third_value[i], flag);
		printf("o%d : %lf\n", i, third_value[i]);
	}
	error = 0;
	for (int i = 1; i < m + 1; i++){
		error += pow((true_class[i - 1] - third_value[i]), 2);
	}
	error /= 2;
	printf("error is %lf\n", error);


}