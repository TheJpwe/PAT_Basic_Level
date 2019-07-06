#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	scanf("%d", &N);
	int *A, *end, *num;
	A = (int *)malloc((N + 1) * sizeof(int));
	num = (int *)malloc(N * sizeof(int));

	end = A;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		num[i] = 0;
		end++;
	}


	int *left, *cur, *right, *curnum;

	
	cur = A;
	curnum = num;
	int cnt = 0;
	while (cur != end)
	{
		left = A;
		right = cur + 1;

		int flag = 0;

		while (left != cur)
		{
			if (*left > *cur)
			{
				flag = 1;
				break;
			}
			left++;

		}

		if (flag)
		{
			cur++;
			curnum++;
			continue;
		}

		flag = 0;
		while (right != end)
		{
			if (*right < *cur)
			{
				flag = 1;
				break;
			}
			
			right++;

		}
		
		if (flag)
		{
			cur++;
			curnum++;
			continue;
		}
		
		cnt++;
		cur++;
		*curnum = 1;
		curnum++;

	}

	printf("%d\n", cnt);
	int flag = 1;
	for (int i = 0; i < N; i++)
	{

		if (num[i])
		{
			if (!flag)
			{
				printf(" ");
			}
			else
			{
				flag = 0;
			}

			printf("%d", A[i]);
		}
	}
	
	free(A);
	free(num);

	return 0;
}