#include <stdio.h>
#include <stdlib.h>
int sx(int n)
{
    //start
    int k,flag=0;
	for(k=2;k<=n/2;k++)
	{
	   if(n%k==0)
	   {
	   	 flag=1;
	   	 break;
	   }	
	} 
	if(n==1)
	flag=1;
	return flag;
    //end
}
int main()
{
   int i,m,n,ans=0;
       scanf("%d%d",&m,&n);
       ans=0;
       for(i=m;i<=n;i++)
          if (sx(i)==0) ans+=i;
        printf("%d\n",ans);
   //printf("Hello world!\n");
    return 0;
}
