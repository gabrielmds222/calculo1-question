#include<stdio.h>
#include<math.h>

int main(){

	double x_old=0.6, tol=1.0e-04;
	double error=1.0, x, f, fp;

	while(error > tol){
		f= x_old*x_old + x_old - 2.0;
		fp=2.0*x_old + 1.0;
		x = x_old - f/fp;

		error = fabs(x-x_old)/fabs(x);
		x_old = x;
	}

	printf("x=%f\n",x);

	return 0;
}