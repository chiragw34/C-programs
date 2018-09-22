#include <stdio.h>
#include "search.h"
int main()
{
    int n,i,key,a[100],flag=0;
    int ch;
    printf("Enter the number of elements: ");
    scanf ("%d",&n);
    printf("\nEnter the elements: ");
    for (i=0;i<n;i++)
    {
        scanf ("%d",&a[i]);
    }
    printf("\nEnter the element to be searched: ");
    scanf ("%d",&key);
    again:
    printf("\nEnter 1 for linear search\nEnter 2 for binary search\n");
    scanf ("%d",&ch);
    switch(ch)
    {
    case 1:
        lsearch(a,n,key);
        break;
    case 2:
        bsearch(a,n,key);
        break;
    default:
        {
        printf("Error, try again.\n");
        goto again;
        }
    }
    return 0;
}

