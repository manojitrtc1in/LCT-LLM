#include <stdio.h>
#include <string.h>

typedef long long ll;

#define MAX 1200000
int dp[1200001];
int pi[1200001];
void sieve()
{
    for (int i = 2; i < MAX; i++) dp[i] = 1;
    for (int i = 2; i < MAX; i++)
        if (dp[i])
            for (int j = 2*i; j < MAX; j += i)
                dp[j] = 0;
    pi[1] = 0;
    for (int i = 2; i <= MAX; i++)
        if (dp[i]) pi[i] = pi[i-1] + 1;
        else pi[i] = pi[i-1];
}

