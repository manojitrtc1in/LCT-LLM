#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define REP(i, n) for (int i=0;i<int(n);++i)
#define REP_C(i, n) for (int n____=int(n),i=0;i<n____;++i)
#define REP_S(it, str) for (char*it=str;*it;++it)
#define _1(x) (1<<(x))

const int N = 1000009, M = 10009, Z = 26;

char A[N], buf[Z]; int Q[M]; bool have[Z]; int ans[Z];
int n, m;

int stk[Z], nn; bool vis[Z]; void push(int x){
    if (!vis[x]) vis[stk[nn++] = x] = true;
    else {
        int j; for(j=0;;j++) if(stk[j] == x)break;
        for(;j<nn-1;j++) stk[j] = stk[j+1]; stk[nn-1] = x;
    }
}

int main(){

    scanf("%s", A);
    n = strlen(A);
    REP_C(i, m){
        scanf("%s", buf);
        REP_S(cur, buf) Q[i] |= _1(*cur - 'a');
        have[Q[i]] = true;
    }

    REP(i, n){
        push(A[i]); int s = 0; for(int j=nn-1;j>=0;j--){
            s |= _1(stk[j]); if (_1(s, A[i+1])) break;
            if (have[s]) ++ans[s];
        }
    }

    REP(i, m) printf("%d\n", ans[Q[i]]);
}
