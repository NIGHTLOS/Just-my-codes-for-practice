#include<stdio.h>
int main() 
{
	int a[50][50];
	int n,i,j;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		int ans=0;
		for(i=1;i<=n-1;i++)
		{
			for(j=1;j<=n-1;j++)
			{
				if(i+j!=n+1)
				ans+=a[i][j];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
