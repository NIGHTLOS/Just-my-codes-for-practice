#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[25];
    int i,n,min,max;
    while(scanf("%d %d %d",&n,&min,&max)!=-1)
    {
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    if(a[i]>=min && a[i]<=max)
    {
    printf("%d ",a[i]);
    }
    }
    printf("\n");
   }
    return 0;
}
       
