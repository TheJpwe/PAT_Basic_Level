#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int score[101] = { 0 };

	const int MAXSIZE = 101;
	
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int tmp = 0;
		scanf("%d", &tmp);
		score[tmp]++;
	}

	int Cnt;
	scanf("%d", &Cnt);

	for (int i = 0; i < Cnt; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		printf("%d", score[tmp]);
		if (i != Cnt-1)
		{
			printf(" ");
		}
	}


	return 0;
}