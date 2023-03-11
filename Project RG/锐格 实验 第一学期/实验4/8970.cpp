#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,n=0,b[20];
	b[0]=1;
	for(i=1;i<=11;i++)
	{
     b[i]=2*b[i-1];
	}
	for(i=0;i<=11;i++)
	{
		n+=b[i];
		if(n>=2000)
		{
			break;
		}
	}
	printf("%d",n);
	return 0;
}

