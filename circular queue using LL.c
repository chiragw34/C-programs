#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *front=NULL;
NODE *rear=NULL;

int insert(int x)
{
    NODE *ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("memory full\n");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    if(front==NULL)
    {
        front=rear=ptr;
        rear->next=front;
    }
    else
    {
        rear->next=ptr;
        rear=ptr;
        rear->next=front;
    }
    printf("%d is inserted",x);
    return 1;
}
int del()
{
    NODE *ptr;
    if(front==NULL)
    {
        printf("queue is empty");
        return 0;
    }
    ptr=front;
    if(front==rear)
        front=rear=NULL;
    else
    {
        front=front->next;
        rear->next=front;
        ptr->next=NULL;
    }
    printf("%d has been deleted",ptr->data);
    free(ptr);
    return 1;
}
void check_front()
{
    if (front==NULL)
        printf("queue is empty\n");
    else
        printf("%d is at front\n",front->data);
}
void traverse()
{
    NODE *p;
    p=front;
    if(p==NULL)
        printf("queue is empty\n");
    else
    {
        printf("the contents of queue are\n");
        while(p!=rear)
        {
            printf("%d\t",p->data);
            p=p->next;
        }
        printf("%d",rear->data);
    }
}
int main()
{
    int option,p,opt;
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

