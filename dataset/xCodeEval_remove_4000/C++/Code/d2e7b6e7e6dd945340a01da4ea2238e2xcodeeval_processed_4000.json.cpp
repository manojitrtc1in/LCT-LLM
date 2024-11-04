



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
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

























tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }




struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        

        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t id2 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id2);
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


























const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);


vector<pii> id11 = {{1,0},{0,1},{-1,0},{0,-1}};
vector<pii> id15 = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr ll pct(ll x) { return __builtin_popcountll(x); }
constexpr int bits(int x) { 

    return x == 0 ? 0 : 31-__builtin_clz(x); } 

constexpr int p2(int x) { return 1<<x; }
constexpr int id6(int x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } 

ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } 


tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } 

tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; } 


int maxi(int a, int b) {return max((int)a, (int)b);}
int mini(int a, int b) {return min((int)a, (int)b);}
ll maxll(ll a, ll b) {return max((ll)a, (ll)b);}
ll minll(ll a, ll b) {return min((ll)a, (ll)b);}

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
    tcT> constexpr bool id13 = is_iterable<T>::value;

    

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
    tcT> constexpr bool id12 = !id0<T> && id13<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id0<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id12<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }
    template<class A,class B,class C> void re(tuple<A,B,C>& t) {auto& [a,b,c]=t; re(a,b,c);}
    template<class A,class B,class C, class D> void re(tuple<A,B,C,D>& t) {auto& [a,b,c,d]=t; re(a,b,c,d);}
    template<class A,class B,class C, class D, class E> void re(tuple<A,B,C>& t) {auto& [a,b,c,d,e]=t; re(a,b,c,d,e);}
    template<class A,class B,class C, class D, class E, class F> void re(tuple<A,B,C>& t) {auto& [a,b,c,d,e,f]=t; re(a,b,c,d,e,f);}
    tcT> typename enable_if<id12<T>,void>::type re(T& i) {
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

    

    void decrement() {} 

    tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
    
    
    
    
    
    
}

inline namespace ToString {
    tcT> constexpr bool id4 = !id1<T> && id13<T>;

    

    tcT> typename enable_if<id1<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } 

    tcT> str bit_vec(T t) { 

        str res = "{"; id5(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

    tcTU> str ts(pair<T,U> p); 

    tcT> typename enable_if<id4<T>,str>::type ts(T v); 

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.first)+", "+ts(p.second)+")"; }
    tcT> typename enable_if<id13<T>,str>::type ts_sep(T v, str sep) {
        

        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<id4<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    

    template<int, class T> typename enable_if<!id4<T>,vs>::type
      id7(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id4<T>,vs>::type
      id7(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.back() += ",";
            vs tmp = id7<lev-1>(t);
            res.insert(end(res),all(tmp));
        }
        id5(i,sz(res)) {
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
    

    template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); }
    

    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); }

    template<class T>
    void pv(T& dat) {for(auto& x : dat) cout<<x<<' '; cout<<'\n';}
    


    const clock_t beg = clock();
    

    db TIME() {return (db)(clock()-beg)/CLOCKS_PER_SEC;}

    
    
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
string id9(T& q) {
    string out = "\n";
    int ctr = 0;
    for ( auto& x : q ) {
        out += to_string(ctr) + "\t" + to_string(x) + "\n";
        ++ctr;
    }
    return out;
}


template<class T>
string id10(T& q) {
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



void debug_out() { std::cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    std::cerr << to_string(H) << "   ";
    debug_out(T...);
}
































    

    
        << std::right << setw(20) << C \
        << std::right << setw(8) << __LINE__        \
        << OUT_BOLD << " : " << OUT_RESET \
        << A << "[ " << 
        << OUT_BOLD << " :    " << OUT_RESET \
        << B, debug_out(__VA_ARGS__); \
        std::cerr << OUT_RESET;

    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    
    
    

    
    

    
    


    
    







db ep = 1e-13;

db d(auto& a, auto& b) {
    auto& [ax, ay] = a;
    auto& [bx, by] = b;
    db dx = ax - bx;
    db dy = ay - by;
    return sqrtl(dx*dx + dy*dy);
}

void brute() {
    lls(N);
    int1(K);
    vector<pll> dat;
    rv(N, dat);
    V<int> perm(N);
    FOR(k,0,N) {perm[k] = k;}

    db out = 1e18;
    do {
        if ( perm[0] != K ) {
            continue;
        }
        db curr = 0.0;
        FOR(k, 0, N-1) {
            curr += d(dat[perm[k]], dat[perm[k+1]]);
        }
        dbg(perm, curr);
        ckmin(out, curr);
    } while ( next_permutation(all(perm)) );
    ps(out);
    return;
}

bool id8(auto& dat, auto& X) {
    auto& [x1, y1] = dat[X[0]];
    auto& [x2, y2] = dat[X[1]];
    auto& [x3, y3] = dat[X[2]];
    ll id14 = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);
    return (id14 == 0);
}


