#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
int main()
{
    int n,i,ans;
    while(scanf("%d",&n)!=-1)
    {
       struct node *head=(struct node*)malloc(sizeof(struct node));
	   struct node *p=head;
	   scanf("%d",&p->data);
	   head->next=NULL;
	   for(i=1;i<n;i++)
	    {
		  struct node *q=(struct node*)malloc(sizeof(struct node));//开辟节点
		  q->next=head;//插入头节点
		  head=q;
		  p=q;
		  scanf("%d",&p->data);//对头节点进行输入
	    }
	    ans=0;
	    p=head;
        int flag=1;
        while(1)
        {
            if(p->data%2==0)
            {
                if(flag==1)
                {
                    printf("%d",p->data);
                    ans++;
                    flag = 0;
                }
                else
                {
                	ans++;
                    printf("  %d",p->data);
				}
            }
            p = p->next;
            if(p==NULL)
            break;
        }
        printf("\n");
        printf("%d\n",ans);
    }
    return 0;
}
