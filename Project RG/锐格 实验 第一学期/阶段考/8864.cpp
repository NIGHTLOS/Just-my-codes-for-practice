#include<stdio.h>
#include<string.h>
int main()
{
	int i,j;
	char a[50],b[50],c[50],d[50],ch[100];
	while(gets(a))
	{
		int len=strlen(a);
		int flag1=0,flag2=0,flag3=0;
		for(i=0;i<len;i++)
		{
			if(a[i]>='a'&&a[i]<='z')
			{
			b[flag1]=a[i];
			flag1++;
		    }
			if(a[i]>='A'&&a[i]<='Z')
			{
			c[flag2]=a[i];
			flag2++;
		    }
			if(a[i]>='0'&&a[i]<='9')
			{
			d[flag3]=a[i];
			flag3++;
		    }
		}
		for(i=0;i<flag1;i++)
		{
			for(j=flag1-1;j>i;j--)
			{
				if(b[j-1]>b[j])
				{
					int temp3=b[j-1];
					b[j-1]=b[j];
					b[j]=temp3;
				}	
			}
		}
		for(i=0;i<flag2;i++)
		{
			for(j=flag2-1;j>i;j--)
			{
				if(c[j-1]>c[j])
				{
					int temp1=c[j-1];
					c[j-1]=c[j];
					c[j]=temp1;
				}
			}
		}
		for(i=0;i<flag3;i++)
		{
			for(j=flag3-1;j>i;j--)
			{
				if(d[j-1]>d[j])
				{
					int temp2=d[j-1];
					d[j-1]=d[j];
					d[j]=temp2;
				}
			}
		}
		for(i=0;i<flag2;i++)
		{
			printf("%c",c[i]);
		}
		for(i=0;i<flag3;i++)
		{
			printf("%c",d[i]);
		}
		for(i=0;i<flag1;i++)
		{
			printf("%c",b[i]);
		}
		printf("\n");			
	}
	return 0;
}
