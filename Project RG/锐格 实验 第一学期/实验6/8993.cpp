#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[10][10],b[10][10],sum,i,j,n,m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=0; i<m; i++) 
            for(j=0; j<n; j++)
                scanf("%d",&a[i][j]);
//start
    for(i=0; i<m; i++)
            for(j=0; j<n; j++)
            {
            	if(i==0||j==0||i==m-1||j==n-1)
            	{
            		b[i][j]=a[i][j];
				}
				else
				b[i][j]=(a[i][j]+a[i-1][j]+a[i][j-1]+a[i][j+1]+a[i+1][j])/5;
			}
//end
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
