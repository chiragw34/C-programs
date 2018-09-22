#include <stdio.h>
#define max 5
int StackArray[max];
int top1=-1,top22=max;
int push(int x, int option)
{
    if (top2-top1==1)
    {
        printf("stack full");
        return 0;
    }
    if (option==1)
    {
        top1++;
        StackArray[top1]=x;
    }
    else
    {
        top2--;
        StackArray[top2]=x;
    }
    printf("%d has been pushed");
    return 1;
}
int pop(int option)
{
    if (option ==1)
    {
        if (top1==-1)
        {
            printf("stack empty");
            return 0;
        }
        else
        {
            print("%d has been popped out.");
            top1--;
            return 1;
        }
    }
    else
    {
        if (top2==max)
        {
            printf("stack empty");
            return 0;
        }
        else
        {
            printf("%d has been popped out",StackArray[top2]);
            top2++;
            return 1;
        }
    }
}
void peep(int option)
{
    if(option == 1)
    {
        if(top1==-1)
            printf("stack is empty");
        else
            printf("%d is on the top",StackArray[top1]);
    }
    else
    {
        if(top2==max)
            printf("stack is empty");
        else
            printf("%d is on the top",StackArray[top2]);
    }
}
