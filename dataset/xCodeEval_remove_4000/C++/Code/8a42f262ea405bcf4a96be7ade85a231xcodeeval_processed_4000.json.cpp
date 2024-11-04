


using namespace std;






















namespace std {
    template<class T>
    T begin(std::pair<T, T> p)
    {
        return p.first;
    }
    template<class T>
    T end(std::pair<T, T> p)
    {
        return p.second;
    }
}



template<class Iterator>
std::reverse_iterator<Iterator> id1(Iterator it)
{
    return std::reverse_iterator<Iterator>(it);
}


template<class Range>
std::pair<std::reverse_iterator<decltype(begin(std::declval<Range>()))>, std::reverse_iterator<decltype(begin(std::declval<Range>()))>> id0(Range &&r)
{
    return std::make_pair(id1(::begin(r)), id1(::end(r)));
}




namespace io{
    template<typename T> void println(const T &t) { cout << t << '\n'; }
    template<typename T, typename ...Args> void println(const T &t, const Args &...rest) { cout << t << ' '; println(rest...); }

    template<typename T> void print(const T &t) { cout << t << ' '; }

    template<typename T, typename ...Args> void print(const T &t, const Args &...rest) { cout << t; print(rest...); }



    template<class T> void scan(T &t) { cin >> t; }
    template<class T, class ...Args> void scan(T &a, Args &...rest) { cin >> a; scan(rest...); }
}
using namespace io;

namespace alias{
    using ll = long long;
    using ull = unsigned long long;
    using vec = vector<ll>;
    using mat = vector<vec>;
    using pii = pair<int, int>;
    using pdd = pair<double, double>;
    using pip = pair<int, pii>;
    using szt = size_t;
    using vi = vector<int>;
    using vl = vector<ll>;
    using vb = vector<bool>;
    using vpii = vector<pii>;
    using vvi = vector<vi>;
    using pli = pair<ll,int>;
    using wg = vector<vpii>; 

}
using namespace alias;

template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> void Min(T &a, const T &b){ a = min(a, b); }
template<class T> void Max(T &a, const T &b){ a = max(a, b); }
namespace util{
    template<class T> int sign(const T &a) { return a == 0 ? 0 : a > 0 ? 1 : -1; }
    

    template<class V, class Cont>
    int get_rank(const V &k, const Cont &a){
        return std::lower_bound(all(a), k) - a.begin();
    }
    

    void rotate(double &x, double &y, double theta) {
        double tx = cos(theta) * x - sin(theta) * y;
        double ty = sin(theta) * x + cos(theta) * y;
        x = tx, y = ty;
    }
    int length(ll x){return snprintf(nullptr, 0, "%lld", x);}
    vi get_d(ll x){
        vi res;
        while(x) {
            res.pb(x%10);
            x /= 10;
        }
        reverse(all(res));
        return res;
    }
    template <class T> T parity(const T &a){
        return a & 1;
    }
    auto bo=[](int x){
        bitset<10> a(x);
        cout << a << endl;
    };
    template <class T>
    void out (const vector<T> &a){
        std::copy(a.begin(), a.end(), std::ostream_iterator<T>(std::cout, ", "));
        cout << endl;
    }
    using order_statistic_tree = __gnu_pbds::tree<
            int,
            __gnu_pbds::null_type,
            greater<int>,
            __gnu_pbds::rb_tree_tag,
            __gnu_pbds::tree_order_statistics_node_update>;
}


int cas;
const double pi = acos(-1);
const ll mod = 1e9 + 7;


template<class T>
inline void add_mod(T &a, const T &b) {
    a += b;
    if (a >= mod) a -= mod;
}
template<class T>
void sub_mod(T &a, const T &b){
    a -= b;
    if (a < 0) a += mod;
}



mat operator*(const mat &a, const mat &b) {
    mat c(a.size(), vec(b[0].size()));
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a[0].size(); j++) {
            if (a[i][j]) { 

                for (size_t k = 0; k < b[0].size(); k++) {
                    add_mod(c[i][k], a[i][j] * b[j][k] % mod);
                }
            }
        }
    }
    return c;
}

