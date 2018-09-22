#include<stdio.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}NODE;
NODE *start;
int insert_beg(int x)
{
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    if (ptr==NULL)
    {
        printf("memory full.");
        return 0;
    }
    ptr->data=x;
    ptr->next=ptr->prev=NULL;
    if(start==NULL)
        start=ptr;
    else
    {
        ptr->next=start;
        start->prev=ptr;
        start=ptr;
    }
    printf("%d has been inserted",x);
    return 1;
}
int insert_end(int x)
{
    NODE *p,*ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("memory full");
        return 0;
    }
    ptr->data=x;
    ptr->next=ptr->prev=NULL;
    if(start==NULL)
        start=ptr;
    else
    {
        p=start;
        while(p->next!=NULL)
            p=p->next;
        p->next=ptr;
        ptr->prev=p;
    }
    printf("%d has been inserted",x);
    return 1;
}
int insert_after(int x,int key)
{
    NODE *p,*ptr=(NODE*)malloc(sizeof(NODE));
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("memory full");
        return 0;
    }
    ptr->data=x;
    ptr->next=ptr->prev=NULL;
    if(start==NULL)
    {
        printf("linked list is empty\n");
        return 0;
    }
    p=start;
    while(p->data!=key && p->next!=NULL)
        p=p->next;
    if(p->data==key)
    {
        ptr->prev=p;
        ptr->next=p->next;
        p->next=ptr;
        if(ptr->next!=NULL)
            ptr->next->prev=ptr;
    }
    else
    {
        printf("key not found");
        return 0;
    }
    printf("%d has been inserted",x);
    return 1;
}
int del_beg()
{
    NODE *p;
    if (start==NULL)
    {
        printf("linked list is empty");
        return 0;
    }
    p=start;
    if(start->next==NULL)
    {
        printf("%d has been deleted",p->data);
        free(p);
        return 1;
    }
    start=start->next;
    start->prev=NULL;
    p->next=NULL;
    printf("%d has been deleted",p->data);
    free(p);
    return 1;
}
int del_end()
{
    NODE *p;
    if(start==NULL)
    {
        printf("linked list is empty");
        return 0;
    }
    if(start->next==NULL)
    {
        printf("%d has been deleted",start->data);
        free(start);
        return 1;
    }
    p=start;
    while(p->next!=NULL)
        p=p->next;
    p->prev->next=NULL;
    p->prev=NULL;
    printf("%d hav been deleted",p->data);
    free(p);
    return 1;
}
int del_node(int key)
{
    NODE *p,*q;
    if(start==NULL)
    {
        printf("linked list empty");
        return 0;
    }
    p=start;
    while(p->data!=key && p->next!=NULL)
        p=p->next;
    if(p->data!=key)
    {
        printf("key not found");
        return 0;
    }
    if (p==start)
    {
        if (start->next==NULL)
            start=NULL;
        else
        {
            start=start->next;
            p->next=NULL;
            start->prev=NULL;
        }
    }
    else
    {
        p->prev=q;
        q->next=p->next;
        if(p->next!=NULL)
            p->next->prev=q;
        p->next=NULL;
        p->prev=NULL;
    }
    printf("%d has been deleted",p->data);
    free(p);
    return 1;
}
void traverse()
{
    NODE *p;
    if(start==NULL)
        printf("linked list is empty");
    else
    {
        p=start;
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            p=p->next;
        }
    }
}
int main()
{
    int option,p,opt,key;
    do
    {
        printf("\nx-x-x-x-choose an option-x-x-x-x");
        printf("\n1. insert beginning");
        printf("\n2. insert end");
        printf("\n3. insert after");
        printf("\n4. delete beginning");
        printf("\n5. delete end");
        printf("\n6. delete specific node");
        printf("\n7. traverse");
        printf("\n8. exit\n");
        printf("enter your option:-");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("enter the number to be inserted:-");
                    scanf("%d",&p);
                    opt=insert_beg(p);
                    if(opt==0)
                        printf("element not inserted");
                    break;
            case 2: printf("enter the number to be inserted:-");
                    scanf("%d",&p);
                    opt=insert_end(p);
                    if(opt==0)
                        printf("element not inserted");
                    break;
            case 3: printf("enter the number to be inserted:-");
                    scanf("%d",&p);
                    printf("enter the element after which %d has to be inserted:-",p);
                    scanf("%d",&key);
                    opt=insert_after(p,key);
                    if(opt==0)
                        printf("element not inserted");
                    break;
            case 4: opt=del_beg();
                    if (opt==0)
                        printf("element not deleted");
                    break;
            case 5: opt=del_end();
                    if (opt==0)
                        printf("element not deleted");
                    break;
            case 6: printf("enter the node to be deleted:-");
                    scanf("%d",&key);
                    opt=del_node(key);
                    if (opt==0)
                        printf("key not deleted");
                    break;
            case 7: traverse();
                    break;
            case 8: break;
            default:printf("invalid option");
        }
    }while(option!=8);
}
