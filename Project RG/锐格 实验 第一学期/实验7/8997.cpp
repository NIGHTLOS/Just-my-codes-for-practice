#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[100],b[100];
    int i,j,len1,len2,flag,sg,p;
    int ans[100];
    while(scanf("%s%s",a,b)!=-1)
    {
        len1=strlen(a);
        len2=strlen(b);
        flag=0;
        sg=0;
        p=0;
        for(i=0;i<len1;i++)
           {
             flag=0;
             for(j=i;j<i+len2;j++)
               {
                if (j>=len1) 
				break;
                if (a[j]!=b[j-i]) 
				{flag=1;break;}
                }
               if (flag==0)
                 {
                 sg=1;
                 ans[++p]=i+1;
                 }
           }
           if (sg==0) 
		   printf("-1\n");
           else
           {
               for(i=1;i<=p;i++)
               if (i!=p) 
			   printf("%d ",ans[i]);
               else  
			   printf("%d\n",ans[i]);
           }
    }
    return 0;

}


