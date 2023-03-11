#include<stdio.h>
#include<math.h>
int main()
{
	double c,f;
	while(scanf("%lf",&f)!=-1)
	{
		c=3.0/8.0*(f-32.0)*sin(f);
		printf("%.2f\n",c);
	}
	return 0;
}

