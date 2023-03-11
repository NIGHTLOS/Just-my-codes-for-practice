#include<stdio.h>
int main()
{
   int i,j,n,a[100]={0};
   while(scanf("%d",&n)!=EOF)
   {
   	for(i=0;i<n;i++)
   	{
   		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=i;j--)
		{
			if(a[i]<a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
   }
   return 0;	
}
