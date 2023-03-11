#include <stdio.h>
#include<string.h>
int lengthOfLastWord(const char *s) 
{
   int len=strlen(s);
   int sum=0;
   for(int i=len-1;i>=0;i--)
   {
   	if(s[i]>='a'&&s[i]<='z')
   	sum++;
   	if(s[i]==' ')
   	break;
   }
    return sum;
}

int main()
{
    char str[1024];
    gets(str);
    int length = lengthOfLastWord(str);
    printf("%d\n", length);
    
    return 0;
}
