#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next,*prev;
}NODE;
NODE *front=NULL;
NODE *rear=NULL;

int insert_rear(int x)
{
    NODE *ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("memory full");
        return 0;
    }
    ptr->data=x;
    ptr->next=ptr->prev=NULL;
    if(front==NULL)
        front=rear=ptr;
    else
    {
        rear->next=ptr;
        ptr->prev=rear;
        rear=ptr;
    }
    printf("%d has been inserted",x);
    return 1;
}
int insert_front(int x)
{
    NODE *ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("memory full");
        return 0;
    }
    ptr->data=x;
    ptr->next=ptr->prev=NULL;
    if(front==NULL)
        front=rear=ptr;
    else
    {
        front->prev=ptr;
        ptr->next=front;
        front=ptr;
    }
    printf("%d has been inserted",x);
    return 1;
}
int del_front()
{
    NODE *ptr;
    if(front==NULL)
    {
        printf("queue is full");
        return 0;
    }
    ptr=front;
    if(front->next==NULL)
        front=rear=NULL;
    else
    {
        front=front->next;
        front->prev=NULL;
        ptr->next=NULL;
    }
    printf("%d is deleted",ptr->data);
    free(ptr);
    return 1;
}
int del_rear()
{
    NODE *ptr;
    if(front==NULL)
    {
        printf("queue is full");
        return 0;
    }
    ptr=rear;
    if(front->next==NULL)
        front=rear=NULL;
    else
    {
        rear=rear->prev;
        rear->next=NULL;
        ptr->prev=NULL;
    }
    printf("%d is deleted",ptr->data);
    free(ptr);
    return 1;
}
void traverse()
{
    NODE *p;
    p=front;
    if(front==NULL)
        printf("queue is empty");
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
        printf("\n1. insert from rear");
        printf("\n2. insert from front");
        printf("\n3. delete from rear");
        printf("\n4. delete from front");
        printf("\n5. traverse");
        printf("\n6. exit\n");
        printf("enter your option:-");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("enter the number to be inserted:-");
                    scanf("%d",&p);
                    opt=insert_rear(p);
                    if(opt==0)
                        printf("element not inserted");
                    break;
            case 2: printf("enter the number to be inserted:-");
                    scanf("%d",&p);
                    opt=insert_front(p);
                    if(opt==0)
                        printf("element not inserted");
                    break;
            case 3: opt=del_rear();
                    if (opt==0)
                        printf("element not deleted");
                    break;
            case 4: opt=del_front();
                    if (opt==0)
                        printf("element not deleted");
                    break;
            case 5: traverse();
                    break;
            case 6: break;
            default:printf("invalid option");
        }
    }while(option!=6);
}

