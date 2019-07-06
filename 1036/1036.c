#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int N;
	char C;

	scanf("%d %c", &N, &C);


	//printf("%d %c", N, C);

	int L;
	L = N / 2;
	if (N % 2)
	{
		L++;
	}

	for (int i = 0; i < L; i++)
	{
		if (i == 0 || i == L-1)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%c", C);
			}
			printf("\n");

		}
		else
		{
			for (int j = 0; j < N; j++)
			{
				if (j == 0 || j == N - 1)
				{
					printf("%c", C);
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}



	}



	return 0;
}