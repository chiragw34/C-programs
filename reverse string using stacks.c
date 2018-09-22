#include <stdio.h>
#include <malloc.h>
#include<string.h>
#define max 100
char stackArray[max];
int top;

int push(char x)
{
    if (top == max-1)
    {
        printf("stack is full");
        return 0;
    }
    top++;
    stackArray[top]=x;
}
void traverse()
{
    int i;
     if (top==-1)
    {
        printf("stack is empty");
    }
    else
        for (i=top;i>=0;i--)
        printf("%c",stackArray[i]);
}
void main()
{
    int i;
    char s[100];
    top=-1;
    printf("enter the string\n");
    gets(s);
    for(i=0;i<strlen(s);i++)
        push(s[i]);

    traverse();
}
