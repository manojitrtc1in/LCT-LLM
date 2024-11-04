




#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <iomanip> 








using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef float ff;
typedef double lf;
typedef long double llf;

typedef complex<ull> cull;
typedef complex<ff> cff;


typedef complex<lf> cllf;

const double eps = 1e-6;
const int int_inf = 2 * 1e9;
const ll ll_inf = 8 * 1e18;
const llf PI = acosl(-1.0);

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define polar(r, a)  (cplx<ld>){r*cos(a),r*sin(a)}






template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

istream& operator >> (istream& in, pii& i) {
    in >> i.first >> i.second;
    return in;
}

template<class T>
istream& operator >> (istream& in, vector<T>& a) {
    for (auto& i : a) {
        in >> i;
    }
    return in;
}

template<class T>
ostream& operator << (ostream& out, vector<T>& a) {
    for (auto i : a) {
        out << i << " ";
    }
    return out;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (ull)rng() % B;
}

template<typename T>
int64_t merge_sort(T* v, T* aux, int l, int r) {
    if (r <= l + 1) return 0;
    int m = (l + r) / 2;
    int64_t res = merge_sort(v, aux, l, m) + merge_sort(v, aux, m, r);
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        aux[k++] = v[i] <= v[j] ? v[i++] : (res += m - i, v[j++]);
    }
    while (i < m) aux[k++] = v[i++];
    while (j < r) aux[k++] = v[j++];
    while (l < r) {
        v[l] = aux[l];
        ++l;
    }
    return res;
}
template<typename T>
int64_t count_inversions(std::vector<T> v) {
    std::vector<T> aux(v.size());
    return merge_sort(v.data(), aux.data(), 0, v.size());
}

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(llf t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }




ll gcd(ll a, ll b) { if (b > a) { return gcd(b, a); } if (b == 0) { return a; } return gcd(b, a % b); }
ll expo(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }
void extendgcd(ll a, ll b, ll* v) { if (b == 0) { v[0] = 1; v[1] = 0; v[2] = a; return; } extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return; } 

ll mminv(ll a, ll b) { ll arr[3]; extendgcd(a, b, arr); return arr[0]; } 

ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
void swap(int& x, int& y) { int temp = x; x = y; y = temp; }
ll combination(ll n, ll r, ll m, ll* fact, ll* ifact) { ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m; }
void google(int t) { std::cout << "Case #" << t << ": "; }
vector<int> sieve(int n) { int* arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) { vect.push_back(i); for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1; } return vect; }
ll mod_add(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m) { a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m; }  

ll phin(ll n) { ll number = n; if (n % 2 == 0) { number /= 2; while (n % 2 == 0) n /= 2; } for (ll i = 3; i * i <= n; i += 2) { if (n % i == 0) { while (n % i == 0)n /= i; number = (number / i * (i - 1)); } } if (n > 1)number = (number / n * (n - 1)); return number; } 





typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
const int MOD = 1e9 + 7;

template<class T> struct cplx {
    T x, y;
    cplx() {
        x = 0.0;
        y = 0.0;
    }
    cplx(T nx, T ny = 0) {
        x = nx;
        y = ny;
    }
    cplx operator+(const cplx& c) const {
        return { x + c.x, y + c.y };
    }
    cplx operator-(const cplx& c) const {
        return { x - c.x, y - c.y };
    }
    cplx operator*(const cplx& c) const {
        return { x * c.x - y * c.y, x * c.y + y * c.x };
    }
    cplx& operator*=(const cplx& c) {
        return *this = { x * c.x - y * c.y, x * c.y + y * c.x };
    }
    inline T real() const {
        return x;
    }
    inline T imag() const {
        return y;
    }
    

    template<class U> cplx operator*(const U& c) const {
        return { x * c, y * c };
    }
    template<class U> cplx operator/(const U& c) const {
        return { x / c, y / c };
    }
    template<class U> void operator/=(const U& c) {
        x /= c;
        y /= c;
    }
};




