#include<stdio.h>
#include<string.h>
int main()
{
  int sum,i,j,num;
  char a[50];
  while(gets(a))
  {
  	char cx='#';
  	sum=0;
  	int len = strlen(a);
  	for(i=0;i<len;i++)
  	{
  		if(a[i]=='*')
  		{
  		 sum++;
		 a[i]='#';	
		}
	}
	printf("%d ",sum);
	puts(a);
  }
  return 0;
}
