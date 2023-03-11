#include <stdio.h>
void sort(int **p,int n)
{
    //write your own codes
	int i,j,tmp;
	for(i=0;i<n;i++)
	for(j=0;j<n-1;j++)
	{
	    if(*(*p+j)>*(*p+j+1))
	    {
	        tmp=*(*p+j);
	        *(*p+j) = *(*p+j+1);
	        *(*p+j+1) = tmp;
	    }
	}
	for(i=0;i<n;i++)
	{
	    printf("%d ",*(*p+i));
	}
}
int main()
{
	int i,n,digit[20],**p,*pstr[20];
	scanf("%d",&n);
	for(i=0;i<n;i++)
     {
         scanf("%d",&digit[i]);
     }
    for(i=0;i<n;i++)
    {
        pstr[i]=&digit[i];
    }
     p=&pstr;
     sort(p,n);
     return 0;
}

