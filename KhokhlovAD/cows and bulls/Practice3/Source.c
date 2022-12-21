#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main()
{
	srand((unsigned int)time(NULL));
	int i, x, k, j, numb_int, st = 1, input, p_numb[N], attempt = 0;
	do
	{
		printf("enter number of digits N=");
		scanf_s("%d", &x);
	} while (x < 2 || x>5);
	int numb[N];
	do
	{
		for (i = 0; i < N - (5 - x); i++)
		{
			numb[i] = 1+rand() % 9;
		}
		k = 0;
		for (i = 0; i < N - (5 - x); i++)
			for (j = i + 1; j < N - (5 - x); j++)
				if (numb[i] == numb[j])
					k++;
	} while (k > 0 || numb[0] == 0);
	numb_int = 0;
	for (i = N - (5 - x) - 1; i >= 0; i--)
	{
		numb_int += numb[i] * st;
		st *= 10;
	}
	for (i = 0; i < N - (5 - x); i++)
	{
		printf("%d", numb[i]);
	}
	printf("\n");
	do
	{
		attempt++;
		int check_p, z;
		do
		{
			printf("enter the number\n");
			scanf_s("%d", &input);
			check_p = input;
			z = 0;
			while (check_p > 0)
			{
				z++;
				check_p /= 10;
			}
		} while (z != x);
		check_p = input;
		for (i = N - (5 - x) - 1; i >= 0; i--)
		{
			p_numb[i] = check_p % 10;
			check_p /= 10;
		}
		int bulls = 0, cows = 0;
		for (i = 0; i < N - (5 - x); i++)
		{
			if (numb[i] == p_numb[i])
				bulls++;
		}
		int digit_comp[10] = { 0 }, digit_p[10] = { 0 }, index, temp = 0;
		for (i = 0; i < N - (5 - x); i++)
		{
			index = numb[i];
			digit_comp[index] = 1;
			index = p_numb[i];
			digit_p[index] = 1;
		}
		for (i = 0; i < 10; i++)
		{
			if (digit_comp[i] == digit_p[i] && digit_comp[i] != 0)
				temp++;
		}
		cows = temp - bulls;
		printf("bulls=%d, cows=%d, attempts=%d", bulls, cows, attempt);
		printf("\n");
	} while (input != numb_int);
	printf("number guessed\n");
	return 0;
}