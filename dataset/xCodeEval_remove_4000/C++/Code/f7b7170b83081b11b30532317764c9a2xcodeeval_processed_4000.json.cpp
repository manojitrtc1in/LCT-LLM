


































































































































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
constexpr int id5(int x) { return p2(x)-1; }

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
    tcT> constexpr bool id10 = is_iterable<T>::value;

    

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
    tcT> constexpr bool id2 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id9 = !id0<T> && id10<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id9<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<id9<T>,void>::type re(T& i) {
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
    tcT> constexpr bool id3 = !id2<T> && id10<T>;

    

    tcT> typename enable_if<id2<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id4(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id3<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<id10<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id3<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id3<T>,vs>::type 
      id7(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id3<T>,vs>::type 
      id7(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = id7<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        id4(i,sz(res)) {
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
    template<int lev, class T> void id11(const T& t) {
        cerr << "\n\n" << ts_sep(id7<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    

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


int questions = 0;
bool querySet(vi S){
    if(sz(S) == 0) return false;

    remDup(S);
    questions++;
    assert(questions <= 82);

    cout << "?" << " ";
    cout << sz(S) << " ";
    for(int i = 0; i < sz(S); i++){
        cout << S[i] << " ";
    }
    cout << "\n";
    cout.flush();

    string res; cin >> res;

    if(res == "YES"){
        return true;
    }

    assert(res == "NO");
    

    

    

    
    return false;
}
void guess(int x){
    cout << "!" << " " << x << "\n";
    cout.flush();
    string res; cin >> res;

    if(res == ":)"){
        exit(0);
    }
}

set<int> toSet(vi a){
    set<int> res; for(auto u: a) res.insert(u);
    return res;
}

vi id8(vi a, vi b){
    set<int> a_set = toSet(a); set<int> b_set = toSet(b);
    vi res;
    for(auto u: a_set){
        if(b_set.count(u)){
            res.pb(u);
        }
    }
    return res;
}

vi removeSet(vi a, vi b){
    set<int> b_set = toSet(b);
    vi res;
    for(auto u: a){
        if(!b_set.count(u)){
            res.pb(u);
        }
    }
    return res;
}

pair<pair<vi, vi>, pair<vi, vi>> splitStates(vi states){
    vi S1, S2;
    vi S3, S4;
    for(int i = 0; i < sz(states); i++){
        if((i>>0)&1){
            S1.pb(states[i]);
        }
        else{
            S2.pb(states[i]);
        }

        if((i>>1)&1){
            S3.pb(states[i]);
        }
        else{
            S4.pb(states[i]);
        }
    }
    return mp(mp(S1, S2), mp(S3, S4));
}

int main() {
    setIO();
    int n;
    cin >> n;

    vi states;
    for(int i = 1; i <= n; i++){
        states.pb(i);
    }

    int iters = 0;
    while(sz(states) > 2){
        if(sz(states) == 3){
            vi sing = vi{states[0]};
            bool res1 = querySet(sing);
            if(!res1){
                res1 = querySet(sing);
                if(!res1){
                    states = vi{states[1], states[2]};
                    continue;
                }
            }
            assert(res1);
            bool res2 = querySet(vi{states[1]});
            guess(states[0]);
            if(res2){
                guess(states[1]);
            }
            else{
                guess(states[2]);
            }
            assert(false);
        }

        pair<pair<vi, vi>, pair<vi, vi>> spl = splitStates(states);

        vi id1;
        if(querySet(spl.f.f)){
            id1 = spl.f.s;
        }    
        else{
            id1 = spl.f.f;
        }
        vi id6;
        if(querySet(spl.s.f)){
            id6 = spl.s.s;
        }
        else{
            id6 = spl.s.f;
        }

        vi set_inter = id8(id1, id6);
        states = removeSet(states, set_inter);
    }

    assert(1 <= sz(states) && sz(states) <= 2);
    for(auto u: states){
        guess(u);
    }
    

    

}


