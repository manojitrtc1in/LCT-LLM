#include <stdio.h>
#include <stdlib.h>

#define REP(i, n) for(int i=0; i<n; i++)
#define FOR_1(i, a, b) for(int i=a; i<=b; i++)
#define PB push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()
#define FLC(A, x) memset(A, x, sizeof(A))
#define INF 0x3f3f3f3f

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int id1(int a, int b){
    return a*b/gcd(a,b);
}

typedef long long LL;
const int L = 360360, N = 100009;

int id1(int a, int b){
    return a*b/gcd(a,b);
}

LL a, b, k; int aa, bb, lcm;
int adj[L][L];

int D[3*L];

int f(int s, int t){
    return D[t];
}

void bfs(){
    int s = aa;
    FLC(D, INF);
    D[0] = 0;

    REP(i, 3 * lcm){
        int u = (s - i) % lcm;
        if (u < 0) u += lcm;

        int Du = D[i];

        if (Du == INF) continue;

        REP(ii, SZ(adj[u])){
            if(D[i + adj[u][ii]] > Du + 1)
                D[i + adj[u][ii]] = Du + 1;
        }
    }
}

int main(){
    scanf("%lld %lld %lld", &a, &b, &k);

    lcm = 1;
    FOR_1(i, 2, k){
        lcm = id1(lcm, i);
    }

    REP(i, lcm){
        adj[i][0] = 1;
        int index = 1;
        FOR_1(j, 2, k){
            if(i % j != 0){
                adj[i][index] = i % j;
                index++;
            }
        }
    }

    LL tt = (a - b) / lcm;

    aa = a % lcm, bb = b % lcm;

    LL step = INF;
    int h;

    bfs();

    bb = (aa - bb + 3 * lcm) % lcm;

    tt *= (LL) (D[bb+lcm] - D[bb]);

    printf("%d\n", D[bb] + tt);

    return 0;
}
