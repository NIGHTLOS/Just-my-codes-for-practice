#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int main()
{
   int m,i,j;
   while(scanf("%d\n",&m)!=EOF)
   {
   	int b[30]={0};
   	char ch[30][55];
    char c[5]="***";	
	for(i=0;i<m;i++)
   	{
   	 gets(ch[i]);
    }
	 for(i=0;i<m;i++)
	   {
	   	for(j=i+1;j<m;j++)
	   	{
	   	  if(strcmp(ch[i],ch[j])==0&&strcmp(ch[j],c)!=0)	
	   	  {
	   	    b[i]++;
	   	    strcpy(ch[j],c);
	   	    b[j]=50;
		  }
		}
	   }
	 for(i=0;i<m;i++)
	 {
	 	if(b[i]!=50)
	 	printf("%d %s\n",b[i]+1,ch[i]);
	 }
   }
   return 0;
} 
