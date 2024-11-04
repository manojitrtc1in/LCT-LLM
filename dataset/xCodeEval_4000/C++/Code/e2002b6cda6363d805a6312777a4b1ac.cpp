#include<bits/stdc++.h>

#pragma GCC optimize(2)


#define hashmap unordered_map
#define hashset unordered_set
#define pq priority_queue
#define cahr char
#define fi first
#define se second
#define pb push_back
#define esle else
#define retunr return
#define so sizeof
#define pr printf


#define cint(x) scanf("%d",&x)
#define cll(x) scanf("%lld",&x)
#define cs(x) scanf("%s",x.begin())
#define cc(x) scanf("%c",&x)

#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)


using namespace std;
typedef long long ll;
typedef int itn;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = (int) 1E6 + 5;
int MOD = (int) 1E9 + 7;

namespace NUM {
    int primes[1000005];
    int visited[1000005];
    vector<int> vp;

    void getAllPrimes() {
        for (int i = 2; i <= 1000000; i++) {
            if (!visited[i]) {
                primes[i] = 1;
                vp.push_back(i);
                for (int j = 2 * i; j <= 1000000; j += i) {
                    visited[j] = 1;
                }
            }
        }
        

    }

    ll gcd(ll a, ll b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void exgcd(int a, int b, int &x, int &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return;
        }
        exgcd(b, (a % b + b) % b, y, x);
        y -= a / b * x;
    }

    ll powmod(ll x, ll n, ll m) {
        if (n == 0) return 1;
        return n % 2 == 0 ? powmod(x * x % m, n / 2, m) : x * powmod(x * x % m, n / 2, m) % m;
    }


    ll block_divide_sum(int x, int s, int e) {
        ll ans = 0;
        for (int i = s; i <= e; i++) {
            int val = x / i;
            int j = min(e, x / val);
            ans += val * (j - i + 1);
            i = j;
        }
        return ans;
    }


}
using namespace NUM;

namespace TP {
    struct tp {
        int i;
        int j;
        int k;

        tp() {}

        tp(int i, int j, int k) : i(i), j(j), k(k) {}

        bool operator==(const tp &rhs) const {
            return i == rhs.i &&
                   j == rhs.j &&
                   k == rhs.k;
        }

        bool operator!=(const tp &rhs) const {
            return !(rhs == *this);
        }
    };

    struct hashtp {
        size_t operator()(const tp &t) const {
            return hash<int>()(t.i) + hash<int>()(t.j) + hash<int>()(t.k);
        }
    };
}
using namespace TP;

namespace ST {

    struct snode {
        int s;
        int e;
        snode *l;
        snode *r;
        ll lazy;
        ll res;
    };

    snode *build(int s, int e, int *p) {
        if (s == e) return new snode{s, e, 0, 0, 0, 1LL << p[s]};

        int m = (s + e) / 2;
        snode *l = build(s, m, p);
        snode *r = build(m + 1, e, p);

        return new snode{s, e, l, r, 0, l->res | r->res};

    }

    void pushdown(snode *root) {
        if (root->lazy != 0) {
            root->l->res = root->lazy;
            root->r->res = root->lazy;
            root->l->lazy = root->lazy;
            root->r->lazy = root->lazy;
            root->lazy = 0;
        }
    }

    void pushup(snode *root) {
        root->res = root->l->res | root->r->res;
    }

    void update(snode *root, int s, int e, int val) {
        if (s == root->s && e == root->e) {
            root->res = 1LL << val;
            root->lazy = 1LL << val;
            return;
        }
        pushdown(root);
        int m = root->s + root->e >> 1;
        if (e <= m) {
            update(root->l, s, e, val);
        } else if (s >= m + 1) {
            update(root->r, s, e, val);
        } else {
            update(root->l, s, m, val);
            update(root->r, m + 1, e, val);
        }
        pushup(root);

    }

    ll query(snode *root, int s, int e) {
        if (s == root->s && e == root->e) {
            return root->res;
        }
        pushdown(root);
        int m = root->s + root->e >> 1;
        if (e <= m) {
            return query(root->l, s, e);
        } else if (s >= m + 1) {
            return query(root->r, s, e);
        } else {
            return query(root->l, s, m) | query(root->r, m + 1, e);
        }
    }

    void rebuild(snode *root, int *p) {
        root->lazy = 0;
        if (root->s == root->e) {
            

            return;
        }
        rebuild(root->l, p);
        rebuild(root->r, p);
        pushup(root);
    }

};
using namespace ST;

namespace UF {

