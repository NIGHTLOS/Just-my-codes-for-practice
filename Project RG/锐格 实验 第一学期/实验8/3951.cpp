#include <stdio.h>
int main(int argc,char *argv[])
{
	int n;
	if(scanf("%d",&n)!=1 || n<1 || n>10000)
	{
		printf("Input error, exit...\n");
		return 0;
	}
	printf("s=%fd\n",2-2.0/(n+1));
 	return 0;
}

