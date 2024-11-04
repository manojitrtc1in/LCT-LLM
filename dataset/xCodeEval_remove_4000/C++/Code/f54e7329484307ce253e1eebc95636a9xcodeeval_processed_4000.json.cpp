

























using namespace std;







std::mt19937 id28(){return std::mt19937(std::random_device()());}
template<typename T=int>
T myrand(T id15=std::numeric_limits<T>::max()){
assert(id15>0);
static std::mt19937 random_engine=id28();
return std::uniform_int_distribution<T>(0,id15-1)(random_engine);
}
template<typename T=int>
T randrange(T low,T high){
assert(low<high);
static std::mt19937 random_engine=id28();
return std::uniform_int_distribution<T>(low,high)(random_engine);
}
bool randbool(){return myrand(2);}

using uint=unsigned int;
using ll=long long int;
using ull=unsigned long long int;
using lll=id9;
using ulll=unsigned id9;
using vb=std::vector<bool>;
using vvb=std::vector<vb>;
using vvvb=std::vector<vvb>;
using vvvvb=std::vector<vvvb>;
using vi=std::vector<int>;
using vvi=std::vector<vi>;
using vvvi=std::vector<vvi>;
using vvvvi=std::vector<vvvi>;
using vll=std::vector<ll>;
using vvll=std::vector<vll>;
using vvvll=std::vector<vvll>;
using vlll=std::vector<lll>;
using vvlll=std::vector<vlll>;
using vvvlll=std::vector<vvlll>;
using pi=std::pair<int,int>;
using vpi=std::vector<pi>;
using vvpi=std::vector<vpi>;
using pll=std::pair<ll,ll>;
using vpll=std::vector<pll>;
using vvpll=std::vector<vpll>;




template<typename T>void sort(T&v){sort(all(v));}




SUMF(int,ll)SUMF(uint,ull)SUMF(ll,id9)SUMF(ull,unsigned id9)SUMF(float,double)SUMF(double,double)

template<typename TI> TI sum(const vector<TI>& a){return std::accumulate(all(a), (TI)0);}
template<typename TI,size_t N> TI sum(const array<TI,N>& a){return std::accumulate(all(a), (TI)0);}

template<typename T>T max(const vector<T>&v){return *max_element(all(v));}
template<typename T,size_t N>T max(const array<T,N>&v){return *max_element(all(v));}

template<typename T>void mk_unique(std::vector<T>&l,optional<bool>need_sort=nullopt){
    if(!need_sort){need_sort=!std::is_sorted(all(l));}
    if(*need_sort){std::sort(all(l));}
    auto it=std::unique(l.begin(),l.end());
auto d=std::distance(l.begin(),it);l.resize(d);}
template<typename T>T&smax(T&l,const T&r){if(l<r)l=r;return l;}
template<typename T>T&smin(T&l,const T&r){if(r<l)l=r;return l;}
template<typename T>bool array_equal(const std::vector<T>&a,const std::vector<T>&b){
if(a.size()!=b.size())return false;
return std::equal(all(a),b.begin());
}
template<typename T>bool array_equal(const std::vector<std::vector<T>>&a,const std::vector<std::vector<T>>&b){
if(a.size()!=b.size())return false;
for(int i=0;i<a.size();i++)if(!array_equal(a[i],b[i]))return false;
return true;
}
template<class Fun>
class id20{Fun fun_;public:
template<class T>explicit id20(T&&fun):fun_(std::forward<T>(fun)){}
template<class...Args>decltype(auto)operator()(Args&&...args){return fun_(std::ref(*this),std::forward<Args>(args)...);}
};
template<class Fun>decltype(auto)id13(Fun&&fun){return id20<std::decay_t<Fun>>(std::forward<Fun>(fun));}
size_t id24(size_t n){
assert(n>0);
while(n&(n-1))n+=size_t(int(n)&(-int(n)));
return n;
}
template<typename T>
optional<T>&id7(optional<T>&lhs,const T&rhs){return lhs=lhs?*lhs+rhs:rhs;}

