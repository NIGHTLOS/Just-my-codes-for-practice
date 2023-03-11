#include<stdio.h>
int main()
{
    int i;
    int sum=0;
    for(i=1;i<=100;i++)
    {
        if((i/10==6)||(i%10==6))
        sum+=i;
    }
    printf("%d\n",sum);
    return 0;
}
