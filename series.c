#include<stdio.h>
void main()
{
    int n,i;
    unsigned long int fact(int);
    float sum=0;
    printf("enter the n");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        sum = sum + (float)fact(i)/i;
    }
    printf("ans is %f",sum);
}
unsigned long int fact(int n)
{
    int i;
    if (n==0) return 1;
    else n*fact(n-1);
}
