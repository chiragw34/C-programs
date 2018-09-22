#include<stdio.h>
void main()
{
	int a[100],i,n;
	void quick_sort(int [],int,int);
	
	printf("enter the number of integers");
	scanf("%d",&n);
	
	printf("enter the integers");
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	quick_sort(a,0,n-1);
	printf("sorted array is \n");
	for (i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void quick_sort(int x[],int lb,int ub)
{
	int i,j,key,temp;
	if (lb<ub)
	{
		i=lb;
		j=ub;
		key=x[lb];
		while (i<j)
		{
			i++;
			while(i<=ub && x[i]<key)
				i++;
			while(j>=lb && x[j]>key)
				j--;
			if (i<j)
			{
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
		temp = x[j];
		x[j] = x[lb];
		x[lb] = temp;
		
		quick_sort(x,lb,j-1);
		quick_sort(x,j+1,ub);
	}
}