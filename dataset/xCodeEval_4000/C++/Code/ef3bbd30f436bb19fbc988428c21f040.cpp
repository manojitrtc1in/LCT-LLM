#include <bits/stdc++.h>

using namespace std;











#define ar array
#define ll long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define lbi(A,x)   (lower_bound(A.begin(),A.end(), x) - A.begin())
#define ubi(A,x)   (upper_bound(A.begin(), A.end(), x) - A.begin())
#define lbir(A,i,j,x)  (lower_bound(A.begin() + i , A.begin() + j , x) - A.begin())
#define ubir(A,i,j,x)  (upper_bound(A.begin() + i, A.begin() + j, x) - A.begin())
#define f_prec(prec)  cout << fixed << setprecision(prec) ;
#define vv(A, T, n1, n2, val) vector<vector<T>> A(n1, vector<T>(n2, val))
#define vvv(A, T, n1, n2, n3, val) vector<vector<vector<T>>> A(n1, vector<vector<T>>(n2, vector<T>(n3, val)))
#define vvvv(A, T, n1, n2, n3, n4, val) vector<vector<vector<vector<T>>>> A(n1, vector<vector<vector<T>>>(n2, vector<vector<T>>(n3, vector<T>(n4, val))))




template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename T>  
string to_string(stack <T> st);
template <typename T>
string to_string(queue<T> q);
string to_string(char c){return string(1, c);}
string to_string(const string s){return '"' + s + '"';}
string to_string(const char* s){return to_string((string)s);}
string to_string(bool b){return (b ? "true" : "false");}
string to_string(vector<bool> v){bool first = true;string res = "{";for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", ";}first = false;res += to_string(v[i]);}res += "}";return res;}


