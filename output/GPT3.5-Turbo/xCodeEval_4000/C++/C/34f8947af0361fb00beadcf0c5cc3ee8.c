#include<stdio.h>
#include<string.h>

#define N 84

int n,a,b,c,d[N],e[N],g[N],h[N],l[N],p[N],f[N][N][N][2];
char s[N];

void mi(int *a, int b) {
    *a = (*a < b) ? *a : b;
}

int main() {
    scanf("%d%s", &n, s);
    
    for(int i=0; i<n; i++) {
        if(i != 0) {
            p[i] = p[i-1];
            h[i] = h[i-1];
            l[i] = l[i-1];
        }
        
        if(s[i] == 'V') {
            d[a++] = i;
            h[i]++;
        } else if(s[i] == 'K') {
            e[b++] = i;
            l[i]++;
        } else {
            g[c++] = i;
            p[i]++;
        }
    }
    
    memset(f, 0x3f, sizeof(f));
    
    for(int i=0; i<=a; i++) {
        for(int j=0; j<=b; j++) {
            for(int k=0; k<=c; k++) {
                for(int t=0; t<=1; t++) {
                    f[i][j][k][t] = 0;
                }
            }
        }
    }
    
    for(int i=0; i<a; i++) {
        for(int j=0; j<b && !t; j++) {
            for(int k=0; k<c; k++) {
                f[i+1][j+1][k][1] = f[i][j][k][0] + abs(l[d[i]] - j) + abs(p[d[i]] - k);
                f[i+1][j][k+1][0] = f[i][j][k][1] + abs(h[e[j]] - i) + abs(p[e[j]] - k);
                f[i][j+1][k+1][0] = f[i][j][k][0] + abs(h[e[j]] - i) + abs(l[d[i]] - j);
            }
        }
    }
    
    printf("%d\n", min(f[a][b][c][0], f[a][b][c][1]) / 2);
    
    return 0;
}
