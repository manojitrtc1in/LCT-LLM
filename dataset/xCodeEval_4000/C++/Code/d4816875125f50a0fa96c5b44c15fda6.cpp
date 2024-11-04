#line 1 "test.cpp"






#include <bits/stdc++.h>
#ifdef LOCAL
#  include <debug.hpp>
#  define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#  define debug(...) (static_cast<void>(0))
#endif




using namespace std;


using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vs = vector<string>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
#define overload4(_1, _2, _3, _4, name, ...) name
#define overload3(a,b,c,name,...) name
#define rep1(n) for (ll UNUSED_NUMBER = 0; UNUSED_NUMBER < (n); ++UNUSED_NUMBER)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i = (n) - 1;i >= 0;i--)
#define rrep2(i,n) for(ll i = (n) - 1;i >= 0;i--)
#define rrep3(i,a,b) for(ll i = (b) - 1;i >= (a);i--)
#define rrep4(i,a,b,c) for(ll i = (a) + ((b)-(a)-1) / (c) * (c);i >= (a);i -= c)
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define all1(i) begin(i) , end(i)
#define all2(i,a) begin(i) , begin(i) + a
#define all3(i,a,b) begin(i) + a , begin(i) + b
#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
template<class... Ts> void in(Ts&... t);
#define elif else if
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__; in(__VA_ARGS__)
#define VEC(type, name, size) vector<type> name(size); in(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); in(name)
ll intpow(ll a, ll b){ ll ans = 1; while(b){if(b & 1) ans *= a; a *= a; b /= 2;} return ans;}
ll modpow(ll a, ll b, ll p){ ll ans = 1; a %= p;while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
ll GCD(ll a,ll b) { if(a % b == 0) return b; else return GCD(b,a%b);}
ll LCM(ll a,ll b) { return a / GCD(a,b) * b;}
namespace IO{
#define VOID(a) decltype(void(a))
struct setting{ setting(){cin.tie(nullptr); ios::sync_with_stdio(false);fixed(cout); cout.precision(12);}} setting;
template<int I> struct P : P<I-1>{};
template<> struct P<0>{};
template<class T> void i(T& t){ i(t, P<3>{}); }
void i(vector<bool>::reference t, P<3>){ int a; i(a); t = a; }
template<class T> auto i(T& t, P<2>) -> VOID(cin >> t){ cin >> t; }
template<class T> auto i(T& t, P<1>) -> VOID(begin(t)){ for(auto&& x : t) i(x); }
template<class T, size_t... idx> void ituple(T& t, index_sequence<idx...>){
    in(get<idx>(t)...);
}
template<class T> auto i(T& t, P<0>) -> VOID(tuple_size<T>{}){
    ituple(t, make_index_sequence<tuple_size<T>::value>{});
}
#undef VOID
}
#define unpack(a) (void)initializer_list<int>{(a, 0)...}
template<class... Ts> void in(Ts&... t){ unpack(IO :: i(t)); }
#undef unpack


constexpr int mod = 998244353;
static const double PI = 3.1415926535897932;
template <class F> struct REC {
    F f;
    REC(F &&f_) : f(forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, forward<Args>(args)...); }
};
#line 2 "library/Modint.hpp"
template <int mod>
struct Modint{
    int x;
    Modint():x(0) {}
    Modint(long long y): x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    Modint &operator += (const Modint &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;}
    Modint &operator -= (const Modint &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;}
    Modint &operator *= (const Modint &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;}
    Modint &operator /= (const Modint &p) {
        *this *= p.inverse();
        return *this;}
    Modint operator -() const{return Modint(-x);}
    Modint operator +(const Modint &p) const {return Modint(*this) += p;}
    Modint operator -(const Modint &p) const {return Modint(*this) -= p;}
    Modint operator *(const Modint &p) const {return Modint(*this) *= p;}
    Modint operator /(const Modint &p) const {return Modint(*this) /= p;}
    Modint &operator ++() {if(x == mod - 1) x = 0; else x++; return *this;}
    Modint &operator --() {if(x == 0) x = mod - 1; else x--; return *this;} 
    bool operator == (const Modint &p) const {return x == p.x;}
    bool operator != (const Modint &p) const {return x != p.x;}
    Modint inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return Modint(u);}
    Modint pow(long long n) const {
        Modint ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;}
    friend ostream &operator<<(ostream &os, const Modint &p) { return os << p.x; }
    friend istream &operator>>(istream &is, Modint &a) {
        long long t;
        is >> t;
        a = Modint<mod>(t);
        return (is);
    }
    static constexpr int get_mod() {return mod;}
};
#line 93 "test.cpp"
using mint = Modint<mod>;
vector<mint> fact, fact_inv;
void make_fact(int n){
    fact.resize(n+1), fact_inv.resize(n+1);
    fact[0] = mint(1); rep(i,1,n+1) fact[i] = fact[i-1] * mint(i);
    fact_inv[n] = fact[n].inverse(); rrep(i,0,n) fact_inv[i] = fact_inv[i+1] * mint(i+1);
}
mint ncr(int n, int r){ if(n < 0 || r < 0 || n < r) return mint(0); return fact[n] * fact_inv[r] * fact_inv[n-r];}
mint npr(int n, int r){ if(n < 0 || r < 0 || n < r) return mint(0); return fact[n] * fact_inv[n-r]; }
#line 3 "library/ntt/ntt.hpp"
using namespace std;
template<typename mint>
struct NTT{
    static constexpr uint32_t get_pr() {
        uint32_t _mod = mint::get_mod();
        using u64 = uint64_t;
        u64 ds[32] = {};
        int idx = 0;
        u64 m = _mod - 1;
        for(u64 i = 2;i * i <= m; ++i) {
            if(m % i == 0) {
                ds[idx++] = i;
                while(m % i == 0) m /= i;
            }
        }
        if (m != 1) ds[idx++] = m;
        uint32_t _pr = 2;
        while(1) {
            int flg = 1;
            for(int i = 0;i < idx; ++i) {
                u64 a = _pr, b = (_mod - 1) / ds[i],r = 1;
                while(b) {
                    if(b & 1) r = r * a % _mod;
                    a = a * a % _mod;
                    b >>= 1;
                }
                if(r == 1) {
                    flg = 0;
                    break;
                }
            }
            if (flg == 1) break;
            ++_pr;
        }
        return _pr;
    };
    static constexpr uint32_t mod = mint::get_mod();
    static constexpr uint32_t pr = get_pr();
    static constexpr int level = __builtin_ctzll(mod - 1);
    mint dw[level], dy[level];
    void setwy(int k) {
        mint w[level],y[level];
        w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));
        y[k - 1] = w[k - 1].inverse();
        for(int i = k - 2;i > 0; --i) w[i] = w[i+1] * w[i+1],y[i] = y[i+1] * y[i+1];
        dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] = y[2];
        for(int i = 3;i < k;++i) {
            dw[i] = dw[i-1] * y[i-2] * w[i];
            dy[i] = dy[i-1] * w[i-2] * y[i];
        }
    }
    NTT() {setwy(level);}
    void fft4(vector<mint> &a,int k) {
        if((int)a.size() <= 1) return;
        if(k == 1) {
            mint a1 = a[1];
            a[1] = a[0] - a[1];
            a[0] += a1;
            return;
        }
        if (k & 1) {
            int v = 1 << (k - 1);
            for(int j = 0;j < v; ++j) {
                mint ajv = a[j + v];
                a[j + v] = a[j] - ajv;
                a[j] += ajv;
            }
        }
        int u = 1 << (2 + (k & 1));
        int v = 1 << (k - 2 - (k & 1));
        mint one = mint(1);
        mint imag = dw[1];
        while(v) {
            {
                int j0 = 0,j1 = v;
                int j2 = j1 + v;
                int j3 = j2 + v;
                for(;j0 < v; ++j0,++j1,++j2,++j3) {
                    mint t0 = a[j0], t1 = a[j1],t2 = a[j2],t3 = a[j3];
                    mint t0p2 = t0 + t2,t1p3 = t1 + t3;
                    mint t0m2 = t0 - t2,t1m3 = (t1 - t3) * imag;
                    a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;
                    a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;
                }
            }
            mint ww = one,xx = one * dw[2],wx = one;
            for(int jh = 4;jh < u;) {
                ww = xx * xx,wx = ww * xx;
                int j0 = jh * v;
                int je = j0 + v;
                int j2 = je + v;
                for(;j0 < je;++j0,++j2) {
                    mint t0 = a[j0], t1 = a[j0 + v] * xx, t2 = a[j2] * ww,t3 = a[j2 + v] * wx;
                    mint t0p2 = t0 + t2,t1p3 = t1 + t3;
                    mint t0m2 = t0 - t2,t1m3 = (t1 - t3) * imag;
                    a[j0] = t0p2 + t1p3, a[j0 + v] = t0p2 - t1p3;
                    a[j2] = t0m2 + t1m3, a[j2 + v] = t0m2 - t1m3;
                }
                xx *= dw[__builtin_ctzll((jh += 4))];
            }
            u <<= 2;
            v >>= 2;
        }
    }
    void ifft4(vector<mint> &a,int k) {
        if((int)a.size() <= 1) return;
        if(k == 1) {
            mint a1 = a[1];
            a[1] = a[0] - a[1];
            a[0] = a[0] + a[1];
            return;
        }
        int u = 1 << (k - 2);
        int v = 1;
        mint one = mint(1);
        mint imag = dy[1];
        while(u) {
            {
                int j0 = 0,j1 = v;
                int j2 = j1 + v;
                int j3 = j2 + v;
                for(;j0 < v;++j0,++j1,++j2,++j3) {
                    mint t0 = a[j0],t1 = a[j1],t2 = a[j2],t3 = a[j3];
                    mint t0p1 = t0 + t1, t2p3 = t2 + t3;
                    mint t0m1 = t0 - t1, t2m3 = (t2 - t3) * imag;
                    a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;
                    a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;
                }
            }
            mint ww = one,xx = one * dy[2],yy = one;
            u <<= 2;
            for(int jh = 4;jh < u;) {
                ww = xx * xx,yy = xx * imag;
                int j0 = jh * v;
                int je = j0 + v;
                int j2 = je + v;
                for(;j0 < je;++j0,++j2) {
                    mint t0 = a[j0], t1 = a[j0 + v], t2 = a[j2], t3 = a[j2 + v];
                    mint t0p1 = t0 + t1, t2p3 = t2 + t3;
                    mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;
                    a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;
                    a[j0 + v] = t0m1 + t2m3, a[j2 + v] = (t0m1 - t2m3) * ww;       
                }
                xx *= dy[__builtin_ctzll(jh += 4)];
            }
            u >>= 4;
            v <<= 2;
        }
        if(k & 1) {
            u = 1 << (k - 1);
            for(int j = 0;j < u;++j) {
                mint ajv = a[j] - a[j+u];
                a[j] += a[j+u];
                a[j+u] = ajv;
            }
        }
    }
    void ntt(vector<mint> &a) {
        if((int)a.size() <= 1) return;
        fft4(a,__builtin_ctz(a.size()));
    }
    void intt(vector<mint> &a) {
        if((int)a.size() <= 1) return;
        ifft4(a,__builtin_ctz(a.size()));
        mint iv = mint(a.size()).inverse();
        for(auto &x:a) x *= iv;
    }
    vector<mint> multiply(const vector<mint> &a,const vector<mint> &b) {
        int l = a.size() + b.size() - 1;
        if(min<int>(a.size(),b.size()) <= 40) {
            vector<mint> s(l);
            for(int i = 0;i < (int)a.size();++i) for(int j = 0;j < (int)b.size();++j) s[i+j] += a[i] * b[j];
            return s;
        }
        int k = 2, M = 4;
        while(M < l) M <<= 1, ++k;
        

        vector<mint> s(M), t(M);
        for(int i = 0;i < (int)a.size();++i) s[i] = a[i];
        for(int i = 0;i < (int)b.size();++i) t[i] = b[i];
        fft4(s,k);
        fft4(t,k);
        for(int i = 0;i < M;++i) s[i] *= t[i];
        ifft4(s,k);
        s.resize(l);
        mint invm = mint(M).inverse();
        for(int i = 0;i < l;++i) s[i] *= invm;
        return s;
    }
    void ntt_doubling(vector<mint> &a) {
        int M = (int)a.size();
        vector<mint> b = a;
        intt(b);
        mint r = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));
        for(int i = 0;i < M;++i) b[i] *= r,r *= zeta;
        ntt(b);
        copy(begin(b),end(b),back_inserter(a));
    }
};
#line 103 "test.cpp"
NTT<mint> ntt;
int main() {
    make_fact(300300);
    INT(TT);
    vector<mint> inv2(150150);
    inv2[0] = 1;
    inv2[1] = mint(2).inverse();
    rep(i,2,150150) {
        inv2[i] = inv2[i-1] * inv2[1];
    }
    while(TT--) {
        INT(n);
        vector<mint> a(n + 1),b(n + 1);
        rep(i,(n/4+1)) {
            a[4 * i] = fact[2*i] * fact_inv[i] * ncr(n-2*i,n-4*i);
        }
        b[0] = 1;
        b[1] = 1;
        rep(i,2,n+1) {
            b[i] = b[i-1] + b[i-2] * (i - 1);
        }
        auto c = ntt.multiply(a,b);
        cout << c[n] << '\n';
    }
}
