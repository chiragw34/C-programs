#include <stdio.h>
#define MAX 30
void main()
{
    int record[MAX],key,index,n,modulo=10;
    int i,j,isInsert=0,isFound=0,comparision=0,startIndex;
    printf("enter the number of records you want to enter");
    scanf("%d",&n);

    for (j=0;j<MAX;j++)
        record[j];

    printf("enter the modulo function:-");
    scanf("%d",&modulo);

    if(modulo>n)
    {
        printf("greater modulo not possible");
        return;
    }
    printf("enter %d number of keys",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&key);
        index = key % modulo;
        while(isInsert!=1)
        {
            if(record[index]==0)
            {
                record[index]=key;
                isInsert=1;
            }
            index=index+1;
            if(index==n)
                index=0;
        }
    }
    printf("Array is\n");
    for(j=0;j<n;j++)
    {
        printf("Index = %d\n\tkey = %d",j,record[j]);
    }
    printf("enter the record to be searched");
    scanf("%d",&key);

    index=key % modulo;
    comparision=0;
    startIndex=index;
    while(isFound!=1)
    {
        comparision++;
        if(record[index]==key)
        {
            isFound=1;
            break;
        }
        index++;

        if(isFound==0)
        {
            printf("%d is not present\n",key);
            printf("no. of comparison = %d\n",comparision);
        }
        else
        {
            printf("%d is present at index %d\n",key,index);
            printf("no of comparisions = %d",comparision);
        }
    }
}
