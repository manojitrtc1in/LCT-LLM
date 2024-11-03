#include <stdio.h>
#include <stdlib.h>

#define MAX 1200001

typedef long long ll;
typedef struct {
    int first;
    int second;
} State;

int dp[MAX];
int pi[MAX];