template <typename T>
struct is_list { enum { value = false };};

template <typename T, typename A>
struct is_list<std::vector<T, A>> { typedef T type; enum { value = true}; };

template <typename T, std::size_t N>
struct is_list<std::array<T, N>> { typedef T type; enum { value = true }; };

template <class T>
using is_list_t = std::enable_if_t<is_list<T>::value, T>;

template <typename T>
struct is_pair { enum { value = false };};

template <typename T1, typename T2>
struct is_pair<pair<T1, T2>> { enum { value = true };};

template <class T>
using is_pair_t = std::enable_if_t<is_pair<T>::value, T>;

template<typename T>
vector<pair<T, int>> get_count(vector<T> t){
    vector<pair<T, int>> res;
    sort(all(t));
    for(T &i: t){
        if(res.empty() || res.back().first != i) res.id22(i, 1);
        else {res.back().second++;}
    }
    return res;
}

namespace{const size_t RFC=chrono::high_resolution_clock::now().time_since_epoch().count();}
template<typename T>
class chash{
    hash<T>h;
public:
    size_t operator()(const T&x)const{return h(x)^ RFC;}
};


using namespace __gnu_pbds;
template<typename _Key,typename _Tp,typename _Hash=chash<_Key>>
class hash_map:public gp_hash_table<_Key,_Tp,_Hash>{
    using gp_hash_table<_Key,_Tp,_Hash>::gp_hash_table;
};

template<typename T>
vector<vector<T>> transpose(const vector<vector<T>>& mat){
    int n=mat.size(), m=mat[0].size();
    vector<vector<T>> res(m, vector<T>(m));
    fori(i,n) fori(j,m) res[j][i] = mat[i][j];
    return res;
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
            (unsigned long long)(((unsigned id9)(z)*im) >> 64);

        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};







constexpr long long id27(long long x, long long n, int m) {
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









constexpr bool id21(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id27(a, t, n);
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
template <int n> constexpr bool is_prime = id21(n);





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







constexpr int id16(int m) {
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
            if (id27(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id16(m);

}  


}  







namespace atcoder {

long long pow_mod(long long x, long long n, int m) {
    assert(0 <= n && 1 <= m);
    if (m == 1) return 0;
    internal::barrett bt((unsigned int)(m));
    unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x, m));
    while (n) {
        if (n & 1) r = bt.mul(r, y);
        y = bt.mul(y, y);
        n >>= 1;
    }
    return r;
}

long long inv_mod(long long x, long long m) {
    assert(1 <= m);
    auto z = internal::id2(x, m);
    assert(z.first == 1);
    return z.second;
}



std::pair<long long, long long> crt(const std::vector<long long>& r,
                                    const std::vector<long long>& m) {
    assert(r.size() == m.size());
    int n = int(r.size());
    

    long long r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        assert(1 <= m[i]);
        long long r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];
        if (m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return {0, 0};
            continue;
        }
        


        

        

        

        

        

        


        

        long long g, im;
        std::tie(g, im) = internal::id2(m0, m1);

        long long u1 = (m1 / g);
        

        if ((r1 - r0) % g) return {0, 0};

        

        long long x = (r1 - r0) / g % u1 * im % u1;

        

        

        

        

        r0 += x * m0;
        m0 *= u1;  

        if (r0 < 0) r0 += m0;
    }
    return {r0, m0};
}

long long floor_sum(long long n, long long m, long long a, long long b) {
    long long ans = 0;
    if (a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }

    long long y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}

}  

















