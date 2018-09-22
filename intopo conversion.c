#include <stdio.h>
#define max 50
int top=-1;
float a=10,b=5,c=12,d=3;
void push(float opndstack[],float x)
{
    if(top>max-1)
        printf("stack full\n");
    else
        opndstack[++top]=x;
}
float pop(float opndstack[])
{
    if (top<0)
    {
        printf("empty stack\n");
        return -1;
    }
    else
    {
        top--;
        return opndstack[top+1];
    }
}
float eval_postfix(char postfix[])
{
    float opndstack[max];
    char symbol;
    float opnd1,opnd2,value;
    int i=0;
    while(postfix[i]!='#')
    {
        symbol=postfix[i];
        if(symbol>='a'&&symbol<='z')
            switch(symbol)
        {
            case 'a':push(opndstack,a);break;
            case 'b':push(opndstack,b);break;
            case 'c':push(opndstack,c);break;
            case 'd':push(opndstack,d);break;
        }
        else
        {
            opnd2=pop(opndstack);
            opnd1=pop(opndstack);
            switch(symbol)
            {
                case '+':value=opnd1+opnd2;break;
                case '-':value=opnd1-opnd2;break;
                case '*':value=opnd1*opnd2;break;
                case '/':value=opnd1/opnd2;break;
            }
            push(opndstack,value);
        }
        i++;
    }
    return pop(opndstack);
}
void main()
{
    char postfix[50];
    int i=0;
    printf("enter the expression in postfix notation ending with #\n");
    do
    {
        scanf("%c",&postfix[i]);
    }while(postfix[i++]!='#');
    printf("answer=%f\n",eval_postfix(postfix));
}
