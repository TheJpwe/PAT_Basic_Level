#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void earthToMars(char *st);

void marsToEarth(char *st);

char *eTom(char *s, int digts, int isTens);

int mToe(char *s, int isTens);

int isSameS(const char *s1, const char *s2);

int main()
{
	int N;
	scanf("%d", &N);

	char *st;
	st = (char *)malloc(10 * sizeof(char));

	char *cur;
	cur = st;

	getchar();

	for (int i = 0; i < N; i++)
	{
		//gets_s(st, 10);
		fgets(st, 15, stdin);
		char *tmp;
		tmp = st;
		while (*tmp != '\n')
		{
			tmp++;
		}

		*tmp = '\0';


		if (*cur >= '0' && *cur <= '9')
		{
			earthToMars(st);
		}
		else
		{
			marsToEarth(st);
		}

	}


	free(st);
	return 0;
}

void earthToMars(char *st)
{
	int s;
	s = atoi(st);
	int tens, units;
	tens = s / 13;
	units = s - tens * 13;


	st = '\0';

	if (tens)
	{
		st = eTom(st, tens, 1);
		printf("%s ", st);
	}
	
	st = eTom(st, units, 0);
	printf("%s", st);

}

void marsToEarth(char *st)
{
	char *tmps;
	tmps = (char *)malloc(5 * sizeof(char));

	char *curSt, *curTmps;
	curSt = st;
	curTmps = tmps;

	while (*curSt != ' ' && *curSt != '\0')
	{
		*(curTmps++) = *(curSt++);

	}

	*curTmps = '\0';


	int tens = 0, units = 0;

	if (*curSt != '\0')
	{
		tens = mToe(tmps, 1);

		curTmps = tmps;
		curSt++;
		while (*curSt != '\0')
		{
			*(curTmps++) = *(curSt++);

		}
		*curTmps = '\0';
		units = mToe(tmps, 0);

		

	}
	else
	{
		units = mToe(tmps, 0);
	}


	printf("%d", tens * 13 + units);



	free(tmps);
}


char *eTom(char *s, int digts, int isTens)
{
	if (isTens)
	{
		switch (digts)
		{
		case 1:
			s = "tam";
			break;
		case 2:
			s = "hel";
			break;
		case 3:
			s = "maa";
			break;
		case 4:
			s = "huh";
			break;
		case 5:
			s = "tou";
			break;
		case 6:
			s = "kes";
			break;
		case 7:
			s = "hei";
			break;
		case 8:
			s = "elo";
			break;
		case 9:
			s = "syy";
			break;
		case 10:
			s = "lok";
			break;
		case 11:
			s = "mer";
			break;
		case 12:
			s = "jou";
			break;
		default:
			break;
		}
	}
	else
	{
		switch (digts)
		{
		case 0:
			s = "tret";
			break;
		case 1:
			s = "jan";
			break;
		case 2:
			s = "feb";
			break;
		case 3:
			s = "mar";
			break;
		case 4:
			s = "apr";
			break;
		case 5:
			s = "may";
			break;
		case 6:
			s = "jun";
			break;
		case 7:
			s = "jly";
			break;
		case 8:
			s = "aug";
			break;
		case 9:
			s = "sep";
			break;
		case 10:
			s = "oct";
			break;
		case 11:
			s = "nov";
			break;
		case 12:
			s = "dec";
			break;
		default:
			break;
		}
	}


	return s;


}

int mToe(char *s, int isTens)
{
	char *tmp;
	tmp = (char *)malloc(5 * sizeof(char));

	if (isTens)
	{
		for (int i = 1; i < 13; i++)
		{
			if (isSameS(s, eTom(tmp, i, 1)))
			{
				return i;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < 13; i++)
		{
			if (isSameS(s, eTom(tmp, i, 0)))
			{
				return i;
				break;
			}
		}
	}



	free(tmp);

}

int isSameS(const char *s1, const char *s2)
{
	const char *cur1, *cur2;
	cur1 = s1;
	cur2 = s2;

	while (*cur1 != '\0')
	{
		if (*cur1 != *cur2)
		{
			break;
		}
		cur1++;
		cur2++;
	}

	if (*cur1 != '\0')
	{
		return 0;
	}
	else
	{
		return 1;
	}




}