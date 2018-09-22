#include<stdio.h>
int factorial(int z)
{
    int i,fact=1;
    for (i=1;i<=z;i++)
        fact=fact*i;
    return fact;
}
int gama(int a)
{
    int b,c;
    b=a-1;
    c=factorial(b);
    return c;
}
float beta(int p,int q)
{
    int s;
    s=(gama(p)*gama(q))/gama(p+q);
    return s;
}
int main()
{
    float beta(int,int);
    int gama(int);
    int factorial(int);
    int p,q;
    printf("enter the p and q");
    scanf("%d %d",&p,&q);
    printf("beta function of %d and %d is %f",p,q,beta(p,q));
}
