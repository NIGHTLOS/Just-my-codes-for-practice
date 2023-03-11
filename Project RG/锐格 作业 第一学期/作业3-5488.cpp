#include <stdio.h>
#include <math.h>
int main()
{
    int i,n,j,sum;
    scanf("%d",&n);
    i=0,sum=0;
while(n>0)
{
    sum=n%10;
	if(sum==7)
	{i++;}
	n=n/10;
}
    if(i>=3)
	{printf("good luck!\n");}
	else if(0<=i<3)
	{printf("%d\n",i);}
	return 0;
}
 

