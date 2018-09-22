#include<stdio.h>
struct processor
{
    char name[50];
    float time;
};
void quicksort(struct processor pro[100],int,int);
void mergeSort(struct processor pro[],int,int);
void merge(struct processor pro[],int,int,int);
void main()
{
    int n,i,k=0;
    struct processor a[100];

    printf("Enter The No Of Processors You Want To Compare:-");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        {
            printf("Enter The Name Of processor %d :-",i);
            scanf("%s",a[i].name);
            printf("Enter The Time Taken By Processor %d:-",i);
            scanf("%f",&a[i].time);
        }
    do
    {
        printf("\n======MENU======\n");
        printf("1. Quick Sort\t2. Merge Sort\t3. Exit\n");
        printf("Enter your option:-");
        scanf("%d",&k);

        switch(k)
        {
            case 1: quick_sort(a,1,n);
                    break;
            case 2: mergeSort(a,0,n);
                    break;
            default:break;
        }
    }while(k<3);

    printf("The processors are arranged according to minimum time required to render video\n");
    printf("lower is better\n");
    printf("NAME           TIME\n");
    for(i=1;i<=n;i++)
            printf("%-15s%.2fs\n",a[i].name,a[i].time);
}
void quick_sort(struct processor pro[100],int lb,int ub)
{
int i,j,key;
struct processor temp;
	if (lb<ub)
	{
        i=lb;
		j=ub;
		key=pro[lb].time;
		while (i<j)
		{
            i++;
			while(i<=ub && pro[i].time<key)
				i++;
			while(j>=lb && pro[j].time>key)
				j--;
			if (i<j)
			{
                temp = pro[i];
				pro[i] = pro[j];
				pro[j] = temp;
			}
		}
		temp = pro[j];
		pro[j] = pro[lb];
		pro[lb] = temp;

		quick_sort(pro,lb,j-1);
		quick_sort(pro,j+1,ub);
	}
}
void merge(struct processor pro[100],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    struct processor L[n1],R[n2];

    for(i=0;i<n1;i++)
        L[i]=pro[l+i];
    for(j=0;j<n2;j++)
        R[j]=pro[m+1+j];
    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2)
    {
        if(L[i].time<=R[j].time)
        {
            pro[k]=L[i];
            i++;
        }
        else
        {
            pro[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        pro[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        pro[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(struct processor pro[100],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergeSort(pro,l,m);
        mergeSort(pro,m+1,r);
        merge(pro,l,m,r);
    }
}
