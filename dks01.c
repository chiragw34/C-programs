#include<stdio.h>
struct chocolateType
{
    char name[25];
    int p,weight;
};
struct chocolateType cho[20];
int max(int a, int b)
{
    if (a>b)
        return a;
    return b;
}
int dynknapsack(int n, int m)
{
    int i,w, c[n+1][m+1], maxcost=0,x[n],temp=m;
    for(i=0;i<=n;i++)
    {
        for(w=0;w<=m;w++)
        {
            if (i==0||w==0)
                c[i][w]=0;
            else if(w>=cho[i].weight)
                c[i][w]=max(cho[i].p+c[i-1][w-cho[i].weight],c[i-1][w]);
            else
                c[i][w]=c[i-1][w];
            printf("%d\t",c[i][w]);
        }
        printf("\n");
    }
    printf("Objects included:\n");
    for(i=n;i>0;i--)
    {
        if (c[i][temp]==c[i-1][temp])
            x[i]=0;
        else
        {
            x[i]=1;
            temp=temp-cho[i].weight;
        }
    }
    printf("NAME      PROFIT WEIGHT\n");
    for(i=1;i<=n;i++)
    if(x[i]==1){
        printf("%-10s",cho[i].name);
        printf("%-6d ",cho[i].p);
        printf("%-6d",cho[i].weight);
        printf("\n");
    }

    return c[n][m];
}
main()
{
    int i,n,m;
    printf("Enter no of items:");
    scanf("%d",&n);
    printf("Enter max knapsack capacity:");
    scanf("%d",&m);
    printf("Enter the name of chocolates:");
     for (i=1;i<=n;i++)
        scanf("%s",&cho[i].name);
    printf("Enter chocolates weights:");
    for (i=1;i<=n;i++)
        scanf("%d",&cho[i].weight);
    printf("Enter chocolates profits:");
    for (i=1;i<=n;i++)
        scanf("%d",&cho[i].p);
    printf("-----------------------------------------------------------------");
    printf("\nMax cost=%d",dynknapsack(n,m));
}
