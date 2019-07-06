#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct student
{
	int school;
	int score;
};

int main()
{
	int N;
	scanf("%d", &N);

	struct student *s;
	s = (struct student *)malloc(N * sizeof(struct student));

	int maxschool = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &s[i].school, &s[i].score);
		if (s[i].school > maxschool)
		{
			maxschool = s[i].school;
		}
	}

	int *schoolscore;
	schoolscore = (int *)malloc((maxschool + 1) * sizeof(int));

	for (int i = 0; i < maxschool + 1; i++)
	{
		schoolscore[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		schoolscore[s[i].school] += s[i].score;
	}

	int maxscore = 0;
	int schoolid;
	for (int j = 1; j < maxschool+1; j++)
	{
		if (schoolscore[j]>maxscore)
		{
			schoolid = j;
			maxscore = schoolscore[j];
		}
	}


	printf("%d %d", schoolid, maxscore);


	free(s);
	free(schoolscore);

	return 0;
}