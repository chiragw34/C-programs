#include<stdio.h>
#include<malloc.h>
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
int insert_end(int x)
{

    NODE *p;
    NODE *ptr=(NODE *)malloc(sizeof(NODE));
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

}
int insert_beg(int x)
{
    NODE *ptr=(NODE *)malloc(sizeof(NODE));
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

int insert_before(int x,int key)
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
    else {
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

void main()
    {
        int option,op,x,key;
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

        }while(option!=9);
   }


