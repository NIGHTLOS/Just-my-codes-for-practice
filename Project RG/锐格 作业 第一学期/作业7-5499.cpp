#include <stdio.h>
 
int main()
{
 
    int i,n;
    double k;
    double pi;
    while(scanf("%d",&n)!=-1)
    {
	pi=0;
	for (i=1;i<=n;i++)
    {
        if (i%2==0)
        {   
            pi=pi-4.0/(2*i-1);
        }
        else 
        {
            pi=pi+4.0/(2*i-1);
        }
        
    }
    printf("%.10f\n",pi);
    }
    return 0;
}
