#include<stdio.h>
int main()
{
	char ch;
	int head = 1;
	int tail = 100;
	int guess = (head + tail) / 2;
	printf("please setting a number (1~100) and i will guess.\n");
	do
	{
		printf("is it %d?\n", guess);
		if (getchar() == 'y')
			break;
		printf("is bigger or smaller?\n");
		while ((ch =getchar())== '\n')
			continue;
		if (ch == 'b')
		{
			tail = guess - 1;
			guess = (head + tail) / 2;;
			continue;
		}
		else if (ch == 's')
		{
			head = guess + 1;
			guess = (head + tail) / 2;;
			continue;
		}
		else
			continue;
	} while (getchar() != 'y');

	printf("i know i can do it!\n");
	return 4;
}