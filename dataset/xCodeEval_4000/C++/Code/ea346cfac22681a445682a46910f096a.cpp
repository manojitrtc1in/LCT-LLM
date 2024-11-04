





#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DECIMAL(n)  std::cout << std::fixed;std::cout << std::setprecision(n);
#define hell 1000000007
#define narak 998244353
#define PI 3.14159265358979323844
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fi first 
#define se second
#define all(v) v.begin(), v.end()
#define endl "\n"
#define sqr(a) (a)*(a)
#define __lcm(m,n) m*(n/__gcd(m,n))
#define inputarr(a,n) for(int xxx=0;xxx<n;++xxx) cin>>(a)[xxx]
#define sz(a) (int)a.size()
#define sl(a) (int)a.length()
#define display(x) for(auto &a:x) cout<<a<<" ";cout<<endl
#define debug cerr<<"bhau"<<endl
#define between(n,a,b) (a<=n&&n<=b)
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC 

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}


template<typename T, typename U> static inline void amin(T &x, U y) { 
    if (y < x) 
        x = y; 
}

template<typename T, typename U> static inline void amax(T &x, U y) { 
    if (x < y) 
        x = y; 
}

template<typename T,typename U> std::ostream& operator<<(std::ostream& out, std::pair<T,U> a) {
    out<<a.fi<<" "<<a.se;
    return out;
}

template<typename T,typename U> std::istream& operator>>(std::istream& in, std::pair<T,U> &a) {
    in>>a.fi>>a.se;
    return in;
}

inline long long toint(const std::string &s) {std::stringstream ss; ss << s; long long x; ss >> x; return x;}
inline std::string tostring(long long number) {std::stringstream ss; ss << number; return ss.str();}
inline std::string tobin(long long x) {return std::bitset<63>(x).to_string();}

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define ll long long
#define pii std::pair<int, int>
#define vi vector<int>  
#define vvi vector<vi > 
#define vii vector<pii >


#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 



















using namespace std;
using namespace __gnu_pbds;
namespace algebra {
    const int inf = 1e9;
    const int magic = 500; 

    
    namespace fft {
        const int maxn = 1 << 18;

        typedef double ftype;
        typedef complex<ftype> point;

        point w[maxn];
        const ftype pi = acos(-1);
        bool initiated = 0;
        void init() {
            if(!initiated) {
                for(int i = 1; i < maxn; i *= 2) {
                    for(int j = 0; j < i; j++) {
                        w[i + j] = polar(ftype(1), pi * j / i);
                    }
                }
                initiated = 1;
            }
        }
        template<typename T>
        void fft(T *in, point *out, int n, int k = 1) {
            if(n == 1) {
                *out = *in;
            } else {
                n /= 2;
                fft(in, out, n, 2 * k);
                fft(in + k, out + n, n, 2 * k);
                for(int i = 0; i < n; i++) {
                    auto t = out[i + n] * w[i + n];
                    out[i + n] = out[i] - t;
                    out[i] += t;
                }
            }
        }
        
