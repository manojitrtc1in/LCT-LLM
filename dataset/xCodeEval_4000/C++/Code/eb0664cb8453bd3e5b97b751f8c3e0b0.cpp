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
tcT> int upb(V<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }



#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7; 

const int MX = 2e5+5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; 

mt19937 rng(127); 
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

    const clock_t beg = clock();
    #define dbg_time() dbg((db)(clock()-beg)/CLOCKS_PER_SEC)
}

inline namespace FileIO {
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); 

        

        

        

        if (sz(s)) setIn(s+".in"), setOut(s+".out"); 

    }
}




const int mx = 1000005;

struct Eff{


int N;
int B[mx];
clock_t BEG;

void tryNonDistinct(){
    vi A;
    A.pb(0);
    for(int i = 1; i <= N; i++){
        A.pb(B[i]);
    }
    remDup(A);

    while(sz(A) < N){
        A.pb(0);
    }

    if(sz(A) == N){
        ps("YES");
        for(auto u: A){
            cout << u << " ";
        }
        cout << "\n";
        exit(0);
    }
}

void try3Evens(){
    vi evens;
    for(int i = 1; i <= N; i++){
        if(B[i] % 2 == 0){
            evens.pb(i);
        }

        if(sz(evens) == 3){
            int sum = B[evens[0]]+B[evens[1]]+B[evens[2]];
            assert(sum % 2 == 0);
            sum/=2;

            vi A = vi{sum-B[evens[0]], sum-B[evens[1]], sum-B[evens[2]]};
            for(int j = 1; j <= N; j++){
                bool is_even_ind = 0;
                for(auto u: evens){
                    if(j == u){
                        is_even_ind = 1;
                        break;
                    }
                }
                if(!is_even_ind){
                    A.pb(B[j]-A[0]);
                }
            }



            assert(sz(A) == N);

            ps("YES");
            for(auto u: A){
                cout << u << " ";
            }
            cout << "\n";

            exit(0);
        }
    }

    
}


void try1Even2Odd(){
    vi evens;
    vi odds;

    for(int i = 1; i <= N; i++){
        if(B[i] % 2 == 0 && sz(evens) < 1){
            evens.pb(i);
        }
        if(B[i] % 2 == 1 && sz(odds) < 2){
            odds.pb(i);
        }

        if(sz(evens) == 1 && sz(odds) == 2){
            int sum = B[evens[0]]+B[odds[0]]+B[odds[1]];
            assert(sum % 2 == 0);
            sum/=2;

            vi A = vi{sum-B[evens[0]], sum-B[odds[0]], sum-B[odds[1]]};
            for(int j = 1; j <= N; j++){
                bool is_already_ind = 0;
                for(auto u: evens){
                    if(j == u){
                        is_already_ind = 1;
                        break;
                    }
                }
                for(auto u: odds){
                    if(j == u){
                        is_already_ind = 1;
                        break;
                    }
                }
                if(!is_already_ind){
                    A.pb(B[j]-A[0]);
                }
            }



            assert(sz(A) == N);

            ps("YES");
            for(auto u: A){
                cout << u << " ";
            }
            cout << "\n";

            exit(0);
        }
    }
}

int getEvenCount(){
    int res = 0;
    for(int i = 1; i <= N; i++){
        if(B[i] % 2 == 0){
            res++;
        }
    }
    return res;
}


pi sum_possible[2*mx];
int three_pow[17];

int getSubsetSum(const vi& sub){
    int res = 0;
    for(const auto& u: sub){
        res+=B[u];
    }
    return res;
}

void genThreePows(){
    three_pow[0] = 1;
    for(int i = 1; i <= 16; i++){
        three_pow[i] = three_pow[i-1]*3;
    }
}

void RANDOMSHUFFLE(){
    vi shuffle_B;
    for(int i = 1; i <= N; i++){
        shuffle_B.pb(B[i]);
    }
    shuffle(all(shuffle_B), rng);
    for(int i = 0; i < N; i++){
        B[i+1] = shuffle_B[i];
    }
}

pair<vi, vi> findCycle(){
    for(int i = 0; i < 2*mx; i++){
        sum_possible[i] = mp(-1, -1);
    }
    

    for(int i = 1; i <= N; i++){
        for(int j = i+1; j <= N; j++){
            int sum = B[i]+B[j];
            if(sum_possible[sum] != mp(-1, -1)){
                dbg("FOUND PAIR");
                return mp(vi{sum_possible[sum].f, sum_possible[sum].s}, vi{i, j});
            }
            sum_possible[sum] = mp(i, j);
        }
    }
    


    if(N <= 13){
        genThreePows();
        for(int i = 1; i < three_pow[N]; i++){
            int sub1_sum = 0;
            int sub2_sum = 0;
            int sub1_num = 0;
            int sub2_num = 0;
            
            for(int j = 0; j < N; j++){
                int bit_val = (i/three_pow[j]) % 3;
                if(bit_val == 0){

                }
                else if(bit_val == 1){
                    sub1_sum+=B[j+1];
                    sub1_num++;
                }
                else if(bit_val == 2){
                    sub2_sum+=B[j+1];
                    sub2_num++;
                }
            }

            if(sub1_sum == sub2_sum && sub1_num == sub2_num){
                vi sub1, sub2;
                for(int j = 0; j < N; j++){
                    int bit_val = (i/three_pow[j]) % 3;
                    if(bit_val == 0){

                    }
                    else if(bit_val == 1){
                        sub1.pb(j+1);
                    }
                    else if(bit_val == 2){
                        sub2.pb(j+1);
                    }
                }
                return mp(sub1, sub2);
            }
        }
        return mp(vi{}, vi{});
    }

    
    

    while(db(clock()-BEG)/db(CLOCKS_PER_SEC) < 0.75){
        RANDOMSHUFFLE();
        

        int len = min(15, N/2);

        map<int, vi> possible1[20];

        for(int beg_sub = 1; beg_sub < (1<<len); beg_sub++){
            vi elements;
            int sum = 0;
            for(int i = 0; i < len; i++){
                if(((beg_sub)>>i)&1){
                    int ind = 1+i;
                    sum+=B[ind];
                    elements.pb(ind);
                }
            }
            possible1[sz(elements)][sum] = elements;
        }
        
        for(int end_sub = 1; end_sub < (1<<len); end_sub++){
            vi elements;
            int sum = 0;
            for(int i = 0; i < len; i++){
                if(((end_sub)>>i)&1){
                    int ind = N-i;
                    sum+=B[ind];
                    elements.pb(ind);
                }
            }
            if(possible1[sz(elements)].count(sum)){
                dbg("FOUND SUB");
                return mp(possible1[sz(elements)][sum], elements);
            }
        }
    }
    

    return mp(vi{}, vi{});
}

void solve(){
    BEG = clock();
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> B[i];
    }
    tryNonDistinct();
    try3Evens();
    try1Even2Odd();

