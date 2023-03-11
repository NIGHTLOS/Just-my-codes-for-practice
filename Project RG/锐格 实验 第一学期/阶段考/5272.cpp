#include<stdio.h>
int main()
{
	int i,n,x;
	while(scanf("%d",&x)!=EOF)
	{
		int sum=0;
		for(i=1;i<=x;i++)
		{
			if(x%i==0&&i%2!=0)
			sum+=i;
		}
		printf("%d\n",sum);
	}
	return 0;
}
