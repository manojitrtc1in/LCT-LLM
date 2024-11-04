

using namespace std;































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












using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename key, typename value, typename cmp = std::less<key>>
using omap = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;












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
void assign_offset(T& A, int off = -1){for (auto& x : A) {x += off;}}
template <class H, class... T>
void read(H& h, T&... t){read(h);read(t...);}






template <typename T>  
void out (T &A, int offset = 0 ){for(auto &x : A){x += offset; cout <<  x <<" ";}cout <<"\n"; }












mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());ll rand_m(ll a, ll b){return uniform_int_distribution<ll>(a, b)(mt_rng);}


template <typename T>
bool a_min(T& a, const T& b){return (b < a) ? (a = b), 1 : 0;}


template <typename T>
bool a_max(T& a, const T& b){return (b > a) ? (a = b), 1 : 0;}


ll ceil(ll m, ll n){return (m + n - 1) / n;}




template<typename T> 
ll gv(int i, int j, vector<T>& pre){if (i > j || (j < 0)) {return 0LL;}ll val = pre[j];if (i - 1 >= 0) {val -= pre[i - 1];}return val;}


template <typename T> 
ll gpv(int i, vector<T>& pre){return gv(0, i, pre);}


template <typename T> 
ll gsv(int i, vector<T>& suf){int n = sz(suf);if (i >= n) {return 0LL;}return suf[i];}


template<typename T> 
void assign_pre(vector<T>& pre, vector<T>& A){int n = sz(A);for (int i = 0; i < n; ++i) {pre[i] = A[i];if (i) {pre[i] += pre[i - 1];}}}


template<typename T> 
void id2(vector<T>& suf, vector<T>& A){int n = sz(A);for (int i = n - 1; i >= 0; --i) {suf[i] = A[i];if (i + 1 < n) {suf[i] += suf[i + 1];}}}


template <typename T> 
int sorted_range (const vector<T>& A , int l , int r){int n = A.size(); if (r < l){return 0 ;}return ubi(A,r) - ubi(A,l-1); }


template <typename T>
void remove_dup(vector<T>& v){sort(all(v));v.erase(unique(all(v)), v.end());}


constexpr int ppcnt(int x){return __builtin_popcount(x);}
constexpr int ppcnt(ll x){return __builtin_popcountll(x);}


constexpr int id3(int x){return 31 - __builtin_clz(x);}
constexpr int id3(ll x){return 63 - __builtin_clzll(x);}






auto start = std::chrono::system_clock::now();






const ld PI = acos((ld)-1);
const ll inf = 2e18;
const ll ninf = -2e18; 

const int M = 1e9 + 7;









bool id4 = 0; 

bool id1 =  0; 












class stree {

    struct snode
    {

        ll val;

        ll delta;

        snode(ll x)
        {
            val = x;
            delta = 0;
        }

        ll getVal()
        {
            return val + delta;
        }
    };

public : 

    vector<ll> L , R , A  ;
    vector<snode> ST ;  

    int n ; 
    stree (vector<ll>& a ){
        A = a; 
        n = a.size(); 
        L.resize(4*n); 
        R.resize(4*n); 
        ST = vector<snode> (4*n , snode(1e18)); 
        init(1 , 0 , n - 1);
    }


    void init (int i , int l , int r){
        
        L[i] = l ;
        R[i] = r; 

        if (l == r){
            ST[i] = snode(A[l]); 
            return; 
        }

        ll mid = (l + r)/ 2; 
        init(2*i , l , mid); 
        init(2*i + 1 , mid + 1 , r);

        merge(i); 


    }

    void propogate (int i ){

        ST[2*i].delta += ST[i].delta; 
        ST[2*i + 1].delta += ST[i].delta; 
    }
    void merge (int i ){

        ST[i].val = min(ST[2*i].getVal() , ST[2*i +1].getVal());
        ST[i].delta = 0 ;
    }
    void update (int i , int l , int r, ll x){
        if (R[i] < l || r < L[i]){
            return; 
        }

        if (l <= L[i] && R[i] <= r){
            ST[i].delta +=  x; 
            return ;
        }

        propogate(i); 
        update(2*i , l , r, x);
        update(2*i + 1 , l , r, x);  
        merge(i); 
    }

    void update(int l , int r , ll x){
        update(1 , l , r , x);
    }

    ll getval (int i , int l , int r){

        if (R[i] < l || r < L[i] ){
            return 1e18 ;
        }

        if (l <= L[i] && R[i] <= r){
            return ST[i].getVal(); 
        }

        propogate(i); 

        ll left  = getval(2* i , l , r); 
        ll right = getval(2 * i + 1 , l, r); 

        merge(i); 

        return min(left , right); 

    }

