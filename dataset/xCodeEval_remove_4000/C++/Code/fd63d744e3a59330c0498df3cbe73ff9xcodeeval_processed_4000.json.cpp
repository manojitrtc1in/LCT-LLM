
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
constexpr int id9(int x) { return p2(x)-1; }

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
    tcT> constexpr bool id19 = is_iterable<T>::value;

    

    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cin >> declval<T&>()), istream&>
            >
        > : true_type {};
    tcT> constexpr bool id3 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id5 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id17 = !id3<T> && id19<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id3<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id17<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<id17<T>,void>::type re(T& i) {
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
    tcT> constexpr bool id7 = !id5<T> && id19<T>;

    

    tcT> typename enable_if<id5<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id8(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id7<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<id19<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id7<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id7<T>,vs>::type 
      id12(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id7<T>,vs>::type 
      id12(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = id12<lev-1>(t);
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
    template<int lev, class T> void id20(const T& t) {
        cerr << "\n\n" << ts_sep(id12<lev>(t),"\n") << "\n" << endl; }
    
        
        
    

        
        
    
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
multiset<pi> id1;

map<pi, deque<pi>> dp; 

int cur_time;

void restrictRange(pi a){
    assert(dp.count(a));
    while(sz(dp[a]) >= 2 && dp[a][1].f+cur_time < a.f){
        dp[a].pop_front();
    }

    if(sz(dp[a]) && dp[a][0].f+cur_time < a.f){
        if(sz(dp[a]) == 1 || dp[a][1].s+dp[a][1].f+cur_time-a.f > dp[a][0].s+a.f-(dp[a][0].f+cur_time)){
            pi id0 = mp(a.f-cur_time, dp[a][0].s+a.f-(dp[a][0].f+cur_time));
            dp[a].pop_front();
            dp[a].push_front(id0);
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
            pi id0 = mp(a.s-cur_time, dp[a][sz(dp[a])-1].s+dp[a][sz(dp[a])-1].f+cur_time-a.s);
            dp[a].pop_back();
            dp[a].pb(id0);
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

pi id13(int a){
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
        it = id1.lb(mp(rang.s, -MOD));
        if(it != id1.begin()){
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

        pi id4 = e.s;

        if(e.f.s){ 

            bool id6 = 0;
            auto it = dp.lb(mp(id4.f, -MOD));
            if(it != dp.begin()){
                it = prev(it);
                if(it->f.s >= id4.s+1){
                    id6 = 1;
                }
            }

            if(id6){
                pi id2 = it->f;
                propLazy(id2);
                swap(dp[mp(id2.f, id4.f-1)], dp[id2]);
                dp.erase(id2);
                dp[mp(id4.s+1, id2.s)] = dp[mp(id2.f, id4.f-1)];
                restrictRange(mp(id2.f, id4.f-1));
                restrictRange(mp(id4.s+1, id2.s));
            }
            else{ 

                vpi id15;
                it = dp.lb(mp(id4.f+1, -MOD));
                if(it != dp.begin()) it = prev(it);
                while(true){
                    if(it == dp.end()) break;
                    pi KEY = it->f;
                    if(KEY.f > id4.s) break;
                    if(KEY.s < id4.f){
                        it = next(it);
                        continue;
                    }
                    
                    id15.pb(KEY);
                    it = next(it);
                }

                for(auto KEY: id15){
                    if(id4.f <= KEY.f && KEY.s <= id4.s){
                        dp.erase(KEY);
                        continue;
                    }

                    propLazy(KEY);
                    if(id4.f <= KEY.f){
                        swap(dp[KEY], dp[mp(id4.s+1, KEY.s)]);
                        dp.erase(KEY);
                        restrictRange(mp(id4.s+1, KEY.s));
                        continue;
                    }

                    if(KEY.s <= id4.s){
                        swap(dp[KEY], dp[mp(KEY.f, id4.f-1)]);
                        dp.erase(KEY);
                        restrictRange(mp(KEY.f, id4.f-1));
                        continue;
                    }

                }
            }

            curses.ins(id4);
            id1.ins(mp(id4.s, id4.f));
        }
        else{ 

            

            

            int pos_l = id4.f-1;
            int pos_r = id4.s+1;
            bool id18 = inDP(pos_l);
            bool id11 = inDP(pos_r);

            pi id10 = id13(pos_l); 

            pi id21 = id13(pos_r);

            curses.erase(curses.find(id4));
            id1.erase(id1.find(mp(id4.s, id4.f)));

            


            pi id16 = id13(pos_l);
            pi id14 = id13(pos_r);


            if(id18){
                

                propLazy(id10);
                

                

            }
            if(id11){
                

                

                propLazy(id21);
                

            }

            

            


            

            if(id18 && id11 && id16 == id14){
                

                mergeDP(id10, id21, id16);
                dp.erase(id10);
                dp.erase(id21);
            }
            else{
                if(id18 && id10 != id16){
                    swap(dp[id10], dp[id16]);
                    dp.erase(id10);
                }
                if(id11 && id21 != id14){
                    swap(dp[id21], dp[id14]);
                    dp.erase(id21);
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


