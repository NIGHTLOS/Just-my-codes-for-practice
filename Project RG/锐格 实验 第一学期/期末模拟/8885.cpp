#include<stdio.h>
float *hanshu(float a[][6],int n)
{
    //start
    float b[100]={0};
    float max=-999.0,*tmp;
    for(int i=0;i<n;i++)
    {
		for(int j=0;j<6;j++)
    	{
    		b[i]+=a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(max<b[i])
		{
			max=b[i];
			tmp=&a[i][0];
		}
	}
	return tmp;
    //end
}
int main()
{
    float a[15][6],*p;
    int m,i,j;
    scanf("%d",&m);
    for(i=0;i<m;i++)
        for(j=0;j<6;j++)
        {
            scanf("%f",&a[i][j]);
        }
    p=hanshu(a,m);
    for(i=0;i<6;i++)
        printf("%.1f ",*(p+i));
    return 0;
}
