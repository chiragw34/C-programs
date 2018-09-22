#include <stdio.h>
int main()
{
    int i, j;
    int input, number=1;

    printf("type your name and press enter ");
    scanf("%c",&input);

    for(i=1; i <= (input-1+1); ++i)
    {
        for(j=1;j<=i;++j)
        {
            printf("%d", number);
        }
        ++number;

        printf("\n");
    }
    return 0;
}
