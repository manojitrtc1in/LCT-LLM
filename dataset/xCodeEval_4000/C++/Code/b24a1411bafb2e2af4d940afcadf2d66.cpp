







































































































































#include <stack>
#include <map>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cassert>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#define pb push_back
#define REP_INT(i,l,r) for(int i = l; i <= r; ++i)
#define GET_REP_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define rep(...) GET_REP_MACRO(__VA_ARGS__,REP_ANY,REP_INT)(__VA_ARGS__)
#define all(v) (v).begin(), (v).end()
#define sz(v) ll(v.size())
#define T1 template<typename T> static
#ifndef __SIZEOF_INT128__
#define __int128 long long
#endif
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
const ll MOD = 1e9 + 7;
T1 ostream& operator<<(ostream& stream, const vector<T>& t);
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}
T1 istream& read(T, T, istream& = cin);
template<typename T, typename SFINAE = void> struct bigger_type{};
template<typename T> using bigger_type_t = typename bigger_type<T>::type;
template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && is_signed<T>::value && sizeof(T) == 4>::type>{using type = long long;};
template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && !is_signed<T>::value && sizeof(T) == 4>::type>{using type = unsigned long long;};
template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && is_signed<T>::value && sizeof(T) == 8>::type>{using type = __int128;};
template<typename T> struct bigger_type<T, typename enable_if<is_integral<T>::value && !is_signed<T>::value && sizeof(T) == 8>::type>{using type = unsigned __int128;};
template<typename int_t = unsigned long long>
struct ModInt{
    static inline int_t add(int_t const&a, int_t const&b, int_t const&mod){
        int_t ret = a+b;
        if(ret>=mod) ret-=mod;
        return ret;
    }
    static inline int_t sub(int_t const&a, int_t const&b, int_t const&mod){
        return add(a, mod-b);
    }
    static inline int_t mul(int_t const&a, int_t const&b, int_t const&mod){
        return a*static_cast<bigger_type_t<int_t>>(b)%mod;
    }
    static inline int_t pow(int_t const&a, int_t const&b, int_t const&mod){
        int_t ret = 1;
        int_t base = a;
        for(int i=0;b>>i;++i){
            if((b>>i)&1) ret = mul(ret, base, mod);
            base = mul(base, base, mod);
        }
        return ret;
    }
};
T1 bool miller_rabin_single(T const&x, T base){
    static_assert(is_integral<T>::value);
    if(x<T(4)) return x>T(1);
    if(x%2 == 0) return false;
    base%=x;
    if(base == 0) return true;
    T xm1 = x-1;
    int j = 1;
    T d = xm1/2;
    while(d%2 == 0){ 

        d/=2;
        ++j;
    }
    T t = ModInt<T>::pow(base, d, x);
    if(t==T(1) || t==T(xm1)) return true;
    for(int k=1;k<j;++k){
        t = ModInt<T>::mul(t, t, x);
        if(t == xm1) return true;
        if(t<=1) break;
    }
    return false;
}
T1 bool miller_rabin_multi(T const&){return true;}
template<typename T, typename... S>
bool miller_rabin_multi(T const&x, T const&base, S const&...bases){
    static_assert(is_integral<T>::value);
    if(!miller_rabin_single(x, base)) return false;
    return miller_rabin_multi(x, bases...);
}
T1 bool miller_rabin(T const&x){
    static_assert(is_integral<T>::value);
    if(x < 316349281) return miller_rabin_multi(x, T(11000544), T(31481107));
    if(x < 4759123141ull) return miller_rabin_multi(x, T(2), T(7), T(61));
    return miller_rabin_multi(x, T(2), T(325), T(9375), T(28178), T(450775), T(9780504), T(1795265022));
}
T1 T isqrt(T const&x){
    static_assert(is_integral<T>::value);
    assert(x>=T(0));
    T ret = static_cast<T>(sqrtl(x));
    while(ret>0 && ret*ret>x) --ret;
    while(x-ret*ret>2*ret)
        ++ret;
    return ret;
}
T1 T icbrt(T const&x){
    static_assert(is_integral<T>::value);
    assert(x>=T(0));
    T ret = static_cast<T>(cbrt(x));
    while(ret>0 && ret*ret*ret>x) --ret;
    while(x-ret*ret*ret>3*ret*(ret+1))
        ++ret;
    return ret;
}
static uint64_t squfof_iter_better(uint64_t const&x, uint64_t const&k, uint64_t const&it_max, uint32_t cutoff_div){
    static vector<uint16_t> saved;
    if(__gcd((uint64_t)k, x)!=1) return __gcd((uint64_t)k, x);
    

    saved.clear();
    uint64_t scaledn = k*x;
    if(scaledn>>62) return 1;
    uint32_t sqrtn = isqrt(scaledn);
    uint32_t cutoff = isqrt(2*sqrtn)/cutoff_div;
    uint32_t q0 = 1;
    uint32_t p1 = sqrtn;
    uint32_t q1 = scaledn-p1*p1;
    if(q1 == 0){
        uint64_t factor = __gcd(x, (uint64_t)p1);
        return factor==x ? 1:factor;
    }
    uint32_t multiplier = 2*k;
    uint32_t coarse_cutoff = cutoff * multiplier;
    

    uint32_t i, j;
    uint32_t p0 = 0;
    uint32_t sqrtq = 0;
    for(i=0;i<it_max;++i){
        uint32_t q, bits, tmp;
        tmp = sqrtn + p1 - q1;
        q = 1;
        if (tmp >= q1)
            q += tmp / q1;
        p0 = q * q1 - p1;
        q0 = q0 + (p1 - p0) * q;
        if (q1 < coarse_cutoff) {
            tmp = q1 / __gcd(q1, multiplier);
            if (tmp < cutoff) {
                saved.push_back((uint16_t)tmp);
            }
        }
        bits = 0;
        tmp = q0;
        while(!(tmp & 1)) {
            bits++;
            tmp >>= 1;
        }
        if (!(bits & 1) && ((tmp & 7) == 1)) {
            sqrtq = (uint32_t)isqrt(q0);
            if (sqrtq * sqrtq == q0) {
                for(j=0;j<saved.size();++j){
                    if(saved[j] == sqrtq) break;
                }
                if(j == saved.size()) break;
                

            }
        }
        tmp = sqrtn + p0 - q0;
        q = 1;
        if (tmp >= q0)
            q += tmp / q0;
        p1 = q * q0 - p0;
        q1 = q1 + (p0 - p1) * q;
        if (q0 < coarse_cutoff) {
            tmp = q0 / __gcd(q0, multiplier);
            if (tmp < cutoff) {
                saved.push_back((uint16_t) tmp);
            }
        }
    }
    if(sqrtq == 1) { return 1;}
    if(i == it_max) { return 1;}
    q0 = sqrtq;
    p1 = p0 + sqrtq * ((sqrtn - p0) / sqrtq);
    q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;
    for(j=0;j<it_max;++j) {
        uint32_t q, tmp;
        tmp = sqrtn + p1 - q1;
        q = 1;
        if (tmp >= q1)
            q += tmp / q1;
        p0 = q * q1 - p1;
        q0 = q0 + (p1 - p0) * q;
        if (p0 == p1) {
            q0 = q1;
            break;
        }
        tmp = sqrtn + p0 - q0;
        q = 1;
        if (tmp >= q0)
            q += tmp / q0;
        p1 = q * q0 - p0;
        q1 = q1 + (p0 - p1) * q;
        if (p0 == p1)
            break;
    }
    if(j==it_max) {cerr << "RNG\n"; return 1;} 

    uint64_t factor = __gcd((uint64_t)q0, x);
    if(factor == x) factor=1;
    return factor;
}
uint64_t squfof(uint64_t const&x){
    static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};
    uint64_t cbrt_x = icbrt(x);
    if(cbrt_x*cbrt_x*cbrt_x == x) return cbrt_x;
    

    uint32_t iter_lim = 300;
    for(uint32_t iter_fact = 1;iter_fact<20000;iter_fact*=4){
        for(uint32_t const&k : multipliers){
            if(numeric_limits<uint64_t>::max()/k<=x) continue; 

            uint32_t const it_max = iter_fact*iter_lim;
            uint64_t factor = squfof_iter_better(x, k, it_max, 1);
            if(factor==1 || factor==x) continue;
            return factor;
        }
    }
    cerr << "failed to factor: " << x << "\n";
    assert(0);
    return 1;
}
T1 vector<T> factorize(T x){
    static_assert(is_integral<T>::value);
    assert(x >= T(1));
    vector<T> ret;
    const uint32_t trial_limit = 5000;
    auto trial = [&](int i){while(x%i == 0){x/=i; ret.push_back(i);}};
    trial(2); trial(3);
    for(uint32_t i=5, j=2;i<=trial_limit && i*i <= x;i+=j, j=6-j){
        trial(i);
    }
    if(x > 1 && trial_limit*trial_limit >= x)
        trial(x);
    if(x>1){
        static stack<T> s;
        s.push(x);
        while(!s.empty()){
            x = s.top(); s.pop();
            if(!miller_rabin(x)){
                T factor = squfof(x);
                if(factor == 1 || factor == x){assert(0); return ret;}
                s.push(factor);
                s.push(x/factor);
            } else {
                ret.push_back(x);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
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
ll phi(ll x){
    if(x == 1)
        return 1;
    map<ll, int> primes;
    for(ll f : factorize(x))
        primes[f]++;
    ll ans = 1;
    for(auto cur : primes){
        ans *= cur.first - 1;
        for(int i = 0; i + 1 < cur.second; ++i)
            ans *= cur.first;
    }
    return ans;
}
T1 void print(T x, string end = "\n"){
    cout << x << end;
}
T1 ostream& print(T b, T e, string sep = " ", ostream& stream = cout){
    for(T it = b; it != e; ++it){
        stream << *it;
        if(it + 1 != e)
            stream << sep;
    }
    return stream;
}
T1 void print(vector<T> arr, string sep = " "){
    if(arr.empty()){
        return;
    }
    print(arr.begin(), arr.end(), sep);
    cout << '\n';
}
vi divisors_of(int x){
    vi divs;
    for(int i = 1; i*i <= x; ++i)
        if(x%i == 0){
            divs.pb(i);
            if(i*i != x)
                divs.pb(x/i);
        }
    return divs;
}
void _(){
    int n,m;
    cin >> n >> m;
    vi banned(m+1),cnt(m+1);
    vvi arr(m+1);
    while(n--){
        int x;
        cin >> x;
        banned[x] = true;
    }
    rep(i,0,m-1)
        if(!banned[i]){
            cnt[gcd(i,m)]++;
            arr[gcd(i,m)].pb(i);
        }
    vi divs = divisors_of(m);
    sort(all(divs));
    vi dp(m+1),last(m+1,-1);
    for(int x : divs){
        int c = cnt[x];
        dp[x] = c;
        for(int y : divisors_of(x)){
            if(x != y && dp[x] < dp[y]+c){
                dp[x] = dp[y]+c;
                last[x] = y;
            }
        }
    }
    int best = 0;
    rep(i,0,m)
        if(dp[i] > dp[best])
            best = i;
    vi ans;
    int best_ori = best;
    while(best != -1){
        ans.insert(ans.end(),all(arr[best]));
        best = last[best];
    }
    assert(sz(ans) == dp[best_ori]);
    reverse(all(ans));
    print(sz(ans));
    vi ret(sz(ans),1);
    ret[0] = ans[0];
    int ph = phi(m)-1;
    rep(i,1,sz(ans)-1){
        int m1 = gcd(m,ans[i-1]);
        int m2 = gcd(m,ans[i]);
        ret[i] = (ans[i]/m2)*ipow(ans[i-1]/m1,ph,m)%m;
        ret[i] *= m2/m1;
        ret[i] %= m;
    }
    vi test = ret;
    rep(i,1,sz(ans)-1)
        test[i] = (test[i-1]*test[i])%m;
    print(ret);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
        _();
}
