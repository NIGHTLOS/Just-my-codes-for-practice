#include <stdio.h>

int main()
{
	long long number = 0;
	scanf("%lld", &number);
	int count = 0;
	do
	{
		number = number / 10;
		count++;
	} 
	while (number != 0);
	printf("%d\n", count);
    return 0;
}
