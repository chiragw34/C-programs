
#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
	 if(a>b)
	 return a;
	 return b;
}
int main()
{
	 int i,j,Matrix[20][20],Backtracking[20][20],n,m,index;
	 char givenStr[20],subsequence[20],finalSequence[20];
	 printf("Enter Sequence:");
	 gets(givenStr);
	 printf("Enter subSequence:");
	 gets(subsequence);
	 n=strlen(givenStr)+1;
	 m=strlen(subsequence)+1;
	 for(i=0;i<m;i++)
	 {
		 for(j=0;j<n;j++)
		 {
			 if((i==0)||(j==0))
			 {
				 Matrix[i][j]=0;
				 Backtracking[i][j]=-1;
			 }
			 else
			 {
				 if(givenStr[j-1]==subsequence[i-1])
				 {
					 Matrix[i][j]=Matrix[i-1][j-1]+1;
					 Backtracking[i][j]=2;
				 }
				 else
				 {
					 if(Matrix[i-1][j]>Matrix[i][j-1])
					 {
						 Matrix[i][j]=Matrix[i-1][j];
						 Backtracking[i][j]=1;
					 }
					 else
					 {
						 Matrix[i][j]=Matrix[i][j-1];
						 Backtracking[i][j]=0;
					 }
				 }
			 }
		 }
	 }
	 for(i=0;i<m;i++)
	 {
		 for(j=0;j<n;j++)
		 {
			 if(Backtracking[i][j]==2)
				printf("%d->%2s|",Matrix[i][j],"di");
			 else
				if(Backtracking[i][j]==1)
					printf("%d->%2s|",Matrix[i][j],"up");
				else
					if(Backtracking[i][j]==0)
						printf("%d->%2s|",Matrix[i][j],"le");
					else
						printf("%d %2s|",Matrix[i][j],"");
		 }
		 printf("\n");
	 }
	 index=0;
	 i=m-1;
	 j=n-1;
	 while((i>0)&&(j>0)&&(Backtracking[i][j]!=-1))
	 {
		 if(Backtracking[i][j]==2)
		 {
			 finalSequence[index]=givenStr[j-1];
			 i--;
			 j--;
		 }
		 else if(Backtracking[i][j]==1)
		 {
			 finalSequence[index]='_';
			 i--;
		 }
		 else if(Backtracking[i][j]==0)
		 {
			 finalSequence[index]='_';
			 j--;
		 }
		 index++;
	 }
	 printf("Thus,The Final Sequence is:");
	 for(i=index-1;i>=0;i--)
	 printf("%c",finalSequence[i]);
	 return 0;
}