#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

	double *x, *y, *Y, h, x0=0.0, xf=1.0, *e;
	double error, sum;
	int n=1000, i;
	FILE *pt;
	//Y: aproximação
	//y: sol. exata

	//memory allocation
	x = (double *)malloc(sizeof(double)*(n+1));
	y = (double *)malloc(sizeof(double)*(n+1));
	Y = (double *)malloc(sizeof(double)*(n+1));
	e = (double *)malloc(sizeof(double)*(n+1));

	h = (xf - x0)/n;
	x[0] = x0;
	//definindo o domínio
	for (i=1; i<=n; i++){
		x[i] = x[i-1] + h;
	}

	Y[0] = 1.0;//valor inicial
	for (i=0; i<n ;i++){
		Y[i+1] = Y[i] + h*x[i];//approx.
		y[i] = ((x[i]*x[i])/2.0) + 1.0;//valor exato
	}
	y[n] = ((x[n]*x[n])/2.0) + 1.0;

	pt = fopen("values.txt", "w");

	for (i=0;i<=n;i++){
		e[i] = fabs(y[i] - Y[i]);
		fprintf(pt, "%lf \t %lf \t %lf \n", x[i], y[i], Y[i]);
	}
	fclose(pt);

	sum=0.0;
	for (i=0;i<=n;i++){
		sum += e[i]*e[i];
	}
	error = sqrt(sum);
	printf("error=%lf\n", error);


	//free
	free(x);
	free(y);
	free(Y);
	free(e);

	return 0;
}
