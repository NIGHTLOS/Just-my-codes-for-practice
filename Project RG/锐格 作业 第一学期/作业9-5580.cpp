#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    long long  func(int n);
    while(scanf("%d",&n)!=EOF)
    {
      printf("%lld\n",func(n));
    }
    return 0;
}
//start 
long long func(int n)
{
	int i;
    long long sum=1;
	for(i=n;i>0;i--)
	{
	   sum=sum*i;
	}
	return sum;
}
//end
