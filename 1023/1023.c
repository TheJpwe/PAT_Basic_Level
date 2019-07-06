#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int A[10], length = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &A[i]);
		length += A[i];
	}

	char *result, *cur;
	int curlength;
	curlength = length;

	result = (char *)malloc((length + 1) * sizeof(char));
	cur = result;
	
	while (curlength > 0)
	{
		if (curlength == length)
		{
			for (int i = 1; i < 10; i++)
			{
				if (A[i] > 0)
				{
					*(cur++) = i + 48;
					A[i]--;
					curlength--;
					break;
				}
			}
		}
		else
		{
			for (int i = 0; i < 10; i++)
			{
				if (A[i] > 0)
				{
					*(cur++) = i + 48;
					A[i]--;
					curlength--;
					break;
				}
			}
		}
	}

	*cur = '\0';

	printf("%s", result);

	free(result);

	return 0;
}