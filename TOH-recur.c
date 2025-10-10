#include <stdio.h>
#include <stdlib.h>

void TOH(int n, char s,char d,char t )
{
    if (n==1)
    {
        printf("\n Move %d disc from %c to %c", n,s,d);
    }
    else
    {
        TOH(n-1,s,t,d);
        printf("\nMove %d disc from %c to %c",n,s,d);
        TOH(n-1,t,d,s);
    }
}

int main()
{
    int n;

    printf("\nRead no. of discs: ");
    scanf("%d",&n);

    TOH(n,'s','d','t');

    printf("\n Total number of moves is %d",((1<<n)-1));
    return 0;

}
