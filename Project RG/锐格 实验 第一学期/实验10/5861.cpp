#include<stdio.h>
#include<math.h>
struct Date
{
    double x;
    double y;
};
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int i,j,k=0;
        struct Date X[n];
        double a,min=99999;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&X[i].x,&X[i].y);
        }
        for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            a =  sqrt((X[j].x-X[i].x)*(X[j].x-X[i].x)+(X[j].y-X[i].y)*(X[j].y-X[i].y));
            if(a<min)
            min = a;
        }
        printf("%.1lf\n", min);
    }
    return 0;
}

