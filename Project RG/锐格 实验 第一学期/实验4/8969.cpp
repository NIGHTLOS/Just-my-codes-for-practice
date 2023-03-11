#include<stdio.h>
#include<math.h>
int main()
{
  int a,b;
  double c=0;
  a=2;
  b=1;
  for(int i=1;i<=20;i++)
  {
  	c+=(double)a/b;
  	a+=b;
  	b=a-b;
  }
  printf("sum=%.2f\n",c);
  return 0;
} 