    struct unode {
        int p = -1;
        int cnt = 1;
    };
    unode nodes[2 * N];

    int getpa(int s) {
        while (nodes[s].p != -1) {
            s = nodes[s].p;
        }
        return s;
    }

    void merge(int s1, int s2) {
        int p1 = getpa(s1);
        int p2 = getpa(s2);
        if (p1 == p2) {
            return;
        }
        if (nodes[p1].cnt < nodes[p2].cnt) {
            nodes[p1].p = p2;
            nodes[p2].cnt += nodes[p1].cnt;
        } else {
            nodes[p2].p = p1;
            nodes[p1].cnt += nodes[p2].cnt;
        }
    }

    int same(int s1, int s2) {
        return getpa(s1) == getpa(s2);
    }
}
using namespace UF;






































































namespace IO {
#define BUF_SIZE 100000
#define OUT_SIZE 100000
#define ll long long
    


    bool IOerror = 0;

    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if (p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if (pend == p1) {
                IOerror = 1;
                return -1;
            }
            

        }
        return *p1++;
    }

    inline bool blank(char ch) { return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; }

    inline void read(int &x) {
        bool sign = 0;
        char ch = nc();
        x = 0;
        for (; blank(ch); ch = nc());
        if (IOerror)return;
        if (ch == '-')sign = 1, ch = nc();
        for (; ch >= '0' && ch <= '9'; ch = nc())x = x * 10 + ch - '0';
        if (sign)x = -x;
    }

    inline void read(ll &x) {
        bool sign = 0;
        char ch = nc();
        x = 0;
        for (; blank(ch); ch = nc());
        if (IOerror)return;
        if (ch == '-')sign = 1, ch = nc();
        for (; ch >= '0' && ch <= '9'; ch = nc())x = x * 10 + ch - '0';
        if (sign)x = -x;
    }

    inline void read(double &x) {
        bool sign = 0;
        char ch = nc();
        x = 0;
        for (; blank(ch); ch = nc());
        if (IOerror)return;
        if (ch == '-')sign = 1, ch = nc();
        for (; ch >= '0' && ch <= '9'; ch = nc())x = x * 10 + ch - '0';
        if (ch == '.') {
            double tmp = 1;
            ch = nc();
            for (; ch >= '0' && ch <= '9'; ch = nc())tmp /= 10.0, x += tmp * (ch - '0');
        }
        if (sign)x = -x;
    }

    inline void read(char *s) {
        char ch = nc();
        for (; blank(ch); ch = nc());
        if (IOerror)return;
        for (; !blank(ch) && !IOerror; ch = nc())*s++ = ch;
        *s = 0;
    }

    inline void read(char &c) {
        for (c = nc(); blank(c); c = nc());
        if (IOerror) {
            c = -1;
            return;
        }
    }

    

    struct Ostream_fwrite {
        char *buf, *p1, *pend;

        Ostream_fwrite() {
            buf = new char[BUF_SIZE];
            p1 = buf;
            pend = buf + BUF_SIZE;
        }

        void out(char ch) {
            if (p1 == pend) {
                fwrite(buf, 1, BUF_SIZE, stdout);
                p1 = buf;
            }
            *p1++ = ch;
        }

        void print(int x) {
            static char s[15], *s1;
            s1 = s;
            if (!x)*s1++ = '0';
            if (x < 0)out('-'), x = -x;
            while (x)*s1++ = x % 10 + '0', x /= 10;
            while (s1-- != s)out(*s1);
        }

        void println(int x) {
            static char s[15], *s1;
            s1 = s;
            if (!x)*s1++ = '0';
            if (x < 0)out('-'), x = -x;
            while (x)*s1++ = x % 10 + '0', x /= 10;
            while (s1-- != s)out(*s1);
            out('\n');
        }

        void print(ll x) {
            static char s[25], *s1;
            s1 = s;
            if (!x)*s1++ = '0';
            if (x < 0)out('-'), x = -x;
            while (x)*s1++ = x % 10 + '0', x /= 10;
            while (s1-- != s)out(*s1);
        }

        void println(ll x) {
            static char s[25], *s1;
            s1 = s;
            if (!x)*s1++ = '0';
            if (x < 0)out('-'), x = -x;
            while (x)*s1++ = x % 10 + '0', x /= 10;
            while (s1-- != s)out(*s1);
            out('\n');
        }

        void print(double x, int y) {
            static ll mul[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000,
                               1000000000, 10000000000LL, 100000000000LL, 1000000000000LL, 10000000000000LL,
                               100000000000000LL, 1000000000000000LL, 10000000000000000LL, 100000000000000000LL};
            if (x < -1e-12)out('-'), x = -x;
            x *= mul[y];
            ll x1 = (ll) floor(x);
            if (x - floor(x) >= 0.5)++x1;
            ll x2 = x1 / mul[y], x3 = x1 - x2 * mul[y];
            print(x2);
            if (y > 0) {
                out('.');
                for (size_t i = 1; i < y && x3 * mul[i] < mul[y]; out('0'), ++i);
                print(x3);
            }
        }

        void println(double x, int y) {
            print(x, y);
            out('\n');
        }

        void print(char *s) { while (*s)out(*s++); }

        void println(char *s) {
            while (*s)out(*s++);
            out('\n');
        }

        void flush() {
            if (p1 != buf) {
                fwrite(buf, 1, p1 - buf, stdout);
                p1 = buf;
            }
        }

        ~Ostream_fwrite() { flush(); }
    } Ostream;

    inline void print(int x) { Ostream.print(x); }

    inline void println(int x) { Ostream.println(x); }

    inline void print(char x) { Ostream.out(x); }

    inline void println(char x) {
        Ostream.out(x);
        Ostream.out('\n');
    }

    inline void print(ll x) { Ostream.print(x); }

    inline void println(ll x) { Ostream.println(x); }

    inline void print(double x, int y) { Ostream.print(x, y); }

    inline void println(double x, int y) { Ostream.println(x, y); }

    inline void print(char *s) { Ostream.print(s); }

    inline void println(char *s) { Ostream.println(s); }

    inline void println() { Ostream.out('\n'); }

    inline void flush() { Ostream.flush(); }

