#include<stdio.h>
int main()
{
	char ch;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	char ch2 = '\n';
	while (scanf("%c", &ch) != -1)
	{
		if (ch == ch2)
			break;
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			a++;
		else if (ch == ' ')
			b++;
		else if (ch >= '0' && ch <= '9')
			c++;
		else
			d++;
	}
	printf("num1=%d,num2=%d,num3=%d,num4=%d", a, c, b, d);
	return 0;
}

