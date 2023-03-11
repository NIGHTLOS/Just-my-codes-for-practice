 #include <stdio.h>
 #include <stdlib.h>
int main()
{
    int x,y;
    long z;
    long IntPower(int base,int exp);
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        z=IntPower(x,y); 
        printf("%ld\n",z);
    }
    return 0;
}
 //start
 long IntPower(int x,int y)
 {
 	long z,sum;
 	sum=1;
	 for(int i=1;i<=y;i++)
 	  {sum=sum*x;}
 	   return sum;
 }
 //end
