#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


struct mooncake
{
	double stock;	//¿â´æ
	double totalprice;
	double unitprice;

};
typedef struct mooncake cake;
typedef cake *pCake;

void swapCake(pCake c1, pCake c2);

int main()
{
	int N, D;
	scanf("%d %d", &N, &D);

	pCake *total;
	total = (pCake *)malloc(N * sizeof(pCake));

	for (int i = 0; i < N; i++)
	{
		total[i] = (pCake)malloc(sizeof(cake));
		scanf("%lf", &(total[i]->stock));
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &(total[i]->totalprice));
		total[i]->unitprice = total[i]->totalprice * 1.0 / total[i]->stock;
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if (total[i]->unitprice < total[j]->unitprice)
			{
				swapCake(total[i], total[j]);
			}
			
		}
		
	}

	double gain = 0.0;

	for (int i = 0; i < N; i++)
	{
		if (D > 0 && D >= total[i]->stock)
		{
			D -= total[i]->stock;
			gain += total[i]->totalprice;
		}
		else if (D>0)
		{
			gain += total[i]->unitprice *D;
			D = 0;
			break;
		}
		else
		{
			break;
		}
		
	}

	printf("%.2f", gain);


	for (int i = 0; i < N; i++)
	{
		free(total[i]);
	}

	free(total);


	return 0;
}

void swapCake(pCake c1, pCake c2)
{
	pCake t;
	t = (pCake)malloc(sizeof(cake));

	t->stock = c1->stock;
	t->totalprice = c1->totalprice;
	t->unitprice = c1->unitprice;

	c1->stock = c2->stock;
	c1->totalprice = c2->totalprice;
	c1->unitprice = c2->unitprice;

	c2->stock = t->stock;
	c2->totalprice = t->totalprice;
	c2->unitprice = t->unitprice;

	free(t);
}
