



using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using db = long double; 

using str = string; 




using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;


using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<db,db>;












tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T,SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vll = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpii = V<pi>;
using vpl = V<pl>;
using vpll = V<pll>;
using vpd = V<pd>;
































struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id4 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id4);
    }
    template<class T, class U>
    size_t operator()(pair<T,U> x) const {
        uint64_t a = (*this)(x.first);
        uint64_t b = (*this)(x.second);
        return a + 3*b;
    }
};

template<class A, class B> using umap = gp_hash_table<A,B,custom_hash>;







template<class A> using uset = gp_hash_table<A,null_type,custom_hash>;



























V<int> rangeint(int start, int end, int inc=1) {
    V<int> out;
    if (inc > 0) {
        for(int curr = start; curr < end; curr += inc) {
            out.push_back(curr);
        }
        return out;
    } else {
        for(int curr = start; curr > end; curr += inc) {
            out.push_back(curr);
        }
        return out;
    }
}






const ll BIG = 1e18; 

const db PI = acos((db)-1);


vector<pii> id13 = {{1,0},{0,1},{-1,0},{0,-1}};
vector<pii> stepsDiagonal = {{1,1},{1,-1},{-1,-1},{-1,1}};
vector<pii> id17 = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());











template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr ll pct(ll x) { return __builtin_popcountll(x); }
constexpr int bits(int x) { 

    return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id7(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcTU> bool ckmin(T& a, const U& b) {
    return (T)b < a ? a = (T)b, 1 : 0; } 

tcTU> bool ckmax(T& a, const U& b) {
    return a < (T)b ? a = (T)b, 1 : 0; } 


int maxi(int a, int b) {return max((int)a, (int)b);}
int mini(int a, int b) {return min((int)a, (int)b);}
ll maxll(ll a, ll b) {return max((ll)a, (ll)b);}
ll minll(ll a, ll b) {return min((ll)a, (ll)b);}

tcT> ll fstTrue(ll lo, ll hi, T f) {
    ++hi; assert(lo <= hi); 

    while (lo < hi) { 

        ll mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1;
    }
    return lo;
}
tcT> ll lstTrue(ll lo, ll hi, T f) {
    --lo; assert(lo <= hi); 

    while (lo < hi) { 

        ll mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    }
    return lo;
}
tcT> void remDup(vector<T>& v) { 

    sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { 

    auto it = t.find(u); assert(it != end(t));
    t.erase(it); } 




template<class ForwardIt>
ll sumv(ForwardIt first, ForwardIt last)
{
    

    ll out = 0;
    for (; first != last; ++first) {
        out += *first;
    }
    return out;
}
template<class T> auto sumv(const T& data) {return sumv(all(data));}
template<class T> auto max_element(const T& data) {return *max_element(all(data));}
template<class T> auto min_element(const T& data) {return *min_element(all(data));}




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
    tcT> constexpr bool id1 = is_readable<T>::value;

    

    

    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
            typename std::enable_if_t<
                is_same_v<decltype(cout << declval<T>()), ostream&>
            >
        > : true_type {};
    tcT> constexpr bool id3 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id14 = !id1<T> && id16<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id1<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id14<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }
    template<class A,class B,class C> void re(tuple<A,B,C>& t) {auto& [a,b,c]=t; re(a,b,c);}
    template<class A,class B,class C, class D> void re(tuple<A,B,C,D>& t) {auto& [a,b,c,d]=t; re(a,b,c,d);}
    template<class A,class B,class C, class D, class E> void re(tuple<A,B,C>& t) {auto& [a,b,c,d,e]=t; re(a,b,c,d,e);}
    template<class A,class B,class C, class D, class E, class F> void re(tuple<A,B,C>& t) {auto& [a,b,c,d,e,f]=t; re(a,b,c,d,e,f);}
    tcT> typename enable_if<id14<T>,void>::type re(T& i) {
        each(x,i) re(x); }
    tcTUU> void re(T& t, U&... u) { re(t); re(u...); } 


    

    void rv(size_t) {}
    tcTUU> void rv(size_t N, V<T>& t, U&... u);
    template<class...U> void rv(size_t, size_t N2, U&... u);
    tcTUU> void rv(size_t N, V<T>& t, U&... u) {
        t.resize(N); re(t);
        rv(N,u...); }
    template<class...U> void rv(size_t, size_t N2, U&... u) {
        rv(N2,u...); }
    void rv1(size_t) {}
    tcTUU> void rv1(size_t N, V<T>& t, U&... u) {
        t.resize(N); re(t); for(auto& x : t) --x;
        rv(N,u...); }


    

    void decrement() {} 

    tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
    
    
    
    
    
    
}

inline namespace ToString {
    tcT> constexpr bool id5 = !id3<T> && id16<T>;

    

    tcT> typename enable_if<id3<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id6(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id5<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.first)+", "+ts(p.second)+")"; }
    tcT> typename enable_if<id16<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id5<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id5<T>,vs>::type
      id9(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id5<T>,vs>::type
      id9(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.back() += ",";
            vs tmp = id9<lev-1>(t);
            res.insert(end(res),all(tmp));
        }
        id6(i,sz(res)) {
            str bef = " "; if (i == 0) bef = "{";
            res[i] = bef+res[i];
        }
        res.back() += "}";
        return res;
    }
}

