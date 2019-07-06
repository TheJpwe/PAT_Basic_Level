#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{

	char *badkey;
	char *input;

	badkey = (char *)malloc(42 * sizeof(char));
	input = (char *)malloc(100001 * sizeof(char));

	scanf("%s %s", badkey, input);

	char *output;
	output = (char *)malloc(100001 * sizeof(char));

	char *curinput, *curoutput, *curbadkey;
	curinput = input;
	curoutput = output;
	curbadkey = badkey;

	while (*curinput != '\0')
	{
		curbadkey = badkey;

		while (*curbadkey != '\0')
		{
			if (*curbadkey == '+')
			{
				if (*curinput >= 'A' && *curinput <= 'Z')
				{
					break;
				}
			}
			else if (*curbadkey >= 'A' && *curbadkey <= 'Z')
			{
				if (*curinput == *curbadkey || *curinput == *curbadkey +32)
				{
					break;
				}
			}
			else
			{
				if (*curinput == *curbadkey)
				{
					break;
				}
			}

			curbadkey++;

		}

		if (*curbadkey == '\0')
		{
			*(curoutput++) = *curinput;
		}

		curinput++;
	}

	*curoutput = '\0';



	printf("%s", output);

	free(badkey);
	free(input);
	free(output);
	return 0;
}