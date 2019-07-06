#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


typedef struct Lnode *PtrToLnode;
typedef struct Lnode LNode;
struct Lnode
{
	int localadd;
	int data;
	int nextadd;
	PtrToLnode nextPtr;
};
typedef PtrToLnode List;


void freememory(List head);
List Reverse(List head, int K);

int main()
{
	LNode *arr;
	int firstadd;
	int N, K;
	scanf("%d %d %d", &firstadd, &N, &K);
	
	arr = (LNode *)malloc(N * sizeof(LNode));

	for (int  i = 0; i < N; i++)
	{
		scanf("%d %d %d", &arr[i].localadd, &arr[i].data, &arr[i].nextadd);
		arr[i].nextPtr = NULL;
	}

	/*for (int i = 0; i < N; i++)
	{
		printf("%d %d %d\n", arr[i].localadd, arr[i].data, arr[i].nextadd);
	}*/

	List Head;
	Head = (List)malloc(sizeof(LNode));
	Head->nextadd = firstadd;

	PtrToLnode curL;
	curL = Head;
	PtrToLnode tmpL;

	int n = 0;	//记录链表中一共有多少个结点（不包含空的头结点）

	while (curL->nextadd != -1)
	{
		n++;
		int i = 0;
		for (; i < N; i++)
		{
			if (arr[i].localadd == curL->nextadd)
			{
				break;
			}
		}

		
		tmpL = (List)malloc(sizeof(LNode));

		tmpL->localadd = arr[i].localadd;
		tmpL->data = arr[i].data;
		tmpL->nextadd = arr[i].nextadd;
		tmpL->nextPtr = NULL;

		curL->nextPtr = tmpL;
		curL = curL->nextPtr;

		tmpL = NULL;

	}

	//curL = Head->nextPtr;
	//while (curL)
	//{
	//	if (curL->nextadd >= 0)
	//	{
	//		printf("%05d %d %05d\n", curL->localadd, curL->data, curL->nextadd);
	//	}
	//	else
	//	{
	//		printf("%05d %d %d\n", curL->localadd, curL->data, curL->nextadd);
	//	}
	//	
	//	curL = curL->nextPtr;
	//}

	//int k;	//表示翻转到第几个循环结点

	//List preL, nextL, HL;
	//curL = Head;
	//preL = curL;
	//curL = curL->nextPtr;

	//if (curL)
	//{
	//	nextL = curL->nextPtr;
	//}
	//
	//int flag = 1;
	//while (n >= K)
	//{
	//	k = 1;
	//	while (k <= K)
	//	{
	//		if (k == 1)
	//		{
	//			HL = curL;
	//			curL->nextPtr = NULL;	//反转当前结点的指向
	//			curL->nextadd = -1;
	//		}
	//		else
	//		{
	//			curL->nextPtr = preL;	//反转当前结点的指向
	//			curL->nextadd = preL->localadd;
	//		}
	//		
	//		if (k == K)
	//		{
	//			HL->nextPtr = nextL;
	//			HL->nextadd = nextL->localadd;
	//			if (flag == K)
	//			{
	//				Head->nextPtr = curL;
	//				Head->nextadd = curL->localadd;
	//			}
	//		}

	//		preL = curL;
	//		curL = nextL;
	//		if (curL)
	//		{
	//			nextL = curL->nextPtr;
	//		}
	//
	//		k++;
	//		n--;
	//		flag++;
	//	}
	//}

	Head->nextPtr = Reverse(Head, K);
	n -= K;
	curL = Head->nextPtr;
	while (n>K)
	{
		for (int i = 1; i < K; i++)
		{
			curL = curL->nextPtr;
		}
		curL = Reverse(curL, K);
		n -= K;
	}


	curL = Head->nextPtr;
	while (curL)
	{
		if (curL->nextadd >= 0)
		{
			printf("%05d %d %05d\n", curL->localadd, curL->data, curL->nextadd);
		}
		else
		{
			printf("%05d %d %d\n", curL->localadd, curL->data, curL->nextadd);
		}

		curL = curL->nextPtr;
	}




	
	freememory(Head);
	free(arr);
	return 0;
}

void freememory(List head)
{
	if(head->nextPtr != NULL)
	{
		freememory(head->nextPtr);
	}
	free(head);
}

List Reverse(List head, int K)
{

	int cnt = 1;
	List new = head->nextPtr;
	List old = new->nextPtr;
	List tmp;

	while (cnt < K)
	{
		tmp = old->nextPtr;
		old->nextPtr = new;
		new = old;
		old = tmp;
		cnt++;
	}

	head->nextPtr->nextPtr = old;
	return new;

}