#include<stdio.h>
int main()
{
    char ch;
    double a,p;
    scanf("%c %lf",&ch,&a);
    switch(ch)
    {
    	case 'A':
    		p=a*19.99;
    		printf("%.2f\n",p);
    		break;
    	case 'B':
    		p=a*17.99;
    		printf("%.2f\n",p);
    		break;
    	case 'C':
    		p=a*15.99;
    		printf("%.2f\n",p);
    		break;
    	case 'D':
    		p=a*11.99;
    		printf("%.2f\n",p);
    		break;
    	default:
    		printf("No available.\n");
	}
	return 0;
}
