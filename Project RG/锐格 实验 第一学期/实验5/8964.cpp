#include <stdio.h>
long long a[100];
int main()
{
   int i,n;
   a[1]=1;
   a[2]=1;
   for(i=3;i<=50;i++)
   a[i]=a[i-1]+a[i-2];
   while(scanf("%d",&n)!=EOF)
   {
       printf("%lld\n",a[n]);
   }
    return 0;
}
