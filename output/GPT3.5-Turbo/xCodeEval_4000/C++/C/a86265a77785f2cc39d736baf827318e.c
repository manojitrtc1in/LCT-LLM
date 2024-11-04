#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

#define LL long long

char gc() {
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

#ifndef _AT_HOME
#define dd c = gc()
#else
#define dd c = getchar()
#endif

char readalpha() {
    char dd;
    for (; !isalpha(c); dd);
    return c;
}

char readchar() {
    char dd;
    for (; c == ' '; dd);
    return c;
}

int read(int* x) {
    int flg = 0;
    char dd;
    *x = 0;
    for (; !isdigit(c); dd) {
        if (c == '-') {
            flg = 1;
        } else if(c == EOF) {
            return 0;
        }
    }
    for (; isdigit(c); dd) {
        *x = (*x * 10) + (c ^ 48);
    }
    if (flg) {
        *x = -*x;
    }
    return 1;
}

#undef dd

void write(int x) {
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

void writesp(int x) {
    write(x);
    putchar(' ');
}

void writeln(int x) {
    write(x);
    puts("");
}

const int maxn = 200005;
const int jd = 200005;
const int mod = 998244353;

int n, k;
int aa[maxn];
int bb[maxn];

int nxt(int x) {
    x++;
    if (x > n) {
        x = 1;
    }
    return x;
}

int pre(int x) {
    x--;
    if (x < 1) {
        x = n;
    }
    return x;
}

void add(int* x, int y) {
    *x += y;
    if (*x >= mod) {
        *x -= mod;
    }
}

int ksm(int a, int b) {
    int ans = 1;
    for (; b; b >>= 1, a = (LL) a * a % mod) {
        if (b & 1) {
            ans = (LL) a * ans % mod;
        }
    }
    return ans;
}

int fac[maxn];
int inv[maxn];

int C(int n, int m) {
    return (LL) fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
    read(&n);
    read(&k);
    for (int i = 1; i <= n; ++i) {
        read(&aa[i]);
        bb[pre(i)] = aa[i];
    }
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (LL) fac[i - 1] * i % mod;
    }
    inv[n] = ksm(fac[n], mod - 2);
    for (int i = n - 1; ~i; --i) {
        inv[i] = (LL) inv[i + 1] * (i + 1) % mod;
    }
    int ans = 1;
    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
        if (aa[i] == bb[i]) {
            ans = (LL) ans * k % mod;
        } else {
            cnt++;
        }
    }


    int tmpans = 0;
    for (int i = 0; i <= cnt; i += 2) {
        int anss = (LL) ksm(k - 2, cnt - i) * C(i, i >> 1) % mod * C(cnt, i) % mod;


        add(&tmpans, anss);
    }
    ans = (LL) tmpans * ans % mod;


    int Ans = ksm(k, n);
    Ans -= ans;
    if (Ans < 0) {
        Ans += mod;
    }
    writeln((LL) Ans * ksm(2, mod - 2) % mod);
    return 0;
}
