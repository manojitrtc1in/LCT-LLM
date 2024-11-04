






























































































































































































































































































































using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double ld;
const int MOD = 998244353;
T1 ostream& operator<<(ostream& stream, const vector<T>& t);
T1 istream& read(T, T, istream& = cin);
T1 istream& operator>>(istream& stream, vector<T>& t){
    return read(all(t), stream);
}
T1 istream& read(T b, T e, istream& stream){
    for(T it = b; it != e; ++it)
        stream >> *it;
    return stream;
}
T1 T id0(T a, T b, T c, T d){
    if(c == T(0))
        return b;
    return id0(c, d, a % c, b - a / c * d);
}
T1 T mod_inverse(T x, T mod = T(MOD)){
    return (id0(mod, T(0), x, T(1)) + mod) % mod;
}
ll mod_inverse(int x, ll mod = MOD){
    return mod_inverse<ll>(x,mod);
}
ll ipow(ll x, ll p, ll mod = MOD){
    if(abs(x) >= mod)
        x %= mod;
    if(x < 0)
        x += mod;
    if(p == 0)
        return 1;
    if(p == 1)
        return x;
    return ipow(x * x % mod, p / 2, mod) * ipow(x, p % 2, mod) % mod;
}
struct Factorial{
    vl fact,ifact;
    ll comb(ll n, ll m){
        assert(n >= m);
        assert(n < sz(fact));
        return fact[n]*ifact[m]%MOD*ifact[n-m]%MOD;
    }
    Factorial(int n){
        fact.resize(n+1);
        ifact.resize(n+1);
        fact[0] = 1;
        for(int i = 1; i <= n; ++i)
            fact[i] = fact[i-1]*i%MOD;
        ifact[n] = mod_inverse(fact[n]);
        for(int i = n-1; i >= 0; --i)
            ifact[i] = (i+1)*ifact[i+1]%MOD;
    }
};
struct _print {
    string sep,end;
    bool space;
    ostream &stream;
    _print(string _sep=" ",string _end="\n",
            ostream &_stream = cout)
        : sep(_sep),end(_end),space(false),
            stream(_stream) {}
    ~_print() { stream << end; }
    template <typename T>
        _print &operator , (const T &t) {
            if (space) stream << sep;
            space = true;
            stream << t;
            return *this;
        }
};

const int N = 3e5+5;
Factorial f(N);
namespace FFT_precision{
     

    struct C { ld re, im;
        C operator * (const C & he) const {
            return C{re * he.re - im * he.im,
                re * he.im + im * he.re};
        }
        void operator += (const C & he) { re += he.re; im += he.im; }
    };
    void dft(vector<C> & a, bool rev) {
        const int n = a.size();
        for(int i = 1, k = 0; i < n; ++i) {
            for(int bit = n / 2; (k ^= bit) < bit; bit /= 2);;;
            if(i < k) swap(a[i], a[k]);
        }
        for(int len = 1, who = 0; len < n; len *= 2, ++who) {
            static vector<C> t[30];
            vector<C> & om = t[who];
            if(om.empty()) {
                om.resize(len);
                const ld ang = 2 * acosl(0) / len;
                rep(i, len) om[i] = i%2 || !who ?
                    C{cos(i*ang), sin(i*ang)} : t[who-1][i/2];
            }
            for(int i = 0; i < n; i += 2 * len)
                rep(k, len) {
                    const C x = a[i+k], y = a[i+k+len]
                        * C{om[k].re, om[k].im * (rev ? -1 : 1)};
                    a[i+k] += y;
                    a[i+k+len] = C{x.re - y.re, x.im - y.im};
                }
        }
        if(rev) rep(i, n) a[i].re /= n;
    }
    template<typename T>vector<T> multiply(const vector<T> & a, const vector<T> & b,
            bool split = true, bool normalize = false) {
        if(a.empty() || b.empty()) return {};
        T big = 0; if(normalize) { 

            assert(a.size() == b.size()); 

            for(T x : a) big = max(big, x);
            for(T x : b) big = max(big, x);
            big /= 2;
        }
        int n = a.size() + b.size();
        vector<T> ans(n - 1);
        
        while(n&(n-1)) ++n;
        auto foo = [&](const vector<C> & w, int i, int k) {
            int j = i ? n - i : 0, r = k ? -1 : 1;
            return C{w[i].re + w[j].re * r, w[i].im
                - w[j].im * r} * (k ? C{0, -0.5} : C{0.5, 0});
        };
        if(!split) { 

            vector<C> in(n), done(n);
            rep(i, a.size()) in[i].re = a[i] - big;
            rep(i, b.size()) in[i].im = b[i] - big;
            dft(in, false);
            rep(i, n) done[i] = foo(in, i, 0) * foo(in, i, 1);
            dft(done, true);
            rep(i, ans.size()) ans[i] = is_integral<T>::value ?
                llround(done[i].re) : done[i].re;
        }
        else { 

            const T M = 1<<15; 

            vector<C> t[2]; 

            rep(x, 2) {
                t[x].resize(n);
                auto & in = x ? b : a; 

                rep(i, in.size()) t[x][i]=C{ld(in[i]%M), ld(in[i]/M)};
                dft(t[x], false);
            }
            T mul = 1;
            for(int s = 0; s < 3; ++s, mul = (mul*M)%MOD) {
                vector<C> prod(n);
                rep(x, 2) rep(y, 2) if(x + y == s) rep(i, n)
                    prod[i] += foo(t[0], i, x) * foo(t[1], i, y);
                dft(prod, true); 

                rep(i, ans.size()) ans[i]= (ans[i]+llround(prod[i].re)%MOD*mul)%MOD;
            }
        }
        if(normalize) {
            T so_far = 0;
            rep(i, ans.size()) {
                if(i < (int) a.size()) so_far += a[i] + b[i];
                else so_far -= a[i-a.size()] + b[i-a.size()];
                ans[i] += big * so_far - big * big * min(i + 1, (int) ans.size() - i);
            }
        }
        return ans;
    }
}
void _(){
    map<ll,ll> ans;
    ll n,m;
    cin >> n >> m;
    vl a(n),odd,even;
    vl b(m);
    cin >> a >> b;
    sort(all(a));
    sort(all(b));
    {
        vl tmp;
        map<ll,ll> cnt;
        for(ll x : a)
            ++cnt[x];
        for(auto _ : cnt)
            if(_.Y >= 2)
                even.pb(_.X);
            else
                odd.pb(_.X);
    }
    for(ll x : b){
        ll id1 = 0, cnt_even = 0;
        for(ll y : odd)
            if(y < x)
                ++id1;
        for(ll y : even)
            if(y < x)
                ++cnt_even;
        vl a1(id1+1),a2(2*cnt_even+1);
        rep(i,0,id1)
            a1[i] = f.comb(id1,i)*ipow(2,i)%MOD;
        rep(i,0,2*cnt_even)
            a2[i] = f.comb(2*cnt_even,i);
        vl res = FFT_precision::multiply(a1,a2);
        rep(i,0,sz(res)-1){
            ans[x+i+1] += res[i];
            ans[x+i+1] %= MOD;
        }
    }
    ll q;
    cin >> q;
    vl w(q);
    cin >> w;
    for(ll x : w)
        print(ans[x/2]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
        _();
}
