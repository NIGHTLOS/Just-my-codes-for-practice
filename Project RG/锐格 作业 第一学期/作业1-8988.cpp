#include <stdio.h>
int main()
{
    double a,b,h,s;
    scanf("%lf%lf%lf",&a,&b,&h);
    s = (a+b)*0.5*h;
    printf("%.2f\n",s);
    return 0;
}
