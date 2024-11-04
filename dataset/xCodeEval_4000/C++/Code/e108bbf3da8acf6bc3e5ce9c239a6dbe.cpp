

#include <cstdio>
#include <bits/stdc++.h>

using namespace std;



inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );



static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}



static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;

inline void readWord( char *s ) {
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}

inline void writeDouble( double x, int output_len ) {
	if (x < 0)
		writeChar('-'), x = -x;
	int t = (int)x;
	writeInt(t), x -= t;
	writeChar('.');
	for (int i = output_len - 1; i > 0; i--) {
		x *= 10;
		t = min(9, (int)x);
		writeChar('0' + t), x -= t;
	}
	x *= 10;
	t = min(9, (int)(x + 0.5));
	writeChar('0' + t);
}









const int base = 1000000000;
const int base_digits = 9;

struct bigint {
    vector<int> a;
    int sign;

    bigint() :
        sign(1) {
    }

    bigint(long long v) {
        *this = v;
    }

    bigint(const string &s) {
        read(s);
    }

    void operator=(const bigint &v) {
        sign = v.sign;
        a = v.a;
    }

    void operator=(long long v) {
        sign = 1;
        if (v < 0)
            sign = -1, v = -v;
        for (; v > 0; v = v / base)
            a.push_back(v % base);
    }

    bigint operator+(const bigint &v) const {
        if (sign == v.sign) {
            bigint res = v;

            for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
                if (i == (int) res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-v);
    }

    bigint operator-(const bigint &v) const {
        if (sign == v.sign) {
            if (abs() >= v.abs()) {
                bigint res = *this;
                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(v - *this);
        }
        return *this + (-v);
    }

    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            

        }
        trim();
    }

    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }

    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1.abs() * norm;
        bigint b = b1.abs() * norm;
        bigint q, r;
        q.a.resize(a.a.size());

        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }

        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }

    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }

    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }

    void operator/=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }

    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }

    int operator%(int v) const {
        if (v < 0)
            v = -v;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m * sign;
    }

    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
    void operator*=(const bigint &v) {
        *this = *this * v;
    }
    void operator/=(const bigint &v) {
        *this = *this / v;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign)
            return sign < v.sign;
        if (a.size() != v.a.size())
            return a.size() * sign < v.a.size() * v.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] * sign < v.a[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }

    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    bigint operator-() const {
        bigint res = *this;
        res.sign = -sign;
        return res;
    }

    bigint abs() const {
        bigint res = *this;
        res.sign *= res.sign;
        return res;
    }

    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }

    friend bigint gcd(const bigint &a, const bigint &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend bigint lcm(const bigint &a, const bigint &b) {
        return a / gcd(a, b) * b;
    }

    void read(const string &s) {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }

    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    typedef vector<long long> vll;

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    bigint operator*(const bigint &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        bigint res;
        res.sign = sign * v.sign;
        for (int i = 0, carry = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = (int) (cur / 1000000);
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }
};








#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")




#define shandom_ruffle random_shuffle
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()
#define pb push_back
#define x first
#define y second









using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using ull = unsigned long long;


























const int M = 998244353;
const int mod = 1e9+7;
const int inf = 1e9+100;
const ll inf64 = 1e18L;
const ld pi = acos(-1.0L);
const ld eps = 1e-5L;
const int di[] = {1, 1,-1,-1, 2, 2,-2,-2};
const int dj[] = {2,-2, 2,-2, 1,-1, 1,-1};
const int dii[] = {0, 1,-1, 0};
const int djj[] = {1, 0, 0,-1};
const int dx[] = {1, 1,-1,-1};
const int dy[] = {1,-1, 1,-1};
const int SQ = 1000;
const int L = 8;
const int nax = 32e6;

int T;
vll nn, kk, alk, fz[50];
bitset<nax> isp;
vi alp;
vector<vector<pll>> g[50];
vll d[50];

void dio(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return;
    }
    dio(b, a % b, x, y);
    ll x1 = y;
    y = x - y * (a / b);
    x = x1;
}

bigint up(bigint a, bigint b) {
    if(a < bigint(0)) return bigint(-1) * divmod(bigint(-1) * a, b).x;
    return divmod(a + b + bigint(-1), b).x;
}

bigint down(bigint a, bigint b) {
    if(a < bigint(0)) return bigint(-1) * divmod(bigint(-1) * a + b + bigint(-1), b).x;
    return divmod(a, b).x;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(10); cout << fixed;
    

    

    isp.set();
    for(int i = 2; i * i < nax; i++) {
        if(isp[i]) {
            for(int j = i * i; j < nax; j += i) {
                isp[j] = 0;
            }
        }
    }
    alp.reserve(isp.count() - 2);
    for(int i = 2; i < nax; i++) {
        if(isp[i]) {
            alp.pb(i);
        }
    }
    cin >> T;
    nn.resize(T);
    kk.resize(T);
    alk.resize(T);
    for(int i = 0; i < T; i++) {
        cin >> nn[i] >> kk[i];
        alk[i] = kk[i];
    }
    sort(all(alk));
    alk.erase(unique(all(alk)), alk.end());
    for(int i = 0; i < sz(alk); i++) {
        ll k = alk[i];
        for(int x : alp) {
            if(k % x == 0) {
                fz[i].pb(x);
                while(k % x == 0) {
                    k /= x;
                }
            }
        }
        if(k != 1) {
            fz[i].pb(k);
        }
    }
    for(int i = 0; i < sz(alk); i++) {
        if(sz(fz[i]) < 3) {
            continue;
        }
        int N = fz[i][0];
        g[i].resize(N);
        for(int u = 0; u < N; u++) {
            for(ll x : fz[i]) {
                g[i][u].pb({(u + x) % N, x});
            }
        }
        d[i].resize(N, inf64);
        d[i][0] = 0;
        set<pll> q;
        q.insert({0, 0});
        while(!q.empty()) {
            int v = q.begin()->y;
            q.erase(q.begin());
            for(pll e : g[i][v]) {
                if(d[i][v] + e.y < d[i][e.x]) {
                    q.erase({d[i][e.x], e.x});
                    d[i][e.x] = d[i][v] + e.y;
                    q.insert({d[i][e.x], e.x});
                }
            }
        }
    }
    for(int i = 0; i < T; i++) {
        if(kk[i] == 1) {
            cout << "NO\n";
            continue;
        }
        int id;
        for(int j = 0; j < sz(alk); j++) {
            if(alk[j] == kk[i]) {
                id = j;
            }
        }
        if(sz(fz[id]) == 1) {
            cout << (nn[i] % fz[id][0] == 0 ? "YES\n" : "NO\n");
        } else if(sz(fz[id]) == 2) {
            ll a = fz[id][0], b = fz[id][1];
            ll x, y;
            dio(a, b, x, y);
            bigint X = x;
            bigint Y = y;
            X *= bigint(nn[i]);
            Y *= bigint(nn[i]);
            bigint l = up(X * bigint(-1), bigint(b));
            bigint r = down(Y, bigint(a));
            cout << (l <= r ? "YES\n" : "NO\n");
        } else {
            cout << (d[id][nn[i] % fz[id][0]] <= nn[i] ? "YES\n" : "NO\n");
        }
    }
}