inline namespace Output {
    template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
    template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
        pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
    template<class T> void id10(ostream& os, str, const T& t) { os << ts(t+1); }
    template<class T, class... U> void id10(ostream& os, str sep, const T& t, const U&... u) {
        id10(os,sep,t); os << sep; id10(os,sep,u...); }
    

    template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); }
    

    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); }
    void ps1() { cout << "\n"; }
    template<class ...T> void ps1(const T&... t) { id10(cout," ",t...); ps1(); }
    void pso() {}
    template<class ...T> void pso(const T&... t) { pr_sep(cout," ",t...); pso(); }
    void id0() {}
    template<class ...T> void id0(const T&... t) { id10(cout," ",t...); id0(); }

    template<class T>
    void pv(T& dat) {bool f=1; for(auto& x : dat) {if (!f) {cout<<' ';} f=0; cout << x;} cout<<'\n';}
    template<class T>
    void pv1(T& dat) {bool f=1; for(auto& x : dat) {if (!f) {cout<<' ';} f=0; cout << x+1;} cout<<'\n';}
    template<class T>
    void pvn(T& dat) {bool f=1; for(auto& x : dat) {if (!f) {cout<<'\n';} f=0; cout << x;} cout<<'\n';}
    template<class T>
    void id15(T& dat) {bool f=1; for(auto& x : dat) {if (!f) {cout<<'\n';} f=0; cout << x+1;} cout<<'\n';}
    


    const clock_t beg = clock();
    

    db TIME() {return (db)(clock()-beg)/CLOCKS_PER_SEC;}
    void flush() {std::cout << std::flush;}
}

inline namespace FileIO {
    void setIn(str s)  { if ( !freopen(s.c_str(),"r",stdin) ) assert(false); }
    void setOut(str s) { if ( freopen(s.c_str(),"w",stdout) ) assert(false); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); 

        cout.tie(0);
        cin.exceptions(cin.failbit);
        

        

        if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

    }
}








template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(char c) {
    return "'" + string(1, c) + "'";
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ", " + to_string(get<4>(p)) + ")";
}



template<class T>
string id11(T& q) {
    string out = "\n";
    int ctr = 0;
    for ( auto& x : q ) {
        out.push_back('\t');
        out += to_string(ctr) + ":\t" + to_string(x) + "\n";
        ++ctr;
    }
    return out;
}


template<class T>
string id12(T& q) {
    string out = "\n";
    for ( auto& x : q ) {
        bool first = true;
        for ( auto& v : x ) {
            if ( !first ) {
                out += '\t';
            }
            out += to_string(v);
            first = false;
        }
        out += '\n';
    }
    return out;
}



void debug_out() {}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    

    

    

    std::cerr << ' ' << to_string(H) << ' ';
    if (sizeof...(T)) {
        std::cerr << " ";
        debug_out(T...);
    }
}






































    

    
        std::cerr << OUT_BOLD << B \
        << std::right << setw(20) << C << ' ' \
        << OUT_RESET << OUT_BOLD << OUT_RED \
        << std::right << setw(7) << __LINE__        \
        << OUT_BOLD << " : " << OUT_RESET \
        << A << "[ " << 
        << OUT_BOLD << " :   " << OUT_RESET \
        << B, debug_out(__VA_ARGS__); \
        std::cerr << OUT_RESET << std::endl;

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    

    
    


    
    
















const ll INF = 2e18;
ll cost_one(int dx, int n) {
    if (n < 0) {return INF;}
    ll base_size = dx / (n+1);
    int num_big = dx % (n+1);
    int num_base = n+1 - num_big;
    ll cost_big = num_big * (base_size + 1) * (base_size + 1);
    ll cost_base = num_base * (base_size) * (base_size);
    ll result = cost_big + cost_base;
    

    return result;
}

ll cost_delta(int dx, int n) {
    

    return cost_one(dx, n) - cost_one(dx, n+1);
}



void brute() {
    lls(N);
    ++N;
    vector<ll> dat(N);
    FOR(k, 1, N) {
        cin >> dat[k];
    }
    lls(GOAL);
    dbgR(N, GOAL, dat);

    ll out = 0;
    ll total_cost = 0;
    

    using t3 = tuple<ll,int,int>;
    priority_queue<t3> intervals;
    FOR(k, 0, N-1) {
        ll dx = dat[k+1] - dat[k];
        total_cost += dx*dx;
        intervals.emplace(cost_delta(dx, 0), dx, 0);
    }

    while (total_cost > GOAL) {
        ++out;
        auto [reduction, dx, n] = intervals.top();
        total_cost -= reduction;
        dbg(out, dx, n, reduction, total_cost, GOAL);
        intervals.pop();
        reduction = cost_delta(dx, n+1);
        intervals.emplace(reduction, dx, n+1);
    }
    V<t3> id2;
    while (!intervals.empty()) {
        id2.push_back(intervals.top());
        intervals.pop();
    }
    sort(all(id2));
    dbgP(id2);
    ps(out);
}


