#include<stdio.h>
#include<stdlib.h>
int main()
{
	char ch1,ch2,ch3;
	int t1,t2,t3;
	scanf("%c %c %c",&ch1,&ch2,&ch3);
	t1=ch1-'0';
	t2=ch2-'0';
	t3=ch3-'0';
	int ans=t1*100+t2*10+t3;
	printf("%d\n",ans);
	return 0;
}
 
