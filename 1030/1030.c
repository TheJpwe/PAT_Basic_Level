#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int *A, int N);
int cmpfunc(const void *a, const void *b);


int main()
{
	int N, p;
	scanf("%d %d", &N, &p);
	int *A;
	A = (int *)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	//InsertionSort(A, N);
	qsort(A, N, sizeof(int), cmpfunc);
	
	long long m, M;
	int cnt = 0, maxcnt = 0;
	for (int i = 0; i < N; i++)
	{
		m = A[i];
		M = m * p;
		int left, right, mid;
		left = i;
		right = N;
		if (M > A[N-1])
		{
			cnt = N - i;
			if (cnt > maxcnt)
			{
				maxcnt = cnt;
			}
			break;
		}
		else
		{
			while (left < right-1)
			{
				mid = (left + right) / 2;
				if (A[mid] < M)
				{
					left = mid + 1;
					if (A[left] > M)
					{
						break;
					}
					else if (A[left] == M)
					{
						left++;
						break;
					}
				}
				else if (A[mid] > M)
				{
					right = mid - 1;
					if (A[right] <= M)
					{
						left = right + 1;
						break;
					}
				}
				else
				{
					left = mid + 1;
					break;
				}
				
			}

			cnt = left -i;
			if (cnt > maxcnt)
			{
				maxcnt = cnt;
			}
		}


	}


	//for (int i = 0; i < N; i++)
	//{
	//	printf("%d ", A[i]);
	//}

	//printf("\n");
	printf("%d", maxcnt);


	free(A);
	return 0;
}

void InsertionSort(int *A, int N)
{
	int temp;
	int j;
	for (int i = 1; i < N; i++)
	{
		temp = A[i];
		for ( j = i-1; j >=0; j--)
		{
			if (temp < A[j])
			{
				A[j + 1] = A[j];
			}
			else
			{
				break;
			}
		}
		A[j+1] = temp;

	}

}

int cmpfunc(const void *a, const void *b)
{

	return (*(int *)a - *(int *)b);

}