        template<typename T>
        void mul_slow(vector<T> &a, const vector<T> &b) {
            vector<T> res(a.size() + b.size() - 1);
            for(size_t i = 0; i < a.size(); i++) {
                for(size_t j = 0; j < b.size(); j++) {
                    res[i + j] += a[i] * b[j];
                }
            }
            a = res;
        }
        
        
        template<typename T>
        void mul(vector<T> &a, const vector<T> &b) {
            if(min(a.size(), b.size()) < magic) {
                mul_slow(a, b);
                return;
            }
            init();
            static const int shift = 15, mask = (1 << shift) - 1;
            size_t n = a.size() + b.size() - 1;
            while(__builtin_popcount(n) != 1) {
                n++;
            }
            a.resize(n);
            static point A[maxn], B[maxn];
            static point C[maxn], D[maxn];
            for(size_t i = 0; i < n; i++) {
                A[i] = point(a[i] & mask, a[i] >> shift);
                if(i < b.size()) {
                    B[i] = point(b[i] & mask, b[i] >> shift);
                } else {
                    B[i] = 0;
                }
            }
            fft(A, C, n); fft(B, D, n);
            for(size_t i = 0; i < n; i++) {
                point c0 = C[i] + conj(C[(n - i) % n]);
                point c1 = C[i] - conj(C[(n - i) % n]);
                point d0 = D[i] + conj(D[(n - i) % n]);
                point d1 = D[i] - conj(D[(n - i) % n]);
                A[i] = c0 * d0 - point(0, 1) * c1 * d1;
                B[i] = c0 * d1 + d0 * c1;
            }
            fft(A, C, n); fft(B, D, n);
            reverse(C + 1, C + n);
            reverse(D + 1, D + n);
            int t = 4 * n;
            for(size_t i = 0; i < n; i++) {
                int64_t A0 = llround(real(C[i]) / t);
                T A1 = llround(imag(D[i]) / t);
                T A2 = llround(imag(C[i]) / t);
                a[i] = A0 + (A1 << shift) + (A2 << 2 * shift);
            }
            return;
        }
    }
    template<typename T>
    T bpow(T x, size_t n) {
        return n ? n % 2 ? x * bpow(x, n - 1) : bpow(x * x, n / 2) : T(1);
    }
    template<typename T>
    T bpow(T x, size_t n, T m) {
        return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : T(1);
    }
    template<typename T>
    T gcd(const T &a, const T &b) {
        return b == T(0) ? a : gcd(b, a % b);
    }
    template<typename T>
    T nCr(T n, int r) { 

        T res(1);
        for(int i = 0; i < r; i++) {
            res *= (n - T(i));
            res /= (i + 1);
        }
        return res;
    }

    template<int m>
    struct modular {
        int64_t r;
        modular() : r(0) {}
        modular(int64_t rr) : r(rr) {if(abs(r) >= m) r %= m; if(r < 0) r += m;}
        modular inv() const {return bpow(*this, m - 2);}
        modular operator * (const modular &t) const {return (r * t.r) % m;}
        modular operator / (const modular &t) const {return *this * t.inv();}
        modular operator += (const modular &t) {r += t.r; if(r >= m) r -= m; return *this;}
        modular operator -= (const modular &t) {r -= t.r; if(r < 0) r += m; return *this;}
        modular operator + (const modular &t) const {return modular(*this) += t;}
        modular operator - (const modular &t) const {return modular(*this) -= t;}
        modular operator *= (const modular &t) {return *this = *this * t;}
        modular operator /= (const modular &t) {return *this = *this / t;}
        
        bool operator == (const modular &t) const {return r == t.r;}
        bool operator != (const modular &t) const {return r != t.r;}
        
        operator int64_t() const {return r;}
    };
    template<int T>
    istream& operator >> (istream &in, modular<T> &x) {
        return in >> x.r;
    }
    
    
    template<typename T>
    struct poly {
        vector<T> a;
        
        void normalize() { 

            while(!a.empty() && a.back() == T(0)) {
                a.pop_back();
            }
        }
        
        poly(){}
        poly(T a0) : a{a0}{normalize();}
        poly(vector<T> t) : a(t){normalize();}
        
        poly operator += (const poly &t) {
            a.resize(max(a.size(), t.a.size()));
            for(size_t i = 0; i < t.a.size(); i++) {
                a[i] += t.a[i];
            }
            normalize();
            return *this;
        }
        poly operator -= (const poly &t) {
            a.resize(max(a.size(), t.a.size()));
            for(size_t i = 0; i < t.a.size(); i++) {
                a[i] -= t.a[i];
            }
            normalize();
            return *this;
        }
        poly operator + (const poly &t) const {return poly(*this) += t;}
        poly operator - (const poly &t) const {return poly(*this) -= t;}
        
