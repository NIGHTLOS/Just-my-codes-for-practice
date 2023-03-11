#include<stdio.h>
int main()
{
	int sum,n,i,k;
	double a[50],avg,s;
    scanf("%d %lf",&n,&s);
		sum=0;
		avg=0.0;
		for(i=0;i<n;i++)
		{
			scanf("%lf",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			if(a[i]>=s)
			{
				sum++;
			}
			avg+=a[i];
		}
		printf("%d %.2f\n",sum,avg/n*1.0);
	return 0;
}
