




















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
        x = (x * 10) + (c ^ 48);
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

namespace dfcmd {

    typedef long long LL;

    const int maxn = 200005;

    int n;
    char s[maxn];
    int x[maxn];
    LL xx[maxn];
    pair<LL, int> idd[maxn];

    inline void solve() {
        scanf("%d%s", &n, s + 2);
        LL noww = 0;
        x[n] = 0;
        for (int i = n - 1; i; --i) {
            if (s[i + 1] == '>') {
                noww += 100000000LL;
                xx[i] = ++noww;
            } else {
                xx[i] = --noww;
            }
        }
        for (int i = 1; i <= n; ++i) {
            idd[i] = make_pair(xx[i], i);
        }
        sort(idd + 1, idd + n + 1);
        for (int i = 1; i <= n; ++i) {
            xx[idd[i].second] = i;
        }
        for (int i = 1; i <= n; ++i) {
            id0(xx[i]);
        }
        puts("");
        int l = 1, r = 1;
        x[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (s[i] == '<') {
                x[i] = ++r;
            } else {
                x[i] = --l;
            }
        }
        for (int i = 1; i <= n; ++i) {
            x[i] -= l;
            x[i]++;
            id0(x[i]);
        }
        puts("");
    }

    int Main() {
        int T;
        scanf("%d", &T);
        while (T--) {
            solve();
        }
        return 0;
    }

}

int main() {
    return dfcmd::Main();
}

