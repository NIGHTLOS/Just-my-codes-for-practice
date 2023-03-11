#include<stdio.h>
int main()
{
	int a[10][15],b[15][10];
	int i,j,n,m;
	while(scanf("%d%d",&m,&n)!=-1)
	{
		for(i=0;i<m;i++)
		    {
		    	for(j=0;j<n;j++)
		    	scanf("%d",&a[i][j]);
			}
		for(i=0;i<m;i++)
		    {
		    	for(j=0;j<n;j++)
		    	b[j][i]=a[i][j];
			}
		for(i=0;i<n;i++)
		    {
		    	for(j=0;j<m;j++)
		    	   {
		    	   	printf("%d ",b[i][j]);
				   }
				   printf("\n");
			}
		
	}
	return 0;
}