vec operator*(const mat &a, const vec &b) {
    vec c(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a[0].size(); j++) {
            add_mod(c[i], a[i][j] * b[j] % mod);
        }
    }
    return c;
}

mat pow(mat a, ull n) {
    mat res(a.size(), vec(a[0].size()));
    for (size_t i = 0; i < a.size(); i++) {
        res[i][i] = 1;
    }
    while (n) {
        if (n & 1) {
            res = res * a;
        }
        a = a * a;
        n >>= 1;
    }
    return res;
}







































ll POW(ll x, ll n){
    ll res = 1;
    for (; n; n /= 2, x *= x, x %= mod) {
        if (n & 1) {
            res *= x;
            res %= mod;
        }
    }
    return res;
}

namespace nt{
    ll INV(ll x) {
        return POW(x, mod - 2);
    }

    ll inv(ll x){
        return x == 1? 1: (mod - mod/x * inv(mod%x) % mod);
    }
}







namespace ds{
    struct dsu{
        vector<int> par;
        explicit dsu(int n){ 

            par.resize(n);
            rng(i, 0, n){
                par[i] = i;
            }
        }
        bool same(int x, int y){
            return root(x) == root(y);
        }
        int root(int x){
            return par[x] == x ? x : par[x] = root(par[x]);
        }
        void unite(int x, int y){
            x = root(x);
            y = root(y);
            par[x] = y;
        }
    };

    struct bit {
        vector<int> a;
        vector<int> id; 

        explicit bit(int n, int v = 0, bool manhattan = false) {
            a.resize(n + 1);
            if(v != 0) {
                for (int i = 1; i <= n; ++i) a[i] = v;
            }
            if(manhattan){
                id.resize(n+1);
                rng(i, 1, n+1) id[i] = -1;
            }
        }

        ll sum(int x) {
            ll res = 0;
            while (x) {
                res += a[x];
                x -= x & -x;
            }
            return res;
        }

        ll sum(int l, int r) {
            if (l > r) return 0;
            return sum(r) - sum(l - 1);
        }

        void add(int x, ll v) {
            while (x < a.size()) {
                a[x] += v;
                x += x & -x;
            }
        }

        void min(int x, int v) {
            while (x < a.size()) {
                a[x] = std::min(a[x], v);
                x += x & -x;
            }
        }

        int manhattan_min(int x){ 

            int ans = -1;
            int res = INT_MAX;
            while(x){
                if(a[x] < res){
                    res = a[x];
                    ans = id[x];
                }
                x -= x & - x;
            }
            return ans;
        }

        void manhattan_min(int x, int v, int i){
            while(x < a.size()){
                if(a[x] > v){
                    a[x] = v;
                    id[x] = i;
                }
                x += x & - x;
            }
        }


        void max(int x, int v) {
            while (x < a.size()) {
                a[x] = std::max(a[x], v);
                x += x & -x;
            }
        }

        int min(int x) {
            int res = INT_MAX;
            while (x) {
                res = std::min(res, a[x]);
                x -= x & -x;
            }
            return res;
        }

        int max(int x) {
            int res = INT_MIN;
            while (x) {
                res = std::max(res, a[x]);
                x -= x & -x;
            }
            return res;
        }
    };

    template<typename Key, typename Compare = std::less<Key>>
    struct mono_queue{
        mono_queue() = default;
        explicit mono_queue(int max_size):window(max_size){}
        int window = INT_MAX; 

        int cnt = 0;
        deque<pair<Key,int>> q;
        Compare cmp = Compare();
        void push_back(const Key &k){
            while(!q.empty() && !cmp(q.back().first, k)){
                q.pop_back();
            }
            q.emplace_back(k, cnt++);
            while(q.back().second - q.front().second >= window){
                q.pop_front();
            }
        }

        decltype(q.front()) front(){
            return q.front();
        }

        decltype(q.back()) back(){
            return q.back();
        }

        size_t size()const{
            return q.size();
        }
        void clear(){
            q.clear();
            cnt = 0;
        }
    };
}
using namespace  ds;

