#include<stdio.h>
#include <stdlib.h>
int main()
{
   int sum1=0,sum2=0;
   for(int i=1;i<=101;i+=4)
   {
   	sum1+=i;
   }
   for(int j=3;j<=99;j+=4)
   {
   	sum2+=j;
   }
   printf("%d",sum1-sum2);
	return 0;
}
