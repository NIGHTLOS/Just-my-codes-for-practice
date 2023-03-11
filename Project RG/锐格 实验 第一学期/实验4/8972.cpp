#include <stdio.h>
#include <math.h>
int main()
{
    int i,j,count = 0,sum = 0;
    int m;
    while(scanf("%d",&m)!=EOF)
    {
	sum=0;
	for(i=1;i<=m;i++)
    {
        for(j=2;j<=m-1;j++)
		{
		if(i%j==0)
            {
                count++;
            }
        }
        if(count==1)
        {
            count = 0;
            sum += i;
        }
        else
        {
            count = 0;
        }
    }
    printf("%d\n",sum);
    }
}
 

