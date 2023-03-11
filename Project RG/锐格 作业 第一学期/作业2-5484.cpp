#include<stdio.h>
int main()
{
    double a,b,c;
    double max;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(b>a)
    {
    max=a;
    a=b;
    b=max;
    }
    if(c>a)
    {
    	max=a;
    	a=c;
    	c=max;
	}
	if(c>b)
	{
		max=b;
		b=c;
		c=max;
	}
    printf("%.2f %.2f %.2f\n",a,b,c);
	return 0;
}
