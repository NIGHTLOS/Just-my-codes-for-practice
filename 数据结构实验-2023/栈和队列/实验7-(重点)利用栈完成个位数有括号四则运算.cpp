#include<bits/stdc++.h>
using namespace std;
#define N 1005 
struct nums_stack  
{
    int nums_stack[N];
    int top; 
}Num;
struct stack_sym 
{
    char symbols[N];
    int top; 
}Symbols;

void js(struct nums_stack* nums_stack, struct stack_sym* symbols)
{
    while (symbols->top != -1 && symbols->symbols[symbols->top] != '(')
    {
        switch (symbols->symbols[symbols->top])
        {
            case '*':
                nums_stack->nums_stack[nums_stack->top - 1] *= nums_stack->nums_stack[nums_stack->top];
                break;
            case '/':
                nums_stack->nums_stack[nums_stack->top - 1] /= nums_stack->nums_stack[nums_stack->top];
                break;
            case '+':
                nums_stack->nums_stack[nums_stack->top - 1] += nums_stack->nums_stack[nums_stack->top];
                break;
            case '-':
                nums_stack->nums_stack[nums_stack->top - 1] -= nums_stack->nums_stack[nums_stack->top];
                break;
        }
        (nums_stack->top)--;
        (symbols->top)--;
    }
}

int main()
{
    int num = 0; 
    int flag = 2; 
    char c;
    Num.top = Symbols.top = -1;
    while ((c = getchar()) != '#')
    {
        if (( '0' <= c && c <= '9'))
        {
            flag = 1;
            num = num * 10 + c - '0';
        }
        else if (c != ' ')
        {
            if (flag != 2)
            {
                Num.nums_stack[++Num.top] = num;
                num = 0;
                flag = 2;
            }
            if (Symbols.top != -1)
            {
                if ((c == '+' || c == '-') && (Symbols.symbols[Symbols.top] == '*' || (Symbols.symbols[Symbols.top] == '/'))) // 只有当栈顶元素优先级大于 C 的时候才会outpush
                {
                    js(&Num, &Symbols);
                }
                else if (c == ')')
                {
                    js(&Num, &Symbols);
                    if (Symbols.symbols[Symbols.top] == '(')
                    {
                        (Symbols.top)--;
                    }
                    continue;
                }
            }
            Symbols.symbols[++Symbols.top] = c;
        }
    }
    if (flag != 2)
    {
        Num.nums_stack[++Num.top] = num;
    }
    if (Symbols.top != -1) //判断栈空
    {
        js(&Num, &Symbols);
    }
    printf("%d\n", Num.nums_stack[0]);
    return 0;
}


