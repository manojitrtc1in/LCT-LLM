#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

typedef struct {
    li arr[70][70];
} mat;

int x, k, n, q;
int c[70];
pt a[70];

int read () {
    if (scanf("%d%d%d%d", &x, &k, &n, &q) != 4)
        return 0;
    forn(i, k)
        scanf("%d", &c[i]);
    forn(i, q){
        scanf("%d%d", &a[i].x, &a[i].y);
        --a[i].x;
    }
    return 1;
}

int cnt;

mat multiply(const mat *a, const mat *b){
    mat c;
    forn(i, cnt) forn(j, cnt) c.arr[i][j] = INF64;
    forn(i, cnt) forn(j, cnt) forn(k, cnt) c.arr[i][j] = min(c.arr[i][j], a->arr[i][k] + b->arr[k][j]);
    return c;
}

mat binpow(mat a, int b){
    mat res;
    forn(i, cnt) forn(j, cnt) res.arr[i][j] = i == j ? 0 : INF64;
    while (b){
        if (b & 1)
            res = multiply(&res, &a);
        a = multiply(&a, &a);
        b >>= 1;
    }
    return res;
}

int num[1 << 8];

mat get(int pos, int *mx){
    *mx = n - x - pos;
    int pr[70] = {0};
    forn(i, q) if (pos < a[i].x){
        if (a[i].x <= pos + k){
            pr[a[i].x - pos - 1] = a[i].y;
            *mx = 1;
        }
        else{
            *mx = min(*mx, a[i].x - (pos + k));
        }
    }
    mat res;
    forn(i, cnt) forn(j, cnt) res.arr[i][j] = INF64;
    forn(mask, 1 << k) if (__builtin_popcount(mask) == x){
        if (mask & 1){
            fore(i, 1, k + 1) if (!((mask >> i) & 1))
                res.arr[num[mask]][num[(mask | (1 << i)) >> 1]] = c[i - 1] + pr[i - 1];
        }
        else{
            res.arr[num[mask]][num[mask >> 1]] = 0;
        }
    }
    return res;
}

void solve(){
    cnt = 0;
    forn(mask, 1 << k) if (__builtin_popcount(mask) == x)
        num[mask] = cnt++;
    
    mat cur;
    forn(i, cnt) forn(j, cnt) cur.arr[i][j] = i == j ? 0 : INF64;
    sort(a, a + q);
    for (int i = 0; i < n - x;){
        int mx;
        mat tmp = get(i, &mx);
        i += mx;
        cur = multiply(&cur, &binpow(tmp, mx));
    }
    
    printf("%lld\n", cur.arr[0][0]);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);


    
    int tt = clock();
    
#endif
    
    while(read()) {    
        solve();
        
#ifdef _DEBUG
    cerr << "TIME = " << clock() - tt << endl;
    tt = clock();
#endif

    }
}