template <size_t S>
string to_string(bitset<S> b){string res;res += '{';bool f = true;for (int i = 0; i < S; ++i) {if (!f) {res += ',';}f = false;res += char('0' + b[i]);}res += '}';return res;}
template <typename A>
string to_string(A v){bool first = true;string res = "{";for (const auto& x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}
template <typename A, typename B>
string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename T >
string to_string(stack <T> st){bool first = true;string res = "{";while (!st.empty()) {if (!first) {res += ", ";}first = false;res += to_string(st.top());st.pop();}res += "}";return res;}
template <typename T>
string to_string(queue<T> q){bool first = true;string res = "{";while (!q.empty()) {if (!first) {res += ", ";}first = false;res += to_string(q.front());q.pop();}res += "}";return res;}
template <typename T>
string to_string(T pq, bool ispq){assert(ispq); bool first = true;string res = "{";while (!pq.empty()) {if (!first) {res += ", ";}first = false;res += to_string(pq.top());pq.pop();}res += "}";return res;}


void DBG(){cerr << " ]" << "\n";}
template <typename Head, typename... Tail>
void DBG(Head H, Tail... T){cerr << " " << to_string(H);if (sizeof...(T)) {cerr << ", ";}DBG(T...);}

#ifdef zxcv_1
#define dbg(...) cerr << "L(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 42
#endif




#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename key, typename value, typename cmp = std::less<key>>
using omap = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;




#define fr(i,a,b,d) for (int i = a; i < b; i += d)
#define rfr(i,b,a,d) for(int i= b; i>= a; i -= d)
#define frc(i,a,b,c,d) for(int i = a; (i< b) && c ; i += d) 
#define rfrc(i,a,b,c,d) for(int i = b; (i>= a) && c ; i -= d)




void read(char &x) {cin >> x;} 
void read(int& x){cin >> x;}
void read(ll& x){cin >> x;}
void read(double& x){cin >> x;}
void read(string& s){cin >> s;}


template <typename T1, typename T2>
void read(pair<T1, T2>& p){cin >> p.first >> p.second;}
template <typename T>
void read(T& A){for (auto& x : A) {read(x);}}
template <typename T>
void a_offset(T& A, int off = -1){for (auto& x : A) {x += off;}}
template <class H, class... T>
void read(H& h, T&... t){read(h);read(t...);}






template <typename T>  
void out (T &A, int offset = 0 ){for(auto &x : A){x += offset; cout <<  x <<" ";}cout <<"\n"; }




#define fsttrue(lo_val,hi_val,valid,ansi) {ll lo = lo_val , hi = hi_val,  mid;while (lo <= hi) {mid = lo + (hi - lo) / 2;if (valid(mid)) {ansi = mid;hi = mid - 1;} else {lo = mid + 1;}}}
#define lsttrue(lo_val,hi_val,valid,ansi) {ll lo = lo_val , hi = hi_val,  mid;while (lo <= hi) {mid = lo + (hi - lo) / 2;if (valid(mid)) {ansi = mid;lo = mid + 1;} else {hi = mid - 1;}}}
#define ternint_hi(lo_val,hi_val,gv,ansi,ansv) {ll lo = lo_val, hi = hi_val, m1, m2;const int diffrange = 7;while (hi - lo > diffrange) {m1 = lo + (hi - lo) / 3;m2 = hi - (hi - lo) / 3;if (gv(m1) < gv(m2)) {    lo = m1;} else {    hi = m2;}}ansi = lo;ansv = gv(lo);for (int i = lo + 1; i <= hi; ++i) {if (a_max(ansv, gv(i))) {    ansi = i;}}}
#define ternint_lo(lo_val,hi_val,gv,ansi,ansv) {ll lo = lo_val, hi = hi_val, m1, m2;const int diffrange = 7;while (hi - lo > diffrange) {m1 = lo + (hi - lo) / 3;m2 = hi - (hi - lo) / 3;if (gv(m1) > gv(m2)) {    lo = m1;} else {    hi = m2;}}ansi = lo;ansv = gv(lo);for (int i = lo + 1; i <= hi; ++i) {if (a_min(ansv, gv(i))) {    ansi = i;}}}
#define terndouble_hi(lo_val,hi_val,gv,ansi,ansv) {double lo = lo_val, hi = hi_val, m1, m2;const double eps = 1e-9; while (hi - lo > eps) {m1 = lo + (hi - lo) / 3;m2 = hi - (hi - lo) / 3;if (gv(m1) < gv(m2)) {lo = m1;} else {hi = m2;}}double ansi = lo;double ansv = gv(lo);}
#define terndouble_lo(lo_val,hi_val,gv,ansi,ansv) {double lo = lo_val, hi = hi_val, m1, m2;const double eps = 1e-9; while (hi - lo > eps) {m1 = lo + (hi - lo) / 3;m2 = hi - (hi - lo) / 3;if (gv(m1) > gv(m2)) {lo = m1;} else {hi = m2;}}double ansi = lo;double ansv = gv(lo);}


template <typename T>
bool a_min(T& a, const T& b){return (b < a) ? (a = b), 1 : 0;}


template <typename T>
bool a_max(T& a, const T& b){return (b > a) ? (a = b), 1 : 0;}


ll ceil(ll m, ll n){return (m + n - 1) / n;}




ll gv(int i, int j, vector<ll>& pre){if (i > j || (j < 0)) {return 0LL;}ll val = pre[j];if (i - 1 >= 0) {val -= pre[i - 1];}return val;}


ll gpv(int i, vector<ll>& pre){return gv(0, i, pre);}


ll gsv(int i, vector<ll>& suf){int n = suf.size();if (i >= n) {return 0LL;}return suf[i];}


void a_pre(vector<ll>& pre, vector<ll>& A){int n = A.size();for (int i = 0; i < n; ++i) {pre[i] = A[i];if (i) {pre[i] += pre[i - 1];}}}


void a_suf(vector<ll>& suf, vector<ll>& A){int n = A.size();for (int i = n - 1; i >= 0; --i) {suf[i] = A[i];if (i + 1 < n) {suf[i] += suf[i + 1];}}}


template <typename T> 
int sorted_r (const vector<T>& A , int l , int r){int n = A.size(); if (r < l){return 0 ;}return ubi(A,r) - ubi(A,l-1); }


template <typename T>
void r_dup(vector<T>& v){sort(all(v));v.erase(unique(all(v)), v.end());}


constexpr int ppcnt(int x){return __builtin_popcount(x);}
constexpr int ppcnt(ll x){return __builtin_popcountll(x);}


constexpr int f_lg(int x){return 31 - __builtin_clz(x);}
constexpr int f_lg(ll x){return 63 - __builtin_clzll(x);}





#ifdef zxcv_1
auto start = std::chrono::system_clock::now();
#endif



const ld PI = acos((ld)-1);
const ll inf = 2e18;
const ll ninf = -2e18; 

const int M = 1e9 + 7;





bool code_jam = 0; 

bool multiple_test_cases =  0; 












class bittree {

public:
    int n_;
    int n;

    vector<ll> bit; 

    vector<ll> bit2; 


    int L;

    bittree(int n_)
    {
        this->n_ = n_;
        n = n_ + 10;
        bit = vector<ll>(n);
        bit2 = vector<ll>(n);
        L = f_lg(n);
    }

    void update(int i, ll x)
    {

        if (i < 0) {
            return;
        }

        ++i;
        while (i < (int)bit.size()) {
            bit[i] += x;

            bit2[i] += (x > 0 ? 1 : -1);

            i += i & -i;
        }
    }

    ll pre(int i)
    {

        if (i < 0) {
            return 0LL;
        }

        ++i;
        ll tot = 0;
        while (i > 0) {
            tot += bit[i];
            i -= i & -i;
        }
        return tot;
    }

    ll range(int i, int j)
    {

        if (j < i) {
            return 0LL;
        }

        return pre(j) - pre(i - 1);
    }

    ll getval(int i)
    {

        return range(i, i);
    }

    


    


    int find(int tar)
    {

        ++tar;

        if (tar == 0) {
            

            assert(false);
        }

        int pos = 0;

        int rem = tar;
        for (int i = L; i >= 0; --i) {

            if ((pos + (1 << i) < (n)) && bit[pos + (1 << i)] < rem) {
                rem -= bit[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        if (pos >= n_) {
            assert(false);
        }

        return pos;
    }

    int find2(int tar)
    {

        ++tar;

        dbg(tar);

        if (tar == 0) {
            

            assert(false);
        }

        int pos = 0;

        int rem = tar;
        for (int i = L; i >= 0; --i) {

            if ((pos + (1 << i) < (n)) && bit2[pos + (1 << i)] < rem) {
                rem -= bit2[pos + (1 << i)];
                pos += (1 << i);
            }
        }

        if (pos >= n_) {
            assert(false);
        }

        return pos;
    }

    

    


    void update_r(int i, int j, ll x)
    {

        update(i, x);
        update(j + 1, -x);
    }

    ll getval_r(int i)
    {

        return pre(i);
    }
};





void solve(){

    int n , q;  

    cin >> n  >> q; 

    bittree bit(n); 

    vector<int> L(n);  vector<vector<int>> R_qind(n); 

    vector<int> A(n); 

    read(A); 

    a_offset(A); 
    
    for(int i = 0; i  < n; ++i){
        
        A[i] =  i -  A[i]; 
    }


    int l , r; 
    for(int i = 0 ; i < q; ++i){
        cin >>  l >> r; 


        r = n- r - 1 ;
        

        R_qind[r].push_back(i); 
        L[i] =  l; 
    }






    ll tar; 
    auto valid = [&](ll  mid){

        return bit.getval_r(mid) >=  tar; 
    }; 


    vector<int> ans (q, -1); 

    dbg(A);

    for(int i = 0;  i < n ; ++i){

        tar =  A[i]; 

        if(tar >= 0){


            int ansi = -1; 

            lsttrue(0 , i , valid, ansi); 

            dbg(i, tar, ansi);

            


            if (ansi != -1){
                bit.update_r(0 , ansi ,  1); 
            }

        }


        for(int q_ind : R_qind[i]){
            ans[q_ind] =  bit.getval_r(L[q_ind]); 
        }
        


    }

    for(int i : ans){
        cout << i << "\n"; 
    }



    












}




int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    

    int T = 1 ;

    if (code_jam){
        multiple_test_cases =  true; 
    }

    if(multiple_test_cases){
        cin >> T;
    }


    for (int t = 1; t <= T; ++t) {
        if(t == 1){
            #ifdef zxcv_1
                start = std::chrono::system_clock::now();
            #endif
        }
        if(code_jam)
            cout << "Case #" << t << ": ";
        solve();
    }


    #ifdef zxcv_1
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cerr << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    #endif


    

    return 0;
}
