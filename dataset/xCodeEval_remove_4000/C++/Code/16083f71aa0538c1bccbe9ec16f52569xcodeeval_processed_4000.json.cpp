
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }





const int mod=998244353,MAX=1<<18;
const ll INF=1LL<<60;













namespace atcoder {
    
    namespace internal {
        

        template <class T>
        using is_signed_int128 =
        typename std::conditional<std::is_same<T, __int128_t>::value ||
        std::is_same<T, __int128>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using is_unsigned_int128 =
        typename std::conditional<std::is_same<T, __uint128_t>::value ||
        std::is_same<T, unsigned __int128>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using make_unsigned_int128 =
        typename std::conditional<std::is_same<T, __int128_t>::value,
        __uint128_t,
        unsigned __int128>;
        
        template <class T>
        using is_integral = typename std::conditional<std::is_integral<T>::value ||
        is_signed_int128<T>::value ||
        is_unsigned_int128<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                         std::is_signed<T>::value) ||
        is_signed_int128<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using is_unsigned_int =
        typename std::conditional<(is_integral<T>::value &&
                                   std::is_unsigned<T>::value) ||
        is_unsigned_int128<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using to_unsigned = typename std::conditional<
        is_signed_int128<T>::value,
        make_unsigned_int128<T>,
        typename std::conditional<std::is_signed<T>::value,
        std::make_unsigned<T>,
        std::common_type<T>>::type>::type;
        

        
        template <class T> using is_integral = typename std::is_integral<T>;
        
        template <class T>
        using is_signed_int =
        typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using is_unsigned_int =
        typename std::conditional<is_integral<T>::value &&
        std::is_unsigned<T>::value,
        std::true_type,
        std::false_type>::type;
        
        template <class T>
        using to_unsigned = typename std::conditional<is_signed_int<T>::value,
        std::make_unsigned<T>,
        std::common_type<T>>::type;
        

        
        template <class T>
        using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
        
        template <class T>
        using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
        
        template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
        
    }  

    
}  




namespace atcoder {
    
    namespace internal {
        
        constexpr long long safe_mod(long long x, long long m) {
            x %= m;
            if (x < 0) x += m;
            return x;
        }
        
        struct barrett {
            unsigned int _m;
            unsigned long long im;
            
            barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
            
            unsigned int umod() const { return _m; }
            
            unsigned int mul(unsigned int a, unsigned int b) const {
                
                unsigned long long z = a;
                z *= b;

                unsigned long long x;
                _umul128(z, im, &x);

                unsigned long long x =
                (unsigned long long)(((unsigned __int128)(z)*im) >> 64);

                unsigned int v = (unsigned int)(z - x * _m);
                if (_m <= v) v += _m;
                return v;
            }
        };
        
        constexpr long long id4(long long x, long long n, int m) {
            if (m == 1) return 0;
            unsigned int _m = (unsigned int)(m);
            unsigned long long r = 1;
            unsigned long long y = safe_mod(x, m);
            while (n) {
                if (n & 1) r = (r * y) % _m;
                y = (y * y) % _m;
                n >>= 1;
            }
            return r;
        }
        
        constexpr bool id1(int n) {
            if (n <= 1) return false;
            if (n == 2 || n == 7 || n == 61) return true;
            if (n % 2 == 0) return false;
            long long d = n - 1;
            while (d % 2 == 0) d /= 2;
            for (long long a : {2, 7, 61}) {
                long long t = d;
                long long y = id4(a, t, n);
                while (t != n - 1 && y != 1 && y != n - 1) {
                    y = y * y % n;
                    t <<= 1;
                }
                if (y != n - 1 && t % 2 == 0) {
                    return false;
                }
            }
            return true;
        }
        template <int n> constexpr bool is_prime = id1(n);
        
