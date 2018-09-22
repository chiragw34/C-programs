#include<stdio.h>
#define max 10
int QueueArray[max];
int front,rear;
int insert(int x)
{
    if (rear==max-1)
    {
        printf("queue is full");
        return 0;
    }
    if (front==-1)
        front=0;
        rear++;
        QueueArray[rear]=x;
        printf("%d has been inserted",x);
        return 1;
}
int del()
{
    if (front==-1 || front>rear)
    {
        printf("queue is empty\n");
        return 0;
    }
    printf("%d has been deleted",QueueArray[front]);
    front++;
    if (front>rear)
        front=rear=-1;
    return 1;
}
void check_front()
{
    if (front==-1)
        printf("queue is empty");
    else
        printf("%d is in front",QueueArray[front]);
}
void traverse()
{
    int i;
    if (front==-1 || front>rear)
        printf("queue is empty");
    else
    {
        printf("contents of queue are\n");
        for(i=front;i<=rear;i++)
            printf("%d\t",QueueArray[i]);
    }
}
void main()
{
    int option,opt,p;
    front=-1;
    rear=-1;
    do
    {
        printf("\nx-x-x-x-choose an option-x-x-x-x");
        printf("\n1. insert");
        printf("\n2. delete");
        printf("\n3. check front");
        printf("\n4. traverse");
        printf("\n5. exit\n");
        printf("enter your option:-");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("enter the number to be inserted:-");
                    scanf("%d",&p);
                    opt=insert(p);
                    if(opt==0)
                        printf("element not inserted");
                    break;
            case 2: opt=del();
                    if (opt==0)
                        printf("element not deleted");
                    break;
            case 3: check_front();
                    break;
            case 4: traverse();
                    break;
            case 5: break;
            default:printf("invalid option");
        }
    }while(option!=5);
}