const int DIG = 9, FDIG = 4;
const int BASE = 1e9, FBASE = 1e4;
typedef cplx<ld> Cplx;







struct BigInt {
    int sgn;
    vector<int> a;
    BigInt() : sgn(1) {}
    BigInt(ll v) {
        *this = v;
    }
    BigInt& operator = (ll v) {
        sgn = 1;
        if (v < 0) sgn = -1, v = -v;
        a.clear();
        for (; v > 0; v /= BASE) a.push_back(v % BASE);
        return *this;
    }
    BigInt(const BigInt& other) {
        sgn = other.sgn;
        a = other.a;
    }
    friend void swap(BigInt& a, BigInt& b) {
        swap(a.sgn, b.sgn);
        swap(a.a, b.a);
    }
    BigInt& operator = (BigInt other) {
        swap(*this, other);
        return *this;
    }
    BigInt(BigInt&& other) : BigInt() {
        swap(*this, other);
    }
    BigInt(const string& s) {
        read(s);
    }
    void read(const string& s) {
        sgn = 1;
        a.clear();
        int k = 0;
        for (; k < s.size() && (s[k] == '-' || s[k] == '+'); k++)
            if (s[k] == '-') sgn = -sgn;
        for (int i = s.size() - 1; i >= k; i -= DIG) {
            int x = 0;
            for (int j = max(k, i - DIG + 1); j <= i; j++) x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }
    friend istream& operator>>(istream& in, BigInt& v) {
        string s;
        in >> s;
        v.read(s);
        return in;
    }
    friend ostream& operator<<(ostream& out, const BigInt& v) {
        if (v.sgn == -1 && !v.zero()) out << '-';
        out << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int)v.a.size() - 2; i >= 0; --i)
            out << setw(DIG) << setfill('0') << v.a[i];
        return out;
    }
    bool operator<(const BigInt& v) const {
        if (sgn != v.sgn) return sgn < v.sgn;
        if (a.size() != v.a.size()) return a.size() * sgn < v.a.size()* v.sgn;
        for (int i = (int)a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i]) return a[i] * sgn < v.a[i] * sgn;
        return 0;
    }
    bool operator>(const BigInt& v) const {
        return v < *this;
    }
    bool operator<=(const BigInt& v) const {
        return !(v < *this);
    }
    bool operator>=(const BigInt& v) const {
        return !(*this < v);
    }
    bool operator==(const BigInt& v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const BigInt& v) const {
        return *this < v || v < *this;
    }
    friend int __cmp(const BigInt& x, const BigInt& y) {
        if (x.a.size() != y.a.size()) return x.a.size() < y.a.size() ? -1 : 1;
        for (int i = (int)x.a.size() - 1; i >= 0; --i) if (x.a[i] != y.a[i])
            return x.a[i] < y.a[i] ? -1 : 1;
        return 0;
    }

    BigInt operator-() const {
        BigInt res = *this;
        if (zero()) return res;
        res.sgn = -sgn;
        return res;
    }

    void __add(const BigInt& v) {
        if (a.size() < v.a.size()) a.resize(v.a.size(), 0);
        for (int i = 0, carry = 0; i < max(a.size(), v.a.size()) || carry; ++i) {
            if (i == a.size()) a.push_back(0);
            a[i] += carry + (i < (int)v.a.size() ? v.a[i] : 0);
            carry = a[i] >= BASE;
            if (carry) a[i] -= BASE;
        }
    }

    void __sub(const BigInt& v) {
        for (int i = 0, carry = 0; i < (int)v.a.size() || carry; ++i) {
            a[i] -= carry + (i < (int)v.a.size() ? v.a[i] : 0);
            carry = a[i] < 0;
            if (carry) a[i] += BASE;
        }
        this->trim();
    }

    BigInt operator+=(const BigInt& v) {
        if (sgn == v.sgn) __add(v);
        else if (__cmp(*this, v) >= 0) __sub(v);
        else {
            BigInt vv = v;
            swap(*this, vv);
            __sub(vv);
        }
        return *this;
    }

    BigInt operator-=(const BigInt& v) {
        if (sgn == v.sgn) {
            if (__cmp(*this, v) >= 0) __sub(v);
            else {
                BigInt vv = v;
                swap(*this, vv);
                __sub(vv);
                sgn = -sgn;
            }
        }
        else __add(v);
        return *this;
    }

    template< typename L, typename R >
    typename enable_if <
        is_convertible<L, BigInt>::value&&
        is_convertible<R, BigInt>::value&&
        is_lvalue_reference < R&& >::value,
        BigInt >::type friend operator + (L&& l, R&& r) {
        BigInt result(forward<L>(l));
        result += r;
        return result;
    }
    template< typename L, typename R >
    typename enable_if <
        is_convertible<L, BigInt>::value&&
        is_convertible<R, BigInt>::value&&
        is_rvalue_reference < R&& >::value,
        BigInt >::type friend operator + (L&& l, R&& r) {
        BigInt result(move(r));
        result += l;
        return result;
    }
    template< typename L, typename R >
    typename enable_if <
        is_convertible<L, BigInt>::value&&
        is_convertible<R, BigInt>::value,
        BigInt >::type friend operator - (L&& l, R&& r) {
        BigInt result(forward<L>(l));
        result -= r;
        return result;
    }

    friend pair<BigInt, BigInt> divmod(const BigInt& a1, const BigInt& b1) {
        ll norm = BASE / (b1.a.back() + 1);
        BigInt a = a1.abs() * norm, b = b1.abs() * norm, q = 0, r = 0;
        q.a.resize(a.a.size());
        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= BASE;
            r += a.a[i];
            ll s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            ll s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            ll d = ((ll)BASE * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0) r += b, --d;
            q.a[i] = d;
        }
        q.sgn = a1.sgn * b1.sgn;
        r.sgn = a1.sgn;
        q.trim();
        r.trim();
        auto res = make_pair(q, r / norm);
        if (res.second < 0) res.second += b1;
        return res;
    }
    BigInt operator/(const BigInt& v) const {
        return divmod(*this, v).first;
    }
    BigInt operator%(const BigInt& v) const {
        return divmod(*this, v).second;
    }
    void operator/=(int v) {
        if (llabs(v) >= BASE) {
            *this /= BigInt(v);
            return;
        }
        if (v < 0) sgn = -sgn, v = -v;
        for (int i = (int)a.size() - 1, rem = 0; i >= 0; --i) {
            ll cur = a[i] + rem * (ll)BASE;
            a[i] = (int)(cur / v);
            rem = (int)(cur % v);
        }
        trim();
    }
    BigInt operator/(int v) const {
        if (llabs(v) >= BASE) return *this / BigInt(v);
        BigInt res = *this;
        res /= v;
        return res;
    }
    void operator/=(const BigInt& v) {
        *this = *this / v;
    }
    ll operator%(ll v) const {
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i) m = (a[i] + m * (ll)BASE) % v;
        return m * sgn;
    }
    void operator*=(int v) {
        if (llabs(v) >= BASE) {
            *this *= BigInt(v);
            return;
        }
        if (v < 0) sgn = -sgn, v = -v;
        for (int i = 0, carry = 0; i < a.size() || carry; ++i) {
            if (i == a.size()) a.push_back(0);
            ll cur = a[i] * (ll)v + carry;
            carry = (int)(cur / BASE);
            a[i] = (int)(cur % BASE);
        }
        trim();
    }
    BigInt operator*(int v) const {
        if (llabs(v) >= BASE) return *this * BigInt(v);
        BigInt res = *this;
        res *= v;
        return res;
    }

    static vector<int> convert_base(const vector<int>& a, int old_digits, int new_digits) {
        vector<ll> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int)p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        ll cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back((ll)(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int)cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    void fft(vector<Cplx>& a, bool invert) const {
        int n = a.size();
        for (int i = 1, j = 0; i < n; ++i) {
            int bit = n / 2;
            for (; j >= bit; bit /= 2) j -= bit;
            j += bit;
            if (i < j) swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len *= 2) {
            ld ang = 2 * PI / len * (invert ? -1 : 1);
            Cplx wlen = polar(1, ang);
            for (int i = 0; i < n; i += len) {
                Cplx w(1);
                for (int j = 0; j < len / 2; ++j) {
                    Cplx u = a[i + j], v = a[i + j + len / 2] * w;
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                    w *= wlen;
                }
            }
        }
        if (invert) for (int i = 0; i < n; ++i) a[i] /= n;
    }
    void multiply_fft(const vector<int>& a, const vector<int>& b, vector<int>& res) const {
        vector<Cplx> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        int n = 1;
        while (n < max(a.size(), b.size())) n *= 2;
        n *= 2;
        fa.resize(n);
        fb.resize(n);
        fft(fa, 0);
        fft(fb, 0);
        for (int i = 0; i < n; ++i) fa[i] *= fb[i];
        fft(fa, 1);
        res.resize(n);
        ll carry = 0;
        for (int i = 0; i < n; i++) {
            ll t = (ll)(fa[i].real() + 0.5) + carry;
            carry = t / FBASE;
            res[i] = t % FBASE;
        }
    }
    static inline int rev_incr(int a, int n) {
        int msk = n / 2, cnt = 0;
        while (a & msk) {
            cnt++;
            a <<= 1;
        }
        a &= msk - 1;
        a |= msk;
        while (cnt--) a >>= 1;
        return a;
    }
    static vector<Cplx> FFT(vector<Cplx> v, int dir = 1) {
        Cplx wm, w, u, t;
        int n = v.size();
        vector<Cplx> V(n);
        for (int k = 0, a = 0; k < n; ++k, a = rev_incr(a, n))
            V[a] = v[k] / ld(dir > 0 ? 1 : n);
        for (int m = 2; m <= n; m <<= 1) {
            wm = polar((ld)1, dir * 2 * PI / m);
            for (int k = 0; k < n; k += m) {
                w = 1;
                for (int j = 0; j < m / 2; ++j, w *= wm) {
                    u = V[k + j];
                    t = w * V[k + j + m / 2];
                    V[k + j] = u + t;
                    V[k + j + m / 2] = u - t;
                }
            }
        }
        return V;
    }
    static void convolution(const vector<int>& a, const vector<int>& b, vector<int>& c) {
        int sz = a.size() + b.size() - 1;
        int n = 1 << int(ceil(log2(sz)));
        vector<Cplx> av(n, 0), bv(n, 0), cv;
        for (int i = 0; i < a.size(); i++) av[i] = a[i];
        for (int i = 0; i < b.size(); i++) bv[i] = b[i];
        cv = FFT(bv);
        bv = FFT(av);
        for (int i = 0; i < n; i++) av[i] = bv[i] * cv[i];
        cv = FFT(av, -1);
        c.resize(n);
        ll carry = 0;
        for (int i = 0; i < n; i++) {
            ll t = ll(cv[i].real() + 0.5) + carry;
            carry = t / FBASE;
            c[i] = t % FBASE;
        }
    }
    BigInt mul_simple(const BigInt& v) const {
        BigInt res;
        res.sgn = sgn * v.sgn;
        res.a.resize(a.size() + v.a.size());
        for (int i = 0; i < a.size(); i++) if (a[i])
            for (int j = 0, carry = 0; j < v.a.size() || carry; j++) {
                ll cur = res.a[i + j] + (ll)a[i] * (j < v.a.size() ? v.a[j] : 0) + carry;
                carry = (int)(cur / BASE);
                res.a[i + j] = (int)(cur % BASE);
            }
        res.trim();
        return res;
    }
    BigInt mul_fft(const BigInt& v) const {
        BigInt res;
        convolution(convert_base(a, DIG, FDIG), convert_base(v.a, DIG, FDIG), res.a);
        res.a = convert_base(res.a, FDIG, DIG);
        res.trim();
        return res;
    }
    void operator*=(const BigInt& v) {
        *this = *this * v;
    }
    BigInt operator*(const BigInt& v) const {
        if (1LL * a.size() * v.a.size() <= 1000111) return mul_simple(v);
        return mul_fft(v);
    }

    BigInt abs() const {
        BigInt res = *this;
        res.sgn *= res.sgn;
        return res;
    }
    void trim() {
        while (!a.empty() && !a.back()) a.pop_back();
    }
    bool zero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }
    friend BigInt gcd(const BigInt& a, const BigInt& b) {
        return b.zero() ? a : gcd(b, a % b);
    }
};
BigInt power(BigInt a, ll k) {
    BigInt ans = 1;
    while (k > 0) {
        if (k & 1) ans *= a;
        a *= a;
        k >>= 1;
    }
    return ans;
}



