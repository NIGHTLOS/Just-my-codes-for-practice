#include <stdio.h>
#include <string.h>
 struct student 
{
	char name[500];
	int num;
};
int main()
{
	int n,j,k;
	char ch[500];
	struct student STD[5]={{"Huang",0},{"Ouyang",0},{"Duan",0},{"Hong",0},{"Wang",0}};
    scanf("%d",&n);
    struct student tmp;
    for(int i=0;i<n;i++)
    {
    	scanf("%s",ch);
    	for(j=0;j<5;j++)
    	{
    		if(strcmp(ch,STD[j].name)==0)
    		{
    			STD[j].num++;
			}
		}
		for(k=0;k<4;k++)
		{
			for(j=k+1;j<5;j++)
			{
				if(STD[k].num<STD[j].num)
				{
					tmp=STD[k];
					STD[k]=STD[j];
					STD[j]=tmp;
				}
			}
		}
	}
	for(k=0;k<5;k++)
	{
		printf("%s %d\n",STD[k].name,STD[k].num);
	}
   return 0; 
}
