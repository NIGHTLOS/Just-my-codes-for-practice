#include<stdio.h>
int main()
{
	int a,c1,c2,c3,a1;
	scanf("%d",&a);
	c1 = a/100;
	c2 = a%10;
	a1 = a/10;
	c3 = a1%10;
	printf("%d\n", c1*c1*c1+c2*c2*c2+c3*c3*c3);
	return 0;
}
