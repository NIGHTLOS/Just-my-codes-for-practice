#include<stdio.h> 
int main()
{
   int i,j,n,z,sum;
   scanf("%d %d",&n,&z);
   for(i=10;;i++)
   {
   	  if((i-z)%5==0&&(i-3)%7==0&&(i-1)%3==0)
   	  {
   	  	sum=i;
   	  	break;
	  }
   }
   printf("%d\n",n+sum);
   return 0;
} 
