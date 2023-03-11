#include<stdio.h>
int main()
{
	struct date{
		int year;
		int month;
		int day;
	}date;
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	while(scanf("%d-%d-%d",&date.year,&date.month,&date.day)!=EOF)
	{
	int y=2000;
	int sum=0;
	for(y;y<date.year;y++)
	{
		if((y%400==0)||(y%4==0&&y%100!=0)) 
		{
			sum+=366;
		} 
		else
		{
			sum+=365;
		}
	}
	for(int m=1;m<date.month;m++) 
	{
		sum+=a[m];
		if(m==2&&((date.year%400==0)||(date.year%4==0&&date.year%100!=0))) 
		{
			sum+=1;
		}
	}
	sum+=date.day;
	if((sum%5==1)||(sum%5==2)||(sum%5==3))
	{
	printf("´òÓã\n");
	}
	else
	{
	printf("É¹Íø\n"); 
	}
    }
	return 0;
}


