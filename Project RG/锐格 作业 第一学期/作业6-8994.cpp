#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int n,m,k;
    while(scanf("%d%d%d", &m,&n,&k)!=-1)
    {
        int a[15][15]={0};
        int i,j,x,tmp;
        for(i=0;i<m;i++)
        {
          for(j=0;j<n;j++)
          {
              scanf("%d", &a[i][j]);
              a[i][n]=a[i][j]+a[i][n];
          }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<m-1;j++)
            {
                if(a[j][k-1]<a[j+1][k-1])
                {
                    for(x=0;x<=n;x++)
                    {
                        tmp=a[j][x];
                        a[j][x]=a[j+1][x];
                        a[j+1][x]=tmp;
                    }
                }
            }
        }
        for(i=0;i<m;i++)
        {
            printf("%d ", i+1);
          for(j=0;j<=n;j++)
          {
              printf("%d ", a[i][j]);
          }
          printf("\n");
        }
    }
    return 0;
}

