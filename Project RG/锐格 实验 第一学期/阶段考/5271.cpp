#include <stdio.h>
#include<string.h> 
int main()
{
	char ch[500];
	int i,j;
	while(gets(ch))
	{
		int len=strlen(ch);
		for(i=0;i<len;i++)
		{
			if(ch[i]>='a'&&ch[i]<='z')
			ch[i]=ch[i]-32;
		}
		for(i=0;i<len;i++)
		{
			printf("%c",ch[i]);
		}
	printf("\n");
	}
	return 0;
}
