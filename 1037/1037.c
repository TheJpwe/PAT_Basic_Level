#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StoInt(char *A, int *G, int *P, int *K);





int main()
{
	char *P, *A;

	P = (char *)malloc(15 * sizeof(char));
	A = (char *)malloc(15 * sizeof(char));

	scanf("%s %s", P, A);

	//printf("%s %s", P, A);

	int PGalleon, PSickle, PKnut;
	int AGalleon, ASickle, AKnut;
	const int StoG = 17;
	const int KtoS = 29;

	StoInt(P, &PGalleon, &PSickle, &PKnut);
	StoInt(A, &AGalleon, &ASickle, &AKnut);

	//printf("%d %d %d\n%d %d %d", PGalleon, PSickle, PKnut, AGalleon, ASickle, AKnut);

	int Psum, Asum;
	Psum = PGalleon * StoG * KtoS + PSickle * KtoS + PKnut;
	Asum = AGalleon * StoG * KtoS + ASickle * KtoS + AKnut;

	int galleon, sickle, knut;


	if (Asum<Psum)
	{
		printf("-");
		galleon = (Psum - Asum) / (StoG * KtoS);
		sickle = ((Psum - Asum) - galleon * StoG * KtoS) / KtoS;
		knut = (Psum - Asum) - galleon * (StoG*KtoS) - sickle * KtoS;

		printf("%d.%d.%d", galleon, sickle, knut);
	}
	else
	{
		galleon = -(Psum - Asum) / (StoG * KtoS);
		sickle = (-(Psum - Asum) - galleon * StoG * KtoS) / KtoS;
		knut = -(Psum - Asum) - galleon * (StoG*KtoS) - sickle * KtoS;
		printf("%d.%d.%d", galleon, sickle, knut);
	}



	free(P);
	free(A);
	return 0;
}

void StoInt(char *A, int *G, int *P, int *K)
{

	char *cur, *curtmp;
	cur = A;

	char *tmp;
	tmp = (char *)malloc(9 * sizeof(char));
	curtmp = tmp;

	while (*cur != '.')
	{
		*(curtmp++) = *(cur++);
	}
	*curtmp = '\0';

	*G = atoi(tmp);

	curtmp = tmp;
	cur++;
	while (*cur != '.')
	{
		*(curtmp++) = *(cur++);
	}
	*curtmp = '\0';
	
	*P = atoi(tmp);

	curtmp = tmp;
	cur++;
	while (*cur != '\0')
	{
		*(curtmp++) = *(cur++);
	}
	*curtmp = '\0';

	*K = atoi(tmp);

	free(tmp);
}