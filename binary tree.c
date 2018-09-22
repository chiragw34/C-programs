#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>
#define  NULL  0

struct  node
{
    int  data;
    struct  node  *left,*right;
};
int  ncount,lcount;
struct node * create()
{
    int  x;
    struct  node  *pnode;
    printf("Enter the data value of node.\n");
    printf("Enter -1 for no data or NULL.\n");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    pnode=(struct node*)malloc(sizeof(struct node));
    pnode->data=x;
    printf("Enter the left child of %d.\n",x);
    pnode->left=create();
    printf("Enter the right child of %d.\n",x);
    pnode->right=create();
    return pnode;
}

/* This function will copy one binary tree into another */
struct node *  copy(struct node *root)
{
    struct node *pnode;
    if(root==NULL)
        return NULL;
    pnode=(struct node*)malloc(sizeof(struct node));
    pnode->data=root->data;
    pnode->left=copy(root->left);
    pnode->right=copy(root->right);
    return pnode;
}

struct node *  mirror(struct node *root)
{
    struct node *pnode;
    if(root==NULL)
        return NULL;
    pnode=(struct node*)malloc(sizeof(struct node));
    pnode->data=root->data;
    pnode->left=mirror(root->right);
    pnode->right=mirror(root->left);
    return pnode;
}

/* Binary Tree Traversal methods */
void  preorder(struct  node  *root)
{
    if(root!=NULL)
    {
        /* Visit the root */
        printf("%d " , root->data);
        /* Traverse the left subtree in preorder */
        preorder(root->left);
        /* Traverse the right subtree in preorder */
        preorder(root->right);
    }
}

void  inorder(struct  node  *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void  postorder(struct  node  *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}



void main()
{
    struct node *root = NULL;
    struct node *root1 = NULL;
    struct node *root2 = NULL;
    int  ch;
    do
    {
        printf("1.Create. \n");
        printf("2.Copy Tree. \n");
        printf("3.Mirror Tree. \n");
        printf("4.Preorder. \n");
        printf("5.Inorder. \n");
        printf("6.Postorder. \n");
        printf("7.Exit. \n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: root=create();
                    break;
            case 2: root1=copy(root);
                    printf("Preorder traversal of copied tree is: \n");
                    preorder(root1);
                    printf("\n");
                    printf("Inorder traversal of copied tree is: \n");
                    inorder(root1);
                    printf("\n");
                    printf("Postorder traversal of copied tree is: \n");
                    postorder(root1);
                    printf("\n");
                    break;
            case 3: root2=mirror(root);
                    printf("Preorder traversal of mirrored tree is: \n");
                    preorder(root2);
                    printf("\n");
                    printf("Inorder traversal of mirrored tree is: \n");
                    inorder(root2);
                    printf("\n");
                    printf("Postorder traversal of mirrored tree is: \n");
                    postorder(root2);
                    printf("\n");
                    break;
            case 4: preorder(root);
                    printf("\n");
                    break;
            case 5: inorder(root);
                    printf("\n");
                    break;
            case 6: postorder(root);
                    printf("\n");
                    break;
            case 7: break;
        }
    }
    while(ch!=7);
    getch();
}

