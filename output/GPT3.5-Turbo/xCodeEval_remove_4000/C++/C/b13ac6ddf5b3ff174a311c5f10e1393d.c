#include <stdio.h>
#include <string.h>

#define MAXN 50
#define MAXL 20

char s[MAXN][MAXL];
int N, L;
double p[1<<MAXL];
int e[MAXN];
long long can[1<<MAXL];

double work(){
    memset(can, -1, sizeof(can));

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (i==j) continue;
            int same = 0;
            for (int k=0; k<L; k++){
                if ( s[i][k]==s[j][k] ){
                    same |= 1<<k;
                }
            }
            can[same] &= ~(1LL<<i);
        }
    }
    for (int mask = (1<<L)-1; mask>=0; mask-- ){
        for (int p = 0; p < L; p++){
            if ( mask&(1<<p) ){
                can[ mask^(1<<p) ] &= can[mask];
            }
        }
    }

    double ret = 0;
    double cnt[25] = {0};
    for (int mask = (1<<L)-1; mask>=0; mask-- ){
        int l = __builtin_popcount(mask);
        for (int p = 0; p < L; p++){
            if ( mask&(1<<p) ){
                long long r = can[ mask^(1<<p) ] ^ can[mask];
                cnt[l] += __builtin_popcountll(r);
            }
        }
    }
    

    for (int i=1; i<=L; i++){
        double t = cnt[i]*i;
        

        double c = 1;
        for (int j=1; j<=i-1; j++){
            c *= L-j+1;
            c /= j;
            

        }
        

        ret += t/c /(L-i+1);
    }
    return ret/N;
}
int main(){
    

    while( scanf("%d", &N) == 1 ){
        for (int i=0; i<N; i++) scanf("%s", s[i]);
        L = strlen(s[0]);
        double ans = work();
        printf("%.12f\n", ans);
    }
    return 0;
}
