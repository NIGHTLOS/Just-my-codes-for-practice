#include<stdio.h>
int main()
{
  int m,n,a[100][100];
  int i,j,k;
  while(scanf("%d%d",&n,&m)!=-1)
  {
  	for(i=1;i<=n;i++)
  	   for(j=1;j<=m;j++)
  	   {
  	   	 scanf("%d",&a[i][j]);
	   }
	for(i=1;i<=n;i++)
  	   for(j=1;j<=m;j++)
  	   {
		 if(a[i][j]%7==0)
		 {
		 	printf("%d %d %d \n",i,j,a[i][j]);
		 }
	   }
  }	
  return 0;
} 
