#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int num,i,j,k,flag=0,a[10]={0};
	scanf("%d",&num);
	k=num;
	i=1;
	while(k>0)
	{
		a[i]=k%10;
		k=k/10;
		i++;
	}
	if(a[1]==a[2]&&a[2]==a[3])
	printf("%d\n",num%6);
	else
    printf("%d\n",num%7);
	return 0;
}
