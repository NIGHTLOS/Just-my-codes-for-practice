#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[15][20],tmp[20];
    int n,i,j,k;
    while(scanf("%d",&n)!=-1)
    {
	for(i=1;i<=n;i++)
    scanf("%s",a[i]);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<n;j++)
       {
         if (strcmp(a[j],a[j+1])>0 )
             {
                 strcpy(tmp,a[j]);
                 strcpy(a[j],a[j+1]);
                 strcpy(a[j+1],tmp);
             }
       }
    }
        for(i=1;i<=n;i++)
        {
       if (i!=n) 
	   printf("%s ",a[i]);
       else 
	   printf("%s\n",a[i]);
        }
    }
    return 0;
}
