#include <stdio.h>
#include <stdlib.h>
int update(int *a,int x,int y,int v)
{ 
  //start
  for(int i=x;i<=y;i++)
  {
  	*(a+i)+=v;
  } 
  //end
  return 0;
}
int main()
{
 int a[100],n,i,x,y,v;
 while(scanf("%d",&n)!=-1)
 {
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    scanf("%d%d%d",&x,&y,&v);
    update(a,x,y,v);
    for( i=1;i<=n;i++)
    printf("%d ",a[i]);
    printf("\n");
 }
    return 0;
}
