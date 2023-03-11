#include<stdio.h>
int main()
{ 
    struct stu_score{
	int mid;
	int end;
	int avg;
}score; 
	while(scanf("%d%d",&score.mid,&score.end)!=EOF)
	{
	score.avg=(score.end+score.mid)/2;
	printf("%d\n",score.avg);
    }
	return 0;
}
