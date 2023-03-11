#include<stdio.h>
int main()
{
	int i,j;
	char ch='*';
	for(i=0;i<5;i++)
	{
		
		for(j=0;j<i;j++)
			{printf(" ");}
		printf("* * * * *");
		printf("\n");
	}
	return 0;
}
