#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


void show(int *a, int N);


int main()
{
	int N;
	scanf("%d", &N);

	int *A, *InterA;
	A = (int *)malloc(N * sizeof(int));

	InterA = (int *)malloc(N * sizeof(int));
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &InterA[i]);
	}


	int flag = 0;

	for (int i = 1; i < N; i++)
	{
		if (InterA[i] < InterA[i - 1])
		{
			int j;
			for (j = i; j < N; j++)
			{
				if (A[j] != InterA[j])
				{
					break;
				}
			}

			if (j == N)
			{
				flag = 1;
				printf("Insertion Sort\n");
				int temp = InterA[i];
				for ( j = i-1; j >= 0; j--)
				{
					if (temp < InterA[j])
					{
						InterA[j + 1] = InterA[j];
					}
					else
					{
						break;
					}
				}

				InterA[j+1] = temp;

				show(InterA, N);

			}

			break;
		}
	}

	if (flag == 0)
	{
		printf("Merge Sort\n");

		int step = 2;
		for (int i = 0; i < N - step; i += step)
		{
			int Mflag = 0;
			for (int j = i; j < i + step - 1; j++)
			{
				if (InterA[j] > InterA[j + 1])
				{
					Mflag = 1;
					break;
				}
			}
			
			if (Mflag)
			{
				break;
			}
			step *= 2;

		}



	}





	free(A);
	free(InterA);
	return 0;
}


void show(int *a, int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%d", a[i]);
		if (i != N-1)
		{
			printf(" ");
		}
	}

}