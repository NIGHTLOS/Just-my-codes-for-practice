#include<stdio.h>//只能用此方法不然超时 
int main()
{
	int i,j,flag,n,a[100][100];
	while(scanf("%d",&n)!=EOF)
	{
		flag=1;
		for(i=1;i<=n;i++)
		 for(j=1;j<=n;j++)
		 {
		 	scanf("%d",&a[i][j]);
		 }
		for(i=1;i<=n;i++)
		{
		 for(j=1;j<=n;j++)
		 {
		 	if(i<j)
		 	{
		 	  if(a[i][j]!=0)
			  flag=0;	
			}
		 }
	    }
		 if(flag==1)
		 	printf("Yes\n");
		 if(flag==0)
		    printf("No\n");
	}
	return 0;
}
