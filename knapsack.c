#include <stdio.h>
struct chapter
{
    float wt,prb,hrs,pbw;
    char topic[100];
};
float knapsack(struct chapter ch[],int cnt,int tc)
{
    int i,j,k=0;
    float arr_pbw[100],temp,profit=0;

    for(i=1;i<=tc;i++)//inserting by profit per weight
        for(j=0;j<ch[i].hrs;j++)
        {   arr_pbw[k]=ch[i].pbw;
            k++;
        }

    for(i=0;i<k;i++)//sorting by profit per weight
        for(j=0;j<k-i-1;j++)
            if(arr_pbw[j]<arr_pbw[j+1])
        {
            temp=arr_pbw[j];
            arr_pbw[j]=arr_pbw[j+1];
            arr_pbw[j+1]=temp;
        }

    for(i=0;i<cnt;i++)
        profit=profit+arr_pbw[i];

    return profit;
}
int main()
{
    int tc,cnt=0,i,j,st=0;
    float ans;
    struct chapter chp[100];
    float knapsack(struct chapter [] ,int,int);
    printf("enter the number of topics :-");
    scanf("%d",&tc);
    printf("Module\t\tWeightage\tProbability\tNo of hours\n");
    printf("_____________________________________________________________\n");
    for (i=1;i<=tc;i++)
    {
        scanf("%s",chp[i].topic);
        scanf("%f",&chp[i].wt);
        scanf("%f",&chp[i].prb);
        scanf("%f",&chp[i].hrs);
        chp[i].pbw=chp[i].wt/chp[i].hrs;
        printf("_____________________________________________________________\n");
    }
    printf("enter the number of hours you have to study:-");
    scanf("%d",&cnt);
    ans=knapsack(chp,cnt,tc);
    printf("\nthe maximum marks that can be scored is:- %f",ans);
}
