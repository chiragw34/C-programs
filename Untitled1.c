#include<stdio.h>
int main ()
{
    int a,x,y;
    printf("ENTER TWO NUMBERS=");
    scanf("%d",&a);
    if (a<=0)
    printf("INVALID DATA");
    else
    {
        x=a/10;
        y=a%10;
        printf("%d %d %d",(x+y),(x*y),(10*y+x));
    }
}
