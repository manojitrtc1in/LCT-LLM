#include <bits/stdc++.h>
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

#define tcT template<class T
#define tcTU tcT, class U


tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;



#define mp make_pair
#define f first
#define s second





#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define rtn return

#define lb lower_bound
#define ub upper_bound 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }



#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

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
constexpr int msk2(int x) { return p2(x)-1; }

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


#define tcTUU tcT, class ...U

inline namespace Helpers {
    

    

    

    tcT, class = void> struct is_iterable : false_type {};
    tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
                                      decltype(end(declval<T>()))
                                     >
                           > : true_type {};
    tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool is_readable_v = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
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
    #define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
    #define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
    tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

    

    tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type 
      ts_lev(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type 
      ts_lev(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = ts_lev<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        F0R(i,sz(res)) {
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
    template<int lev, class T> void dbgl_out(const T& t) {
        cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
    #ifdef LOCAL
        #define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
        #define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
    #else 

        #define dbg(...) 0
        #define dbgl(lev,x) 0
    #endif
}

inline namespace FileIO {
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); 

        

        

        

        if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

    }
}

multiset<pi> curses;
multiset<pi> rev_curses;

map<pi, deque<pi>> dp; 

int cur_time;

void restrictRange(pi a){
    assert(dp.count(a));
    while(sz(dp[a]) >= 2 && dp[a][1].f+cur_time < a.f){
        dp[a].pop_front();
    }

    if(sz(dp[a]) && dp[a][0].f+cur_time < a.f){
        if(sz(dp[a]) == 1 || dp[a][1].s+dp[a][1].f+cur_time-a.f > dp[a][0].s+a.f-(dp[a][0].f+cur_time)){
            pi add_rang = mp(a.f-cur_time, dp[a][0].s+a.f-(dp[a][0].f+cur_time));
            dp[a].pop_front();
            dp[a].push_front(add_rang);
        }
        else{
            dp[a].pop_front();
        }
    }

    while(sz(dp[a]) >= 2 && dp[a][sz(dp[a])-2].f+cur_time > a.s){
        dp[a].pop_back();
    }

    if(sz(dp[a]) && dp[a][sz(dp[a])-1].f+cur_time > a.s){
        if(sz(dp[a]) == 1 || dp[a][sz(dp[a])-2].s+a.s-(dp[a][sz(dp[a])-2].f+cur_time) > dp[a][sz(dp[a])-1].s+dp[a][sz(dp[a])-1].f+cur_time-a.s){
            pi add_rang = mp(a.s-cur_time, dp[a][sz(dp[a])-1].s+dp[a][sz(dp[a])-1].f+cur_time-a.s);
            dp[a].pop_back();
            dp[a].pb(add_rang);
        }
        else{
            dp[a].pop_back();
        }
    }
}
void propLazy(pi a){
    assert(dp.count(a));
    restrictRange(a);
}

bool inDP(int a){
    auto it = dp.lb(mp(a+1, -MOD));
    if(it == dp.begin()) return false;
    it = prev(it);
    if(it->f.f <= a && a <= it->f.s) return true;

    return false;
}

pi getDPRange(int a){
    auto it = dp.lb(mp(a+1, -MOD));
    if(it == dp.begin()) return mp(-MOD, -MOD);
    it = prev(it);
    pi rang = it->f;

    if(a < rang.f || rang.s < a) return mp(-MOD, MOD);

    {
        auto it = curses.lb(mp(rang.f, -MOD));
        if(it != curses.end()){
            rang.s = (it->f)-1;
        }
        else{
            rang.s = 3*1000000+5;
        }
        it = rev_curses.lb(mp(rang.s, -MOD));
        if(it != rev_curses.begin()){
            it = prev(it);
            rang.f = (it->f)+1;
        }
        else{
            rang.f = -3*1000000-5;
        }
    }
    

    return rang;
}



void mergeDP(pi l, pi r, pi loc){
    assert(l.s < r.f);
    assert(dp.count(l));
    assert(dp.count(r));
    deque<pi>& a = dp[l];
    deque<pi>& b = dp[r];
    while(sz(a) && sz(b)){
        if(a.bk.s >= b.front().s+b.front().f-a.bk.f){
            a.pop_back();
            continue;
        }
        if(b.front().s >= a.bk.s+b.front().f-a.bk.f){
            b.pop_front();
            continue;
        }
        break;
    }

    if(sz(a) > sz(b)){
        while(sz(b)){
            a.pb(b.front()); b.pop_front();
        }
        swap(a, dp[loc]);
    }
    else{
        while(sz(a)){
            b.push_front(a.bk); a.pop_back();
        }
        swap(b, dp[loc]);
    }
    
    
}

int main() {
    setIO();
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<pair<pair<int, bool>, pi>> events;
    for(int i = 1; i <= n; i++){
        int tl, tr, l, r;
        cin >> tl >> tr >> l >> r;
        events.pb(mp(mp(tl-1, 1), mp(l, r)));
        events.pb(mp(mp(tr+1, 0), mp(l, r)));
    }

    sort(all(events));

    dp[mp(-3*1000000-5, 3*1000000+5)].push_back(mp(x, 0));

    for(auto e: events){ 

        

        

        if(e.f.f > cur_time){
            cur_time = e.f.f;
        }

        pi curse_rang = e.s;

        if(e.f.s){ 

            bool splits_range = 0;
            auto it = dp.lb(mp(curse_rang.f, -MOD));
            if(it != dp.begin()){
                it = prev(it);
                if(it->f.s >= curse_rang.s+1){
                    splits_range = 1;
                }
            }

            if(splits_range){
                pi split_rang = it->f;
                propLazy(split_rang);
                swap(dp[mp(split_rang.f, curse_rang.f-1)], dp[split_rang]);
                dp.erase(split_rang);
                dp[mp(curse_rang.s+1, split_rang.s)] = dp[mp(split_rang.f, curse_rang.f-1)];
                restrictRange(mp(split_rang.f, curse_rang.f-1));
                restrictRange(mp(curse_rang.s+1, split_rang.s));
            }
            else{ 

                vpi keys_to_modify;
                it = dp.lb(mp(curse_rang.f+1, -MOD));
                if(it != dp.begin()) it = prev(it);
                while(true){
                    if(it == dp.end()) break;
                    pi KEY = it->f;
                    if(KEY.f > curse_rang.s) break;
                    if(KEY.s < curse_rang.f){
                        it = next(it);
                        continue;
                    }
                    
                    keys_to_modify.pb(KEY);
                    it = next(it);
                }

                for(auto KEY: keys_to_modify){
                    if(curse_rang.f <= KEY.f && KEY.s <= curse_rang.s){
                        dp.erase(KEY);
                        continue;
                    }

                    propLazy(KEY);
                    if(curse_rang.f <= KEY.f){
                        swap(dp[KEY], dp[mp(curse_rang.s+1, KEY.s)]);
                        dp.erase(KEY);
                        restrictRange(mp(curse_rang.s+1, KEY.s));
                        continue;
                    }

                    if(KEY.s <= curse_rang.s){
                        swap(dp[KEY], dp[mp(KEY.f, curse_rang.f-1)]);
                        dp.erase(KEY);
                        restrictRange(mp(KEY.f, curse_rang.f-1));
                        continue;
                    }

                }
            }

            curses.ins(curse_rang);
            rev_curses.ins(mp(curse_rang.s, curse_rang.f));
        }
        else{ 

            

            

            int pos_l = curse_rang.f-1;
            int pos_r = curse_rang.s+1;
            bool in_dp_l = inDP(pos_l);
            bool in_dp_r = inDP(pos_r);

            pi orig_dp_rang_l = getDPRange(pos_l); 

            pi orig_dp_rang_r = getDPRange(pos_r);

            curses.erase(curses.find(curse_rang));
            rev_curses.erase(rev_curses.find(mp(curse_rang.s, curse_rang.f)));

            


            pi dp_rang_l = getDPRange(pos_l);
            pi dp_rang_r = getDPRange(pos_r);


            if(in_dp_l){
                

                propLazy(orig_dp_rang_l);
                

                

            }
            if(in_dp_r){
                

                

                propLazy(orig_dp_rang_r);
                

            }

            

            


            

            if(in_dp_l && in_dp_r && dp_rang_l == dp_rang_r){
                

                mergeDP(orig_dp_rang_l, orig_dp_rang_r, dp_rang_l);
                dp.erase(orig_dp_rang_l);
                dp.erase(orig_dp_rang_r);
            }
            else{
                if(in_dp_l && orig_dp_rang_l != dp_rang_l){
                    swap(dp[orig_dp_rang_l], dp[dp_rang_l]);
                    dp.erase(orig_dp_rang_l);
                }
                if(in_dp_r && orig_dp_rang_r != dp_rang_r){
                    swap(dp[orig_dp_rang_r], dp[dp_rang_r]);
                    dp.erase(orig_dp_rang_r);
                }
            }

        }
    }
    assert(sz(dp) == 1);
    assert(sz(dp[mp(-3*1000000-5, 3*1000000+5)]) > 0);
    int ans = MOD;
    for(auto u: dp[mp(-3*1000000-5, 3*1000000+5)]){
        ckmin(ans, u.s);
    }
    ps(ans);
    

}


