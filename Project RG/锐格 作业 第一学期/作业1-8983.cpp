#include <stdio.h>
int main()
{
    double c,f;
    scanf("%lf",&f);
    c = (f-32)*5/9;
    printf("%.2lf\n",c);
    return 0;
}
