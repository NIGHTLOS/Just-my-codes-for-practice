#include <stdio.h>
#include <stdlib.h>
struct sa{
int num;
struct sa *next;
};
int show(struct sa *h)
{
  int ans=0;
  struct sa *p;
  p=h->next;
  while(p!=NULL)
   {
       ans++;
       printf("%d  ",p->num);
       p=p->next;
   }
   printf("\n");
   printf("%d\n",ans);
   return 0;
}
int main()
{
    struct sa *p,*h;
    int i,n,x;
    h= (struct sa *)malloc(sizeof(struct sa));
    //h->num=100; 头结点没数的尾插法 
    h->next=NULL; 
    p=h;
    while(1)
    {  
	 scanf("%d",&x);
     if(x==0) 
	   {
	   	 break;
	   }
     p->next=(struct sa *)malloc(sizeof(struct sa));
     p=p->next;
     p->num=x;
     p->next=NULL;
    }
    show(h);
    return 0;
}
