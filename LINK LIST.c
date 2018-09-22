#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *start=NULL;

NODE *start1=NULL;

int insert_beg(int x)
{
    NODE *ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    if (ptr==NULL)
    {
        printf("memory full\n");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    if (start==NULL)
       {
           start=ptr;
       }
    else
    {
        ptr->next=start;
        start=ptr;
    }
    printf("%d has been inserted\n",x);
    return 1;
}
int insert_end(int x)
{
    NODE*p;
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    if (ptr==NULL)
    {
        printf("memory full\n");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    if (start==NULL)
        start=ptr;
    else
    {
        p=start;
        while (p->next!=NULL)
            p=p->next;
        p->next=ptr;
    }
    printf("%d has been inserted\n",x);
    return 1;
}
int insert_before(int x,int key)
{
    NODE *p,*prev;
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    if (ptr==NULL)
    {
        printf("memory full");
        return 0;
    }
    p=start;
    prev=NULL;
    ptr->data=x;
    while(p->next!=NULL && p->data!=key)
    {
        prev=p;
        p=p->next;
    }
    if (p->next==NULL && p->data!=key)
    {
        printf("%d not found\n",key);
        return 0;
    }
    else
    {
        if (p==start)
        {
            ptr->next=p;
            start=ptr;
        }
        else
        {
            ptr->next=prev->next;
            prev->next=ptr;
        }
        printf("%d has been inserted\n",x);
        return 1;
    }
}
int insert_after(int x,int key)
{
    NODE *p;
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    if (ptr==NULL)
    {
        printf("memory full");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    p=start;
    while(p->next!=NULL && p->data!=key)
        p=p->next;
    if (p->data==key)
    {
        ptr->next=p->next;
        p->next=ptr;
        printf("%d has been inserted\n",x);
        return 1;
    }
    else
    {
        printf("key is absent");
        return 0;
    }

}
int insert_pos(int x,int pos)
{
    int ret,i;
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    NODE *p;
    if (ptr==NULL)
    {
        printf("memory full\n");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    if (pos <=1)
    {
        ret=insert_beg(x);
        return ret;
    }
    p=start;
    for(i=1;i<=pos-2;i++)
    {
        p=p->next;
        if(p==NULL)
            break;
    }
    if (i<=pos-2)
    {
        printf("invalid position\n");
        return 0;
    }
    ptr->next=p->next;
    p->next=ptr;
    printf("%d has been inserted\n",x);
    return 1;
}
int delete_beg()
{
    NODE *p;
    if (start==NULL)
    {
        printf("link list empty\n");
        return 0;
    }
    p=start;
    if (start->next==NULL)
        start=NULL;
    else
    {
        start=p->next;
        p->next=NULL;
    }
    printf("%d has been deleted\n",p->data);
    free(p);
    return 1;
}
int delete_end()
{
    NODE *p,*prev;
    if (start==NULL)
    {
        printf("linklist is empty\n");
        return 0;
    }
    p=start;
    prev=NULL;
    if (start->next==NULL)
        start=NULL;
    else
    {
        while(p->next!=NULL)
        {
            prev=p;
            p=p->next;
        }
        prev->next=NULL;
    }
    printf("%d has been deleted\n",p->data);
    free(p);
    return 1;
}
int delete_after(int key)
{
    NODE *p,*ptr;
    if(start==NULL)
    {
        printf("link is empty\n");
        return 0;
    }
    if(start->next==NULL)
    {
        printf("list has only one element\n");
        return 0;
    }
    p=start;
    while(p->data!=key && p->next!=NULL)
        p=p->next;
    if(p->next==NULL)
    {
        if(p->data==key)
            printf("no element after key\n");
        else
            printf("key not found\n");
        return 0;
    }
    ptr=p->next;
    p->next=ptr->next;
    ptr->next=NULL;
    printf("%d has been deleted\n",ptr->data);
    return 1;
}
int delete_node(int key)
{
    NODE *p,*prev;
    if(start==NULL)
    {
        printf("linklist is empty\n");
        return 0;
    }
    p=start;
    prev=NULL;
    while(p->data!=key && p->next!=NULL)
    {
        prev=p;
        p=p->next;
    }
    if(p->next==NULL && p->data!=key)
    {
        printf("key not found\n");
        return 0;
    }
    if(start==p)
        start=start->next;
    else
        prev->next=p->next;
    p->next=NULL;
    printf("%d has been deleted\n",p->data);
    return 1;
}
void traverse()
{
    NODE *p;
    p=start;
    if(start==NULL)
        printf("linklist is empty\n");
    else
    {
        while(p!=NULL)
        {
            printf("%d\t",p->data);
            p=p->next;
        }
    }
}
int search(int key)
{
    NODE *p;
    if (start==NULL)
    {
        printf("linklist is empty\n");
        return 0;
    }
    p=start;
    while(p->data!=key && p->next!=NULL)
        p=p->next;
    if(p->data==key)
    {
        printf("%d is present\n",key);
        return 1;
    }
    else
    {
        printf("%d is not present\n",key);
        return 0;
    }
}
void main()
{
    int option,x,ans,key;
    do
    {
        printf("\n*choose an option*");
        printf("\n1.  Insert a node at beginning.");
        printf("\n2.  Insert a node at the end.");
        printf("\n3.  Insert a node before a given node.");
        printf("\n4.  Insert a node after a given node.");
        printf("\n5.  Insert a node at specific position.");
        printf("\n6.  Delete node at beginning.");
        printf("\n7.  Delete node at end.");
        printf("\n8.  Delete node after a given node.");
        printf("\n9.  Delete a given node.");
        printf("\n10. Display the list.");
        printf("\n11. Search in linked list.");
        printf("\n12. Exit.");

        printf("\nEnter your option:-");
        scanf("%d",&option);

        switch (option)
        {
            case 1:{
                        printf("enter the node to be inserted:-");
                        scanf("%d",&x);
                        ans=insert_beg(x);
                        if(ans==0)
                            printf("element not inserted.\n");
                        break;
                    }
            case 2:{
                        printf("enter the node to be inserted:-");
                        scanf("%d",&x);
                        ans=insert_end(x);
                        if(ans==0)
                            printf("element not inserted.\n");
                        break;
                    }
            case 3:{
                        printf("enter the node to be inserted:-");
                        scanf("%d",&x);
                        printf("enter the node before which %d has to be inserted:-",x);
                        scanf("%d",&key);
                        ans=insert_before(x,key);
                        if(ans==0)
                            printf("element not inserted.\n");
                        break;
                    }
            case 4:{
                        printf("enter the node to be inserted:-");
                        scanf("%d",&x);
                        printf("enter the node after which %d has to be inserted:-",x);
                        scanf("%d",&key);
                        ans=insert_after(x,key);
                        if(ans==0)
                            printf("element not inserted.\n");
                        break;
                    }
            case 5:{
                        printf("enter the node to be inserted:-");
                        scanf("%d",&x);
                        printf("enter the position at which %d has to be inserted:-",x);
                        scanf("%d",&key);
                        ans=insert_pos(x,key);
                        if(ans==0)
                            printf("element not inserted.\n");
                        break;
                    }
            case 6:{
                        ans=delete_beg(x);
                        if(ans==0)
                            printf("element not deleted\n");
                        break;
                    }
            case 7:{
                      ans=delete_end();
                      if(ans==0)
                            printf("element not deleted\n");
                        break;
                    }
            case 8:{
                        printf("enter the element after which node has to be deleted:-");
                        scanf("%d",&key);
                        ans=delete_after(key);
                        if(ans==0)
                            printf("element not deleted\n");
                        break;
                    }
            case 9:{
                        printf("enter the node to be deleted:-");
                        scanf("%d",&key);
                        ans=delete_node(key);
                        if(ans==0)
                            printf("element not deleted\n");
                        break;
                    }
            case 10:{
                        traverse();
                        break;
                    }
            case 11:{
                        printf("enter the element to be searched:-");
                        scanf("%d",&key);
                        ans=search(key);
                        break;
                    }
            case 12:break;
            default:printf("invalid option!\n");break;
        }
    }while(option!=12);
}
