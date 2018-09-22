
#include <stdio.h>
void main()
{
    int a[100],n,i;
    void insertion_sort (int [],int);
    printf("enter the number of elements:-");
    scanf("%d",&n);
    printf("enter the elements:-\n");
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    insertion_sort(a,n);
    printf("sorted elements are:-\n");
    for (i=0;i<n;i++)
        printf("%d\t",a[i]);
}
void insertion_sort(int x[],int n)
{
    int i,y,k;
    for (k=1;k<n;k++)
    {
        y=x[k];
        for (i=k-1;i>=0 && y<x[i];i--)
            x[i+1]=x[i];
        x[i+1]=y;
    }
}
