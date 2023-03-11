#include <stdio.h>

calc(double l,double w,double h)
{
	double ans;
	ans=l*w*h;
	return ans;
}
ata(double l,double w,double h)
{
	double a;
	a=l*w;
	return a;
}

atb(double l,double w,double h)
{
	double b;
	b=l*h;
	return b;
}

atc(double l,double w,double h)
{
	double c;
	c=w*h;
	return c;
}
int main()
{
	double v,l,w,h;//分别代表:体积、长、宽、高
    scanf("%lf", &l);
	scanf("%lf", &w);
	scanf("%lf", &h);
	v=calc(l,w,h);
	double s1,s2,s3;
	s1=ata(l,w,h);
	s2=atb(l,w,h);
	s3=atc(l,w,h);
	printf("%.0lf %.0lf %.0lf %.0lf\n",v,s1,s2,s3);
    
	return 0;
}
