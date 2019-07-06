#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct jilu
{
	int alljilu[3];	//总的胜平负记录
	int Bjilu[3];	//出布的时候胜平负的记录
	int Cjilu[3];	//出锤子的时候胜平负的记录
	int Jjilu[3];	//出剪刀的时候胜平负的记录
};
typedef struct jilu JL;

int jieguo(char jiashou, char yishou);	//jiashou胜利则结果返回1，平则返回0，负则返回-1

int main()
{
	JL jia, yi;

	for (int i = 0; i < 3; i++)
	{
		jia.alljilu[i] = 0;
		jia.Bjilu[i] = 0;
		jia.Cjilu[i] = 0;
		jia.Jjilu[i] = 0;

		yi.alljilu[i] = 0;
		yi.Bjilu[i] = 0;
		yi.Cjilu[i] = 0;
		yi.Jjilu[i] = 0;
	}

	int N;
	char jiaShou, yiShou;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf(" %c %c", &jiaShou, &yiShou);
		switch (jiaShou)
		{
		case 'B':
			switch ( jieguo(jiaShou, yiShou) )
			{
			case -1:
				jia.Bjilu[2]++;
				jia.alljilu[2]++;

				yi.alljilu[0]++;
				yi.Jjilu[0]++;
				break;
			case 0:
				jia.alljilu[1]++;
				jia.Bjilu[1]++;

				yi.alljilu[1]++;
				yi.Bjilu[1]++;
				break;
			case 1:
				jia.alljilu[0]++;
				jia.Bjilu[0]++;

				yi.alljilu[2]++;
				yi.Cjilu[2]++;
				break;
			}
			break;
		case 'C':
			switch (jieguo(jiaShou, yiShou))
			{
			case -1:
				jia.Cjilu[2]++;
				jia.alljilu[2]++;

				yi.alljilu[0]++;
				yi.Bjilu[0]++;
				break;
			case 0:
				jia.alljilu[1]++;
				jia.Cjilu[1]++;

				yi.alljilu[1]++;
				yi.Cjilu[1]++;
				break;
			case 1:
				jia.alljilu[0]++;
				jia.Cjilu[0]++;

				yi.alljilu[2]++;
				yi.Jjilu[2]++;
				break;
			}
			break;
		case 'J':
			switch (jieguo(jiaShou, yiShou))
			{
			case -1:
				jia.Jjilu[2]++;
				jia.alljilu[2]++;

				yi.alljilu[0]++;
				yi.Cjilu[0]++;
				break;
			case 0:
				jia.alljilu[1]++;
				jia.Jjilu[1]++;

				yi.alljilu[1]++;
				yi.Jjilu[1]++;
				break;
			case 1:
				jia.alljilu[0]++;
				jia.Jjilu[0]++;

				yi.alljilu[2]++;
				yi.Bjilu[2]++;
				break;
			}
			break;
		default:
			break;
		}

	}

	printf("%d %d %d\n", jia.alljilu[0], jia.alljilu[1], jia.alljilu[2]);
	printf("%d %d %d\n", yi.alljilu[0], yi.alljilu[1], yi.alljilu[2]);

	if (jia.Bjilu[0] >= jia.Cjilu[0])
	{
		if (jia.Bjilu[0] >= jia.Jjilu[0])
		{
			printf("B ");
		}
		else
		{
			printf("J ");
		}
	
	}
	else
	{
		if (jia.Cjilu[0] >= jia.Jjilu[0])
		{
			printf("C ");
		}
		else
		{
			printf("J ");
		}
	}


	if (yi.Bjilu[0] >= yi.Cjilu[0])
	{
		if (yi.Bjilu[0] >= yi.Jjilu[0])
		{
			printf("B");
		}
		else
		{
			printf("J");
		}

	}
	else
	{
		if (yi.Cjilu[0] >= yi.Jjilu[0])
		{
			printf("C");
		}
		else
		{
			printf("J");
		}
	}


	return 0;
}

int jieguo(char jiashou, char yishou)
{
	switch (jiashou)
	{
	case 'B':
		if (yishou=='B')
		{
			return 0;
		}
		else if (yishou=='C')
		{
			return 1;
		}
		else
		{
			return -1;
		}
		break;
	case 'C':
		if (yishou == 'B')
		{
			return -1;
		}
		else if (yishou == 'C')
		{
			return 0;
		}
		else
		{
			return 1;
		}
		break;
	case 'J':
		if (yishou == 'B')
		{
			return 1;
		}
		else if (yishou == 'C')
		{
			return -1;
		}
		else
		{
			return 0;
		}
		break;
	default:
		return 2;
		break;
	}

}