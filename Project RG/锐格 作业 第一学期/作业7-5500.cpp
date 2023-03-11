#include<stdio.h>
int main()
{
	int n,i;
	float sum,e;
	while(scanf("%d",&n)!=-1)
	{
		sum=1.0;
	    e=1.0;
		for(i=1;i<n;i++)
		{
			sum*=i;
			e+=1/sum;
		}
		printf("%.4f\n",e);
	}
	return 0;
} 
