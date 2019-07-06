#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *A, *tmpA, *Q, *tmpQ;
	int B, R = 0;

	A = (char *)malloc(1001 * sizeof(char));
	tmpA = A;

	Q = (char *)malloc(1001 * sizeof(char));
	tmpQ = Q;

	*Q = '\0';

	scanf("%s %d", A, &B);

	//printf("%s %d", A, B);

	int tempR, tempQ;

	while (*tmpA != '\0')
	{
		tempR = R * 10 + *tmpA - '0';
		tempQ = 0;
		while (tempR >= B)
		{
			tempQ++;
			tempR -= B;
		}
		R = tempR;
		*tmpQ = tempQ + 48;
		tmpQ++;
		*tmpQ = '\0';
		tmpA++;
	}

	tmpQ = Q;
	while (*tmpQ == '0')
	{
		tmpQ++;
		
	}
	if (*tmpQ == '\0')
	{
		printf("0");
	}
	else
	{
		printf("%s", tmpQ);
	}
	
	printf(" %d", R);

	free(A);
	free(Q);

	return 0;
}