    if(getEvenCount() >= 1){
        bool case1 = (N == 2);
        bool case2 = (N == 3 && getEvenCount() == 2);
        assert(case1 || case2);
        ps("NO");
        exit(0);
    }

    assert(N >= 3);

    


    pair<vi, vi> cyc = findCycle(); 

    dbg(cyc);
    assert(sz(cyc.f) == sz(cyc.s));
    if(sz(cyc.f) == 0){
        ps("NO");
        exit(0);
    }

    vi A;
    A.pb(0);
    for(int i = 0; i < sz(cyc.f); i++){
        A.pb(B[cyc.f[i]]-A.bk);
        A.pb(B[cyc.s[i]]-A.bk);
    }
    A.pop_back();

    dbg(A);

    set<int> remaining_indices;

    for(int i = 1; i <= N; i++){
        remaining_indices.ins(i);
    }
    for(auto u: cyc.f){
        remaining_indices.erase(u);
    }
    for(auto u: cyc.s){
        remaining_indices.erase(u);
    }

    for(auto u: remaining_indices){
        A.pb(B[u]-A[0]);
    }

    assert(sz(A) == N);

    ps("YES");
    for(auto u: A){
        cout << u << " ";
    }
    cout << "\n";
    


}


};

int main() {
    setIO();
    Eff e;
    e.solve();
    


    

}


