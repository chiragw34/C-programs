#include<stdio.h>
int linear (int *a,int n,int key)
{
    int i,c=0;
    for (i=0;i<n;i++)
    {
        c++;
        if (a[i]==key)
        {
            printf("\n%d is present in array\n",key);
            break;
        }
    }
    if (i==n)
        printf("\n%d is not present in array\n",key);
    return c;
}
void main()
{
    int i,n,key,a[100],d;

    printf("enter the no. of elements:-");
    scanf("%d",&n);

    printf("enter the elements of array\n");
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter the element to be searched:-");
    scanf("%d",&key);

    d=linear(a,n,key);
    printf("no.of comparisions = %d",d);

}
