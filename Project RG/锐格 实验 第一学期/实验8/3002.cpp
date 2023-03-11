#include <stdio.h>

//write your code here
int factorial(int n)
{
	int sum=1;
	for(int j=1;j<=n;j++)
	{
		sum=sum*j;
	}
	return sum;
}


int main()
{
	int i,n;
    scanf("%d", &n);

	for (i=1;i<=n;i++)
    	printf("%d\n", factorial(i));
	return 0;
}

