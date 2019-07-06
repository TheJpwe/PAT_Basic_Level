#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
	char *A, *cur;
	int length = sizeof(char);
	A = (char *)malloc(length);
	*A = '\0';

	while (true)
	{
		length += sizeof(char);
		A = (char *)realloc(A, length);
		cur = A;

		while (*cur != '\0')
		{
			cur++ ;
		}

		scanf("%c", cur);
		if (*cur == '\n')
		{
			*cur = '\0';
			break;
		}
		else
		{
			*(++cur) = '\0';
		}
		
	}
	
	//printf("%s\n", A);

	char *intA, *expStart;	//分别指向A的整数部分第一个字符和指数部分的第一个字符
	intA = A;
	expStart = A;
	while (*expStart != 'E')
	{
		expStart++;
	}
	expStart++;

	int exp = 0;	//表示指数部分的绝对值
	char *exps, *expA, *tmpexps;
	exps = (char *)malloc(5 * sizeof(char));
	expA = expStart;
	tmpexps = exps;

	while (*expA != '\0')
	{
		*(tmpexps++) = *(expA++);
	}

	*tmpexps = '\0';

	exp = atoi(exps);

	exp = exp >= 0 ? exp : -exp;

	char *result, *curResult;
	result = (char *)malloc(10000 * sizeof(char));
	curResult = result;

	if (exp == 0)
	{
		if (*intA == '+')
		{
			intA++;
		}

		while (*intA != 'E')
		{
			*(curResult++) = *(intA++);
		}

		*curResult = '\0';
	}
	else
	{
		if (*expStart == '-')
		{
			if (*(intA++) == '-')
			{
				*(curResult++) = '-';
			}
			*(curResult++) = '0';
			*(curResult++) = '.';

			while ((exp-1) > 0)
			{
				*(curResult++) = '0';
				exp--;
			}

			while (*intA != 'E')
			{
				if (*intA != '.')
				{
					*(curResult++) = *(intA++);
				}
				else
				{
					intA++;
				}
				
			}

			*curResult = '\0';
		}
		else
		{
			if (*intA == '-')
			{
				*(curResult++) = *(intA++);
			}
			else
			{
				intA++;
			}
			*(curResult++) = *(intA++);
			while (exp-- > 0)
			{
				if (*(intA + 1) != 'E')
				{
					*intA = *(intA + 1);
					*(curResult++) = *intA;
					*(++intA) = '.';
					
				}
				else
				{
					*(curResult++) = '0';
				}
			}
			if (*(intA+1)!='E')
			{
				while (*(intA) != 'E')
				{
					*(curResult++) = *(intA++);
				}
			}
			

			*curResult = '\0';
		}
	}


	printf("%s", result);

	free(A);
	free(exps);
	free(result);
	return 0;
}