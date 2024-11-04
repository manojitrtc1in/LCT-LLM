#include <stdio.h>
#include <stdlib.h>

#define MAX 1200001

typedef long long ll;
typedef struct {
    int first;
    int second;
} State;

int dp[1200001];
int pi[1200001];
void sieve()
{
    int i, j;
    for (i = 2; i < MAX; i++) dp[i] = 1;
    for (i = 2; i < MAX; i++)
        if (dp[i])
            for (j = 2*i; j < MAX; j += i)
                dp[j] = 0;
    pi[1] = 0;
    for (i = 2; i <= MAX; i++)
        if (dp[i]) pi[i] = pi[i-1] + 1;
        else pi[i] = pi[i-1];
}

