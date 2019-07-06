#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int pow(int a, int k);

int main()
{
	char *stA, *stB;
	int Da, Db;

	stA = (char *)malloc(12 * sizeof(char));
	stB = (char *)malloc(12 * sizeof(char));


	scanf("%s", stA);
	scanf("%d", &Da);
	scanf("%s", stB);
	scanf("%d", &Db);

	int cntA = 0, cntB = 0;
	int Pa = 0, Pb = 0;

	char *temp = stA;

	while (*temp != '\0')
	{
		if (Da == *temp - '0')
		{
			cntA++;
			Pa += pow(10, cntA)*Da;
		}

		temp++;
	}

	temp = stB;

	while (*temp != '\0')
	{
		if (Db == *temp - '0')
		{
			cntB++;
			Pb += pow(10, cntB)*Db;
		}

		temp++;
	}


	printf("%d", Pa + Pb);


	//printf("%s ", stA);
	//printf("%d ", Da);
	//printf("%s ", stB);
	//printf("%d", Db);


	free(stA);
	free(stB);

	return 0;
}

int pow(int a, int k)
{
	int result = 1;
	if (k==1)
	{
		result = 1;
	}
	else if (k > 1)
	{
		while (k > 1)
		{
			result *= a;
			k--;
		}
	}
	else
	{
		result = 0;
	}

	return result;

}