        poly mod_xk(size_t k) const { 

            k = min(k, a.size());
            return vector<T>(begin(a), begin(a) + k);
        }
        poly mul_xk(size_t k) const { 

            poly res(*this);
            res.a.insert(begin(res.a), k, 0);
            return res;
        }
        poly div_xk(size_t k) const { 

            k = min(k, a.size());
            return vector<T>(begin(a) + k, end(a));
        }
        poly substr(size_t l, size_t r) const { 

            l = min(l, a.size());
            r = min(r, a.size());
            return vector<T>(begin(a) + l, begin(a) + r);
        }
        poly inv(size_t n) const { 

            assert(!is_zero());
            poly ans = a[0].inv();
            size_t a = 1;
            while(a < n) {
                poly C = (ans * mod_xk(2 * a)).substr(a, 2 * a);
                ans -= (ans * C).mod_xk(a).mul_xk(a);
                a *= 2;
            }
            return ans.mod_xk(n);
        }
        
        poly operator *= (const poly &t) {fft::mul(a, t.a); normalize(); return *this;}
        poly operator * (const poly &t) const {return poly(*this) *= t;}
        
        poly reverse(size_t n, bool rev = 0) const { 

            poly res(*this);
            if(rev) { 

                res.a.resize(max(n, res.a.size()));
            }
            std::reverse(res.a.begin(), res.a.end());
            return res.mod_xk(n);
        }
        
        pair<poly, poly> divmod_slow(const poly &b) const { 

            vector<T> A(a);
            vector<T> res;
            while(A.size() >= b.a.size()) {
                res.push_back(A.back() / b.a.back());
                if(res.back() != T(0)) {
                    for(size_t i = 0; i < b.a.size(); i++) {
                        A[A.size() - i - 1] -= res.back() * b.a[b.a.size() - i - 1];
                    }
                }
                A.pop_back();
            }
            std::reverse(begin(res), end(res));
            return {res, A};
        }
        
        pair<poly, poly> divmod(const poly &b) const { 

            if(deg() < b.deg()) {
                return {poly{0}, *this};
            }
            int d = deg() - b.deg();
            if(min(d, b.deg()) < magic) {
                return divmod_slow(b);
            }
            poly D = (reverse(d + 1) * b.reverse(d + 1).inv(d + 1)).mod_xk(d + 1).reverse(d + 1, 1);
            return {D, *this - D * b};
        }
        
        poly operator / (const poly &t) const {return divmod(t).first;}
        poly operator % (const poly &t) const {return divmod(t).second;}
        poly operator /= (const poly &t) {return *this = divmod(t).first;}
        poly operator %= (const poly &t) {return *this = divmod(t).second;}
        poly operator *= (const T &x) {
            for(auto &it: a) {
                it *= x;
            }
            normalize();
            return *this;
        }
        poly operator /= (const T &x) {
            for(auto &it: a) {
                it /= x;
            }
            normalize();
            return *this;
        }
        poly operator * (const T &x) const {return poly(*this) *= x;}
        poly operator / (const T &x) const {return poly(*this) /= x;}
        
        void print() const {
            for(auto it: a) {
                cout << it << ' ';
            }
            cout << endl;
        }
        T eval(T x) const { 

            T res(0);
            for(int i = int(a.size()) - 1; i >= 0; i--) {
                res *= x;
                res += a[i];
            }
            return res;
        }
        
        T& lead() { 

            return a.back();
        }
        int deg() const { 

            return a.empty() ? -inf : a.size() - 1;
        }
        bool is_zero() const { 

            return a.empty();
        }
        T operator [](int idx) const {
            return idx >= (int)a.size() || idx < 0 ? T(0) : a[idx];
        }
        
        T& coef(size_t idx) { 

            return a[idx];
        }
        bool operator == (const poly &t) const {return a == t.a;}
        bool operator != (const poly &t) const {return a != t.a;}
        
