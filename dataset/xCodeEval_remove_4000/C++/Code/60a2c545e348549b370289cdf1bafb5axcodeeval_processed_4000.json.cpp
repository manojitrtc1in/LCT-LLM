
using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 




using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;








tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;



















tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }










const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

    return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id11(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; } 


tcTU> T fstTrue(T lo, T hi, U f) {
    ++hi; assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    --lo; assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    } 
    return lo;
}
tcT> void remDup(vector<T>& v) { 

    sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { 

    auto it = t.find(u); assert(it != end(t));
    t.erase(it); } 




inline namespace Helpers {
    

    

    

    tcT, class = void> struct is_iterable : false_type {};
    tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
                                      decltype(end(declval<T>()))
                                     >
                           > : true_type {};
    tcT> constexpr bool id16 = is_iterable<T>::value;

    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool id2 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id6 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id14 = !id2<T> && id16<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id2<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id14<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<id14<T>,void>::type re(T& i) {
        each(x,i) re(x); }
    tcTUU> void re(T& t, U&... u) { re(t); re(u...); } 


    

    void rv(size_t) {}
    tcTUU> void rv(size_t N, V<T>& t, U&... u);
    template<class...U> void rv(size_t, size_t N2, U&... u);
    tcTUU> void rv(size_t N, V<T>& t, U&... u) {
        t.rsz(N); re(t);
        rv(N,u...); }
    template<class...U> void rv(size_t, size_t N2, U&... u) {
        rv(N2,u...); }

    

    void decrement() {} 

    tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
    
    
}

inline namespace ToString {
    tcT> constexpr bool id9 = !id6<T> && id16<T>;

    

    tcT> typename enable_if<id6<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id10(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id9<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<id16<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id9<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id9<T>,vs>::type 
      id12(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id9<T>,vs>::type 
      id12(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = id12<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        id10(i,sz(res)) {
            str bef = " "; if (i == 0) bef = "{";
            res[i] = bef+res[i];
        }
        res.bk += "}";
        return res;
    }
}

inline namespace Output {
    template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
    template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
        pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
    

    template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
    

    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
    

    template<class ...T> void dbg_out(const T&... t) {
        pr_sep(cerr," | ",t...); cerr << endl; }
    void loc_info(int line, str names) {
        cerr << "Line(" << line << ") -> [" << names << "]: "; }
    template<int lev, class T> void id17(const T& t) {
        cerr << "\n\n" << ts_sep(id12<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    

    const clock_t beg = clock();
    
}

inline namespace FileIO {
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); 

        

        

        

        if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

    }
}



struct frac {
    ll n,d;
    frac(ll _n, ll _d) {
        n = _n, d = _d;
        ll g = gcd(n,d); n /= g, d /= g;
        if (d < 0) n *= -1, d *= -1;
    }
    frac(ll _n) : frac(_n,1) {}
    frac() : frac(0) {}
    friend frac abs(frac F) { return frac(abs(F.n),F.d); }
    friend str ts(const frac& a) { return ts(a.n)+"/"+ts(a.d); }
 
    friend bool operator<(const frac& l, const frac& r) { return l.n*r.d < r.n*l.d; }
    friend bool operator==(const frac& l, const frac& r) { return l.n == r.n && l.d == r.d; }
    friend bool operator!=(const frac& l, const frac& r) { return !(l == r); }
 
    frac operator-() const { return frac(-n,d); }
    friend frac operator+(const frac& l, const frac& r) { return frac(l.n*r.d+r.n*l.d,l.d*r.d); }
    friend frac operator-(const frac& l, const frac& r) { return frac(l.n*r.d-r.n*l.d,l.d*r.d); }
    friend frac operator*(const frac& l, const frac& r) { return frac(l.n*r.n,l.d*r.d); }
    friend frac operator*(const frac& l, int r) { return l*frac(r,1); }
    friend frac operator*(int r, const frac& l) { return l*r; }
    friend frac operator/(const frac& l, const frac& r) { return l*frac(r.d,r.n); }
    friend frac operator/(const frac& l, const int& r) { return l/frac(r,1); }
    friend frac operator/(const int& l, const frac& r) { return frac(l,1)/r; }
 
    friend frac& operator+=(frac& l, const frac& r) { return l = l+r; }
    friend frac& operator-=(frac& l, const frac& r) { return l = l-r; }
    template<class T> friend frac& operator*=(frac& l, const T& r) { return l = l*r; }
    template<class T> friend frac& operator/=(frac& l, const T& r) { return l = l/r; }
};






using namespace __gnu_pbds;
tcT> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>; 



void treeExample() {
    Tree<int> t, t2; t.insert(8);
    auto it = t.insert(10).f; assert(it == t.lb(9));
    assert(t.ook(10) == 1 && t.ook(11) == 2 && *t.fbo(0) == 8);
    t.join(t2); 

}





tcT> struct BIT {
    int N; V<T> data;
    void init(int _N) { N = _N; data.rsz(N); }
    void add(int p, T x) { for (++p;p<=N;p+=p&-p) data[p-1] += x; }
    T sum(int l, int r) { return sum(r+1)-sum(l); }
    T sum(int r) { T s = 0; for(;r;r-=r&-r)s+=data[r-1]; return s; }
    int lower_bound(T sum) {
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1<<25; pw; pw >>= 1) {
            int npos = pos+pw;
            if (npos <= N && data[npos-1] < sum)
                pos = npos, sum -= data[pos-1];
        }
        return pos;
    }
};

const int mx = 100005;

struct Eff{ 




int n;
ll a, b, c;

ll getRest(int id4, int id3, int id13){
    int used = min(id4, id3);
    ll res = 0;
    res+=b*used+a*used;
    id4-=used;
    id3-=used;

    if(id3 > 0){
        assert(id4 == 0);
        res+=a;
        return res;
    }

    if(id4 > 0){
        int id15 = min(id4, id13);
        res+=max(ll(0), id15*(b-c));
    }

    return res;
}

ll solveRuns(int id5, vi id0, int id7, int id13){ 

    sort(all(id0));
    int id8 = id7;
    for(auto u: id0){
        id8+=u;
    }
    

    dbg(id5, id0, id7, id13);
    ll res = 0;

    ll cur_money = 0;
    

    for(int i = 0; i <= sz(id0); i++){ 

        

        if(i >= 1){
            int id1 = id0[i-1];
                
            if(id5-id1 < 0){
                break;
            }
            cur_money+=b*(id1+1);
            cur_money+=a*(id0[i-1]);
            id8-=id0[i-1];
            cur_money-=c;

            id5-=id1;
        }

        ckmax(res, cur_money+getRest(id5, id8, id13));
        

    }

    return res;
}

void solveTestCase(){
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;

    int id5 = 0;
    for(int i = 0; i+1 < sz(s); i++){
        if(s[i] == '1' && s[i+1] == '1'){
            id5++;
        }
    }

    vi id0;
    int id7 = 0;
    int id13 = 0;
    for(int i = 0; i < sz(s); i++){
        if(s[i] == '0'){
            int L = i;
            int R = i;
            for(int j = i; j < sz(s); j++){
                if(s[j] == '0'){
                    R = j;
                }
                else{
                    break;
                }
            }

            if(L == 0 || R == n-1){
                id7+=R-L;
                id13++;
            }
            else{
                id0.pb(R-L);
            }

            i = R;
        }
    }

    ll ans = 0;
    ckmax(ans, solveRuns(id5, id0, id7, id13));
    

    if(id5 > 0){
        id5--;
        ckmax(ans, b+solveRuns(id5, id0, id7, id13));
    }

    ps(ans);


}

void solve(){
    int T = 1;
    cin >> T;
    for(int t = 1; t <= T; t++){
        solveTestCase();
    }
}

}; 


int main() {
    setIO();
    Eff e; e.solve();
    

}


