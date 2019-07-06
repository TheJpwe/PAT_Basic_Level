#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	char ch;
	scanf("%d %c", &N, &ch);

	int k = 0;
	while (1+2*k*(k+2) <= N)
	{
		k++;
	}

	k--;
	int col = 2 * k + 1;

	int spacenum, chnum;

	for (int i = -k; i < k+1; i++)
	{
		int j = (i < 0 ? -i : i);
		chnum = 2 * j + 1;
		spacenum = (col - chnum) / 2;

		for (int i = spacenum; i > 0; i--)
		{
			printf(" ");
		}
		
		for (int i = chnum; i > 0; i--)
		{
			printf("%c", ch);
		}

		for (int i = spacenum; i > 0; i--)
		{
			printf(" ");
		}
		printf("\n");
	}

		printf("%d", N - 2 * k * (k + 2) - 1);
	


	return 0;
}