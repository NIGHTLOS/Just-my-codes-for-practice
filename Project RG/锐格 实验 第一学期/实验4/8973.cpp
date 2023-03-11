#include<stdio.h>
int main()
{
	int i,j,k;
	for(i=1;i<=9;i++)
	{
		for(k=0;k<9-i;k++)
				{
				printf(" ");
				}
		for(j=1;j<=i;j++)
		{
			
			if (j==1)
			printf("%d",j);
			else 
			printf(" %d",j);
		}
		printf("\n");
		}	
	return 0;
}

