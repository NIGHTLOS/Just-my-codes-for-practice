#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[99];
    int n,i,j,x;
    while(scanf("%d%d",&n,&x)!=EOF)
    {
        for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
        a[n]=x;
        for(i=0;i<n+1;i++)
        {
            if(a[i]<a[n])
            {
                j=a[i];
                a[i]=a[n];
                a[n]=j;
            }
        }
        for(i=0;i<n+1;i++)
        {
            printf("%d ",a[i]);
        }
    printf("\n");
    }
    return 0;
}
