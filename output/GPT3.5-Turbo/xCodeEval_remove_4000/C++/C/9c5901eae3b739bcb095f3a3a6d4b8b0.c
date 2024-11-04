#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define forn(i, n) for(int i=0; i<n; i++)
#define sz(x) ((int)(x).size())
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long li;
typedef long double ld;

typedef struct {
    int x;
    int y;
} pt;

typedef struct {
    int first;
    int second;
} pair;

typedef struct {
    int v;
    int u;
} edge;

int** g;
int n;

bool read () {
    if (scanf("%d", &n) != 1)
        return false;
    g = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        g[i] = NULL;
    }
    for(int i=0; i<n-1; i++){
        int v, u;
        scanf("%d%d", &v, &u);
        --v, --u;
        if(g[v] == NULL){
            g[v] = (int*)malloc(sizeof(int));
            g[v][0] = u;
        } else {
            int size = 0;
            while(g[v][size] != NULL){
                size++;
            }
            g[v] = (int*)realloc(g[v], (size+1) * sizeof(int));
            g[v][size] = u;
        }
        if(g[u] == NULL){
            g[u] = (int*)malloc(sizeof(int));
            g[u][0] = v;
        } else {
            int size = 0;
            while(g[u][size] != NULL){
                size++;
            }
            g[u] = (int*)realloc(g[u], (size+1) * sizeof(int));
            g[u][size] = v;
        }
    }
    return true;
}

int add(int a, int b){
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b){
    return a * li(b) % MOD;
}

int** dp;

void dfs(int v, int p){
    dp[v][0] = 1;
    dp[v][1] = 1;
    int* vals = NULL;
    int* init = NULL;
    int valsSize = 0;
    int initSize = 0;
    for(int i=0; i<sz(g[v]); i++){
        int u = g[v][i];
        if (u != p){
            dfs(u, v);
            vals = (int*)realloc(vals, (valsSize+1) * sizeof(int));
            vals[valsSize] = add(dp[u][1], add(dp[u][2], dp[u][2]));
            init = (int*)realloc(init, (initSize+1) * sizeof(int));
            init[initSize] = add(dp[u][0], dp[u][1]);
            dp[v][0] = mul(dp[v][0], add(dp[u][1], add(dp[u][2], dp[u][2])));
            dp[v][1] = mul(dp[v][1], add(dp[u][1], dp[u][2]));
            valsSize++;
            initSize++;
        }
    }
    dp[v][0] = add(dp[v][0], -dp[v][1]);
    
    int* pr = (int*)malloc(sizeof(int));
    pr[0] = 1;
    int* su = (int*)malloc(sizeof(int));
    su[0] = 1;
    for(int i=0; i<valsSize; i++){
        pr = (int*)realloc(pr, (i+2) * sizeof(int));
        pr[i+1] = mul(pr[i], vals[i]);
    }
    for(int i=valsSize-1; i>=0; i--){
        su = (int*)realloc(su, (valsSize-i+1) * sizeof(int));
        su[valsSize-i] = mul(su[valsSize-i-1], vals[i]);
    }
    
    dp[v][2] = 0;
    for(int i=0; i<valsSize; i++){
        dp[v][2] = add(dp[v][2], mul(init[i], mul(pr[i], su[i + 1])));
    }
}

void solve() {
    dp = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        dp[i] = (int*)malloc(3 * sizeof(int));
    }
    dfs(0, -1);
    printf("%d\n", add(dp[0][1], dp[0][2]));
}

int main() {
    freopen("input.txt", "r", stdin);
    
    int tt = clock();
    
    while(read()) {    
        solve();
    }
    
    return 0;
}
