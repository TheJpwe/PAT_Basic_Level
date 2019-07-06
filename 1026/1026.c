#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define CLK_TCK 100


int main()
{
	int C1, C2;
	scanf("%d %d", &C1, &C2);

	int totalC = C2 - C1;

	int sectime = totalC / CLK_TCK + (totalC % CLK_TCK >= CLK_TCK / 2 ? 1 : 0);

	int hh = sectime / 3600;
	int mm = (sectime - hh * 3600) / 60;
	int ss = sectime - hh * 3600 - mm * 60;

	printf("%02d:%02d:%02d", hh, mm, ss);



	return 0;
}