    ll getval(int l , int r){
        return getval(1 , l , r); 
    }

    ll findminind (int i , ll x ){

        if (L[i] == R[i]){
            return L[i]; 
        }

        if (getval(2*i , L[2*i] , R[2*i] ) == x){
            return findminind (2 * i , x); 
        }

        return  findminind(2*i + 1,x); 

    }

    ll findminind(ll x){
        return findminind(1 , x); 
    }

    

    ll findind (int i , ll x){
        
        



        if (L[i] == R[i] ){
            
            if (ST[i].getVal() == x){
                return L[i]; 
            }
            assert(false);             
            return -1; 
        }

        propogate(i); 

        merge(i); 

        ll lt =  ST[2*i].getVal(); 

        

        if (lt <= x){
            return findind(2*i, x); 
        }

        return findind(2*i + 1 , x); 

    }
    ll findind (ll x){
        return findind(1 , x); 
    }


};





class id0 {

    struct snode
    {

        ll val;

        ll delta;

        snode(ll x)
        {
            val = x;
            delta = 0;
        }

        ll getVal(ll L, ll R)
        {
            return val + (R - L + 1) * delta;
        }
    };

public : 

    vector<ll> L , R , A  ;
    vector<snode> ST ;  

    int n ; 
    id0 (vector<ll>& a ){
        A = a; 
        n = a.size(); 
        L.resize(4*n); 
        R.resize(4*n); 
        ST = vector<snode> (4*n , snode(0)); 
        init(1 , 0 , n - 1);
    }


    void init (int i , int l , int r){
        
        L[i] = l ;
        R[i] = r; 

        if (l == r){
            ST[i] = snode(A[l]); 
            return; 
        }

        ll mid = (l + r)/ 2; 
        init(2*i , l , mid); 
        init(2*i + 1 , mid + 1 , r);

        merge(i); 


    }

    void propogate (int i ){
        ST[2*i].delta += ST[i].delta; 
        ST[2*i + 1].delta += ST[i].delta; 
    }

    void merge (int i ){

        ST[i].val = ST[2*i].getVal(L[2*i], R[2*i]) +  ST[2*i + 1].getVal(L[2*i + 1], R[2*i + 1]);  
        ST[i].delta = 0 ;
    }


    void update (int i , int l , int r, ll x){
        if (R[i] < l || r < L[i]){
            return; 
        }

        if (l <= L[i] && R[i] <= r){
            ST[i].delta +=  x; 
            return ;
        }

        propogate(i); 
        update(2*i , l , r, x);
        update(2*i + 1 , l , r, x);  
        merge(i); 
    }

    void update(int l , int r , ll x){
        update(1 , l , r , x);
    }

    ll getval (int i , int l , int r){
        

        if (R[i] < l || r < L[i] ){
            return 0 ;
        }

        if (l <= L[i] && R[i] <= r){
            return ST[i].getVal(L[i], R[i]); 
        }

        propogate(i); 

        ll left  = getval(2* i , l , r); 
        ll right = getval(2 * i + 1 , l, r); 

        merge(i); 

        return left + right ;  

    }

    ll getval(int l , int r){
        return getval(1 , l , r); 
    }


};




void solve(){

    int n ; 
    cin >> n  ;

    string s; 
    cin >> s; 


    vector<ll> A (n);

    stree st_m (A);

    id0 st_a (A); 


    ll ans = 0; 

    vector<int>  ones(n); 



    for(int i = 0 ; i < n ;++i){

        if (s[i] == '0'){
            ans +=  st_a.getval(0 , n -1); 
            ones[i] = 0; 
            continue; 
        }

        if (i){
            ones[i] =  ones[i - 1] + 1; 
        }
        else{
            ones[i] = 1; 
        }

    
        int ind =  st_m.findind(ones[i] - 1);   

        
        st_a.update(ind, i , 1);
        st_m.update(ind , i, 1); 

        dbg(ones[i] - 1 , ind, i, st_a.getval(0 , n -1)); 

        ans +=  st_a.getval(0,  n -1); 

        dbg(st_m.ST[8].getVal(), st_m.L[8] , st_m.R[8]); 

        
    }

    cout << ans <<"\n";




    









}




int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    

    int T = 1 ;

    if (id4){
        id1 =  true; 
    }

    if(id1){
        cin >> T;
    }


    for (int t = 1; t <= T; ++t) {
        if(t == 1){
            
                start = std::chrono::system_clock::now();
            
        }
        if(id4)
            cout << "Case 
        solve();
    }


    
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cerr << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    


    

    return 0;
}


