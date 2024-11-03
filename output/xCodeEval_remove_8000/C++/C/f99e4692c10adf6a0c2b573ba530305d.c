#include <stdio.h>
#include <stdlib.h>

#define REP_C(i, n) for(int i=0;i<n;++i)
#define REP(i, n) for(int i=1;i<=n;++i)
#define Rush int T;scanf("%d",&T);while(T--)
#define DWN(i, n, x) for(int i=n;i>=x;--i)

const int N = 1000009;
int a[N], n, s[N], top;

int main(){
    REP_C(i, scanf("%d", &n)) scanf("%d", &a[i]);
    Rush a[scanf("%d", &n)-1] *= -1;

    DWN(i, n, 0){
        if (a[i] > 0){
            if (top && s[top] == a[i]) --top;
            else s[++top] = a[i], a[i] = -a[i];
        }
        else
            s[++top] = - a[i];
    }

    if (top) puts("NO"); else {
        puts("YES"); REP(i, n) printf("%d ", a[i]);
    }
}
