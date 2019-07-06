#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *pat;
	pat = (char *)malloc(100001 * sizeof(char));

	scanf("%s", pat);

	char *t;
	//char *a;
	//char *p;
	t = pat;
	//a = pat;
	//p = pat;

	long long cnt = 0;
	long long sumP = 0, sumPat = 0, sumAp = 0;


	while (*t != '\0')
	{
		switch (*t)
		{
		case 'P':
			sumP++;
			break;
		case 'A':
			sumAp += sumP;
			break;
		case 'T':
			sumPat += sumAp;
			break;
			
		default:
			printf("ERRPR1\n");
			break;
		}
		
		t++;
	}



	//for ( t = pat; *t != '\0'; t++)
	//{
	//	if (*t == 'T')
	//	{
	//		for ( a = pat; a != t; a++)
	//		{
	//			if (*a == 'A')
	//			{
	//				for ( p = pat; p != a; p++)
	//				{
	//					if (*p == 'P')
	//					{
	//						cnt++;
	//					}
	//				}
	//			}
	//		}
	//	}
	//	
	//}

	printf("%lld", sumPat % 1000000007);

	free(pat);

	return 0;
}