















using namespace std;
using ll = long long;
template<class T>using rpriority_queue = priority_queue<T, vector<T>, greater<T>>;
const int MOD=1000000007;
const int MOD2=998244353;
const int INF=1<<30;
const ll INF2=(ll)1<<60;


void scan(int& a){scanf("%d",&a);}
void scan(long long& a){scanf("%lld",&a);}
template<class T,class L>void scan(pair<T, L>& p){scan(p.first);scan(p.second);}
template<class T> void scan(T& a){cin>>a;}
template<class T> void scan(vector<T>& vec){for(auto&& it:vec)scan(it);}
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){scan(head);in(tail...);}


void print(const int& a){printf("%d",a);}
void print(const long long& a){printf("%lld",a);}
void print(const double& a){printf("%.15lf",a);}
template<class T,class L>void print(const pair<T, L>& p){print(p.first);putchar(' ');print(p.second);}
template<class T> void print(const T& a){cout<<a;}
template<class T> void print(const vector<T>& vec){if(vec.empty())return;print(vec[0]);for(auto it=vec.begin();++it!= vec.end();){putchar(' ');print(*it);}}
void out(){putchar('\n');}
template<class T> void out(const T& t){print(t);putchar('\n');}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);}


template<class T> void dprint(const T& a){cerr<<a;}
template<class T> void dprint(const vector<T>& vec){if(vec.empty())return;cerr<<vec[0];for(auto it=vec.begin();++it!= vec.end();){cerr<<" "<<*it;}}
void debug(){cerr<<endl;}
template<class T> void debug(const T& t){dprint(t);cerr<<endl;}
template <class Head, class... Tail> void debug(const Head& head, const Tail&... tail){dprint(head);cerr<<" ";debug(tail...);}
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
ll modinv(ll a, ll m) {ll b = m, u = 1, v = 0;while (b) {ll t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}
ll updivide(ll a,ll b){if(a%b==0) return a/b;else return (a/b)+1;}
template<class T> void chmax(T &a,const T b){if(b>a)a=b;}
template<class T> void chmin(T &a,const T b){if(b<a)a=b;}

namespace internal {
constexpr long long safe_mod(long long x, long long m) {x %= m;if (x < 0) x += m;return x;}
struct barrett {
    unsigned int _m;
    unsigned long long im;
    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
    unsigned int umod() const { return _m; }
    unsigned int mul(unsigned int a, unsigned int b) const {
        unsigned long long z = a;
        z *= b;

        unsigned long long x;
        _umul128(z, im, &x);

        unsigned long long x =
            (unsigned long long)(((unsigned long long)(z)*im));

        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};
constexpr long long id5(long long x, long long n, int m) {
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
constexpr bool id4(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id5(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {y = y * y % n;t <<= 1;}
        if (y != n - 1 && t % 2 == 0) {return false;}
    }
    return true;
}
template <int n> constexpr bool is_prime = id4(n);
constexpr std::pair<long long, long long> id1(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;
    while (t) {long long u = s / t;s -= t * u;m0 -= m1 * u;auto tmp = s;s = t;t = tmp;tmp = m0;m0 = m1;m1 = tmp;}
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}
constexpr int id2(int m) {
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
        if (x % i == 0) {divs[cnt++] = i;while (x % i == 0) {x /= i;}}
    }
    if (x > 1) {divs[cnt++] = x;}
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (id5(g, (m - 1) / divs[i], m) == 1) {ok = false;break;}
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id2(m);
unsigned long long id0(unsigned long long n,unsigned long long m,unsigned long long a,unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {ans += n * (n - 1) / 2 * (a / m);a %= m;}
        if (b >= m) {ans += n * (b / m);b %= m;}
        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}
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
template <class T> using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T> using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
struct modint_base {};
struct static_modint_base : modint_base {};
template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;
}  

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct id3 : internal::static_modint_base {
    using mint = id3;
  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {mint x;x._v = v;return x;}
    id3() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id3(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();_v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id3(T v) {_v = (unsigned int)(v % umod());}
    unsigned int val() const { return _v; }
    mint& operator++() {_v++;if (_v == umod()) _v = 0;return *this;}
    mint& operator--() {if (_v == 0) _v = umod();_v--;return *this;}
    mint operator++(int) {mint result = *this;++*this;return result;}
    mint operator--(int) {mint result = *this;--*this;return result;}
    mint& operator+=(const mint& rhs) {_v += rhs._v;if (_v >= umod()) _v -= umod();return *this;}
    mint& operator-=(const mint& rhs) {_v -= rhs._v;if (_v >= umod()) _v += umod();return *this;}
    mint& operator*=(const mint& rhs) {unsigned long long z = _v;z *= rhs._v;_v = (unsigned int)(z % umod());return *this;}
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(long long n) const {assert(0 <= n);mint x = *this, r = 1;while (n) {if (n & 1) r *= x;x *= x;n >>= 1;}return r;}
    mint inv() const {if (prime) {assert(_v);return pow(umod() - 2);} else {auto eg = internal::id1(_v, m);assert(eg.first == 1);return eg.second;}}
    friend mint operator+(const mint& lhs, const mint& rhs) {return mint(lhs) += rhs;}
    friend mint operator-(const mint& lhs, const mint& rhs) {return mint(lhs) -= rhs;}
    friend mint operator*(const mint& lhs, const mint& rhs) {return mint(lhs) *= rhs;}
    friend mint operator/(const mint& lhs, const mint& rhs) {return mint(lhs) /= rhs;}
    friend bool operator==(const mint& lhs, const mint& rhs) {return lhs._v == rhs._v;}
    friend bool operator!=(const mint& lhs, const mint& rhs) {return lhs._v != rhs._v;}
    

    friend istream& operator>>(istream& os,mint& rhs) noexcept {
        long long v;
        rhs = mint{(os >> v, v)};
        return os;
    }
    friend constexpr ostream& operator << (ostream &os, const mint& rhs) noexcept {
        return os << rhs._v;
    }
  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};
using mint=id3<1000000007>;
using mint2=id3<998244353>;

template<class T> struct compressed_array{
    int N;
    vector<T> dat;
    const T operator[](int i) const { return dat[i]; }
    T operator[](int i) { return dat[i]; }
    compressed_array(){}
    compressed_array(vector<int> &a){
        dat=a;
    }
    void build(){
        sort(dat.begin(), dat.end());
        dat.erase(unique(dat.begin(), dat.end()), dat.end());
        N = dat.size();
    }
    void insert(const T v){
        dat.push_back(v);
    }
    void insert(vector<T> &a){
        for(int i = 0; i < a.size() ; i++)dat.push_back(a[i]);
    }
    

    void insert(vector<pair<T, T>> &a, int type){
        if(type==1){
            for(int i = 0; i < a.size(); i++)dat.push_back(a[i].first);
        }else{
            for(int i = 0; i < a.size(); i++)dat.push_back(a[i].second);
        }
    }
    template<size_t size> void insert(vector<array<T,size>> &a, int pos){
        assert(0 <= pos && pos < size);
        for(int i = 0; i < a.size() ; i++){
            dat.push_back(a[i][pos]);
        }
    }
    int load(T &v){
        return lower_bound(dat.begin(), dat.end(), v) - dat.begin();
    }
    void load(vector<T> &a){
        for(int i = 0; i < a.size() ; i++)a[i] = load(a[i]);
    }
    void load(vector<pair<T, T>> &a, int type){
        if(type==1){
            for(int i = 0; i < a.size(); i++)a[i].first = load(a[i].first);
        }else{
            for(int i = 0; i < a.size(); i++)a[i].second = load(a[i].second);
        }
    }
    template<size_t size> void load(vector<array<T,size>> &a, int pos){
        assert(0 <= pos && pos < size);
        for(int i = 0; i < a.size() ; i++){
            a[i][pos] = load(a[i][pos]);
        }
    }
};
 
template <class S, class T = int> struct IntervalManager {
    struct node {
        T l, r;
        S x;
        node(const T &l, const T &r, const S &x) : l(l), r(r), x(x) {}
        constexpr bool operator<(const node &rhs) const {
            if(l != rhs.l) return l < rhs.l;
            return r < rhs.r;
        }
    };
    set<node> s;
    IntervalManager() {}
    IntervalManager(const vector<T> &a) {
        vector<node> setter;
        for(int l = 0; l < a.size(); l++) {
            int r = l;
            for(; r < a.size() and a[l] == a[r]; r++) {}
            setter.emplace_back(l, r, a[l]);
            l = r - 1;
        }
        s = set<node>(all(setter));
    }
    S get(T x) {
        auto it = s.lower_bound(node(x, numeric_limits<T>::max(), 0));
        it = prev(it);
        return it->x;
    }
    S operator[](T k) const { return get(k); }
    void update(T l, T r, const S &x) {
        auto it = s.lower_bound(node(l, numeric_limits<T>::max(), 0));
        while(it != s.end()) {
            if(r <= it->l) break;
            if(it->r <= r) {
                it = s.erase(it);
            } else {
                node n = *it;
                it = s.erase(it);
                if(x == n.x) {
                    r = n.r;
                } else {
                    if(r < n.r) {
                        n.l = max(r, n.l);
                        it = s.emplace(n).first;
                    }
                }
                break;
            }
        }
        if(it != s.begin()) {
            it = prev(it);
            node n = *it;
            s.erase(it);
            if(n.x == x) {
                l = n.l;
                r = max(r, n.r);
            } else if(n.r < l) {
                s.emplace(n);
            } else {
                int memr = n.r;
                n.r = l;
                if(n.l < n.r) { s.emplace(n); }
                if(r < memr) { s.emplace(r, memr, n.x); }
            }
        }
        s.emplace(l, r, x);
    }
    template <class ADD, class DEL> void update(T l, T r, const S &x, const ADD &add, const DEL &del) {
        auto it = s.lower_bound(node(l, numeric_limits<T>::max(), 0));
        while(it != s.end()) {
            if(r <= it->l) break;
            if(it->r <= r) {
                del(it->l, it->r, it->x);
                it = s.erase(it);
            } else {
                node n = *it;
                del(it->l, it->r, it->x);
                it = s.erase(it);
                if(x == n.x) {
                    r = n.r;
                } else {
                    if(r < n.r) {
                        n.l = max(r, n.l);
                        add(n.l, n.r, n.x);
                        it = s.emplace(n).first;
                    }
                }
                break;
            }
        }
        if(it != s.begin()) {
            it = prev(it);
            node n = *it;
            del(it->l, it->r, it->x);
            s.erase(it);
            if(n.x == x) {
                l = n.l;
                r = max(r, n.r);
            } else if(n.r < l) {
                add(n.l, n.r, n.x);
                s.emplace(n);
            } else {
                int memr = n.r;
                n.r = l;
                if(n.l < n.r) {
                    add(n.l, n.r, n.x);
                    s.emplace(n);
                }
                if(r < memr) {
                    add(r, memr, n.x);
                    s.emplace(r, memr, n.x);
                }
            }
        }
        add(l, r, x);
        s.emplace(l, r, x);
    }
};

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

int main(){
    INT(n,m,q);
    vector<ll> a(n),b(m),c,sumv(n+m+1,0);
    vector<pair<ll,ll>> d;
    in(a,b);
    rep(i,n)c.push_back(a[i]);
    rep(i,m)c.push_back(b[i]);
    sort(all(c));
    rep(i,n+m)sumv[i+1]=sumv[i]+c[i];
    rep(i,c.size()-1)d.emplace_back(c[i+1]-c[i],i);
    sort(all(d));
    ll ans=0,s;
    auto add=[&](int l,int r,int x){
        ans+=sumv[r]-sumv[r-x];
    };
    auto del=[&](int l,int r,int x){
        ans-=sumv[r]-sumv[r-x];
    };
    IntervalManager<int> IM(vector<int>(c.size(),0));
    rep(i,n){
        int l=upper_bound(all(c),a[i])-c.begin();
        IM.update(l-1,l,IM.get(l-1)+1,add,del);
    }
    s=ans;
    dsu uf(c.size());
    for(int i=0;i<d.size();i++){
        int u=d[i].second;
        int v=d[i].second+1;
        IM.update(u-uf.size(u)+1,v+uf.size(v),IM.get(d[i].second)+IM.get(d[i].second+1),add,del);
        uf.merge(u,v);
        d[i].second=ans;
    }
    int x;
    while(q--){
        in(x);
        pair<ll,ll> p={x+1,-1};
        int j=upper_bound(all(d),p)-d.begin();
        if(j==0)out(s);
        else out(d[j-1].second);
    }
}