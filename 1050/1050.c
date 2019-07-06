#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


typedef struct HNode *MaxHeap;
struct HNode
{
	int *data;
	int size;
	int capacity;
};

MaxHeap CreatHeap(int maxsize);

void BuildMaxHeap(MaxHeap H);	//��һ�������е����ݵ���Ϊ����

void PercDown(MaxHeap H, int p);	//��H����pΪ���ڵ�Ķѵ���Ϊ����

int DeleteMax(MaxHeap H);	//��������ȡ������Ԫ�ز�ɾ��һ���ڵ�

bool IsEmpty(MaxHeap H);	//�ж��Ƿ�Ϊ��

int main()
{

	int N;
	scanf("%d", &N);

	int m = 1, n = 1;
	for (int i = sqrt((double)N); i >= 1; i--)
	{
		if (N % i == 0)
		{
			n = i;
			break;
		}
	}

	m = N / n;

	//printf("%d %d\n", m, n);

	MaxHeap H;

	H = CreatHeap(N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &H->data[i]);
		H->size++;

	}

	int *resultCol;	//���������������
	int **result;	//��������������

	
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

	//��A�����ɴ�С���򡣿�����ϰ�����ѽ�������

	BuildMaxHeap(H);
	//for (int i = 0; i < H->size; i++)
	//{
	//	printf("%d ", H->data[i]);
	//	
	//}
	//printf("\n");

	//���ź������������������

	int index;
	for ( index = 0; index < m; index++)
	{
		int i = index, j;
		if (i < m)
		{
			for ( j = i; j < n-i; j++)
			{
				result[i][j] = DeleteMax(H);
			
			}
		}
		

		j = n - 1 - index;
		if (j < n && j >= 0)
		{
			for ( i = index+1; i < m-index; i++)
			{
			

				result[i][j] =DeleteMax(H);

			
			}
		}
		

		i = m - 1 - index;
		if (i  > index)
		{
			for ( j = n - 1 - index - 1; j >= index; j--)
			{


				result[i][j] = DeleteMax(H);

			
			}
		}
		

		j = index;
		if (j < n - index - 1)
		{
			for ( i = m - 1 - index - 1; i > index; i--)
			{

			
				result[i][j] = DeleteMax(H);
			

			}
		}
		

	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", result[i][j]);
			if (j != n-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}





	free(H->data);
	free(H);
	for (int i = 0; i < m; i++)
	{
		free(result[i]);
	}
	free(result);
	return 0;
}

MaxHeap CreatHeap(int maxsize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));

	H->size = 0;
	H->capacity = maxsize;

	H->data = (int *)malloc(maxsize * sizeof(int));

	return H;

}

void PercDown(MaxHeap H, int p)
{
	int parent, child;
	int x;

	x = H->data[p];
	for ( parent = p; parent * 2 + 1 < H->size; parent = child)
	{
		child = parent * 2 + 1;
		if (child != H->size-1 && H->data[child] < H->data[child+1])
		{
			child++;
		}

		if (x < H->data[child])
		{
			H->data[parent] = H->data[child];
		}
		else
		{
			break;
		}


	}

	H->data[parent] = x;


}

void BuildMaxHeap(MaxHeap H)
{
	for (int i = H->size/2 - 1; i >= 0; i--)
	{
		PercDown(H, i);
	}
}

int DeleteMax(MaxHeap H)
{
	if (IsEmpty(H))
	{
		return -1;
	}

	int maxItem, x;
	int parent, child;

	maxItem = H->data[0];
	x = H->data[H->size - 1];
	H->size--;

	for ( parent = 0; parent * 2 + 1 < H->size; parent = child)
	{
		child = parent * 2 + 1;
		if (child != H->size - 1 && H->data[child] < H->data[child+1])
		{
			child++;
		}

		if (x < H->data[child])
		{
			H->data[parent] = H->data[child];
		}
		else
		{
			break;
		}


	}

	H->data[parent] = x;

	return maxItem;

}


bool IsEmpty(MaxHeap H)
{
	if (H->size > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}