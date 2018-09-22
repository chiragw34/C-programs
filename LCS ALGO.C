#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,k=0,m,n1,n2;
    char s1[100],s2[100],v1[100]={0},v2[100]={0},lcs[100]={' '};

    printf("enter 1st string:-");
    gets(s1);
    printf("enter 2nd string:-");
    gets(s2);

    n1=strlen(s1);
    n2=strlen(s2);

    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(v1[i]==0 && v2[j]==0)
            {
                if(s1[i]==s2[j])
                {
                    lcs[k]=s2[j];
                    k++;
                    v1[i]=v2[j]=1;
                }
            }
        }
    }
    m=strlen(lcs);
    printf("the longest common sequence is:");
    puts(lcs);
    printf(" and its length is %d",m);
}