void solve() {
    lls(N);
    int1(K);
    vector<pll> dat;
    rv(N, dat);
    pll pk = dat[K];
    

    remDup(dat);
    K = 0;
    while ( dat[K] != pk ) {
        ++K;
    }
    N = dat.size();
    dbgY(N, dat);

    if ( N == 1 ) {
        return ps(0.);
    } else if ( N == 2 ) {
        return ps(d(dat[0], dat[1]));
    }

    
    int ncp = -1;
    if ( N == 3 ) {
        ncp = K;
    } else {
        

        V<int> on_line;
        FOR(exclude, 0, 4) {
            on_line.clear();
            FOR(k, 0, 4) {
                if ( k == exclude ) {
                    continue;
                }
                on_line.push_back(k);
            }
            if ( id8(dat, on_line) ) {
                break;
            }
        }
        ncp = 0;
        while ( true ) {
            if ( ncp == on_line[0] || ncp == on_line[1] || ncp == on_line[2] ) {
                ++ncp;
                continue;
            }
            on_line[2] = ncp;
            if ( !id8(dat, on_line) ) {
                

                break;
            }
            ++ncp;
        }
    }
    dbg(ncp, dat[ncp]);

    pll id3 = dat[ncp];
    dat.erase(dat.begin() + ncp);
    --N;
    dbgP(id3, K, dat[K], dat);


    pll L = dat[0];
    pll R = dat[N-1];
    if ( ncp == K ) {
        

        db out = min(d(id3, L), d(id3, R));
        out += d(dat[0], dat[N-1]);
        return ps(out);
    }
    if ( K > ncp ) {
        --K;
    }
    dbgcP("update K", K, dat[K]);

    

    db out = 1e18;
    FOR(mask, 0, 8) {
        bool hi = mask % 2;
        bool lo = (mask/2) % 2;
        bool dir = (mask/4) % 2;
        if ( K == N-1 && !hi ) {
            continue;
        }
        if ( K == 0 && !lo ) {
            continue;
        }

        if ( !lo && !hi ) {
            db curr = d(dat[K], id3);
            curr += min(d(id3, L), d(id3, R));
            curr += d(L, R);
            ckmin(out, curr);
        } else if ( lo && !hi ) {
            if ( dir ) {
                continue;
            }
            dbgcP("visit lo, not hi");
            FOR(lbd, 0, N-1) {  

                dbg(lbd);
                int remnant = max(lbd+1, K+1);
                db curr = d(dat[K], L);
                curr += d(L, dat[lbd]);
                curr += d(dat[lbd], id3);
                curr += min(d(id3, dat[remnant]), d(id3, R));
                curr += d(dat[remnant], R);
                dbg(d(dat[K], L), d(L, dat[lbd]), d(dat[lbd], id3), min(d(id3, dat[remnant]), d(id3, R)), d(dat[remnant], R));
                dbg(curr);
                ckmin(out, curr);
            }
        } else if ( !lo && hi ) {
            if ( dir ) {
                continue;
            }
            FOR(lbd_helper, 0, N-1) {  

                int lbd = N-1 - lbd_helper;
                int remnant = min(lbd-1, K-1);
                db curr = d(dat[K], R);
                curr += d(R, dat[lbd]);
                curr += d(dat[lbd], id3);
                curr += min(d(id3, dat[remnant]), d(id3, L));
                curr += d(dat[remnant], L);
                ckmin(out, curr);
            }
        } else if ( dir ) {
            

            db curr = d(dat[K], L) + d(L, R) + d(R, id3);
            ckmin(out, curr);
        } else {
            db curr = d(dat[K], R) + d(L, R) + d(L, id3);
            ckmin(out, curr);
        }
    }


    dbg();
    ps(out);

    return;
}








int main() {
    setIO();

    int T = 1;
    

    for ( int CASE = 1 ; CASE <= T ; ++CASE ) {
        el; dbgcBold("CASE" , CASE );

        solve();

        brute();

    }
    dbg(TIME());

    return 0;
}

