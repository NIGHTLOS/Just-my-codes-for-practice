#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int stat(char a[],char c)
{ //统计数组a中字符c的个数
  //start
  int len=strlen(a);
  int i,num=0;
  for(i=0;i<len;i++)
  {
  	if(a[i]==c)
  	num++;
  }
  return num;
  //end
}
int main()
{
    char a[100],c;
    int n;
    while(scanf("%s %c",a,&c)!=EOF)
    {
        n=stat(a,c);
        printf("%d\n",n);
    }
    return 0;
}
