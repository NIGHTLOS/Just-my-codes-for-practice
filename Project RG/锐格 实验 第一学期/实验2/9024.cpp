#include <stdio.h>
int main()
{
    int a,i,n=4;
    char ch;
    scanf("%d %c",&a,&ch);
    if(ch=='y')
        n+=5;
    if(a>1000)
    {
        a=a-1000;
        i=0;
        while(a>0)
        {
            a=a-500;
            i=i+1;
        }
        n+=3*i;
    }
    printf("%d",n);
    return 0;
}
 
