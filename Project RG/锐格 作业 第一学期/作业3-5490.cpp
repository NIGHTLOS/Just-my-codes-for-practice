#include <stdio.h>
#include <math.h>
int main()
{
    int i,j,m;
    int sum=0;
    scanf("%d",&i);
    for(j=1;j<=i;j++)
    {
		if(i%j==0)
    	sum=j+sum;
	}
	printf("%d\n",sum);
	return 0;
}
 

