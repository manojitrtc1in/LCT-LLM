
































































































































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
constexpr int id9(int x) { return p2(x)-1; }

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
    tcT> constexpr bool id2 = is_iterable<T>::value;

    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool id7 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id0 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id1 = !id7<T> && id2<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id7<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id1<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<id1<T>,void>::type re(T& i) {
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
    tcT> constexpr bool id6 = !id0<T> && id2<T>;

    

    tcT> typename enable_if<id0<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id8(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id6<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<id2<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id6<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id6<T>,vs>::type 
      id10(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id6<T>,vs>::type 
      id10(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = id10<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        id8(i,sz(res)) {
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
    template<int lev, class T> void id12(const T& t) {
        cerr << "\n\n" << ts_sep(id10<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    

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

vi id4(vi v){
    pi min_ind = mp(MOD, -1);
    for(int i = 0; i < sz(v); i++){
        ckmin(min_ind, mp(v[i], i));
    }
    return vi{(min_ind.s+1) % 3, (min_ind.s+2) % 3};
}
int main() {
    setIO();
    vs inp(3); cin >> inp[0] >> inp[1] >> inp[2];
    map<char, vi> cnt;
    for(char c = 'A'; c <= 'Z'; c++){
        cnt[c] = vi{0, 0, 0};
    }
    for(int j = 0; j < 3; j++){
        for(auto u: inp[j]){
            cnt[u][j]++;
        }
    }

    int id3 = min(sz(inp[0]), min(sz(inp[1]), sz(inp[2])));

    vector<pair<char, int>> trips;
    for(char c = 'A'; c <= 'Z'; c++){
        while(id3 > 0){
            vi id5 = id4(cnt[c]);
            assert(sz(id5) == 2);
            if(cnt[c][id5[0]] > 0 && cnt[c][id5[1]] > 0){
                cnt[c][id5[0]]--;
                cnt[c][id5[1]]--;
                trips.pb(mp(c, 3-id5[0]-id5[1]));
                id3--;
            }
            else{
                break;
            }
        }
    }

    dbg(trips);
    dbg(cnt);
    vs chars_left(3);
    for(char c = 'A'; c <= 'Z'; c++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < cnt[c][j]; k++){
                chars_left[j].pb(c);
            }
        }
    }

    vs ans;
    for(auto u: trips){
        char extra_char = chars_left[u.s].bk; chars_left[u.s].pop_back();
        

        ans.pb(string(1, u.f)+string(1, extra_char));
    }
    


    while(sz(chars_left[0]) + sz(chars_left[1]) + sz(chars_left[2]) > 0){
        int id11 = 0;
        for(int j = 0; j < 3; j++){
            if(sz(chars_left[j]) > 0){
                id11++;
            }
        }
        if(id11 == 1){
            for(int j = 0; j < 3; j++){
                if(sz(chars_left[j]) > 0){
                    ans.pb(string(1, chars_left[j].bk) + string(1, chars_left[j].bk));
                    chars_left[j].pop_back();
                    break;
                }
            }
        }
        else{
            assert(id11 >= 2);
            vi inds = id4(vi{sz(chars_left[0]), sz(chars_left[1]), sz(chars_left[2])});
            ans.pb(string(1, chars_left[inds[0]].bk) + string(1, chars_left[inds[1]].bk));
            chars_left[inds[0]].pop_back(); chars_left[inds[1]].pop_back();
        }
    }

    ps(sz(ans));
    for(auto u: ans){
        assert(sz(u) == 2);
        ps(u);
    }


    

}

