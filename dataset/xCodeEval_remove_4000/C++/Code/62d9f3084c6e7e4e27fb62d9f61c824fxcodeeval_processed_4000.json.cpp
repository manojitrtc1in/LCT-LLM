

using namespace std;

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
















const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);


vector<pii> id7 = {{1,0},{0,1},{-1,0},{0,-1}};
vector<pii> id12 = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr ll pct(ll x) { return __builtin_popcountll(x); }
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


int maxi(int a, int b) {return max((int)a, (int)b);}
int mini(int a, int b) {return min((int)a, (int)b);}
int maxll(ll a, ll b) {return max((ll)a, (ll)b);}
int minll(ll a, ll b) {return min((ll)a, (ll)b);}

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
    tcT> constexpr bool id11 = is_iterable<T>::value;

    

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
    tcT> constexpr bool id2 = is_printable<T>::value;
}

inline namespace Input {
    tcT> constexpr bool id10 = !id1<T> && id11<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); 


    

    tcT> typename enable_if<id1<T>,void>::type re(T& x) { cin >> x; } 

    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 

    tcT> typename enable_if<id10<T>,void>::type re(T& i); 

    tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }
    tcT> typename enable_if<id10<T>,void>::type re(T& i) {
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
    tcT> constexpr bool id3 = !id2<T> && id11<T>;

    

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

    tcTU> str ts(pair<T,U> p) { return "("+ts(p.first)+", "+ts(p.second)+")"; }
    tcT> typename enable_if<id11<T>,str>::type ts_sep(T v, str sep) {
        

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
      id6(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<id3<T>,vs>::type
      id6(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.back() += ",";
            vs tmp = id6<lev-1>(t);
            res.insert(end(res),all(tmp));
        }
        id4(i,sz(res)) {
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
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
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

void debug_out() { std::cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    std::cerr << to_string(H) << "   ";
    debug_out(T...);
}


















    

    

    
        << std::right << setw(20) << A \
        << std::right << setw(8) << __LINE__        \
        << OUT_BOLD << " : " << OUT_RESET \
        << OUT_GREEN << "[ " << 
        << OUT_BOLD << " :    " << OUT_RESET \
        << OUT_CYAN, debug_out(__VA_ARGS__); \
        std::cerr << OUT_RESET;
    
    

    

    
    
    

    
    

    
    
    
    
    










int INF = 2e9;
tcT> struct SegTree { 

	const T ID{-1}; T cmb(T a, T b) { return max(a,b); }
	int n; V<T> seg;
	void init(int _n) { 

		for (n = 1; n < _n; ) n *= 2;
		seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { 

		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	

		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
	

	

	

	

	

	

	

};


const int INF = 2e9;


template<class T, bool id0 = true>
struct IntervalUnion {
    set<pair<T, T>> x;

    

    pair<T, T> merge_intervals(const pair<T,T>& a, const pair<T,T>& b) {
        return { min(a.first, b.first) , max(a.second, b.second) };
    }

    void insert(pair<T, T> pr) {
        while ( true ) {
            auto it = x.lower_bound( pr );
            if ( it != x.end() && it->first <= pr.second + id0 ) {
                

                pr = merge_intervals(pr, *it);
                x.erase( it );
                continue;
            }
            if ( it == x.begin() ) {
                break;
            }
            --it;
            if ( it->second >= pr.first - id0 ) {
                pr = merge_intervals(pr, *it);
                x.erase(it);
                continue;
            }
            break;
        }
        x.insert( pr );
    }

    set<pair<T,T>>::const_iterator query(T p) {
        auto it = x.lower_bound(MP(p,p));
        if ( it != x.end() && it->first == p ) {
            return it;
        }
        if ( it == x.begin() ) {
            return x.end();
        }
        --it;
        if ( it->second >= p ) {
            return it;
        }
        return x.end();
    }

    

    

    T test_contained(pair<T,T> pr) {
        auto& [a,b] = pr;
        auto it = query(a);
        if ( it == x.end() ) {
            return a;
        }
        if ( it->second >= b ) {
            return INF;
        }
        return it->second + 1;
    }

    

    vector<pair<T,T>> missing_sections(pair<T,T> pr) {
        dbgc("ms", pr);
        auto& [a, b] = pr;
        vector<pair<T,T>> out;
        auto itpre = query(a);
        T pos;
        if ( itpre == x.end() ) {
            pos = a;
        } else {
            pos = itpre->second + id0;
        }
        dbg(pos, *itpre);
        while ( true ) {
            if ( pos >= b ) {
                break;
            }
            

            auto it = x.lower_bound(MP(pos,pos));
            

            if ( it != x.end() && it->second == pos ) {
                ++it;
            }
            T last = b;
            if ( it != x.end() && it->first <= b ) {
                last = it->first - id0;
            }
            out.emplace_back( pos , last );
            if ( it != x.end() && it->second < b ) {
                pos = it->second + id0;
            } else {
                break;
            }
        }
        return out;
    }
};




void solve() {
    ints(N);
    dbg(sizeof(pii));
    vector<pii> dat;
    rv(N, dat);
    dbg(N, dat);
    

    sort(all(dat));




    SegTree<int> st;
    st.init(N);
    set<pii> starts;
    FOR(k, 0, N) {
        st.upd(k, dat[k].second);
        starts.emplace(dat[k].first, k);
    }

    ll out = 0;
    int idx = 0;
    while ( true ) {
        auto& [curr_height, curr_cost] = dat[idx];
        


        

        auto it = starts.lower_bound(MP(curr_height, N+1));
        --it;  

        int id9 = it->second;

        

        int id8 = st.query(idx, id9);

        

        it = starts.lower_bound(MP(id8, -1));
        
    }



    IntervalUnion<int, false> iu;
    for ( auto& [height, cost] : dat ) {
        iu.insert(MP(height, height+cost));
    }
    dbg(iu.x);
    auto missing = iu.missing_sections(MP(dat[0].first, dat[N-1].first));
    dbg(missing);
    ll out = 0;
    for ( auto& [a, b] : missing ) {
        out += b - a;
    }

    dbg(out);
    for ( auto& [height, cost] : dat ) {
        out += cost;
    }
    ps(out);
    return;
}




int main() {
    setIO();

    int T = 1;
    

    for ( int CASE = 1 ; CASE <= T ; ++CASE ) {
        el; dbgc("CASE" , CASE );
        solve();
    }

    return 0;
}