        poly deriv() { 

            vector<T> res;
            for(int i = 1; i <= deg(); i++) {
                res.push_back(T(i) * a[i]);
            }
            return res;
        }
        poly integr() { 

            vector<T> res = {0};
            for(int i = 0; i <= deg(); i++) {
                res.push_back(a[i] / T(i + 1));
            }
            return res;
        }
        size_t leading_xk() const { 

            if(is_zero()) {
                return inf;
            }
            int res = 0;
            while(a[res] == T(0)) {
                res++;
            }
            return res;
        }
        poly log(size_t n) { 

            assert(a[0] == T(1));
            return (deriv().mod_xk(n) * inv(n)).integr().mod_xk(n);
        }
        poly exp(size_t n) { 

            if(is_zero()) {
                return T(1);
            }
            assert(a[0] == T(0));
            poly ans = T(1);
            size_t a = 1;
            while(a < n) {
                poly C = ans.log(2 * a).div_xk(a) - substr(a, 2 * a);
                ans -= (ans * C).mod_xk(a).mul_xk(a);
                a *= 2;
            }
            return ans.mod_xk(n);
            
        }
        poly pow_slow(size_t k, size_t n) { 

            return k ? k % 2 ? (*this * pow_slow(k - 1, n)).mod_xk(n) : (*this * *this).mod_xk(n).pow_slow(k / 2, n) : T(1);
        }
        poly pow(size_t k, size_t n) { 

            if(is_zero()) {
                return *this;
            }
            if(k < magic) {
                return pow_slow(k, n);
            }
            int i = leading_xk();
            T j = a[i];
            poly t = div_xk(i) / j;
            return bpow(j, k) * (t.log(n) * T(k)).exp(n).mul_xk(i * k).mod_xk(n);
        }
        poly mulx(T x) { 

            T cur = 1;
            poly res(*this);
            for(int i = 0; i <= deg(); i++) {
                res.coef(i) *= cur;
                cur *= x;
            }
            return res;
        }
        poly mulx_sq(T x) { 

            T cur = x;
            T total = 1;
            T xx = x * x;
            poly res(*this);
            for(int i = 0; i <= deg(); i++) {
                res.coef(i) *= total;
                total *= cur;
                cur *= xx;
            }
            return res;
        }
        vector<T> chirpz_even(T z, int n) { 

            int m = deg();
            if(is_zero()) {
                return vector<T>(n, 0);
            }
            vector<T> vv(m + n);
            T zi = z.inv();
            T zz = zi * zi;
            T cur = zi;
            T total = 1;
            for(int i = 0; i <= max(n - 1, m); i++) {
                if(i <= m) {vv[m - i] = total;}
                if(i < n) {vv[m + i] = total;}
                total *= cur;
                cur *= zz;
            }
            poly w = (mulx_sq(z) * vv).substr(m, m + n).mulx_sq(z);
            vector<T> res(n);
            for(int i = 0; i < n; i++) {
                res[i] = w[i];
            }
            return res;
        }
        vector<T> chirpz(T z, int n) { 

            auto even = chirpz_even(z, (n + 1) / 2);
            auto odd = mulx(z).chirpz_even(z, n / 2);
            vector<T> ans(n);
            for(int i = 0; i < n / 2; i++) {
                ans[2 * i] = even[i];
                ans[2 * i + 1] = odd[i];
            }
            if(n % 2 == 1) {
                ans[n - 1] = even.back();
            }
            return ans;
        }
        template<typename iter>
        vector<T> eval(vector<poly> &tree, int v, iter l, iter r) { 

            if(r - l == 1) {
                return {eval(*l)};
            } else {
                auto m = l + (r - l) / 2;
                auto A = (*this % tree[2 * v]).eval(tree, 2 * v, l, m);
                auto B = (*this % tree[2 * v + 1]).eval(tree, 2 * v + 1, m, r);
                A.insert(end(A), begin(B), end(B));
                return A;
            }
        }
        vector<T> eval(vector<T> x) { 

            int n = x.size();
            if(is_zero()) {
                return vector<T>(n, T(0));
            }
            vector<poly> tree(4 * n);
            build(tree, 1, begin(x), end(x));
            return eval(tree, 1, begin(x), end(x));
        }
        template<typename iter>
        poly inter(vector<poly> &tree, int v, iter l, iter r, iter ly, iter ry) { 

            if(r - l == 1) {
                return {*ly / a[0]};
            } else {
                auto m = l + (r - l) / 2;
                auto my = ly + (ry - ly) / 2;
                auto A = (*this % tree[2 * v]).inter(tree, 2 * v, l, m, ly, my);
                auto B = (*this % tree[2 * v + 1]).inter(tree, 2 * v + 1, m, r, my, ry);
                return A * tree[2 * v + 1] + B * tree[2 * v];
            }
        }
    };
    template<typename T>
    poly<T> operator * (const T& a, const poly<T>& b) {
        return b * a;
    }
    