        constexpr std::pair<long long, long long> id2(long long a, long long b) {
            a = safe_mod(a, b);
            if (a == 0) return {b, 0};
            
            long long s = b, t = a;
            long long m0 = 0, m1 = 1;
            
            while (t) {
                long long u = s / t;
                s -= t * u;
                m0 -= m1 * u;  

                
                
                auto tmp = s;
                s = t;
                t = tmp;
                tmp = m0;
                m0 = m1;
                m1 = tmp;
            }
            if (m0 < 0) m0 += b / s;
            return {s, m0};
        }
        
        constexpr int id3(int m) {
            if (m == 2) return 1;
            if (m == 167772161) return 3;
            if (m == 469762049) return 3;
            if (m == 754974721) return 11;
            if (m == 998244353) return 3;
            int divs[20] = {};
            divs[0] = 2;
            int cnt = 1;
            int x = (m - 1) / 2;
            while (x % 2 == 0) x /= 2;
            for (int i = 3; (long long)(i)*i <= x; i += 2) {
                if (x % i == 0) {
                    divs[cnt++] = i;
                    while (x % i == 0) {
                        x /= i;
                    }
                }
            }
            if (x > 1) {
                divs[cnt++] = x;
            }
            for (int g = 2;; g++) {
                bool ok = true;
                for (int i = 0; i < cnt; i++) {
                    if (id4(g, (m - 1) / divs[i], m) == 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) return g;
            }
        }
        template <int m> constexpr int primitive_root = id3(m);
        
    }  

    
}  










namespace atcoder {
    
    namespace internal {
        
        struct modint_base {};
        struct static_modint_base : modint_base {};
        
        template <class T> using is_modint = std::is_base_of<modint_base, T>;
        template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;
        
    }  

    
    template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
    struct id0 : internal::static_modint_base {
        using mint = id0;
        
    public:
        static constexpr int mod() { return m; }
        static mint raw(int v) {
            mint x;
            x._v = v;
            return x;
        }
        
