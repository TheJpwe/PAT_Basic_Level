#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct student
{
	char id[17];
	int firstId;
	int secondId;
};

int main()
{
	int N;
	scanf("%d", &N);

	struct student *st;
	st = (struct student *)malloc(N * sizeof(struct student));
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d %d", st[i].id, &st[i].firstId, &st[i].secondId);
	}

	int M, cnt;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &cnt);
		for (int j = 0; j < N; j++)
		{
			if (cnt == st[j].firstId)
			{
				printf("%s %d\n", st[j].id, st[j].secondId);
				break;
			}
			
		}
		
	}



	free(st);
	return 0;
}