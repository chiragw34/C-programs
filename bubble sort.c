//C PROGRAM FOR BUBBLE SORT

#include<stdio.h>
void main ()
{
    int i,j,n,temp;
    int a[50];


    printf("enter the number of elements:-");
    scanf("%d",&n);

    printf("enter the elements:-\n");
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("sorted array is:-\n");
    for (i=0;i<n;i++)
        printf("%d\t",a[i]);
}


