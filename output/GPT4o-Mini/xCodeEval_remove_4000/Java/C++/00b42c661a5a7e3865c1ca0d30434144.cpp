#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

class Main {
public:
    void run() {
        solve();
    }

private:
    long mul(long a, long b, long p) {
        long res = 0, base = a;
        while (b > 0) {
            if ((b & 1L) > 0)
                res = (res + base) % p;
            base = (base + base) % p;
            b >>= 1;
        }
        return res;
    }

    long mod_pow(long k, long n, long p) {
        long res = 1L;
        long temp = k;
        while (n != 0L) {
            if ((n & 1L) == 1L) {
                res = (res * temp) % p;
            }
            temp = (temp * temp) % p;
            n >>= 1L;
        }
        return res % p;
    }

    int ct = 0;
    int f[200001];
    int b[200001];
    int str[200001];

    void go(int rt, vector<int> g[]) {
        str[ct] = rt;
        f[rt] = ct;
        for (int cd : g[rt]) {
            ct++;
            go(cd, g);
        }
        b[rt] = ct;
    }

    int add = 0;

    void sort(long a[], int n) {
        random_device rd;
        mt19937 gen(rd());
        for (int i = 1; i < n; ++i) {
            int p = gen() % (i + 1);
            swap(a[p], a[i]);
        }
        sort(a, a + n);
    }

    void dfs(int from, int k) {
        // Implementation needed
    }

    void add(int u, int v) {
        to[ct] = u;
        ne[ct] = h[v];
        h[v] = ct++;
    }

    int r = 0;
    void dfs1(int c, int ff) {
        clr[c][aa[c]]++;
        for (int j = h[c]; j != -1; j = ne[j]) {
            if (to[j] == ff) continue;
            dfs1(to[j], c);
            clr[c][1] += clr[to[j]][1];
            clr[c][2] += clr[to[j]][2];
            if ((clr[to[j]][1] == s1 && clr[to[j]][2] == 0) || (clr[to[j]][2] == s2 && clr[to[j]][1] == 0)) {
                r++;
            }
        }
    }

    int *h, *ne, *to, *fa;
    int clr[200001][3];
    int aa[200001];
    int s1 = 0;
    int s2 = 0;

    bool f(int n) {
        int c = 0;
        while (n > 0) {
            c += n % 10;
            n /= 10;
        }
        return (c & 3) == 0;
    }

    vector<vector<int>> next(string s) {
        int len = s.length();
        vector<vector<int>> ne(len + 1, vector<int>(26, -1));
        for (int i = len - 1; i >= 0; --i) {
            ne[i] = ne[i + 1];
            ne[i][s[i] - 'a'] = i + 1;
        }
        return ne;
    }

    void solve() {
        string s, t;
        cin >> s >> t;
        int len = s.length();
        vector<int> pref(len), suf(len + 1);
        int p = 0;
        int tlen = t.length();
        for (int i = 0; i < len; ++i) {
            if (p < tlen && s[i] == t[p]) {
                p++;
            }
            pref[i] = p;
        }
        p = 0;
        for (int i = len - 1; i >= 0; --i) {
            if (p < tlen && s[i] == t[tlen - 1 - p]) {
                p++;
            }
            suf[i] = p;
        }
        int e = -1, all = 0;
        for (int i = -1; i < len; ++i) {
            int r = tlen - (i < 0 ? 0 : pref[i]);
            while (e + 1 <= len && suf[e + 1] >= r) {
                e++;
            }
            all = max(all, e - i - 1);
        }
        cout << all << endl;
    }

    long t1[200001];

    void update(long t[], int i, long v) {
        for (; i < sizeof(t) / sizeof(t[0]); i += (i & -i)) {
            t[i] += v;
        }
    }

    long get(long t[], int i) {
        long s = 0;
        for (; i > 0; i -= (i & -i)) {
            s += t[i];
        }
        return s;
    }

    int id0(long t[], long v) {
        int s = 0, p = 0;
        for (int i = __builtin_ctzll(__builtin_huge_val(t.length())); i >= 0; --i) {
            if (p + (1 << i) < t.length() && s + t[p + (1 << i)] < v) {
                v -= t[p + (1 << i)];
                p |= 1 << i;
            }
        }
        return p + 1;
    }

    struct S {
        int l = 0;
        int r = 0;
        long le = 0;
        long ri = 0;
        long tot = 0;
        long all = 0;

        S(int l, int r) : l(l), r(r) {}
    };

    static S a[800001];
    static int *o;

    static void init(int f[]) {
        o = f;
        int len = sizeof(o) / sizeof(o[0]);
        a[len * 4];
        build(1, 0, len - 1);
    }

    static void build(int num, int l, int r) {
        S cur(l, r);
        if (l == r) {
            a[num] = cur;
            return;
        } else {
            int m = (l + r) >> 1;
            int le = num << 1;
            int ri = le | 1;
            build(le, l, m);
            build(ri, m + 1, r);
            a[num] = cur;
            pushup(num, le, ri);
        }
    }

    static long dd = 10007;

    static void update(int num, int l, long v) {
        if (a[num].l == a[num].r) {
            a[num].le = v % dd;
            a[num].ri = v % dd;
            a[num].all = v % dd;
            a[num].tot = v % dd;
        } else {
            int m = (a[num].l + a[num].r) >> 1;
            int le = num << 1;
            int ri = le | 1;
            pushdown(num, le, ri);
            if (l <= m) {
                update(le, l, v);
            }
            if (l > m) {
                update(ri, l, v);
            }
            pushup(num, le, ri);
        }
    }

    static void pushup(int num, int le, int ri) {
        a[num].all = (a[le].all * a[ri].all) % dd;
        a[num].le = (a[le].le + a[le].all * a[ri].le) % dd;
        a[num].ri = (a[ri].ri + a[ri].all * a[le].ri) % dd;
        a[num].tot = (a[le].tot + a[ri].tot + a[le].ri * a[ri].le) % dd;
    }

    static void pushdown(int num, int le, int ri) {
        // Implementation needed
    }

    long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Main().run();
    return 0;
}
