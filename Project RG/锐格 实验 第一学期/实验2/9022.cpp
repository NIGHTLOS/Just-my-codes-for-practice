#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	if(a>=400&&a<800)
	{printf("%d\n",a-100);}
	if(a>=800&&a<1200)
	{printf("%d\n",a-250);}
	if(a>=1200)
	{printf("%d\n",a-400);}
	if(a<400)
	{printf("%d\n",a);}
	return 0;

}
