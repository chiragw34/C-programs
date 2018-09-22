#include<stdio.h>
int main()
{
    int n,r;
    unsigned long int nf,rf,nrf;
    unsigned long int factorial(int);
    printf("enter the n:");
    scanf("%d %d",&n,&r);
    if(n<0||r<0||n<r)
        printf("invalid data");
    else
    {
        nf=factorial(n);
        rf=factorial(r);
        nrf=factorial(n-r);
        printf("answer is %lu \n",nf/(rf*nrf));
    }
    return 0;
}
unsigned long int factorial(int n)
{
    unsigned long int fact=1;
    int i;
    for(i=1;i<=n;i++)
    fact=fact*i;
    return fact;
}
