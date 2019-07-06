#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct data
{
	char sign;
	int intpart;
	int numerator;
	int denominator;
	int Infflag;
	
};
typedef struct data rational;

void showRational(const rational r);

int LCM(int a, int b);	//a和b的最小公倍数

int GCD(int a, int b);	//a和b的最大公约数

rational sToRational(const char *s);

rational sumR(rational r1, rational r2);

rational diffR(rational r1, rational r2);

rational productR(rational r1, rational r2);

rational quotientR(rational r1, rational r2);

int main()
{
	char *s1, *s2;
	s1 = (char *)malloc(15 * sizeof(char));
	s2 = (char *)malloc(15 * sizeof(char));

	scanf("%s %s", s1, s2);

	//printf("%s\n%s", s1, s2);

	rational r1, r2;

	r1 = sToRational(s1);
	r2 = sToRational(s2);

	showRational(r1);
	printf(" + ");
	showRational(r2);
	printf(" = ");
	showRational(sumR(r1, r2));
	printf("\n");

	showRational(r1);
	printf(" - ");
	showRational(r2);
	printf(" = ");
	showRational(diffR(r1, r2));
	printf("\n");

	showRational(r1);
	printf(" * ");
	showRational(r2);
	printf(" = ");
	showRational(productR(r1, r2));
	printf("\n");

	showRational(r1);
	printf(" / ");
	showRational(r2);
	printf(" = ");
	showRational(quotientR(r1, r2));
	printf("\n");

	

	free(s1);
	free(s2);
	return 0;
}

rational sToRational(const char *s)
{
	rational result;
	const char *tmps;
	char *tmp, *curtmp;
	tmps = s;
	tmp = (char *)malloc(15 * sizeof(char));
	curtmp = tmp;

	while (*tmps != '/')
	{
		*(curtmp++) = *(tmps++);
	}
	*curtmp = '\0';

	result.numerator = atoi(tmp);
	if (result.numerator < 0)
	{
		result.sign = '-';
		result.numerator *= -1;
	}
	else
	{
		result.sign = '+';
	}

	curtmp = tmp;
	tmps++;

	while (*tmps != '\0')
	{
		*(curtmp++) = *(tmps++);
	}
	*curtmp = '\0';

	result.denominator = atoi(tmp);

	result.intpart = result.numerator / result.denominator;
	
	result.numerator -= result.intpart * result.denominator;
	

	if (result.numerator == 0)
	{
		result.denominator = 1;
	}


	result.Infflag = 0;


	free(tmp);
	return result;
}

void showRational(const rational r)
{
	if (r.Infflag == 1)
	{
		printf("Inf");
	}
	else if(r.numerator == 0 && r.intpart == 0)
	{
		printf("0");
	}
	else
	{
		if (r.sign == '-')
		{
			if (r.intpart > 0)
			{
				if (r.numerator > 0)
				{
					printf("(-%d %d/%d)", r.intpart, r.numerator, r.denominator);
				}
				else
				{
					printf("(-%d)", r.intpart);
				}
				
			}
			else
			{
				printf("(-%d/%d)", r.numerator, r.denominator);
			}
		}
		else
		{
			if (r.intpart > 0)
			{
				if (r.numerator > 0)
				{
					printf("%d %d/%d", r.intpart, r.numerator, r.denominator);
				}
				else
				{
					printf("%d", r.intpart);
				}

			}
			else
			{
				printf("%d/%d", r.numerator, r.denominator);
			}
		}
	}


}

int LCM(int a, int b)
{
	int result;
	int max, min;
	if (a >= b)
	{
		max = a;
		min = b;
	}
	else
	{
		max = b;
		min = a;
	}

	while (max % min)
	{
		max += max;
	}

	result = max;

	return result;

}

int GCD(int a, int b)
{
	int min = a > b ? b : a;
	int result = 1;

	for (int i = 2; i <= min; i++)
	{
		if (a%i==0 && b%i==0)
		{
			result = i;
		}
	}

	return result;

}

rational sumR(rational r1, rational r2)
{
	rational result;
	if (r1.sign == r2.sign)
	{
		result.sign = r1.sign;
		result.intpart = r1.intpart + r2.intpart;

		result.denominator = LCM(r1.denominator, r2.denominator);
		r1.numerator *= result.denominator / r1.denominator;
		r2.numerator *= result.denominator / r2.denominator;

		result.numerator = r1.numerator + r2.numerator;
		
		while (result.numerator > result.denominator)
		{
			result.intpart++;
			result.numerator -= result.denominator;
		}

	}
	else if (r1.sign == '+' && r2.sign == '-')
	{
		r2.sign = '+';
		result = diffR(r1, r2);
	}
	else
	{
		r1.sign = '+';
		result = diffR(r2, r1);
	}

	result.Infflag = 0;

	return result;
	
}

rational diffR(rational r1, rational r2)
{
	rational result;
	if (r1.sign == r2.sign)
	{
		result.sign = r1.sign;
		r1.numerator += r1.intpart * r1.denominator;
		r1.intpart = 0;
		
		r2.numerator += r2.intpart * r2.denominator;
		r2.intpart = 0;

		result.denominator = LCM(r1.denominator, r2.denominator);

		r1.numerator *= result.denominator / r1.denominator;
		r2.numerator *= result.denominator / r2.denominator;

		result.numerator = r1.numerator - r2.numerator;

		if (result.numerator < 0)
		{
			if (result.sign == '+')
			{
				result.sign = '-';
			}
			else
			{
				result.sign = '+';
			}

			result.numerator *= -1;
		}

		result.intpart = result.numerator / result.denominator;
		result.numerator -= result.intpart * result.denominator;


	}
	else if (r1.sign == '+' && r2.sign == '-')
	{
		r2.sign = '+';
		result = sumR(r1, r2);
	}
	else
	{
		r2.sign = '-';
		result = sumR(r1, r2);
	}

	result.Infflag = 0;

	return result;


}

rational productR(rational r1, rational r2)
{
	rational result;
	int tmp;

	if (r1.sign == r2.sign)
	{
		result.sign = '+';
	}
	else
	{
		result.sign = '-';
	}

	r1.numerator += r1.intpart * r1.denominator;
	r1.intpart = 0;

	r2.numerator += r2.intpart * r2.denominator;
	r2.intpart = 0;

	result.denominator = r1.denominator * r2.denominator;
	result.numerator = r1.numerator * r2.numerator;

	result.intpart = result.numerator / result.denominator;
	result.numerator -= result.intpart * result.denominator;

	result.Infflag = 0;

	tmp = GCD(result.numerator, result.denominator);

	if (tmp != 1)
	{
		result.numerator /= tmp;
		result.denominator /= tmp;
	}

	return result;
}

rational quotientR(rational r1, rational r2)
{
	rational result;
	int tmp;
	if (r2.intpart==0 && r2.numerator==0)
	{
		result.Infflag = 1;
	}
	else
	{
		r2.numerator += r2.intpart * r2.denominator;
		r2.intpart = 0;

		tmp = r2.numerator;
		r2.numerator = r2.denominator;
		r2.denominator = tmp;

		r2.intpart = r2.numerator / r2.denominator;
		r2.numerator -= r2.intpart * r2.denominator;

		result = productR(r1, r2);

	}

	return result;

}