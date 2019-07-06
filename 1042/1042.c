#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct set
{
	char s[1];
	int cnt;
};

int main()
{
	char ch[1];
	struct set *A;
	A = (struct set *)malloc(1001 * sizeof(struct set));
	for (int i = 0; i < 1001; i++)
	{
		A[i].cnt = 0;
	}
	int cur, end = 0;
	int maxcnt = 0, maxi=0;

	scanf("%c", ch);
	while (*ch != '\n')
	{
		if (*ch >= 'A' && *ch <= 'Z')
		{
			*ch += 32;
		}

		if (*ch >= 'a' && *ch <= 'z')
		{


			cur = 0;
			while (cur != end)
			{
				if (A[cur].s[0] == *ch)
				{
					A[cur].cnt++;
					if (A[cur].cnt > maxcnt)
					{
						maxcnt = A[cur].cnt;
						maxi = cur;
					}
					else if (A[cur].cnt == maxcnt)
					{
						if (A[cur].s[0] < A[maxi].s[0])
						{
							maxi = cur;
						}
					}
					break;
				}
				
				cur++;

			}

			if (cur == end)
			{
				A[cur].s[0] = *ch;
				A[cur].cnt++;
				if (A[cur].cnt > maxcnt)
				{
					maxcnt = A[cur].cnt;
					maxi = cur;
				}
				else if (A[cur].cnt == maxcnt)
				{
					if (A[cur].s[0] < A[maxi].s[0])
					{
						maxi = cur;
					}
				}

				end++;
			}

		}

		scanf("%c", ch);


	}

	printf("%c %d", A[maxi].s[0], A[maxi].cnt);


	free(A);
	return 0;
}