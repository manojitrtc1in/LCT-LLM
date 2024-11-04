#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 1000000007

int opp(char a, char b)
{
    return (a == 'W' && b == 'E') || (a == 'E' && b == 'W') || (a == 'S' && b == 'N') || (a == 'N' && b == 'S');
}

char ccinv(char x)
{
    switch (x)
    {
    case 'N':
        return 'S';
    case 'S':
        return 'N';
    case 'W':
        return 'E';
    case 'E':
        return 'W';
    }
    return 'W';
}

int main()
{
    srand(time(NULL));
    char r[100];
    scanf("%s", r);
    char a[100];
    scanf("%s", a);
    char b[100];
    scanf("%s", b);
    int n = strlen(a);
    char ar[100];
    for (int i = 0; i < n; i++)
    {
        ar[i] = ccinv(a[n - i - 1]);
    }
    int va = 0;
    int vb = 0;
    int p = 1;
    for (int i = 0, j = n - 1; i < n; i++, j--)
    {
        va = (va * 131 + ar[i]) % M;
        vb = (vb + b[j] * p) % M;
        p = (p * 131) % M;
        if (vb == va)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

    return 0;
}
