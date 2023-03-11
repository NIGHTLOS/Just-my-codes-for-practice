#include<stdio.h>
main()
{ 
	int n,i,j,sum=0;           
	scanf("%d",&n);                
	for (i=n;i>0;i--)               
	{
		for(j=1;j<=n-i+1;j++)  
		sum+=j;                 
	}
	printf("%d\n",sum);
} 
