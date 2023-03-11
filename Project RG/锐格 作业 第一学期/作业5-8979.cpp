#include<stdio.h>
int main()
{
	int i,n,x,num,max;

	while(scanf("%d",&n)!=-1) 
	{
		num=0;
		max=0;
		int a[31]={0};
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			a[x]++;
		}
		for(i=0;i<n;i++) 
		{
			if(a[i]>max) max=a[i];
		
		}
		for(i=0;i<n;i++) 
		{
			if (a[i]==max)
			{	
				num++;
				if(num==1)printf("%d",i);
				else printf(" %d",i);
			}
		
		}
		printf("\n");
	}
	
	
	return 0;
}

