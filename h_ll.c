#include<stdio.h>
#include<malloc.h>
/*typedef struct node
{
   int data;
   struct node *next;
}NODE;
NODE *start=NULL;*/
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *start=NULL;

void create()
{
    char option;
    int x;
    start=NULL;
    option='y';
    while(option=='Y'||option=='y')
    {
        printf("Enter the value of the node to be inserted:");
        scanf("%d",&x);
        insert_end(x);
        fflush(stdin);
        printf("DO YOU WANT TO INSERT MORE DATA?\n");
        scanf("%d",&option);

    }
}

/*int insert_beg(int x)
{
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("memory is full\n");
        return 0;

    }
    ptr->data=x;
    ptr->next=NULL;
    if(start==NULL)
    {
        start=ptr;
    }
    else
        ptr->next=start;
        start=ptr;
        printf("%d is inserted\n",x);
        return 1;

}*/
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
/*
int insert_end(int x)
{

    NODE *p;
    NODE *ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("memory is full\n");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    if(start==NULL)
    {
        start=ptr;
    }

    else
        p=start;
    while(p!=NULL)
        p=p->next;
    p->next=ptr;
    printf("%d is inserted\n",x);

}*/
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
int insert_after(int x,int key)
{  NODE  *p;
    NODE *ptr=(NODE *)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("memory is full\n");
        return 0;

    }
    ptr->data=x;
    ptr->next=NULL;
    p=start;
    while(p->data!=key&&p->next!=NULL)
    {
        p=p->next;

    }
    if (p->data==key)
    {
        ptr->next=p->next;
        p->next=ptr;
        printf("%d is inserted",x);
        return 1;
    }
    else
    {
        printf("Element not found");
        return 0;
    }

}

/*int insert_before(int x,int key)
{
    NODE *prev,*p;
    NODE *ptr=(NODE *)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("memory is full\n");
        return 0;

    }
    ptr->data=x;
    ptr->next=NULL;
    p=start;
    prev=NULL;
    while(p->data!=key&&p->next!=NULL)
{
     prev=p;
    p=p->next;
}
if(p->data!=key)
{
    printf("element not found");
    return 0;
}
else
{
    if(p==start)
    {
        ptr->next=start;
        start=ptr;
    }

    else
    {
        ptr->next=prev->next;
        prev->next=ptr;
    }
    printf("%d is inserted",x);
    return 1;
}*/
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
int delete_beg()
{
    NODE *p;
    if(start==NULL)
    {
        printf("Linkedlist is empty\n");
        return 0;
    }
    p=start;
    if(start->next==NULL)
    {
        start=NULL;
    }
    else
    {
        start=p->next;
        p->next=NULL;
    }
    printf("%d is deleted",p->data);
    free(p);
    return 1;
}
int delete_end()
{
    NODE *prev,*p;
    if(start==NULL)
    {
        printf("list is empty");
        return 0;

    }
    p=start;
    prev=NULL;
    if(start->next==NULL)
    {
        start=NULL;

    }
    else
    {
        while (p->next!=NULL)
        {
            prev=p;
            p=p->next;

        }
    }
    printf("%d is deleted\n",p->data);
    free(p);
    return 1;

}
int destroy()
{
  NODE *prev,*p;
  p=start;
  prev=NULL;
  while(p!=NULL)
  {
    prev=p;
  p=p->next;
  prev->next=NULL;
  free(prev);
  }
  start=NULL;
  printf("linklist is destroyed");

}
  void display()
  {
      NODE *p;
      p=start;
      printf("the created linklist is \n");
      while(p!=NULL)
      {
          printf("%d",p->data);
          p=p->next;
      }
  }
    /*int main()
    {
        int option,op;
        printf("***MENU***\n");
        printf("0. CREATE\n");
        printf("1. INSERT AT THE BEGINNING\n");
        printf("2. INSERT AT THE END \n");
        printf("3. INSERT AFTER \n");
        printf("4. INSERT BEFORE\n");
        printf("5. DELETE BEGINNING\n");
        printf("6. DELETE END\n");
        printf("7. DESTROY THE LINKLIST");
        printf("8. DISPLAY\n");
        printf("9. EXIT\n");
        do
        {

            printf("enter your option:\n");
            scanf("%d",&option);
            switch(option)
            {
                case 0:create();
                break;
                case 1: printf("enter the number to be inserted at beg:\n");
                scanf("%d",&x);
                op=insert_beg(x);
                if(op==0)
                    printf("Element not inserted.");
                break;
                case 2: printf("enter the number to be inserted at end:\n");
                scanf("%d",&x);
                op=insert_end(x);
                if(op==0)
                    printf("Element not inserted.");
                break;
                case 3: printf("enter the number to be inserted at after :\n");
                scanf("%d",&x);
                printf("enter the node after which the data to be inserted:\n");
                scanf("%d",key);
                op=insert_after(x,key);
                if(op==0)
                    printf("Element not inserted.");
                break;
                case 4: printf("enter the number to be inserted at after :\n");
                scanf("%d",&x);
                printf("enter the node before which the data to be inserted:\n");
                scanf("%d",key);
                op=insert_before(x,key);
                if(op==0)
                    printf("Element not inserted.");
                break;
                case 5: op=delete_beg();
                if (op==0)
                    printf("deletion not possible");
                break;
                case 6:op=delete_end();
                if (op==0)
                    printf("deletion not possible");
                break;
                case 7: destroy();
                printf("linklist is destroyed");
                break;
                case 8:display();
                break;
                case 9: break;

            }

        }
        while(option!=9);
        return 0;

    }

}
*/
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


