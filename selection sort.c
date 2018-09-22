#include <stdio.h>
void selectionSort(int arr[], int n)
{
    int i, j, min_idx,temp[100];
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        temp[min_idx]=arr[min_idx];
        arr[min_idx]=arr[i];
        arr[i]=temp[min_idx];
    }
}
int main()
{
    int arr[100],i,n;
    printf("enter the number of elements:-");
    scanf("%d",&n);
    printf("enter %d elements\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