#undef ll
#undef OUT_SIZE
#undef BUF_SIZE
};
using namespace IO;

struct mat {
    int temp[2][2];

    mat() {}

    mat(int a, int b, int c, int d) {

        temp[0][0] = a;
        temp[0][1] = b;
        temp[1][0] = c;
        temp[1][1] = d;
    }

    mat operator*(mat m) {
        mat res;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int sum = 0;
                for (int k = 0; k < 2; k++) {
                    sum += (1LL * temp[i][k] * m.temp[k][j]);

                }
                res.temp[i][j] = sum;

            }

        }
        return res;
    }
};

int s2b[N];
int arr[N];
pii qs[N];
int qs_copy[N];
int cnt[N];
int sqt[N];

bool compa(int i, int j) {
    pii p1 = qs[i];
    pii p2 = qs[j];
    int temp1 = p1.fi / 2000;
    int temp2 = p2.fi / 2000;
    if (temp1 == temp2) {
        if (temp1 % 2) return p1.se < p2.se;
        return p1.se > p2.se;
    }
    return temp1 < temp2;
}

int mapp[N];
hashmap<int, int> b2s;

void solve() {
    int n, m;
    read(n);
    for (int i = 0; i < n; i++) {
        read(arr[i]);
        b2s[arr[i]] = 0;
    }

    int index = 0;
    for (auto &a:b2s) {
        s2b[index] = a.fi;
        a.se = index++;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = b2s[arr[i]];
    }

    read(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        read(a);
        read(b);
        a--;
        b--;
        qs[i].fi = a;
        qs[i].se = b;

        qs_copy[i] = i;



    }
    sort(qs_copy, qs_copy + m, compa);
    int i = 0, j = -1, ans = 0;
    for (int ii = 0; ii < m; ii++) {
        pii &p = qs[qs_copy[ii]];
        while (i != p.fi) {
            if (i < p.fi) {
                cnt[arr[i]]--;
                if (cnt[arr[i]] != 0) {

                    ans ^= s2b[arr[i]];
                }
                i++;
            } else {
                i--;
                cnt[arr[i]]++;
                if (cnt[arr[i]] != 1) {
                    ans ^= s2b[arr[i]];
                }
            }
        }
        while (j != p.se) {
            if (j < p.se) {
                j++;
                cnt[arr[j]]++;
                if (cnt[arr[j]] != 1) {
                    ans ^= s2b[arr[j]];
                }

            } else {
                cnt[arr[j]]--;
                if (cnt[arr[j]] != 0) {

                    ans ^= s2b[arr[j]];
                }
                j--;

            }
        }
        mapp[qs_copy[ii]] = ans;

    }
    for (int i = 0; i < m; i++) {
        pii &p = qs[i];
        println(mapp[i]);

    }

}


int main() {

    solve();

    return 0;
}