namespace atcoder {

namespace internal {


template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, id9>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned id9>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned id9>;

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

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  


template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct id18 : internal::static_modint_base {
    using mint = id18;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id18() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id18(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id18(T v) {
        _v = (unsigned int)(v % umod());
    }
    id18(bool v) { _v = ((unsigned int)(v) % umod()); }

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

template <int id> struct id17 : internal::modint_base {
    using mint = id17;

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

    id17() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id17(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id17(T v) {
        _v = (unsigned int)(v % mod());
    }
    id17(bool v) { _v = ((unsigned int)(v) % mod()); }

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
template <int id> internal::barrett id17<id>::bt = 998244353;

using modint998244353 = id18<998244353>;
using modint1000000007 = id18<1000000007>;
using modint = id17<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id17<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  













namespace atcoder {









struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    

    

    std::vector<int> parent_or_size;
};

}  























namespace atcoder {}
using namespace atcoder;

using mi = modint1000000007;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
using vvvvmi = vector<vvmi>;


namespace io{
    const int id14 = 1e4;
    char _readbuffer[id14]; 

    bool id1(){cin.rdbuf()->pubsetbuf(_readbuffer,id14); return true;}
    const bool id11 = id1();
    inline char get(istream&in){
        char c; if(!in.get(c)) throw std::runtime_error("No more inputs while reading!");
        return c;}
    template<typename T>
    istream&read_int(istream &in, T &f) {
        char c; bool neg = false; f = 0;
        while(isspace(c=get(in))){};
        if(c=='-' || c=='+'){ neg = c=='-'; c=get(in);}
        do{ if (!isdigit(c)) throw std::runtime_error("Illegal character encounter");
            f = (f << 3) + (f << 1) + (c & 15);
            if(!in.get(c))break;
        }while(!isspace(c));
        if(neg){assert(is_signed<T>::value); f = -f;}
        return in;
    }
    template<typename T>
    istream&__read(istream&in, T& f){
        if constexpr(is_integral<T>::value || is_same<T,id9>::value || is_same<T, unsigned id9>::value) read_int(in, f);
        else if constexpr(is_list<T>::value) for(auto& i: f) __read(in, i);
        else if constexpr(is_pair<T>::value) { __read(in, f.first);__read(in, f.second); }
        else if constexpr(internal::is_modint<T>::value) {ll v; __read(in, v); f = v;}
        else in>>f;
        return in;
    }

    template<typename T, typename V>void _printarray(ostream&out,const V &arr){
        constexpr char sep=(is_list<T>::value||is_pair<T>::value)?'\n':' ';
        bool first=true;for(const T&i: arr){if(!first){out.put(sep);}first=false,out << i;}}
    template<typename T>void id23(ostream&out,T v){char c='0'+((int)(v%10));if(v>=10){id23(out,v/10);}out<<c;}
    template<typename T>void _printint(ostream&out,T v){if(v<0){(out << '-'),v*=-1;}id23(out,v);}

    template<typename T>
    ostream&__print(ostream&out, const T& f){
        if constexpr(is_same<T,id9>::value || is_same<T, unsigned id9>::value) _printint(out, f);
        else if constexpr(is_list<T>::value) _printarray<>(f);
        else if constexpr(is_pair<T>::value) { __print(out, f.first);__print(out,' ');__print(out, f.second);}
        else if constexpr(internal::is_modint<T>::value) {__print(out, f.val());}
        else out<<f;
        return out;
    }

    istream&_read(istream&in){return in;}
    template<typename T, typename...Args>istream&_read(istream&in,T& t,Args&...args){__read(in,t);return _read(in,args...);}
    ostream&_print(ostream&out){return out;}
    template<typename T, typename...Args>ostream&_print(ostream&out,const T&t,const Args&...args){__print(out,t);return _print(out,args...);}
}
template<typename T>
class cvector{
    vector<T> inner;
    int start_idx, end_idx;
    void inner_resize(size_t n, size_t cur_size){
        inner.resize(n);
        if(size()==0) return;
        int diff = inner.size() - cur_size;
        repr(i, cur_size-1, start_idx) inner[i+diff] = inner[i];
        start_idx+=diff, end_idx+=diff;
    }
    void grow_if_needed(){
        if(inner.size() == size()){
            size_t cur_size = size();
            inner.id22();
            inner_resize(inner.capacity(), cur_size);
        }
    }
    size_t get_idx(size_t i)const {
        assert(i >= 0 && i < size());
        i += start_idx;
        if (i >= inner.size()) { i -= inner.size(); }
        assert(i >= 0 && i < inner.size());
        return i;
    }
    T&new_front(){
        grow_if_needed();
        start_idx--; if(start_idx<0)start_idx+=inner.size(),end_idx+=inner.size();
        return at(0);
    }
    T&new_back(){
        grow_if_needed();
        end_idx++;
        return at(size()-1);
    }
public:
    cvector():inner(),start_idx(0),end_idx(0){inner.resize(inner.capacity());}
    cvector(size_t n):inner(n),start_idx(0),end_idx(n){}
    cvector(size_t n, const T& val):inner(n, val),start_idx(0),end_idx(n){}

    void reserve(size_t n){assert(n>size()); if(n>inner.size()) inner_resize(n, inner.size());}

    void pop_back(){assert(!empty()); end_idx--;}
    void pop_front() {
        assert(!empty());
        start_idx++;
        if (int(inner.size()) == start_idx) start_idx = 0, end_idx -= inner.size();
    }
    bool empty()const{return start_idx==end_idx;}
    size_t size()const{return end_idx-start_idx;}
    T& back(){assert(!empty()); return at(size()-1);}
    T& front(){assert(!empty()); return at(0);}

    T& at(size_t i){return inner[get_idx(i)];}
    const T& at(size_t i)const{return inner[get_idx(i)];}
    T& operator[](size_t i){return at(i);}
    const T& operator[](size_t i)const{return at(i);}

    template<typename... _Args>T& id22(_Args&&... __args){return new_back()=move(T(__args...));}
    template<typename... _Args>T& id10(_Args&&... __args){return new_front()=move(T(__args...));}

    void push_back(const T& o){return new_back()=o;}
    void push_back(T&& o){return new_back()=o;}
    void push_front(const T& o){return new_front()=o;}
    void push_front(T&& o){return new_front()=o;}

    template<typename FT, typename TT, bool id8, bool id5>
    class iterator: public std::iterator<std::random_access_iterator_tag,TT,long,TT*,TT&>{
        FT *ft; int i;
        typedef iterator<FT,TT,id8,id5> IT;
        void cindex(){
            auto sz = ft->size();
            if(id5){
                if(sz>0 && abs(i)>=sz*2) i %= sz;
                if(i<0)i+=sz;
                if(i>=sz)i-=sz;
            }
        }
        int rindex()const{
            int _i = i;
            if(id8)_i=int(ft->size())-1-i;
            return _i;
        }
    public:
        iterator(IT&o)=default;iterator(IT&&o)=default;iterator(const IT&o)=default;
        IT&operator=(IT&o)=default;IT&operator=(IT&&o)=default;IT&operator=(const IT&o)=default;
        iterator(FT *ft, int i):ft(ft),i(i){cindex();}
        bool operator==(const IT&lhs)const{return lhs.ft==ft && lhs.i==i;};
        bool operator!=(const IT&lhs)const{return !(*this==lhs);}
        IT operator+(int _i)const{return IT(ft, i+_i);};
        IT operator-(int _i)const{return IT(ft, i-_i);};
        IT& operator+=(int _i){return *this=*this+_i;};
        IT& operator-=(int _i){return *this=*this-_i;};
        IT& operator++(){return *this+=1;};
        IT& operator--(){return *this-=1;};
        IT operator++(int){IT o=*this;++this;return o;};
        IT operator--(int){IT o=*this;--this;return o;};
        TT& operator*()const{return ft->at(rindex());}
        TT* operator->()const{return &(*this);}
        int operator-(const IT&o)const{return i-o.i;}
        TT& operator[](int _i)const{return *(*this+_i);}
        bool operator<(const IT&o)const{return ft==o.ft && i<o.i;}
        bool operator>(const IT&o)const{return ft==o.ft && i>o.i;}
        bool operator<=(const IT&o)const{return ft==o.ft && i<=o.i;}
        bool operator>=(const IT&o)const{return ft==o.ft && i>=o.i;}
    };
    template<bool id8, bool id5> using IT =iterator<cvector<T>,T,id8,id5>;
    template<bool id8, bool id5> using CIT =iterator<const cvector<T>,const T,id8,id5>;
    typedef IT<false,false> iter; typedef IT<false,true> citer; typedef IT<true,false> riter; typedef IT<true,true> criter;
    typedef CIT<false,false> const_iter; typedef CIT<false,true> const_citer;
    typedef CIT<true,false> const_riter; typedef CIT<true,true> const_criter;

    iter begin(){return iter(this,0);}
    iter end(){return iter(this,size());}
    riter rbegin(){return riter(this,0);}
    riter rend(){return riter(this,size());}
    citer cbegin(){return citer(this,0);}
    criter crbegin(){return criter(this,0);}
    const_iter begin()const{return const_iter(this,0);}
    const_iter end()const{return const_iter(this,size());}
    const_riter rbegin()const{return const_riter(this,0);}
    const_riter rend()const{return const_riter(this,size());}
    const_citer cbegin()const{return const_citer(this,0);}
    const_criter crbegin()const{return const_criter(this,0);}
};

template<typename T>
ostream&operator<<(ostream&io,const cvector<T>&o){io::_printarray<T>(io,o);return io;}
template<typename T>
istream&operator>>(istream&io,cvector<T>&o){for(auto&i:o)io::_read(i);return io;}







template<typename T=mi, enable_if_t<internal::is_static_modint<T>::value> * = nullptr>
static T factorial(uint n) {
    static vector<T> mem;
    static T last;
    if (mem.empty())mem.push_back(last = 1);
    while (n >= mem.size()) { mem.push_back(mem.back() * last++); }
    return mem[n];
}

template<typename T=mi, enable_if_t<internal::is_static_modint<T>::value> * = nullptr>
static T id19(uint n) {
    constexpr int mod = T::mod();
    static vector<T> mem, inv;
    static int last;
    if (mem.empty()) fori(_, 2) mem.push_back(1), inv.push_back(1), last = 2;
    while (n >= inv.size()) { inv.push_back(inv[mod % last] * (mod - mod / last)), last++; }
    while (n >= mem.size()) { mem.push_back(mem.back() * inv[mem.size()]); }
    return mem[n];
}

template<typename T=mi, enable_if_t<internal::is_modint<T>::value> * = nullptr>
static T id12(uint n, uint k) {
    assert(k <= n);
    return factorial<T>(n) * id19<T>(k) * id19<T>(n - k);
}

template<typename T, typename U>
struct __is_prime {
    static bool check(const T n) {
        if (n <= 2) { return n == 2; }
        if (n % 2 == 0)return false;
        T d = n - 1;
        while (d % 2 == 0) d /= 2;
        for (T i: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) if (!check(i, d, n)) return false;
        return true;
    }

private:
    static T powmod(T a, T b, T n) {
        U x = a % n, res = 1;
        for (; b; b >>= 1, x = (x * x) % n) if (b & 1) res = (x * res) % n;
        return res;
    }

    static bool check(T a, T d, T n) {
        if (n <= a) return true;
        T t = d;
        T y = powmod(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = U(y) * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) { return false; }
        return true;
    }
};

bool is_prime(ll n) {
    assert(n >= 0);
    return __is_prime<ull, __uint128_t>::check(n);
}

bool is_prime(int n) {
    assert(n >= 0);
    return __is_prime<uint, ull>::check(n);
}

template<typename T, typename U>
struct __pollard_factorial {
    static vector<T> get_factorials(T n) {
        vector<T> res;
        get_factorials(n, res);
        sort(all(res));
        return res;
    }

private:
    static void get_factorials(T n, vector<T> &res) {
        if (n == 1) return;
        T x = single(n);
        if (x == n)return res.push_back(n);
        get_factorials(x, res), get_factorials(n / x, res);
    }

    static T single(const T n) {
        auto f = [&](long long x) { return (U(x) * x + 1) % n; };
        if (is_prime(n)) return n;
        if (n % 2 == 0) return 2;
        long long st = 0;
        while (true) {
            st++;
            long long x = st, y = f(x);
            while (true) {
                long long p = gcd((y - x + n), n);
                if (p == 0 || p == n) break;
                if (p != 1) return p;
                x = f(x);
                y = f(f(y));
            }
        }
    }
};

vector<int> id26(int n) { return __pollard_factorial<int, ll>::get_factorials(n); }

vector<ll> id26(ll n) { return __pollard_factorial<ll, __int128_t>::get_factorials(n); }

vector<pair<int, int>> id25(int n) { return get_count(id26(n)); }

vector<pair<ll, int>> id25(ll n) { return get_count(id26(n)); }

template<typename T>
vector<T> id3(T n) {
    auto factors = id25(n);
    int no_opt = 1;
    for (auto[factor, id0] : factors) no_opt *= id0 + 1;
    vector<T> res(no_opt, 1);
    int width = 1;
    for (auto[factor, id0] : factors) {
        id0 += 1;
        T cur = 1;
        for (int id6 = 0; id6 < id0; id6++, cur *= factor) {
            for (int i_start = width * id6; i_start < int(res.size()); i_start += width * id0) {
                for (int offset = 0; offset < width; offset++) {
                    res[i_start + offset] *= cur;
                }
            }
        }
        width *= id0;
    }
    return res;
}

vector<int> id4(int n) { return id3(n); }

vector<ll> id4(ll n) { return id3(n); }



namespace graphs{
    template<typename EdgeWeight, typename Dist=EdgeWeight>
    pair<vector<Dist>,vector<bool>> dijkstra(const vector<vector<pair<int, EdgeWeight>>> &e, int start, Dist start_dist={}){
        int n = e.size();
        vector<bool> added(n);
        vector<Dist> res(n);
        using DI = pair<Dist, int>;
        struct greater_first : public binary_function<DI, DI, bool>{
            constexpr bool operator()(const DI& x, const DI& y) const { return y.first < x.first; }
        };
        priority_queue<DI, vector<DI>, greater_first> pq;
        auto add = [&](int i, const Dist &d){
            if(added[i] == false){
                added[i] = true;
            }else if(!(d<res[i])) return;
            res[i]=d;
            pq.emplace(d, i);
        };
        add(start, start_dist);
        while(!pq.empty()){
            auto [d,i] = pq.top(); pq.pop();
            if(res[i]<d) continue;
            for(auto [j, ew]: e[i]){
                add(j, d+ew);
            }
        }
        return {move(res), move(added)};
    }
}






















using namespace std;

class EXORInverse {
	class Solver {
	public:
        istream &_in;
        ostream &_out;
        template<typename...Args>void rd(Args &...args) { io::_read(_in, args...); }
        template<typename...Args>void pr(const Args &...args) { io::_print(_out, args...); }
        template<typename...Args>void prln(const Args &...args) { pr(args..., '\n'); }
        Solver(std::istream &in, std::ostream &out) : _in(in), _out(out) {}

        ll opt_v[30][2] = {};
        vvvi vs = vvvi(30, vvi(2));

        void rec(int i, vi &a) {
            if(i < 0 || a.empty()) return;
            vvi &v = vs[i];
            v[0].clear(), v[1].clear();
            for(auto j: a) {
                int b = ((j >> i) & 1);
                opt_v[i][b] += v[!b].size();
                v[b].push_back(j);
            }
            rec(i-1, v[0]), rec(i-1, v[1]);
        }

        void solve() {
            

            int n; rd(n);
            vi a(n); rd(a);
            rec(29, a);
            int x = 0;
            ll ans = 0;
            fori(i, 30) {
                int b = opt_v[i][0] > opt_v[i][1];
                ans += opt_v[i][b];
                x |= b << i;
            }
            

            prln(ans, ' ', x);
        }
	};

public:
	static void solve(std::istream &in, std::ostream &out) {
		Solver(in, out).solve();
	}
};

int main() {
	std::ios_base::sync_with_stdio(false), cin.tie(0);
	EXORInverse solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
