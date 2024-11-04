
using namespace std;
 
using ll = long long;
using db = long double; 

using str = string; 


using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;





tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;



























tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }










const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll INF = 1e18; 

const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

    return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id4(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

tcTU> T fstTrue(T lo, T hi, U f) {
    hi ++; assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    lo --; assert(lo <= hi); 

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
    tcT> constexpr bool id8 = is_iterable<T>::value;

    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool id0 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id1 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id7 = !id0<T> && id8<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id7<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<id7<T>,void>::type re(T& i) {
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
    tcT> constexpr bool id2 = !id1<T> && id8<T>;

    

    tcT> typename enable_if<id1<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id3(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id2<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<id8<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id2<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id2<T>,vs>::type 
      id5(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id2<T>,vs>::type 
      id5(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = id5<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        id3(i,sz(res)) {
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
    template<int lev, class T> void id9(const T& t) {
        cerr << "\n\n" << ts_sep(id5<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    
}

inline namespace FileIO {
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); 

        

        

        

        if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

    }
}





using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>; 



void treeExample() {
    Tree<int> t, t2; t.insert(8);
    auto it = t.insert(10).f; assert(it == t.lb(9));
    assert(t.ook(10) == 1 && t.ook(11) == 2 && *t.fbo(0) == 8);
    t.join(t2); 

}





template<class T, int SZ> struct LazySeg { 
    static_assert(pct(SZ) == 1); 

    const T ID = -MOD; T comb(T a, T b) { return max(a, b); }
    T seg[2*SZ], lazy[2*SZ]; 
    LazySeg() { id3(i,2*SZ) seg[i] = lazy[i] = ID; }
    void push(int ind, int L, int R) { 

        seg[ind] += lazy[ind]; 

        if (L != R) id3(i,2) lazy[2*ind+i] += lazy[ind]; 

        lazy[ind] = 0; 
    } 

    void pull(int ind) { seg[ind] = comb(seg[2*ind],seg[2*ind+1]); }
    void build() { ROF(i,1,SZ) pull(i); }
    void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
        push(ind,L,R); if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) { 
            lazy[ind] = inc; push(ind,L,R); return; }
        int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
        upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
    }
    T query(int lo, int hi, int ind=1, int L=0, int R=SZ-1) {
        push(ind,L,R); if (lo > R || L > hi) return ID;
        if (lo <= L && R <= hi) return seg[ind];
        int M = (L+R)/2; 
        return comb(query(lo,hi,2*ind,L,M),query(lo,hi,2*ind+1,M+1,R));
    }
};

const int mx = 200005;
int a[mx];

LazySeg<int, 262144> lseg;

bool zero_ones[mx];

void setIndex(int pos, int val){
    lseg.upd(pos, pos, -lseg.query(pos, pos)+val);
}

int getDist(int a, int b){
    if(a == b) return 0;
    assert(a < b);
    if(a % 2 == 1){
        return b-a;
    }
    return b-a+1;
}

int main() {
    setIO();
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        vi id6;
        for(int i = 1; i <= n; i++){
            id6.pb(i);
        }
        sort(all(id6), [&](int l, int r){
            return a[l] > a[r];
        });

        for(int i = 1; i <= n; i++){
            zero_ones[i] = 0;
        }

        for(int i = 1; i <= n; i++){
            setIndex(i, -MOD);
        }

        int ans = 0;

        int cur_one = n+1;
        Tree<int> tr;
        for(int i = 0; i < n; i++){
            int change_pos = id6[i];
            

            zero_ones[change_pos] = 1;
            while(cur_one > 1){
                if(zero_ones[cur_one-1]){
                    cur_one--;
                }
                else{
                    break;
                }
            }
            int ones_right = sz(tr)-tr.ook(change_pos);
            tr.ins(change_pos);
            

            lseg.upd(1, change_pos-1, -1);
            lseg.upd(change_pos+1, cur_one-1, 1);
            lseg.upd(change_pos, change_pos, MOD+getDist(change_pos, n)); 


            int res = lseg.query(1, cur_one-1);

            

            

            


            ckmax(ans, res);

            
            

        }

        ps(ans);
    }
    

}