        id0() : _v(0) {}
        template <class T, internal::is_signed_int_t<T>* = nullptr>
        id0(T v) {
            long long x = (long long)(v % (long long)(umod()));
            if (x < 0) x += umod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T>* = nullptr>
        id0(T v) {
            _v = (unsigned int)(v % umod());
        }
        id0(bool v) { _v = ((unsigned int)(v) % umod()); }
        
        unsigned int val() const { return _v; }
        
        mint& operator++() {
            _v++;
            if (_v == umod()) _v = 0;
            return *this;
        }
        mint& operator--() {
            if (_v == 0) _v = umod();
            _v--;
            return *this;
        }
        mint operator++(int) {
            mint result = *this;
            ++*this;
            return result;
        }
        mint operator--(int) {
            mint result = *this;
            --*this;
            return result;
        }
        
        mint& operator+=(const mint& rhs) {
            _v += rhs._v;
            if (_v >= umod()) _v -= umod();
            return *this;
        }
        mint& operator-=(const mint& rhs) {
            _v -= rhs._v;
            if (_v >= umod()) _v += umod();
            return *this;
        }
        mint& operator*=(const mint& rhs) {
            unsigned long long z = _v;
            z *= rhs._v;
            _v = (unsigned int)(z % umod());
            return *this;
        }
        mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
        
        mint operator+() const { return *this; }
        mint operator-() const { return mint() - *this; }
        
        mint pow(long long n) const {
            assert(0 <= n);
            mint x = *this, r = 1;
            while (n) {
                if (n & 1) r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }
        mint inv() const {
            if (prime) {
                assert(_v);
                return pow(umod() - 2);
            } else {
                auto eg = internal::id2(_v, m);
                assert(eg.first == 1);
                return eg.second;
            }
        }
        
        friend mint operator+(const mint& lhs, const mint& rhs) {
            return mint(lhs) += rhs;
        }
        friend mint operator-(const mint& lhs, const mint& rhs) {
            return mint(lhs) -= rhs;
        }
        friend mint operator*(const mint& lhs, const mint& rhs) {
            return mint(lhs) *= rhs;
        }
        friend mint operator/(const mint& lhs, const mint& rhs) {
            return mint(lhs) /= rhs;
        }
        friend bool operator==(const mint& lhs, const mint& rhs) {
            return lhs._v == rhs._v;
        }
        friend bool operator!=(const mint& lhs, const mint& rhs) {
            return lhs._v != rhs._v;
        }
        
    private:
        unsigned int _v;
        static constexpr unsigned int umod() { return m; }
        static constexpr bool prime = internal::is_prime<m>;
    };
    
    template <int id> struct id5 : internal::modint_base {
        using mint = id5;
        
    public:
        static int mod() { return (int)(bt.umod()); }
        static void set_mod(int m) {
            assert(1 <= m);
            bt = internal::barrett(m);
        }
        static mint raw(int v) {
            mint x;
            x._v = v;
            return x;
        }
        
        id5() : _v(0) {}
        template <class T, internal::is_signed_int_t<T>* = nullptr>
        id5(T v) {
            long long x = (long long)(v % (long long)(mod()));
            if (x < 0) x += mod();
            _v = (unsigned int)(x);
        }
        template <class T, internal::is_unsigned_int_t<T>* = nullptr>
        id5(T v) {
            _v = (unsigned int)(v % mod());
        }
        id5(bool v) { _v = ((unsigned int)(v) % mod()); }
        
        unsigned int val() const { return _v; }
        
        mint& operator++() {
            _v++;
            if (_v == umod()) _v = 0;
            return *this;
        }
        mint& operator--() {
            if (_v == 0) _v = umod();
            _v--;
            return *this;
        }
        mint operator++(int) {
            mint result = *this;
            ++*this;
            return result;
        }
        mint operator--(int) {
            mint result = *this;
            --*this;
            return result;
        }
        
        mint& operator+=(const mint& rhs) {
            _v += rhs._v;
            if (_v >= umod()) _v -= umod();
            return *this;
        }
        mint& operator-=(const mint& rhs) {
            _v += mod() - rhs._v;
            if (_v >= umod()) _v -= umod();
            return *this;
        }
        mint& operator*=(const mint& rhs) {
            _v = bt.mul(_v, rhs._v);
            return *this;
        }
        mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
        
        mint operator+() const { return *this; }
        mint operator-() const { return mint() - *this; }
        
        mint pow(long long n) const {
            assert(0 <= n);
            mint x = *this, r = 1;
            while (n) {
                if (n & 1) r *= x;
                x *= x;
                n >>= 1;
            }
            return r;
        }
        mint inv() const {
            auto eg = internal::id2(_v, mod());
            assert(eg.first == 1);
            return eg.second;
        }
        
        friend mint operator+(const mint& lhs, const mint& rhs) {
            return mint(lhs) += rhs;
        }
        friend mint operator-(const mint& lhs, const mint& rhs) {
            return mint(lhs) -= rhs;
        }
        friend mint operator*(const mint& lhs, const mint& rhs) {
            return mint(lhs) *= rhs;
        }
        friend mint operator/(const mint& lhs, const mint& rhs) {
            return mint(lhs) /= rhs;
        }
        friend bool operator==(const mint& lhs, const mint& rhs) {
            return lhs._v == rhs._v;
        }
        friend bool operator!=(const mint& lhs, const mint& rhs) {
            return lhs._v != rhs._v;
        }
        
    private:
        unsigned int _v;
        static internal::barrett bt;
        static unsigned int umod() { return bt.umod(); }
    };
    template <int id> internal::barrett id5<id>::bt = 998244353;
    
    using modint998244353 = id0<998244353>;
    using modint1000000007 = id0<1000000007>;
    using modint = id5<-1>;
    
    namespace internal {
        
        template <class T>
        using is_static_modint = std::is_base_of<internal::static_modint_base, T>;
        
        template <class T>
        using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;
        
        template <class> struct is_dynamic_modint : public std::false_type {};
        template <int id>
        struct is_dynamic_modint<id5<id>> : public std::true_type {};
        
        template <class T>
        using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;
        
    }  

    
}  


using mint=atcoder::modint998244353;

ll rui(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}

ll fac[MAX];

struct Lagrange{
    vector<ll> A,C;
    int N;
    
