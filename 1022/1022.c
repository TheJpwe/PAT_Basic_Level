#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int A, B;
	int D;

	scanf("%u %u %d", &A, &B, &D);

	unsigned int sum;
	sum = A + B;

	char *result, *cur;
	int length = sizeof(char);

	result = (char *)malloc(sizeof(char));
	*result = '\0';

	while (sum > 0)
	{
		length += sizeof(char);
		result = realloc(result, length);

		cur = result;
		while (*cur != '\0')
		{
			cur++;
		}

		*cur = sum % D + 48;
		*(++cur) = '\0';

		sum /= D;

	}

	if (length==1)
	{
		printf("0");
	}
	else
	{
		for (int i = length-1; i > 0; i--)
		{
			printf("%c", *(--cur));
		}
	}
	

	free(result);

	return 0;
}