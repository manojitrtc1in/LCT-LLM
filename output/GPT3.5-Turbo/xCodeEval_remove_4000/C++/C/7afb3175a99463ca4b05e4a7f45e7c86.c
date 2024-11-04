#include <stdio.h>
#include <string.h>

#define REP(i, n) for(int i=0; i<n; i++)
#define REP_2(i, j, n, m) for(int i=0; i<n; i++) for(int j=0; j<m; j++)
#define REP_C(i, n) for(int i=1; i<=n; i++)
#define DWN(i, n, m) for(int i=n; i>=m; i--)
#define FOR_1(i, n, m) for(int i=n; i<=m; i++)
#define ALL(x) x.begin(), x.end()
#define rTs return *this

typedef long long LL;
typedef double DB;

const int N = 50, M = 20;

char S[N][M+1];
LL f[1<<M], ok[M+1];
int n, m;

int main(){
    scanf("%d", &n);
    REP(i, n) scanf("%s", S[i]);
    m = strlen(S[0]);

    REP_2(i, j, n, n) if (i != j){
        int s = 0; REP(k, m) if (S[i][k] == S[j][k]) s |= (1<<k);
        f[s] |= (1<<i);
    }

    DWN(s, (1<<m)-1, 0){
        REP(i, m) if (!(s&(1<<i))){
            f[s^(1<<i)] |= f[s];
        }
    }

    REP(s, (1<<m)){
        int step = 0;
        REP(i, m) if (s&(1<<i)) step++;
        REP(i, m) if (!(s&(1<<i))){
            LL d = f[s|(1<<i)]^f[s];
            ok[step] += __builtin_popcountll(d);
        }
    }

    DB ans = 0;
    REP(i, m) if (ok[i]){
        DB t = ok[i] * i;
        REP(j, i-1) t *= j;
        FOR_1(j, m-i+1, m) t /= j;
        ans += t;
    }

    ans /= n;
    printf("%.15f\n", ans);
    return 0;
}
