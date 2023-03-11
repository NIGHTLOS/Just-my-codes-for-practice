# include <stdio.h>
int main()
{
int n=20;
int a[n];
a[0]=1;
a[1]=2;
a[2]=3;
for(int i=0;i<n; i++)
{
   if(i>=3)
   {
    a[i] = a[i-1] + a[i-2] + a[i-3];
   }
printf("%lld ", a[i]);
}
return 0;
}

 

