#include <stdio.h>
#include <stdlib.h>

#define NUM 10

int main(void)
{
	int r_value = rand() % NUM;

	int a[NUM];
	int b[NUM];

	int i;

	for (i = 0; i < NUM; i++)
	{
		a[i] = rand() % NUM;
	}

	for (i = 0; i < NUM; i++)
	{
		b[i] = a[i];
	}

	printf("    ");
	for (i = 0; i < NUM; i++)
	{
		printf("%5d", i);
	}
	printf("\n");

	printf("a : ");
	for (i = 0; i < NUM; i++)
	{
		printf("%5d", a[i]);
	}
	printf("\n");

	printf("b : ");
	for (i = 0; i < NUM; i++)
	{
		printf("%5d", b[i]);
	}
	printf("\n");

	return 0;
}