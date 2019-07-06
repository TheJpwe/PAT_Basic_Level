#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{

	int N;
	scanf("%d", &N);

	double *A;
	A = (double *)malloc(N * sizeof(double));



	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &A[i]);
	}


	double sum = 0.00;
	for (int i = 0; i < N; i++)
	{
		double cnt = (N - 1) + 1 + (double)i * ((N - 1) - i);
		sum += A[i] * cnt;

	}

	printf("%.2lf", sum);



	free(A);

	return 0;
}