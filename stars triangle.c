#include <stdio.h>
void main()
{
    int i,j,n,k;
    printf("enter the n:-");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        for (k=1;k<=n-i;k++)
            printf("   ");
        for (j=1;j<=2*i-1;j++)
            printf(" %d ",k);
        printf("\n");


    }
    for (i=1;n>=i;i++)
    {
        for (k=1;k<=n+
        i;k++)
            printf("   ");
        for (j=1;j<=2*i-1;j++)
            printf(" %d ",k);
        printf("\n");


    }
}
