#include<stdio.h>
void main()
{

    int i,x,a[100],choice,n,beg=0,end,j,temp,pos,mid;
    printf("**//enter the size of array//**\n");
    scanf("%d",&n);

    printf("enter the elements of an array:-\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("enter the element to be searched\n");
    scanf("%d",&x);

    printf("******enter choice******\n");
    printf("1:linear search\n2:binary search\n3:exit\n");
    scanf("%d",&choice);

    switch(choice)
    {

    case 1:{for(i=0;i<n;i++);
     {      if(a[i]==x)
        {
                  printf("%d is present ",x);
                  break;
   	    }
     }
            if(i==n)
                   printf("element not found ");

                   break;
           }
     case 2: {end=n-1;
              pos=-1 ;
              mid=(beg+end)/2;
              while(beg<=end)
               {
                   if(a[mid]<x)
 		beg=mid+1;
	    else if(a[mid]==x)
 		{
		     printf("element is present");
		     break;
		}
		else
		       end=mid-1;
		      mid=(beg+end)/2;
		      }
	if(beg>end)
               printf("element is not present");
               break;}
      case 3:printf("exit");break;
}
}








