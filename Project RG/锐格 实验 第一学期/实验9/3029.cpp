#include <stdio.h>
void move(int *a)
{
	int b[10];
	for(int i=1;i<=5;i++)
	{
		b[i]=a[i];
	}
	for(int i=1;i<=5;i++)
	{
		a[i]=0;
	}
	a[1]=b[3];
	a[2]=b[4];
	a[3]=b[5];
	a[4]=b[1];
	a[5]=b[2];
}
int main()
{
    int a[10];
    for(int i=1;i<=5;i++)
    {
    	scanf("%d",&a[i]);
	}
	move(a);
	for(int i=1;i<=5;i++)
	{
		printf("%d ",a[i]);
	}
    return 0;
}