ll fact[35];

ll powmod(ll a, ll b, ll p) {
    a %= p;
    if (a == 0) return 0;
    ll product = 1;
    while (b > 0) {
        if (b & 1) {    

            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    

    }
    return product;
}

ll inv(ll a, ll p) {
    return powmod(a, p - 2, p);
}

ll nCk(ll n, ll k, ll p) {
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n - k], p)) % p;
}






void solve() {
    int n, k;
    ll x;
    cin >> n >> k >> x;

    string s;
    cin >> s;
    if (k == 0) {
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                cout << s[i];
            }
        }
        cout << '\n';
        return;
    }

    vector<ll> possible_b;

    int first = 1, last = 0;

    if (s[0] != 'a') {
        last = 0;
    }

    bool flag = true;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            if (!flag) {
                possible_b.push_back(k * (last - first + 1));
            }
            flag = true;
        }
        else {
            if (flag) {
                first = i;
                last = i;
                flag = false;
            }
            else {
                last = i;
            }
        }
    }
    if (!flag) {
        possible_b.push_back(k * (last - first + 1));
    }
    flag = true;
    if (possible_b.size() == 0) {
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                cout << s[i];
            }
        }
        cout << '\n';
        return;
    }
    reverse(all(possible_b));
    vector<BigInt> ans(possible_b.size(), 0);
    vector<BigInt> pos(possible_b.size(), 0LL);
    BigInt cur_pos = 1LL;
    int cur_i = possible_b.size();
    for (int i = 0; i < possible_b.size(); ++i) {
        pos[i] = cur_pos;
        BigInt position = (x + cur_pos - 1) / cur_pos;
        if (position > possible_b[i] + 1) {
            cur_pos *= possible_b[i] + 1;
        }
        else {
            cur_i = i;
            break;
        }
    }
    BigInt l = 0, r = possible_b[cur_i] + 1;
    while (r - l > 1) {
        BigInt m = l + (r - l) / 2;
        if (cur_pos * m < x) {
            l = m;
        }
        else {
            r = m;
        }
    }

    ans[cur_i] = BigInt(r);
    BigInt last_pos = r * pos[cur_i];

    for (int i = cur_i - 1; i >= 0; --i) {
        ll l = -1, r = possible_b[i] + 2;
        while (r - l > 1) {
            ll m = l + (r - l) / 2;
            if (last_pos - pos[i] * m < x) {
                r = m;
            }
            else {
                l = m;
            }
        }
        ans[i] = possible_b[i] + 1 - l;
        last_pos -= pos[i] * l;
    }

    reverse(all(ans));

    flag = false;

    int p = 0;

    if (s[0] == 'a') flag = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            if (!flag) {
                for (BigInt j = 0; j < ans[p] - 1; j += 1) {
                    cout << 'b';
                }
                ++p;
            }
            cout << 'a';
            flag = true;
        }
        else {
            flag = false;
        }
    }
    if (!flag) {
        for (BigInt j = 0; j < ans[p] - 1; j += 1) {
            cout << 'b';
        }
    }
    cout << '\n';
    return;
}

signed main() {
    

    

    

    

    

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}