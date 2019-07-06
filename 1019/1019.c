#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *incressSort(char *strn);	//非递减排序
char *decressSort(char *strn);	//非递增排序

int main()
{
	char *strN, *ptrN;
	strN = (char *)malloc(5 * sizeof(char));
	

	int N;
	char *incrstrN, *decrstrN;
	int chazhi;

	incrstrN = (char *)malloc(5 * sizeof(char));
	decrstrN = (char *)malloc(5 * sizeof(char));

	scanf("%d", &N);
	while (N != -1)
	{


		strN[4] = '\0';
		for (int i = 3; i >= 0; i--)
		{
			strN[i] = N % 10 + 48;
			N = N / 10;
		}
		ptrN = strN;
		char temp = *ptrN;
		int isSame = 1;	//为1表示四位整数各位置上的数字都相等
		while (*ptrN != '\0')
		{
			if (temp != *ptrN)
			{
				isSame = 0;
				break;
			}
			ptrN++;
		}

		

		if (isSame)
		{
			printf("%s - %s = 0000", strN, strN);
		}
		else
		{
			do
			{
				incressSort(strN);
				for (int i = 0; i < 5; i++)
				{
					incrstrN[i] = strN[i];
				}
				decressSort(strN);
				for (int i = 0; i < 5; i++)
				{
					decrstrN[i] = strN[i];
				}

				chazhi = atoi(decrstrN) - atoi(incrstrN);


				printf("%s - %s = %04d\n", decrstrN, incrstrN, chazhi);


				int tchazhi = chazhi;
				for (int i = 3; i >= 0; i--)
				{
					strN[i] = tchazhi % 10 + 48;
					tchazhi = tchazhi / 10;
				}

			} while (chazhi != 6174);
		}

		scanf("%d", &N);

	}

	free(strN);
	free(incrstrN);
	free(decrstrN);
	return 0;
}

char *incressSort(char *strn)
{
	char *ptrn;
	ptrn = strn;
	char temp;

	for (; *ptrn != '\0'; ptrn++)
	{
		for (char *ptrn2 = ptrn; *ptrn2 != '\0'; ptrn2++)
		{
			if (*ptrn > *ptrn2)
			{
				temp = *ptrn;
				*ptrn = *ptrn2;
				*ptrn2 = temp;
			}
		}
	}

	return strn;
}

char *decressSort(char *strn)
{
	char *ptrn;
	ptrn = strn;
	char temp;

	for (; *ptrn != '\0'; ptrn++)
	{
		for (char *ptrn2 = ptrn; *ptrn2 != '\0'; ptrn2++)
		{
			if (*ptrn < *ptrn2)
			{
				temp = *ptrn;
				*ptrn = *ptrn2;
				*ptrn2 = temp;
			}
		}
	}

	return strn;
}