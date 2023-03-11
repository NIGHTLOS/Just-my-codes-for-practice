#include "stdio.h"
int cube(int i)
{
	int ans;
	ans=i*i*i;
	return ans;
}
int main()
{
    int i;
    scanf("%d",&i);
    printf("%d\n",cube(i));
	return 0;
} 
