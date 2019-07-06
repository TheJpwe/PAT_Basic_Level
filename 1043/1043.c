#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char S[1];
	int count[6] = { 0 };

	scanf("%c", S);

	while (S[0] != '\n')
	{
		switch (S[0])
		{
		case 'P':
			count[0]++;
			break;
		case 'A':
			count[1]++;
			break;
		case 'T':
			count[2]++;
			break;
		case 'e':
			count[3]++;
			break;
		case 's':
			count[4]++;
			break;
		case 't':
			count[5]++;
			break;
		default:
			break;
		}

		scanf("%c", S);

	}

	int max = 0;
	for (int i = 0; i < 6; i++)
	{
		if (count[i] > max)
		{
			max = count[i];
		}
		
	}

	while (max-- > 0)
	{
		for (int i = 0; i < 6; i++)
		{
			if (count[i] > 0)
			{
				switch (i)
				{
				case 0:
					printf("P");
					break;
				case 1:
					printf("A");
					break;
				case 2:
					printf("T");
					break;
				case 3:
					printf("e");
					break;
				case 4:
					printf("s");
					break;
				case 5:
					printf("t");
					break;
				default:
					break;
				}

				count[i]--;
				
			}
		
		}
		
	}


	return 0;
}