template<class node>
struct segment_tree{
    vector<node> a;
    using tag = typename node::lazy_tag;
    segment_tree() = default;
    inline int lson(int i){return i*2;}
    inline int rson(int i){return i*2+1;}
    template<class T>
    void build(int i, int l, int r, const T *arr){
        if(l==r){
            a[i] = node(arr[l]);
        }
        else{
            int mid = (l+r)/2;
            build(lson(i), l, mid, arr);
            build(rson(i), mid+1, r, arr);
            a[i].put_up(a[lson(i)], a[rson(i)]);
        }
    }

    template<class T>
    segment_tree(const T *arr, int n){
        a.resize(4*(ull)n);
        build(1, 1, n, arr); 

    }

    void push_down(int i){
        a[lson(i)].put_tag(a[i].tag);
        a[rson(i)].put_tag(a[i].tag);
        a[i].tag = {};
    }

    template<class T> using UnaryFunction = std::function<T(const node &)>;
    template<class T> using MergeFunction = std::function<T(T,T)>;

    template<typename T>
    T query(int i, int l, int r, int ql, int qr, const UnaryFunction<T> &get_res, const MergeFunction<T> &merge){
        if(l > qr || r < ql) return {};
        if(ql <= l && r <= qr){
            return get_res(a[i]);
        }
        int mid = (l+r)/2;
        push_down(i);
        return merge(query(lson(i), l, mid, ql, qr, get_res, merge), query(rson(i), mid+1, r, ql, qr, get_res, merge));
    }

    virtual void maintain(int i, int l, int r){}; 


    void change(int i, int l, int r, int ql, int qr, const tag &tag){
        if(l > qr || r < ql) return;
        if(l >= ql && r <= qr){
            a[i].put_tag(tag);
            maintain(i, l, r);
        }
        else{
            int mid = (l+r)/2;
            push_down(i);
            change(lson(i), l, mid, ql, qr, tag);
            change(rson(i), mid+1, r, ql, qr, tag);
            a[i].put_up(a[lson(i)], a[rson(i)]);
        }
    }
};

struct node{
    using lazy_tag = int;
    int min; int sum; lazy_tag tag;
    node()=default;
    explicit node(int x){
        min = x;
        sum = 0;
        tag = 0;
    }
    void put_up(const node &l, const node &r){
        min = std::min(l.min, r.min);
        sum = l.sum + r.sum;
    }
    void put_tag(const lazy_tag &ft) {

        tag += ft;
        min += ft;
    }
};

template <class node>
struct tree : segment_tree<node>{
    using segment_tree<node>::a; 

    using segment_tree<node>::lson;
    using segment_tree<node>::rson;
    using segment_tree<node>::query;
    using segment_tree<node>::push_down;
    tree()= default;
    template<typename T>
    tree(const T *arr, int n):segment_tree<node>(arr, n){}

    

    void maintain(int i, int l, int r) override {
    }
};




const ll LINF = LLONG_MAX/10;
const int INF = INT_MAX/10;
const int M = 5005;
const double eps = 1e-7;

const int N = 1e5+5;



int main() {
    

    cout << std::fixed;
    cout << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("main.in", "r", stdin);



    int x1, x2, sy;
    scan(sy, x1, x2);
    int n;
    scan(n);

    vector<int> a;
    rep(n){
        int l, r;
        scan(l, r);
        a.pb(l);
        a.pb(r);
    }

    vector<double> sum(2*n);

    rng(i, 1, 2*n){
        if(i%2 == 1) {
            sum[i] = sum[i-1] + a[i] - a[i-1];
        }
        else {
            sum[i] = sum[i-1];
        }
    }

    int q;
    scan(q);
    rep(q){
        int x, y;
        scan(x, y);
        double l = 1. * y / (y - sy) * (x1 - x) + x;
        double r = 1. * y / (y - sy) * (x2 - x) + x;
        l = min(l, double(a.back()));
        r = min(r, double(a.back()));
        int L = ceil(l);
        int R = ceil(r);
        int pl = lower_bound(all(a), L) - a.begin();
        int pr = lower_bound(all(a), R) - a.begin();





        Min(pl, 2*n-1);
        Min(pr, 2*n-1);
















        double ans = sum[pr] - sum[pl];
        if(pl & 1) {
            ans += a[pl] - l;
        }
        if(pr & 1) {
            ans -= a[pr] - r;
        }
        println(ans * (y - sy) / y);
    }



    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}