#include <stdio.h>
int main()
{
	int n;
	int yanghui[50][50];
	while(scanf("%d",&n)!=-1)
{
	for(int i=0;i<n;i++)
	{
		yanghui[i][0]=1;
		yanghui[i][i]=1;
		for(int j=1;j<i;j++)
		{
			yanghui[i][j]=yanghui[i-1][j-1]+yanghui[i-1][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			printf("%3d ",yanghui[i][j]);
		}
		printf("\n");
	}
}
	return 0;
}

