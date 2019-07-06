#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	scanf("%d", &N);

	char M[11] = { '1', '0','X','9','8','7','6','5','4','3','2' };
	int W[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };

	char *id;
	id = (char *)malloc(19 * sizeof(char));
	char *cur;
	int flag = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("%s", id);
		cur = id;
		int j = 0, wsum = 0;
		
		for (j = 0; j < 17; j++)
		{
			if (*cur < '0' || *cur >'9')
			{
				printf("%s\n", id);
				flag = 1;
				break;
			}
			wsum += W[j] * (*cur - '0');
			cur++;
		}

		int z;
		if (j == 17)
		{
			z = wsum % 11;
			if (*cur != M[z])
			{
				printf("%s\n", id);
				flag = 1;
			}
		}

	}
	if (flag == 0)
	{
		printf("All passed");
	}

	free(id);
	return 0;
}