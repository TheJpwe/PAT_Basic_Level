#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


typedef struct faceNode *face;
struct faceNode
{
	char *data;
	int size;

};

	struct faceNode hand[10], eye[10], mouth[10];
	int handcnt = 0, eyecnt = 0, mouthcnt = 0;
	//hand = (face)malloc(10 * sizeof(struct faceNode));
	//eye = (face)malloc(10 * sizeof(struct faceNode));
	//mouth = (face)malloc(10 * sizeof(struct faceNode));


void SaveChar(face f);
void PickChar(face f, int *cnt);
void ShowFace(int *A);
void ShowFaceChar(face f, int index);



int main()
{


	for (int i = 0; i < 10; i++)
	{
		hand[i].data = 0;
		hand[i].size = 0;

		eye[i].data = 0;
		eye[i].size = 0;

		mouth[i].data = 0;
		mouth[i].size = 0;
	}

	PickChar(hand, &handcnt);
	PickChar(eye, &eyecnt);
	PickChar(mouth, &mouthcnt);

	int N;
	scanf("%d", &N);
	int A[5];
	for (int i = 0; i < N; i++)
	{
		int flag = 0;
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &A[j]);
			switch (j)
			{
			case 0:
				if (A[j] > handcnt)
				{
					flag = 1;
				}
				break;
			case 1:
				if (A[j] > eyecnt)
				{
					flag = 1;
				}
				break;
			case 2:
				if (A[j] > mouthcnt)
				{
					flag = 1;
				}
				break;
			case 3:
				if (A[j] > eyecnt)
				{
					flag = 1;
				}
				break;
			case 4:
				if (A[j] > handcnt)
				{
					flag = 1;
				}
				break;
			default:
				break;
			}
		}

		if (flag)
		{
			printf("Are you kidding me? @\\/@");
			if (i != N-1)
			{
				printf("\n");
			}
		}
		else
		{
			ShowFace(A);
			if (i != N - 1)
			{
				printf("\n");
			}
		}
		
	}


	for (int i = 0; i < 10; i++)
	{
		free(hand[i].data);
		free(eye[i].data);
		free(mouth[i].data);
	}
	return 0;
}

void SaveChar(face f)
{
	char tmp;
	tmp = getchar();
	
	while (tmp != ']')
	{
		f->data = (char *)realloc(f->data, (f->size + 1) * sizeof(char));
		f->data[f->size++] = tmp;
		tmp = getchar();
	}
}

void PickChar(face f, int *cnt)
{
	char tmp;
	do
	{
		tmp = getchar();
		if (tmp == '[')
		{
			SaveChar(&f[(*cnt)++]);

		}

	} while (tmp != '\n');
}


void ShowFace(int *A)
{
	ShowFaceChar(hand, A[0]-1);
	printf("(");
	ShowFaceChar(eye, A[1] - 1);
	ShowFaceChar(mouth, A[2] - 1);
	ShowFaceChar(eye, A[3] - 1);
	printf(")");
	ShowFaceChar(hand, A[4] - 1);
}

void ShowFaceChar(face f, int index)
{
	for (int i = 0; i < f[index].size; i++)
	{
		printf("%c", f[index].data[i]);
	}
}