#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double R1, P1, R2, P2;
	scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
	double R, P, A, B;
	R = R1 * R2;
	P = P1 + P2;
	A = R * cos(P);
	B = R * sin(P);

	if (A<0 && A>=-0.005)
	{
		A = 0.00;
	}

	if (B<0 && B>=-0.005)
	{
		B = 0.00;
	}



	printf("%.2f%+.2fi", A, B);

	return 0;
}