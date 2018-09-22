#include<stdio.h>
struct pair
{
  float min;
  float max;
};
struct player
{
    char name[50];
    float k,d;
    float kdr;
};
struct pair getMinMax(struct player p[100], int low, int high)
{
  struct pair minmax, mml, mmr;
  int mid;

  if (low == high)
  {
     minmax.max = p[low].kdr;
     minmax.min = p[low].kdr;
     return minmax;
  }

  if (high == low + 1)
  {
     if (p[low].kdr > p[high].kdr)
     {
        minmax.max = p[low].kdr;
        minmax.min = p[high].kdr;
     }
     else
     {
        minmax.max = p[high].kdr;
        minmax.min = p[low].kdr;
     }
     return minmax;
  }

  mid = (low + high)/2;
  mml = getMinMax(p, low, mid);
  mmr = getMinMax(p, mid+1, high);

  if (mml.min < mmr.min)
    minmax.min = mml.min;
  else
    minmax.min = mmr.min;

  if (mml.max > mmr.max)
    minmax.max = mml.max;
  else
    minmax.max = mmr.max;

  return minmax;
}

void main()
{
    int i,j,n;
    struct player p[100];
    struct pair minmax;
    printf("Enter The No Of Players:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the name of player %d:-",i+1);
        scanf("%s",p[i].name);
      //  printf("name is %s\n",p[i].name);
        printf("Enter the kills of player %d:-",i+1);
        scanf("%f",&p[i].k);
     //   printf("%f\n",p[i].k);
        printf("Enter the deaths of player %d:-",i+1);
        scanf("%f",&p[i].d);
       // printf("%f\n",p[i].d);
        p[i].kdr=(p[i].k)/(p[i].d);
        printf("KDR is:- %f\n",p[i].kdr);
    }
    minmax = getMinMax(p, 0, n-1);
    printf("\nMinimum KDR is %f", minmax.min);
    printf("\nMaximum KDR is %f", minmax.max);
}
