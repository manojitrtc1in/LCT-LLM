#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100000

typedef long long lli;

int N;
lli a[MAX_N];
lli b[MAX_N];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < N; ++i)
    {
        scanf("%lld", &b[i]);
    }

    int mp[MAX_N] = {0};
    for (int i = 0; i < N; ++i)
    {
        mp[a[i]]++;
    }

    lli ans = 0;
    for (int i = 0; i < N; ++i)
    {
        bool isok = false;
        for (int j = 0; j < N; ++j)
        {
            if ((a[i] & a[j]) == a[i] && mp[a[j]] > 1)
            {
                isok = true;
                break;
            }
        }

        if (isok)
        {
            ans += b[i];
        }
    }

    printf("%lld\n", ans);

    return 0;
}
