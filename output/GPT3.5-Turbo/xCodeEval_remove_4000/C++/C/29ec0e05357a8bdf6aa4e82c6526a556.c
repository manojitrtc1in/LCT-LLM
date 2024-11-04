#include <stdio.h>
#include <stdlib.h>

#define N 16
#define S (1 << 16)

typedef long long LL;

LL F[S], k, t;
int adj[N], A[N], P[N], n;

LL dfs(){
    for(int i = 0; i < S; i++){
        F[i] = 0;
    }
    F[0] = 1;
    for(int s = 0; s < (1 << n) - 1; s++){
        if(F[s]){
            for(int i = 0; i < n; i++){
                if(!(s & (1 << i)) && !(s & adj[i])){
                    F[s | (1 << i)] += F[s];
                }
            }
        }
    }
    return F[(1 << n) - 1];
}

int main(){
    scanf("%d %lld", &n, &k);
    k -= 2000;
    for(int i = 0; i < n; i++){
        adj[i] = 0;
    }
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x - 1] |= (1 << (y - 1));
    }
    for(int i = 0; i < n; i++){
        P[i] = -1;
    }
    if(dfs() < k){
        printf("The times have changed\n");
    }
    else{
        int s = (1 << n) - 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(s & (1 << j)){
                    P[A[i] = j] = i;
                    t = dfs();
                    if(t < k){
                        k -= t;
                        P[j] = -1;
                    }
                    else{
                        s ^= (1 << j);
                        printf("%d ", j + 1);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
