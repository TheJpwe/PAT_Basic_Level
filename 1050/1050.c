#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


typedef struct HNode *MaxHeap;
struct HNode
{
	int *data;
	int size;
	int capacity
};







int main()
{

	int N;
	scanf("%d", &N);

	int m = 1, n = 1;
	while (m*n<N)
	{
		if (m==n)
		{
			m++;
		}
		else
		{
			n++;
		}

	}

	int *A;
	A = (int *)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);

	}

	int *resultCol;	//螺旋矩阵的行向量
	int **result;	//螺旋矩阵行向量

	
	result = (int **)malloc(m * sizeof(int *));

	for (int i = 0; i < m; i++)
	{
		resultCol = (int *)malloc(n * sizeof(int));
		result[i] = resultCol;
		for (int j = 0; j < n; j++)
		{
			resultCol[j] = 0;
			
		}

	}



	//对A进行由大到小排序。考虑练习用最大堆进行排序







	//将排好序的数填入螺旋矩阵

	int index, cnt = 0;
	for ( index = 0; index < m; index++)
	{
		int i = index, j;
		for ( j = i; j < n-i; j++)
		{
			if (cnt < N)
			{
				result[i][j] = A[cnt++];
			}
			
		}

		j = n - 1 - index;
		for ( i = index+1; i < m-index; i++)
		{
			if (cnt < N)
			{
				result[i][j] = A[cnt++];
			}
			
		}

		i = m - 1 - index;
		for ( j = n - 1 - index - 1; j >= index; j--)
		{
			if (cnt < N)
			{
				result[i][j] = A[cnt++];
			}
			
		}

		j = index;
		for ( i = m - 1 - index - 1; i > index; i--)
		{
			if (cnt < N)
			{
				result[i][j] = A[cnt++];
			}

		}

	}

	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		printf("%d ", result[i][j]);
	//	}
	//	printf("\n");
	//}





	free(A);
	for (int i = 0; i < m; i++)
	{
		free(result[i]);
	}
	free(result);
	return 0;
}