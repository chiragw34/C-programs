#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char text[100],pattern[100];
	int i,j;
	int n,m;

	//Taking Input
	printf("Enter The Text:");
	scanf("%s",text);
	printf("Enter The Pattern:");
	scanf("%s",pattern);

	n = strlen(text);
	m = strlen(pattern);

	//Logic
	for(i=0;i<=n-m;i++)
	{
		for(j=0;j<m;j++)
		{
			if (text[i]!=pattern[j])
				break;
			else
				i++;
			/*
				Karan and Karu K is matched now,
				you are in j loop and u have to simultaneously increase i and
				u cant go to i wala forloop
				thus u have to increment i by urself in j's forloop
			*/
		}
		if (j==m)
			printf("%s found at %d\n",pattern,i-m);
		else
			/*
				when Karan and Karu ,K a r have increased i thrice now
				when you have to compare next time you have to compare
				'K' of Karu with 'a' of Karan
				thus decreament whatever u have incremented i
			*/
			i=i-j;

	}


	return 0;
}
