#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
	char name[6];
	char bornday[11];
	int flag;
};

int year(char *bornday);
int month(char *bornday);
int day(char *bornday);
int isavailable(char *bornday, char *today);
int compare(char *bornday1, char *bornday2);	//b1比b2年长则返回1，否则返回0

int main()
{
	int N;
	scanf("%d", &N);
	struct person *people;
	people = (struct person *)malloc(N * sizeof(struct person));

	char today[11] = "2014/09/06";

	for (int i = 0; i < N; i++)
	{

		scanf("%s %s", people[i].name, people[i].bornday);
		people[i].flag = isavailable(people[i].bornday, today);

	}

	int i, cnt = 0;
	int old = -1, new = -1;
	for ( i = 0; i < N; i++)
	{
		if (people[i].flag)
		{
			cnt++;
			if (old < 0)
			{
				old = i;
			}
			else if (new < 0)
			{
				if (compare(people[i].bornday, people[old].bornday))
				{
					new = old;
					old = i;
				}
				else
				{
					new = i;
				}

			}
			else
			{
				if (compare(people[i].bornday, people[old].bornday))
				{
					old = i;
				}
				else if (compare(people[new].bornday, people[i].bornday))
				{
					new = i;
				}
			}
		}
	}




	printf("%d %s %s", cnt, people[old].name, people[new].name);

	free(people);

	return 0;
}

int year(char *bornday)
{
	char *tmp, *y, *cur;
	y = (char *)malloc(5 * sizeof(char));
	tmp = bornday;
	cur = y;
	while (*tmp != '/')
	{
		*(cur++) = *(tmp++);
	}
	*cur = '\0';

	int yyyy = atoi(y);

	free(y);

	return yyyy;

}

int month(char *bornday)
{
	char *tmp, *m, *cur;
	m = (char *)malloc(3 * sizeof(char));
	tmp = bornday;
	tmp += 5;
	cur = m;
	while (*tmp != '/')
	{
		*(cur++) = *(tmp++);
	}
	*cur = '\0';

	int mm = atoi(m);

	free(m);
	return mm;

}

int day(char *bornday)
{
	char *tmp, *d, *cur;
	d = (char *)malloc(3 * sizeof(char));
	tmp = bornday;
	tmp += 8;
	cur = d;
	while (*tmp != '\0')
	{
		*(cur++) = *(tmp++);
	}
	*cur = '\0';

	int dd = atoi(d);

	free(d);
	return dd;

}

int isavailable(char *bornday, char *today)
{
	int byear = year(bornday);
	int tyear = year(today);
	int bmonth = month(bornday);
	int tmonth = month(today);
	int bday = day(bornday);
	int tday = day(today);

	if (byear > tyear)
	{
		return 0;
	}
	else if (byear == tyear)
	{
		if (bmonth > tmonth)
		{
			return 0;
		}
		else if (bmonth == tmonth)
		{
			if (bday > tday)
			{
				return 0;
			}
		}
	}
	else if (byear < tyear-200)
	{
		return 0;
	}
	else if (byear == tyear-200)
	{
		if (bmonth < tmonth)
		{
			return 0;
		}
		else if (bmonth == tmonth)
		{
			if (bday < tday)
			{
				return 0;
			}
		}
	}

	return 1;

}

int compare(char *bornday1, char *bornday2)
{
	int b1year = year(bornday1);
	int b2year = year(bornday2);
	int b1month = month(bornday1);
	int b2month = month(bornday2);
	int b1day = day(bornday1);
	int b2day = day(bornday2);

	if (b1year < b2year)
	{
		return 1;
	}
	else if (b1year == b2year)
	{
		if (b1month < b2month)
		{
			return 1;
		}
		else if (b1month == b2month)
		{
			if (b1day < b2day)
			{
				return 1;
			}
		}
	}

	return 0;

}