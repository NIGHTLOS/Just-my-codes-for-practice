#include<stdio.h>
int main()
{
	int i,n,x,max;
	while(scanf("%d",&n)!=-1) 
	{
		int max=-9999;
		int a[100]={0};
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			a[x]++;
		}
		for(i=0;i<100;i++)
		{
		   if(max<a[i])	
		    max=a[i];
		}
		printf("%d\n",max);
	}
	return 0;
}

