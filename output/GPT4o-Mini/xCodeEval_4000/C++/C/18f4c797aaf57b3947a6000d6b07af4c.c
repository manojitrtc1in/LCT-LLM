#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>

#define N 1000009
#define M 10009
#define Z 26

char A[N], buf[Z];
int Q[M];
std::set<int> have;
std::map<int, int> ans;
int n, m;

int stk[Z], nn;
bool vis[Z];

void push(int x) {
    if (!vis[x]) {
        vis[stk[nn++] = x] = true;
    } else {
        int j;
        for (j = 0;; j++) if (stk[j] == x) break;
        for (; j < nn - 1; j++) stk[j] = stk[j + 1];
        stk[nn - 1] = x;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

    n = strlen(fgets(A, N, stdin));
    for (int i = 0; i < n; i++) A[i] -= 'a';
    A[n] = Z;

    for (int i = 0; i < m; i++) {
        fgets(buf, Z, stdin);
        int cur = 0;
        for (char *p = buf; *p; p++) {
            Q[i] |= (1 << (*p - 'a'));
        }
        have.insert(Q[i]);
    }

    for (int i = 0; i < n; i++) {
        push(A[i]);
        int s = 0;
        for (int j = nn - 1; j >= 0; j--) {
            s |= (1 << stk[j]);
            if (s & (1 << A[i + 1])) break;
            if (have.count(s)) ans[s]++;
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", ans[Q[i]]);
    }
}
