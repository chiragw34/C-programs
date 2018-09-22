#include<stdio.h>
#include "sort.h"
int main()
{
    int n,i,ch;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d  integers:-\n",n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("Choose sorting technique:-\n");
    printf("1.Bubble Sort.\n");
    printf("2.Insertion Sort.\n");
    do
        {
        scanf("%d",&ch);
        switch(ch)
            {
                case 1:
                bubblesort(a,n);
                break;
                case 2:
                insertionsort(a,n);
                break;
                default:
                printf("Wrong Choice!! Please enter choice again:- ");
            }
        }
    while(ch!=1&&ch!=2);
    printf("The sorted elements are:-\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