    template<typename T>
    poly<T> xk(int k) { 

        return poly<T>{1}.mul_xk(k);
    }

    template<typename T>
    T resultant(poly<T> a, poly<T> b) { 

        if(b.is_zero()) {
            return 0;
        } else if(b.deg() == 0) {
            return bpow(b.lead(), a.deg());
        } else {
            int pw = a.deg();
            a %= b;
            pw -= a.deg();
            T mul = bpow(b.lead(), pw) * T((b.deg() & a.deg() & 1) ? -1 : 1);
            T ans = resultant(b, a);
            return ans * mul;
        }
    }
    template<typename iter>
    poly<typename iter::value_type> kmul(iter L, iter R) { 

        if(R - L == 1) {
            return vector<typename iter::value_type>{-*L, 1};
        } else {
            iter M = L + (R - L) / 2;
            return kmul(L, M) * kmul(M, R);
        }
    }
    template<typename T, typename iter>
    poly<T> build(vector<poly<T>> &res, int v, iter L, iter R) { 

        if(R - L == 1) {
            return res[v] = vector<T>{-*L, 1};
        } else {
            iter M = L + (R - L) / 2;
            return res[v] = build(res, 2 * v, L, M) * build(res, 2 * v + 1, M, R);
        }
    }
    template<typename T>
    poly<T> inter(vector<T> x, vector<T> y) { 

        int n = x.size();
        vector<poly<T>> tree(4 * n);
        return build(tree, 1, begin(x), end(x)).deriv().inter(tree, 1, begin(x), end(x), begin(y), end(y));
    }
};

using namespace algebra;
const int mod=narak;
typedef modular<mod> base;
typedef poly<base> polyn;
void meowmeow321()
{
    int n,m;
    cin>>n>>m;
    int c[n];
    inputarr(c,n);
    set<int> x(c,c+n);
    vector<base> dog;
    for (int i = 0; i <=100000; ++i) {
        if(x.count(i))dog.pb(1);
        else dog.pb(0);
    }
    polyn cz(dog);
    cz*=4;
    polyn one;
    one.a.pb(1);
    cz = one - cz;
    cz = cz.log(m+1);
    for(auto &u:cz.a)u/=2;
    cz = cz.exp(m+1);
    cz = one + cz;
    for (int i = 0; i < sz(cz.a); ++i) {
        cz.a[i]/=2;
    }
    cz = cz.inv(m+1);
    for (int i = 1; i <=m; ++i) {
        if(i<sz(cz.a))
            cout<<cz.a[i]<<endl;
        else cout<<0<<endl;
    }

}
signed main()
{
    FAST;
    int testcases=1;
    

    for(int i=0;i<testcases;++i)
    {
        meowmeow321();
    }
    cerr<<endl<<"Time Elasped : "<<elasped_time<<endl;
    return 0;
}