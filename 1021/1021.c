#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *N, *tN;
	N = (char *)malloc(1001 * sizeof(char));
	tN = N;

	scanf("%s", N);

	int result[10] = { 0 };

	while (*tN != '\0')
	{
		result[*tN - '0']++;
		tN++;
	}

	for (int i = 0; i < 10; i++)
	{
		if (result[i] != 0)
		{
			printf("%d:%d\n", i, result[i]);
		}
	}

	free(N);


	return 0;
}