#include<stdio.h>
void main()
{
    int i,n;
    printf("enter th number");
    scanf("%d",&n);
    printf("//factors of %d are//\n",n);
    for (i=2;i<=n;i++)
    {
        if (n%i==0)
            printf("%d\t",i);
    }
}
