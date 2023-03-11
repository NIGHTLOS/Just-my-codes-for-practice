#include <stdio.h>
 
int main()
{
    int i,N;   
    int index = 0;    
    int max;
    int num[N];   
    while(scanf("%d",&N)!=-1)
    {
    for(i=0;i<N;i++)
	{
        scanf("%d",&num[i]);
    }
    max = num[0];
    for(i=0;i<N;i++)
	{
        if(max<num[i])
		{
            max = num[i];
            index = i+1;
        }
    }
    printf("%d\n",index);
    }
    return 0;
}
