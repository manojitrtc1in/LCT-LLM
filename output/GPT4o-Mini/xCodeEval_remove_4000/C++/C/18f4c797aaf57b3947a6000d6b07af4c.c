#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>

#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REP_C(i, n) for(int i = 0; i < (n); ++i)
#define REP_S(cur, str) for(char *cur = (str); *cur; ++cur)
#define DWN(i, n, m) for(int i = (n) - 1; i >= (m); --i)

typedef long long LL;
typedef std::set<int> SI;
typedef std::map<int, int> MII;

const int N = 1000009, M = 10009, Z = 26;

char A[N], buf[Z]; 
int Q[M]; 
SI have; 
MII ans;
int n, m;

int stk[Z], nn; 
bool vis[Z]; 

void push(int x) {
    if (!vis[x]) {
        vis[stk[nn++] = x] = true;
    } else {
        int j; 
        for(j = 0;; j++) if(stk[j] == x) break;
        for(; j < nn - 1; j++) stk[j] = stk[j + 1]; 
        stk[nn - 1] = x;
    }
}

int main() {
    freopen("in.txt", "r", stdin);

    REP_C(i, n = strlen(fgets(A, N, stdin))) A[i] -= 'a'; 
    A[n] = Z;

    REP_C(i, m) {
        fgets(buf, Z, stdin); 
        REP_S(cur, buf) Q[i] |= (1 << (*cur - 'a'));
        have.insert(Q[i]);
    }

    REP(i, n) {
        push(A[i]); 
        int s = 0; 
        DWN(j, nn, 0) {
            s |= (1 << stk[j]); 
            if ((s & (1 << A[i + 1]))) break;
            if (have.count(s)) ++ans[s];
        }
    }

    REP(i, m) printf("%d\n", ans[Q[i]]);
}
