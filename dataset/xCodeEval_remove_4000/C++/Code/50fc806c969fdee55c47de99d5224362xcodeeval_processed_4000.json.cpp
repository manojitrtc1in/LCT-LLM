




















using namespace std;

inline char gc() {
    static const int L = 233333;
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
    for (; !isalpha(c); dd);
    return c;
}

inline char readchar() {
    char dd;
    for (; c == ' '; dd);
    return c;
}

template <class T>
inline bool read(T& x) {
    bool flg = false;
    char dd;
    x = 0;
    for (; !isdigit(c); dd) {
        if (c == '-') {
            flg = true;
        } else if(c == EOF) {
            return false;
        }
    }
    for (; isdigit(c); dd) {
        x = (x << 1) + (x << 3) + (c ^ 48);
    }
    if (flg) {
        x = -x;
    }
    return true;
}


template <class T>
inline void write(T x) {
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

template <class T>
inline void id0(T x) {
    write(x);
    putchar(' ');
}

template <class T>
inline void writeln(T x) {
    write(x);
    puts("");
}

typedef long long LL;

const int maxn = 1000005;
const int mod = 998244353;

int l[maxn];
int r[maxn];
int C1[maxn];
int C2[maxn];
int fac[maxn];
int inv[maxn];
char s[maxn];

inline void add(int& x, const int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

inline int ksm(int a, int b) {
    int ans = 1;
    for (; b; b >>= 1, a = (LL) a * a % mod) {
        if (b & 1) {
            ans = (LL) ans * a % mod;
        }
    }
    return ans;
}

inline int C(int n, int m) {
    if (n < m || n < 0 || m < 0) {
        return 0;
    }
    return (LL) fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int ans = 0;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (LL) fac[i - 1] * i % mod;
    }
    inv[n] = ksm(fac[n], mod - 2);
    for (int i = n - 1; ~i; --i) {
        inv[i] = (LL) inv[i + 1] * (i + 1) % mod;
    }
    for (int i = 1; i <= n; ++i) {
        l[i] = l[i - 1];
        C1[i] = C1[i - 1];
        if (s[i] == '(') {
            l[i]++;
        } else if (s[i] == '?') {
            C1[i]++;
        }
    }
    for (int i = n; i; --i) {
        r[i] = r[i + 1];
        C2[i] = C2[i + 1];
        if (s[i] == ')') {
            r[i]++;
        } else if (s[i] == '?') {
            C2[i]++;
        }
    }
    for (int i = 1; i < n; ++i) {
        int tmpans = 0;
        int L = l[i], R = r[i + 1];
        int c1 = C1[i], c2 = C2[i + 1];


        add(tmpans, (LL) L * C(c1 + c2, c1 + L - R) % mod);
        add(tmpans, (LL) c1 * C(c1 + c2 - 1, c1 + L - R) % mod);
        add(ans, tmpans);
    }
    writeln(ans);
    return 0;
}

