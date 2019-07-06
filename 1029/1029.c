#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *wantinput, *realinput;

	wantinput = (char *)malloc(81 * sizeof(char));
	realinput = (char *)malloc(81 * sizeof(char));

	scanf("%s %s", wantinput, realinput);

	//printf("%s\n%s", wantinput, realinput);

	char *badkey, *curw, *curr, *curb;

	badkey = (char *)malloc(81 * sizeof(char));
	*badkey = '\0';
	curb = badkey;

	curw = wantinput;

	while (*curw != '\0')
	{
		curr = realinput;

		while (*curr != '\0')
		{
			if (*curw == *curr)
			{
				break;
			}
			curr++;
		}

		if (*curr == '\0')
		{
			*(curb++) = *curw;
			*curb = '\0';
		}

		curw++;
	}

	curb = badkey;
	while (*curb != '\0')
	{
		if (*curb >= 'a' && *curb <= 'z')
		{
			*curb -= 32;
		}
		curb++;
	}

	curb = badkey;
	while (*curb != '\0')
	{
		if (*curb == '.')
		{
			curb++;
			continue;
		}

		char *tmp;
		tmp = curb + 1;
		while (*tmp != '\0')
		{
			if (*tmp == *curb)
			{
				*tmp = '.';
			}
			tmp++;
		}

		curb++;
	}

	curb = badkey;
	while (*curb != '\0')
	{
		if (*curb == '.')
		{
			char *start1, *tmp;
			start1 = curb;
			tmp = curb;

			while (*tmp == '.')
			{
				tmp++;
			}

			char *start2;
			start2 = tmp;

			while (*tmp != '.' && *tmp != '\0')
			{
				tmp++;
			}

			char *end;
			end = tmp;

			while (start2 != end)
			{
				*(start1++) = *start2;
				*start2 = '.';
				start2++;
			}

			*start1 = *end;

			curb = start1;

		}
		else
		{
			curb++;
		}

	}



	printf("%s", badkey);




	free(wantinput);
	free(realinput);
	free(badkey);
	return 0;
}