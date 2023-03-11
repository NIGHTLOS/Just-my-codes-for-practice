#include<stdio.h>
#include<string.h>
int main()
{
	char ch;
    for(int i=0;i<=5;i++)
	{
		scanf("%c",&ch);
		if(ch<='z'&&ch>='a')
			{
			ch=ch+3;
			printf("%c",ch);
		    }
		else
		{printf("%c",ch);}
	}
	
	return 0;
}
