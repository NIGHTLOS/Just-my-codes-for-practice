#include <stdio.h>
#include <string.h>
void Strcat(char *s1,char *s2)
{
   int num=0,n=0;
   while(*(s1+num)!='\0')
   {
   	num++;
   }
   while(*(s2+n)!='\0')
   {
   	*(s1+num++)=*(s2+n++);
   }
   *(s1+num)='\0'; 
}
int main()
{
	char str1[200];
	char str2[100];

	scanf("%s",str1); 
	getchar();
	scanf("%s",str2);
    Strcat(str1,str2);
	puts(str1);
	return 0;		
}
