#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int i, j;
    char a[500];
    while (gets(a))
    {
        int len = strlen(a);
        int sum = 0;
        for (i = 0; i < len; i++)
        {
            if (a[i] == ' ')
                sum = sum + 1;
        }
        printf("%d\n", sum + 1);
        char b[500];
        int k = 0;
        char t;
        a[len]=' '; 
        for (i = 0; i <=len ; i++) 
        {
            if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) 
            {
                b[k++] = a[i];
            }
            else if (a[i] == ' ' || ispunct(a[i]))//判断是否为标点，基本函数之一 
            {
                if (k == 0)
                    continue;
                if (ispunct(a[i - 1]))
                    k--;
                for (j = 0; j < k / 2; j++)
                {
                    t = b[j];
                    b[j] = b[k - j - 1];
                    b[k - j - 1] = t;
                }
                b[k] = 0;
                printf("%s ", b);
                k = b[k] = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
