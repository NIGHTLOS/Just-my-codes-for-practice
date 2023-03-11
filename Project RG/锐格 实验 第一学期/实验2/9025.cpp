#include<stdio.h>
int main()
{
	int a,b,hh,mm,a1,a2,b1,b2;
	scanf("%d%d",&a,&b);
	a1=a/100;
	a2=a%100;
	b1=b/100;
	b2=b%100;
	mm=b2-a2;
	if(a1==b1&&a2==b2)
	printf("%02d:%02d",0,0);
	else if(mm<0)
	{
		hh=b1-a1-1;
		mm=60+mm;
		printf("%02d:%02d\n",hh,mm);
	}
	else if(mm<60)
	{
		hh=b1-a1;
		printf("%02d:%02d\n",hh,mm);
	}
    return 0;	
}