void solve() {
    lls(N);
    ++N;
    vector<ll> dat(N);
    FOR(k, 1, N) {
        cin >> dat[k];
    }
    lls(GOAL);
    dbgR(N, GOAL, dat);

    ll total_cost = 0;
    

    using t4 = tuple<ll,int,int,int>;
    set<t4> intervals;
    FOR(k, 0, N-1) {
        ll dx = dat[k+1] - dat[k];
        total_cost += dx*dx;
        intervals.emplace(cost_delta(dx, 0), dx, 0, k);
    }

    auto check = [&](ll T) {
        ll nc = T - N;  

        


        ll tc_local = total_cost;
        set<t4> id18;
        

        ll cost_local = N;
        dbgY(T, T-N);

        
        dbgP(db(dat[N-1]) / (nc+1));
        for(auto& [_1, dx, _2, iidx] : intervals) {
            ll n_new = dx * (nc+1) / dat[N-1] - 1;
            ckmax(n_new, 0);
            dbg(dx, n_new);
            ll reduction = cost_one(dx, 0) - cost_one(dx, n_new);
            tc_local -= reduction;
            cost_local += n_new;
            id18.emplace(cost_delta(dx, n_new), dx, n_new, iidx);
        }
        dbg(id18, cost_local);
        if (cost_local > T) {dbg(false); return false;}

        while (tc_local > GOAL) {
            ++cost_local;
            if (cost_local > T) {dbg(false); return false;}
            auto it = id18.rbegin();
            auto [reduction, dx, n, iidx] = *it;
            if (reduction == 0) {dbg(false); return false;}
            tc_local -= reduction;
            dbg(cost_local, dx, n, reduction, tc_local, GOAL);
            id18.erase(*it);
            reduction = cost_delta(dx, n+1);
            id18.emplace(reduction, dx, n+1, iidx);
        }
        dbgP(id18);
        dbg(true);
        return true;
    };
    dbgBold(N, dat[N-1]+1);
    ll id8 = fstTrue(N, dat[N-1] + 1, check);
    ll out = id8 - N;
    ps(out);
}





void solve_old() {
    

    

    

    

    lls(N);
    ++N;
    vector<ll> dat(N);
    FOR(k, 1, N) {
        cin >> dat[k];
    }
    lls(GOAL);
    dbgR(N, GOAL, dat);

    

    V<int> interval_sizes;
    FOR(k, 0, N-1) {
        interval_sizes.push_back(dat[k+1] - dat[k]);
    }
    sort(all(interval_sizes));
    FOR(k, 1, N) {
        dat[k] = dat[k-1] + interval_sizes[k-1];
    }

    ll R = dat.back();
    V<ll> jb(N);  

    V<V<ll>> dp(2, V<ll>(N+1, INF));
    V<ll> dat_local;
    

    auto check_out = [&](ll T) {
        el; dbgY(T, T-N);
        dbg(R, dat);

        

        

        dat_local = {0};
        ll cost_pre = 0;
        ll offset = 0;
        ll T_local = T;
        ll R_local = R;
        dbg(db(R) / (T-1));
        FOR(k, 1, N) {
            ll dx = dat[k]-offset - dat_local.back();
            

            if (dx * (T_local-1) <= R_local) {
                

                cost_pre += dx*dx;
                offset += dx;
                R_local = R - offset;
                --T_local;
            } else {
                dat_local.push_back(dat[k] - offset);
            }
        }
        dbg(db(R_local) / (T_local-1));
        ll N_local = dat_local.size();
        dbgP(N_local, R_local, dat_local);
        if (R_local == 0) {
            bool out = (cost_pre <= GOAL);
            dbgcY("done early", out);
            return out;
        }


        dbg_only(jb.resize(N_local));
        FOR(k, 0, N_local) {
            jb[k] = dat_local[k] * (T_local-1) / R_local;
            

        }
        dbg(jb);
        FOR(o,0,2) FOR(k,0,N_local+1) {dp[o][k] = INF;}
        dp[0][0] = 0;
        FOR(n,0,N_local-1) FOR(o,0,2) {
            if (dp[o][n] == INF) {
                continue;
            }
            

            FOR(p,0,2) {
                int num_between = jb[n+1] - jb[n] + p - o - 1;
                

                ll cost_here = cost_one(dat_local[n+1] - dat_local[n], num_between);
                ckmin(dp[p][n+1], dp[o][n] + cost_here);
            }
        }
        ll result = dp[0][N_local-1];
        result += cost_pre;
        bool out = (result <= GOAL);
        dbgY(result, out, pdh(dp));
        return out;
    };

    

    

    


    ll id8 = fstTrue(N, R + 1, check_out);
    ll out = id8 - N;
    ps(out);
    return;
}










int main() {
    setIO();

    int T = 1;

    dbgc("loading num cases!!!"); std::cin >> T;  


    for ( int CASE = 1 ; CASE <= T ; ++CASE ) {
        el;

        dbgcBold("CASE" , CASE );
        solve();

        dbgcBold("brute force" , CASE );
        brute();

    }
    dbgR(TIME());

    return 0;
}

