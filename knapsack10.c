#include<stdio.h>
struct question
{
    int marks,qno;
    int time;
};
struct question q[20];
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int dynknapsack(int n,int m)
{
    int a[n+1][m+1],i,j,wt=0,x[n],temp=m;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                a[i][j]=0;
            else if(j>=q[i].time)
                    a[i][j]=max(q[i].marks+a[i-1][j-q[i].time], a[i-1][j]);
                 else
                    a[i][j]=a[i-1][j];
            printf("%d\t",a[i][j]);
        }
        printf("\n___________________________________________________\n");
    }

    printf("Questions solved are:\n");
    for(i=n;i>0;i--)
    {
        if (a[i][temp]==a[i-1][temp])
            x[i]=0;
        else
        {
            x[i]=1;
            temp=temp-q[i].time;
        }
    }
    printf("Q.NO MARKS  TIME\n");
    for(i=1;i<=n;i++)
    if(x[i]==1)
    {
        printf("%-6d",q[i].qno);
        printf("%-6d ",q[i].marks);
        printf("%-6d",q[i].time);
        printf("\n");
    }
    return a[n][m];
}

void main()
{
    int i,n,m;
    printf("Enter no of questions:");
    scanf("%d",&n);
    printf("enter the number of minutes you have:-");
    scanf("%d",&m);
    printf("Enter question numbers:");
    for (i=1;i<=n;i++)
        scanf("%d",&q[i].qno);
    printf("Enter time:");
    for (i=1;i<=n;i++)
        scanf("%d",&q[i].time);
    printf("Enter marks:");
    for (i=1;i<=n;i++)
        scanf("%d",&q[i].marks);
    printf("\n___________________________________________________\n");
    printf("\nMax marks scored =%d",dynknapsack(n,m));
}
