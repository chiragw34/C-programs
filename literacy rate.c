#include<string.h>
#include <stdio.h>
struct state
{
    char name[40];
    unsigned long int pop;
    float literacy_rate,avg_income;

};
void main()
{
    int i,j,n;
    float max,min;
    struct state s[100],low_pop,high_income;
    printf("enter the number of states:-");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        printf("enter the name of state %d :-",i);
        fflush(stdin);
        gets(s[i].name);
        printf("enter the population of state %d:-",i);
        scanf("%lu",&s[i].pop);
        printf("enter the literacy rate of state %d:-",i);
        scanf("%f",&s[i].literacy_rate);
        printf("enter the average income of state %d:-",i);
        scanf("%f",&s[i].avg_income);
    }
    max=s[1].avg_income;
    min=s[1].pop;

    for (i=1;i<=n;i++)
    {
        if (s[i].avg_income<s[i+1].avg_income)
        {
            max=s[i+1].avg_income;
            high_income=s[i+1];
        }
        if(s[i].pop>s[i+1].pop)
        {
            min=s[i+1].pop;
            low_pop=s[i+1];
        }
    }
    printf("\nthe state with high income is %s with income of %d",high_income.name,max);
    printf("\nthe state with low population is %s with population of %lu",low_.name,min);

}
