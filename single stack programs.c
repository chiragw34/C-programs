#include <stdio.h>
#include <malloc.h>
#define max 10
int stackArray[max];
int top;
int push(int x)
{
    if (top == max-1)
    {
        printf("stack is full");
        return 0;
    }
    top++;
    stackArray[top]=x;
    printf("%d is pushed",x);
    return 1;
}
int pop()
{
    if (top==-1)
    {
        printf("stack is empty");
        return 0;
    }
    printf("%d has been popped out",top);
    top--;//removing the access from user.
    return 1;
}
void peep()
{
     if (top==-1)
    {
        printf("stack is empty");
    }
    else printf("%d is on the top",stackArray[top]);
}
void traverse()
{
    int i;
     if (top==-1)
    {
        printf("stack is full");
    }
    else
        for (i=top;i>=0;i--)
        printf("%d\t",stackArray[i]);
}
void main()
{
    int option,p,opt;
    top=-1;
    do
    {
        printf("\nx-x-x-x-choose an option-x-x-x-x");
        printf("\n1. Push into stack");
        printf("\n2. Pop from stack");
        printf("\n3. Peep into stack");
        printf("\n4. Traverse");
        printf("\n5.exit\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:printf("enter the number to be pushed:-");
                    scanf("%d",&p);
                    opt=push(p);
                    if(opt==0)
                        printf("element not pushed");
                    break;
            case 2: opt=pop();
                    if (opt==0)
                        printf("element not popped");
                    break;
            case 3: peep();
                    break;
            case 4: traverse();
                    break;
            case 5: break;
            default:printf("invalid option");
        }
    }while(option!=5);
}
