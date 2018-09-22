#include<stdio.h>
#define max 25
int top=-1;
void push(char opstack[],char x)
{
    if(top>=max-1)
        printf("stack is full\n");
    else
        opstack[++top]=x;
}
char pop(char opstack[])
{
    if(top<0)
    {
        printf("stack empty\n");
        return ' ';
    }
    else
    {
        top--;
        return opstack[top+1];
    }
}
char stop(char opstack[])
{
    if(top<0)
    {
        printf("stack empty\n");
        return ' ';
    }
    else
        return opstack[top];
}
int f(char c)
{
    switch(c)
    {
        case '-':
        case '+':return 1;
        case '*':
        case '/':return 2;
    }
    return 0;
}
void infix_postfix(char infix[])
{
    char opstack[max],postfix[max],symbol,topsymbol;
    int i=0,j=0;
    while (infix[i]!='#')
    {
        symbol=infix[i];//get front character of string//
        if (symbol>='A'&&symbol<='Z' || symbol>='a'&&symbol<='z')
            postfix[j++]=infix[i];
        else
            if(symbol=='(')
               push(opstack,symbol);
            else
            {
                while(top!=-1 && f(stop(opstack))>=f(symbol))
                {
                    topsymbol=pop(opstack);
                    if(topsymbol!='(')
                        postfix[j++]=topsymbol;
                    else break;
                }
                if (symbol!=')')
                    push(opstack,symbol);
            }
            i++;
    }
    while(top!=-1)
    {
        topsymbol=pop(opstack);
        postfix[j++]=topsymbol;
    }
    postfix[j]='#';
    i=0;
    while (postfix[i]!='#')
        printf("%c",postfix[i++]);
}
void main()
{
    char x[50];
    int i=0;
    printf("enter the expression in infix notation ending with #\n");
    do
    {
        scanf("%c",&x[i]);
    }while(x[i++]!='#');
    infix_postfix(x);
}

