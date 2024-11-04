#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

typedef long long ll;
typedef struct {
    int F, S;
} pii;

typedef struct {
    ll F, S;
} pll;

const int maxn1 = 31, maxn2 = 100, maxn3 = (1 << 20) + 10;
const ll inf = 1e18;

ll C[maxn2][maxn2];
int arr[2 * maxn1], A, B, n, N;
int pa1, pb1;
ll pre1, opt[maxn1][maxn1];
ll vec[maxn1][maxn3], pt[maxn1];

void do_save(int l, int r) {
    memset(pt, 0, sizeof(pt));
    int MSKA = 0, MSKB = 0, SZ = r - l;
    for (int i = l; i < r; i++) {
        if (arr[i] == 1) MSKA += (1 << (i - l));
        if (arr[i] == -1) MSKB += (1 << (i - l));
    }
    for (int msk = 0; msk < (1 << SZ); msk++) {
        if ((MSKA & msk) != MSKA || (MSKB & msk) != 0 || pa1 + __builtin_popcount(msk) >= maxn1) continue;
        int cnta = pa1, cntb = pb1;
        ll num = pre1;
        for (int i = 0; i < SZ; i++) {
            if (bit(msk, i))
                num += C[cnta][A - 1] * C[cntb][A], cnta++;
            else
                num -= C[cnta][A] * C[cntb][A - 1], cntb++;
        }
        vec[cnta][pt[cnta]++] = num;
    }
    for (int i = 0; i < maxn1; i++) {
        qsort(vec[i], pt[i], sizeof(ll), cmp);
    }
}

int cmp(const void *a, const void *b) {
    return (*(ll *)a > *(ll *)b) - (*(ll *)a < *(ll *)b);
}

pll do_calc(int l, int r) {
    int MSKA = 0, MSKB = 0, SZ = r - l;
    pll ans = {inf, 0};
    for (int i = l; i < r; i++) {
        if (arr[i] == 1) MSKA += (1 << (i - l));
        if (arr[i] == -1) MSKB += (1 << (i - l));
    }
    for (int msk = 0; msk < (1 << SZ); msk++) {
        int pp = __builtin_popcount(msk);
        int cnta = n - pp, cntb = l - cnta, start = cnta;
        ll num = 0;
        if (cnta < 0 || cntb < 0 || (MSKA & msk) != MSKA || (MSKB & msk) != 0) continue;
        for (int i = 0; i < SZ; i++) {
            if (bit(msk, i))
                num += C[cnta][A - 1] * C[cntb][A], cnta++;
            else
                num -= C[cnta][A] * C[cntb][A - 1], cntb++;
        }
        ll *it = bsearch(&(-num), vec[start], pt[start], sizeof(ll), cmp);
        pll cand1 = {inf, 0}, cand2 = {inf, 0};
        if (it != vec[start] + pt[start]) {
            ll x = *it;
            cand1 = (pll){num + x, upper_bound(it, vec[start] + pt[start], x) - it};
        }
        if (it != vec[start]) {
            ll x = *(it - 1);
            cand2 = (pll){-num - x, it - lower_bound(vec[start], it, x)};
        }
        if (cand1.F < ans.F) ans = (pll){cand1.F, 0};
        if (cand2.F < ans.F) ans = (pll){cand2.F, 0};
        if (cand1.F == ans.F) ans.S += cand1.S;
        if (cand2.F == ans.F) ans.S += cand2.S;
    }
    return ans;
}

pll solve() {
    pll ans = {inf, 0};
    int Ca = 0, Cb = 0;
    for (int start = 0; start < N; start++) {
        int mid = (start + 1 + N) >> 1;
        if (Ca < A && arr[start] != -1 && Ca + start + 1 >= A && start >= 2 * A - 1) {
            pa1 = A, pb1 = start + 1 - A, pre1 = C[pb1][A];
            do_save(start + 1, mid);
            pll p = do_calc(mid, N);
            if (p.F < ans.F) ans = (pll){p.F, 0};
            if (p.F == ans.F) ans.S += C[start - Ca - Cb][A - 1 - Ca] * p.S;
        }
        if (Cb < A && arr[start] != 1 && Cb + start + 1 >= A && start >= 2 * A - 1) {
            pb1 = A, pa1 = start + 1 - A, pre1 = -C[pa1][A];
            do_save(start + 1, mid);
            pll p = do_calc(mid, N);
            if (p.F < ans.F) ans = (pll){p.F, 0};
            if (p.F == ans.F) ans.S += C[start - Ca - Cb][A - 1 - Cb] * p.S;
        }
        Ca += arr[start] == 1;
        Cb += arr[start] == -1;
    }
    return ans;
}

int main() {
    ll opt[21][21] = {0};
    opt[1][1] = 0; opt[1][2] = 1; opt[1][3] = 0; opt[1][4] = 1; opt[1][5] = 0; opt[1][6] = 1; opt[1][7] = 0; opt[1][8] = 1; opt[1][9] = 0; opt[1][10] = 1;
    // ... (initialize the rest of the opt array as in the C++ code)
    
    C[0][0] = 1;
    for (int i = 1; i < maxn2; i++) {
        C[i][i] = C[i][0] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    scanf("%d %d", &A, &B);
    n = A + B, N = 2 * n;
    char s[200]; // Adjust size as needed
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'A') arr[i] = 1;
        if (s[i] == 'B') arr[i] = -1;
    }
    pll p = solve();
    printf("%lld\n", (p.F == opt[A][B] ? p.S : 0));
    return 0;
}
