#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k;
	char ch[100];
	while(scanf("%s",ch)!=EOF)
	{
		int s1=0,s2=0,s3=0,s4=0;
		int len=strlen(ch);
		for(i=0;i<len;i++)
		{
			if(ch[i]>='a'&&ch[i]<='z')
			s1=1;
			else if(ch[i]>='A'&&ch[i]<='Z')
			s2=1;
			else if(ch[i]>='0'&&ch[i]<='9')
			s3=1;
			else
			s4=1;
		}
		if(s1+s2+s3+s4>=3&&len>=8)
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}
