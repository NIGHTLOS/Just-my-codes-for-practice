#include<stdio.h>
int main()
{
	int price,high,age;
	scanf("%d%d%d",&price,&high,&age);
	if((age>=60&&age<=70)||(high>=120&&high<=140))
	{
		price=price/2;
	}
	else if((age>=70)||(high<=120))
	{
		price=0;
	}
	printf("%d\n",price);
	return 0;
}

