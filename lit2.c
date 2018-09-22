#include<string.h>
#include <stdio.h>
struct state
{
    char name[40];
    float pop;
    float literacy_rate,avg_income;

};
void main()
{
    int i,j,n;
    float max=0,min=0;
    struct state s[100],low_pop,high_income;
    printf("enter the number of states:-");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        printf("enter the name of state %d :-",i);
        fflush(stdin);
        gets(s[i].name);
        printf("enter the population of state %d:-",i);
        scanf("%f",&s[i].pop);
        printf("enter the literacy rate of state %d:-",i);
        scanf("%f",&s[i].literacy_rate);
        printf("enter the average income of state %d:-",i);
        scanf("%f",&s[i].avg_income);
    }
    max=s[1].avg_income;
    min=s[1].pop;
    high_income=s[1];
    low_pop=s[1];


    for (i=2;i<=n;i++)
    {
        if (s[i].avg_income>max)
        {
            max=s[i].avg_income;
            high_income=s[i];
        }

        if(s[i].pop<min)
        {
            min=s[i].pop;
            low_pop=s[i];

        }
    }
    printf("\nthe state with high income is ");
    puts(high_income.name);
    printf("with average income of %f",max);
    printf("\nthe state with low population is ");
    puts(low_pop.name);
    printf("with population of %f",min);

}

