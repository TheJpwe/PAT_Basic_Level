#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *sellBall, *wantBall;
	sellBall = (char *)malloc(1001 * sizeof(char));
	wantBall = (char *)malloc(1001 * sizeof(char));

	int *sellFlag, *wantFlag;
	sellFlag = (int *)malloc(1001 * sizeof(int));
	wantFlag = (int *)malloc(1001 * sizeof(int));

	for (int i = 0; i < 1001; i++)
	{
		sellFlag[i] = 1;
		wantFlag[i] = 0;
	}

	scanf("%s %s", sellBall, wantBall);

	//printf("%s\n%s", sellBall, wantBall);

	char *curSell, *curWant;
	int	*curSellFlag, *curWantFlag;
	curSell = sellBall;
	curWant = wantBall;
	curSellFlag = sellFlag;
	curWantFlag = wantFlag;

	while (*curWant != '\0')
	{
		
		curSell = sellBall;
		curSellFlag = sellFlag;

		while (*curSell != '\0')
		{
			
			if (*curSellFlag)
			{
				if (*curSell == *curWant)
				{
					*curSellFlag = 0;
					*curWantFlag = 1;
					break;
				}
			}
			
			curSell++;
			curSellFlag++;

		}

		curWant++;
		curWantFlag++;

	}

	curWant = wantBall;
	curWantFlag = wantFlag;

	int cnt = 0;
	while (*curWant != '\0')
	{
		if (*curWantFlag == 0)
		{
			cnt++;
		}

		curWant++;
		curWantFlag++;

	}

	curSell = sellBall;
	curSellFlag = sellFlag;


	if (!cnt)
	{
		cnt = 0;
		while (*curSell != '\0')
		{
			if (*curSellFlag)
			{
				cnt++;
			}

			curSell++;
			curSellFlag++;
		}

		printf("Yes %d", cnt);

	}
	else
	{
		printf("No %d", cnt);
	}






	free(sellBall);
	free(wantBall);
	free(sellFlag);
	free(wantFlag);
	return 0;
}