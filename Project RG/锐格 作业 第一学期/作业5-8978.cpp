#include <stdio.h>
#define N 10
int main()
{
double a[N];
int i;
float avg;
while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9])!=EOF)
{
double min,max,sum=0;
min=a[0];
max=a[0];
for(i=0;i<N;i++)
{
if(a[i]<min)
min=a[i];
if(a[i]>max)
max=a[i];
sum=sum+a[i];
}
avg=(sum-max-min)/(N-2);
printf("%.3f\n",avg);
}
return 0;
}