    void init(vector<ll> &a){
        A=a;
        N=si(A)-1;
        C.resize(N+1);
        fac[0]=1;
        for(ll i=1;i<=N;i++){
            fac[i]=fac[i-1]*i%mod;
        }
        
        for(int i=0;i<=N;i++){
            if((N-i)&1) C[i]=A[i]*rui(fac[i]*(mod-fac[N-i])%mod,mod-2)%mod;
            else C[i]=A[i]*rui(fac[i]*fac[N-i]%mod,mod-2)%mod;
        }
    }
    
    ll query(ll T){
        T%=mod;
        if(T<=N) return A[T];
        
        ll base=1;
        for(int i=0;i<=N;i++){
            base*=(T-i);
            base%=mod;
        }
        
        ll res=0;
        for(int i=0;i<=N;i++){
            res+=base*rui(T-i,mod-2)%mod*C[i]%mod;
            res%=mod;
        }
        
        return res;
    }
};

mint cn[13][13][13];

mint dp[2035][25][25];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<ll> X={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,0,0,0,0,0,0,0,0,0,0,1,4,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,2,12,2,0,0,0,0,0,0,0,0,0,2,12,4,0,0,0,0,0,0,0,0,0,0,9,6,0,0,0,0,0,0,0,0,0,0,3,6,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,10,1,0,0,0,0,0,0,0,0,0,3,28,13,0,0,0,0,0,0,0,0,0,4,35,29,1,0,0,0,0,0,0,0,0,3,35,41,4,0,0,0,0,0,0,0,0,1,30,44,7,0,0,0,0,0,0,0,0,0,17,45,7,0,0,0,0,0,0,0,0,0,8,30,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,20,6,0,0,0,0,0,0,0,0,0,4,55,50,3,0,0,0,0,0,0,0,0,6,80,118,18,0,0,0,0,0,0,0,0,6,95,186,48,0,0,0,0,0,0,0,0,6,101,230,85,2,0,0,0,0,0,0,0,2,94,260,113,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,35,21,1,0,0,0,0,0,0,0,0,5,96,145,26,0,0,0,0,0,0,0,0,8,155,358,124,3,0,0,0,0,0,0,0,9,207,616,313,16,0,0,0,0,0,0,0,11,250,859,567,53,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,56,56,8,0,0,0,0,0,0,0,0,6,154,350,126,4,0,0,0,0,0,0,0,10,268,898,552,48,0,0,0,0,0,0,0,12,389,1654,1404,204,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,84,126,36,1,0,0,0,0,0,0,0,7,232,742,448,43,0,0,0,0,0,0,0,12,427,1967,1887,357,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,120,252,120,10,0,0,0,0,0,0,0,8,333,1428,1302,252,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,165,462,330,55,1,0,0,0,0,0};
    
    vector<vector<ll>> Y;
    
    int t=0;
    for(int i=0;i<=12;i++){
        for(int j=0;j<=11;j++){
            for(int k=0;k<=11;k++){
                cn[i][j][k]=X[t];
                if(X[t]){
                    Y.push_back({i,j,k,X[t]});
                    

                }
                t++;
            }
        }
    }
    
    dp[0][0][0]=1;
    for(int i=0;i<2000;i++){
        for(int j=0;j<=11;j++){
            for(int k=0;k<=11;k++){
                for(auto x:Y){
                    dp[i+x[0]][j+x[1]][k+x[2]]+=dp[i][j][k]*x[3];
                }
            }
        }
    }
    
    vector<vector<Lagrange>> L(12,vector<Lagrange>(12));
    
    for(int i=0;i<=11;i++){
        for(int j=0;j<=11;j++){
            vector<ll> T(51);
            for(int k=1850;k<=1900;k++) T[k-1850]=dp[k][i][j].val();
            L[i][j].init(T);
        }
    }
    
    int Q;cin>>Q;
    while(Q--){
        ll N,A,B;cin>>N>>A>>B;
        if(N<=2000) cout<<dp[N][A][B].val()<<"\n";
        else{
            cout<<L[A][B].query(N-1850)<<"\n";
        }
    }
}
