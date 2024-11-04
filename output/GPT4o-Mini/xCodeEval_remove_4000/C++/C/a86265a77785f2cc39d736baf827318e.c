#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

typedef long long LL;

#define MAXN 200005
#define MOD 998244353

int n, k;
int aa[MAXN];
int bb[MAXN];

inline char gc() {
    static const LL L = 233333;
    static char sxd[L], *sss = sxd, *ttt = sxd;
    if (sss == ttt) {
        ttt = (sss = sxd) + fread(sxd, 1, L, stdin);
        if (sss == ttt) {
            return EOF;
        }
    }
    return *sss++;
}

inline char readalpha() {
    char dd;
    char c;
    for (c = gc(); !isalpha(c); c = gc());
    return c;
}

inline char readchar() {
    char dd;
    char c;
    for (c = gc(); c == ' '; c = gc());
    return c;
}

inline bool read(int *x) {
    bool flg = false;
    char c;
    *x = 0;
    for (c = gc(); !isdigit(c); c = gc()) {
        if (c == '-') {
            flg = true;
        } else if(c == EOF) {
            return false;
        }
    }
    for (; isdigit(c); c = gc()) {
        *x = (*x * 10) + (c ^ 48);
    }
    if (flg) {
        *x = -(*x);
    }
    return true;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x < 10) {
        putchar(x | 48);
        return;
    }
    write(x / 10);
    putchar((x % 10) | 48);
}

inline void id0(int x) {
    write(x);
    putchar(' ');
}

inline void writeln(int x) {
    write(x);
    puts("");
}

inline int nxt(int x) {
    x++;
    if (x > n) {
        x = 1;
    }
    return x;
}

inline int pre(int x) {
    x--;
    if (x < 1) {
        x = n;
    }
    return x;
}

inline void add(int *x, int y) {
    *x += y;
    if (*x >= MOD) {
        *x -= MOD;
    }
}

inline int ksm(int a, int b) {
    int ans = 1;
    for (; b; b >>= 1, a = (LL) a * a % MOD) {
        if (b & 1) {
            ans = (LL) a * ans % MOD;
        }
    }
    return ans;
}

int fac[MAXN];
int inv[MAXN];

inline int C(int n, int m) {
    return (LL) fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main() {
    read(&n), read(&k);
    for (int i = 1; i <= n; ++i) {
        read(&aa[i]);
        bb[pre(i)] = aa[i];
    }
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (LL) fac[i - 1] * i % MOD;
    }
    inv[n] = ksm(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i) {
        inv[i] = (LL) inv[i + 1] * (i + 1) % MOD;
    }
    int ans = 1;
    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
        if (aa[i] == bb[i]) {
            ans = (LL) ans * k % MOD;
        } else {
            cnt++;
        }
    }

    int tmpans = 0;
    for (int i = 0; i <= cnt; i += 2) {
        int anss = (LL) ksm(k - 2, cnt - i) * C(i, i >> 1) % MOD * C(cnt, i) % MOD;
        add(&tmpans, anss);
    }
    ans = (LL) tmpans * ans % MOD;

    int Ans = ksm(k, n);
    Ans -= ans;
    if (Ans < 0) {
        Ans += MOD;
    }
    writeln((LL) Ans * ksm(2, MOD - 2) % MOD);
    return 0;
}
