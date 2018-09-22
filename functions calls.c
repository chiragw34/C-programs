#include <stdio.h>
void main()
{
    int a[10][10],b[10][10],c[10][10],at[10][10],bt[10][10],ct[10][10],mt[10][10];
    int m1,m2,n1,n2,ans;
    void read(int[][10],int,int);
    void print(int[][10],int,int);
    void multiply(int[][10],int[][10],int[][10],int,int,int);
    void transpose(int[][10],int[][10],int,int);
    int equal(int[][10],int[][10],int,int,int,int);

    printf("enter the order of matrix A\n");
    scanf("%d %d",&m1,&n1);
    printf("enter the order of matrix b \n");
    scanf("%d %d",&m2,&n2);

    if (n1==m2)
    {
        printf("enter the elements of A\n" );
        read(a,m1,n1);
        printf("enter the elements of B\n");
        read(b,m2,n2);

        multiply(a,b,c,m1,n2,n1);
        transpose(c,ct,m1,n2);
        transpose(b,bt,m2,n2);
        transpose(a,at,m1,n1);

        multiply(bt,at,mt,n2,m1,n1);
        ans=equal(ct,mt,n2,m1,n2,m1);
        if (ans==1)
            printf("property verified\n");
        else
            printf("property is wrong\n");
        printf("LHS=\n");
        print(ct,n2,m1);
        printf("RHS=\n");
        print(mt,n2,m1);
    }
    else
        printf("order mis match");
}
void read(int a[][10],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
}
void print(int p[][10],int m,int n)
{
    int i,j;
    for (i=0;i<m;i++)
    {for(j=0;j<n;j++)
    printf("%d\t",p[i][j]);
    printf("\n");
    }
}
void multiply(int a[][10],int b[][10],int c[][10],int m1,int n2,int n1)
{
    int i,j,k;
    for(i=0;i<m1;i++)
    for(j=0;j<n2;j++)
    {
        c[i][j]=0;
        for (k=0;k<n1;k++)
        c[i][j]=c[i][j]+a[i][k]+b[k][j];
    }
}
void transpose(int a[][10],int at[][10],int m,int n)
{
    int i,j;
    for (i=0;i<m;i++)
        for(j=0;j<n;j++)
        at[j][i]=a[i][j];
}
int equal(int a[][10],int b[][10],int m1,int n1,int m2,int n2)
{
    int count=0,i,j;
    if((m1==m2)&&(n1==n2))
    {
        for (i=0;i<m1;i++)
            for(j=0;j<n1;j++)
            if(a[i][j]==b[i][j])
                count++;
        if(count==m1*n1)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
