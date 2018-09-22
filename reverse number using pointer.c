#include <stdio.h>
void main()
{
    int x,y;
    void reverse(int *,int *);
    printf("enter two numbers:-\t");
    scanf("%d %d",&x,&y);
    printf("numbers before swaping\n%d\t%d\n",x,y);
    reverse(&x,&y);
    printf("numbers after swaping\n%d\t%d",x,y);
}
void reverse(int *p,int*q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
