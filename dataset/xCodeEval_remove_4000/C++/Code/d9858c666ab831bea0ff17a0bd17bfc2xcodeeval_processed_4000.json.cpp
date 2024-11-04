

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
void id1(vector<T>& suf, vector<T>& A){int n = sz(A);for (int i = n - 1; i >= 0; --i) {suf[i] = A[i];if (i + 1 < n) {suf[i] += suf[i + 1];}}}


template <typename T> 
int sorted_range (const vector<T>& A , int l , int r){int n = A.size(); if (r < l){return 0 ;}return ubi(A,r) - ubi(A,l-1); }


template <typename T>
void remove_dup(vector<T>& v){sort(all(v));v.erase(unique(all(v)), v.end());}


constexpr int ppcnt(int x){return __builtin_popcount(x);}
constexpr int ppcnt(ll x){return __builtin_popcountll(x);}


constexpr int id2(int x){return 31 - __builtin_clz(x);}
constexpr int id2(ll x){return 63 - __builtin_clzll(x);}






auto start = std::chrono::system_clock::now();






const ld PI = acos((ld)-1);
const ll inf = 2e18;
const ll ninf = -2e18; 



const int M =  998244353;







bool id3 = 0; 

bool id0 =  0; 











const int N = 3e5 + 10;

const int invN = 1500; 

ll ainv[invN]; 

ll fact[N];


int add(int x, int y)
{

    

    
    x += y;
    if (x >= M)
        return x - M;
    return x;
}

int sub(int x, int y)
{

    

    
    x -= y;
    if (x < 0)
        return x + M;
    return x;
}

int mul(int x, int y)
{
    

    
    return ((ll)x * y) % M;
}

void preprocess(){

    ainv[1] = 1 ;

    for(int i = 2 ; i < invN; ++i){
        ainv[i] = M - M/i * ainv[M % i] %M;
    }

    fact[0] = 1 ;

    for(int i = 1 ; i< N;++i){
        fact[i] = mul(fact[i-1],i); 
    }

}


void euclid (ll a, ll b , ll &x , ll &y){

    if(a == 1){

        x = 1 ;
        y = 0 ; 
        return ;
    }

    ll x1 , y1 ;
    euclid(b % a , a , x1 , y1); 

    x = y1 - (b/a) * x1; 

    y = x1; 

}


ll einv (ll b){

    int a= b % M; 

    if (__gcd(a, M) != 1){
        return -1; 
    }

    ll x, y ;

    euclid(a ,M , x,  y);

    x = (x % M + M) % M ;
    return x ;
}

ll bpow(ll a, ll b)
{

    ll res = 1;

    while (b > 0) {

        if (b & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        b >>= 1;
    }

    return res;
}

ll binv(ll x){
    return bpow(x , M - 2);
}


ll divide (ll x, ll y){
    x %= M ;
    y %= M ;

    

    return mul(x,  einv(y));
}


int C(int n , int k){

    if (n  < k || n < 0 || k < 0){
        return 0;
    }

    return divide(fact[n] , mul(fact[k] , fact[n-k])); 
}





void solve(){



    int n ; 
    cin >> n  ;

    n *= 2 ;

    vector<int> A(n);

    read(A); 

    sort(all(A)); 

    int sum = 0; 

    for(int i  = 0 ; i < n ; ++i){
        A[i] %= M ;
        if (i < n/2){
            sum =  sub(sum , A[i]); 
        }
        else{
            sum =  add(sum , A[i]); 
        }

    }

    int ans =  mul(sum, C(n , n/2)); 

    cout << ans <<"\n";









}




int main()
{

    preprocess();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    

    int T = 1 ;

    if (id3){
        id0 =  true; 
    }

    if(id0){
        cin >> T;
    }


    for (int t = 1; t <= T; ++t) {
        if(t == 1){
            
                start = std::chrono::system_clock::now();
            
        }
        if(id3)
            cout << "Case 
        solve();
    }


    
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cerr << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    


    

    return 0;
}
