#include <stdio.h>
void main()
{
    char choice;
    float a1,a2,b1,b2;

    float addition(float ,float);
    float subtraction(float ,float);

    printf("enter the initials of the operator you want\n" );
    scanf("%c",&choice);

    printf("enter first number\n");
    scanf("%f %f",&a1,&b1);

    printf("enter second number\n");
    scanf("%f %f",&a2,&b2);

    switch (choice)
    {
        case 'a':printf("addition is\n%.2f + %.2f i",addition(a1,a2)),addition(b1,b2);
                break;
        case 's':printf("subtraction is\n%.2f - %.2f i",subtraction(a1,a2),subtraction(b1,b2));
                break;
        default:printf("initial unsupported\n");
    }
}
float addition(float a,float b)
{
    return (a+b);
}
float subtraction(float a,float b)
{
    return (a-b);
}
