#include <stdio.h>
int main()
{
	double a[100];
	double k;
	int i,j,n;
	while(scanf("%d\n",&n)!=-1)
	{
	for(j=0;j<n;j++)
	{
		scanf("%lf",&a[j]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]<a[j])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
		printf("%.2f ",a[i]);
	}
	putchar('\n');
    }
    return 0;
}

               
