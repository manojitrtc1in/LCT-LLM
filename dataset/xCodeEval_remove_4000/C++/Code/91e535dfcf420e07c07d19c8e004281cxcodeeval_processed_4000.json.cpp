

using namespace std;






























template <typename A, typename B>
string to_string(pair<A, B> p);
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
void a_offset(T& A, int off = -1){for (auto& x : A) {x += off;}}
template <class H, class... T>
void read(H& h, T&... t){read(h);read(t...);}






template <typename T>  
void out (T &A, int offset = 0 ){for(auto &x : A){x += offset; cout <<  x <<" ";}cout <<"\n"; }












template <typename T>
bool a_min(T& a, const T& b){return (b < a) ? (a = b), 1 : 0;}


template <typename T>
bool a_max(T& a, const T& b){return (b > a) ? (a = b), 1 : 0;}


ll ceil(ll m, ll n){return (m + n - 1) / n;}




ll gv(int i, int j, vector<ll>& pre){if (i > j || (j < 0)) {return 0LL;}ll val = pre[j];if (i - 1 >= 0) {val -= pre[i - 1];}return val;}


ll gpv(int i, vector<ll>& pre){return gv(0, i, pre);}


ll gsv(int i, vector<ll>& suf){int n = suf.size();if (i >= n) {return 0LL;}return suf[i];}


void a_pre(vector<ll>& pre, vector<ll>& A){int n = A.size();for (int i = 0; i < n; ++i) {pre[i] = A[i];if (i) {pre[i] += pre[i - 1];}}}


void id2(vector<ll>& suf, vector<ll>& A){int n = A.size();for (int i = n - 1; i >= 0; --i) {suf[i] = A[i];if (i + 1 < n) {suf[i] += suf[i + 1];}}}


template <typename T> 
int sorted_r (const vector<T>& A , int l , int r){int n = A.size(); if (r < l){return 0 ;}return ubi(A,r) - ubi(A,l-1); }


template <typename T>
void r_dup(vector<T>& v){sort(all(v));v.erase(unique(all(v)), v.end());}


constexpr int ppcnt(int x){return __builtin_popcount(x);}
constexpr int ppcnt(ll x){return __builtin_popcountll(x);}


constexpr int id1(int x){return 31 - __builtin_clz(x);}
constexpr int id1(ll x){return 63 - __builtin_clzll(x);}






auto start = std::chrono::system_clock::now();




const ld PI = acos((ld)-1);
const ll inf = 2e18;
const ll ninf = -2e18; 

const int M = 1e9 + 7;





bool id3 = 0; 

bool id0 =  0; 









const int N = 2e5 + 5 ;

int dp[N][2]; 


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


ll binpow(ll a, ll b){

    a %= M; 

    ll res = 1 ;

    while(b > 0){

        if (b & 1){
            res = res * a % M;
        }

        a = a * a % M; 

        b >>= 1;
    }

    return res;
}



ll binv(ll x){
    return binpow(x , M - 2);
}


ll divide (ll x, ll y){
    x %= M ;
    y %= M ;

    

    return mul(x,  einv(y));
}


int C(int n , int k){

    return divide(fact[n] , mul(fact[k] , fact[n-k])); 
}


int col[N]; 

int get_one (vector<int>& childs){

    int ans = 1 ;
    
    int  n = sz(childs); 

    vector<vector<int>> dp2 (n + 1 , vector<int>(2)); 

    dp2[0][0] = 1; 
    dp2[0][1] = 0 ;

    for(int i = 1 ; i <= n; ++i){
        int c = childs[i - 1]; 
        dp2[i][0] = mul(dp2[i - 1][0] , add(dp[c][0], dp[c][1])); 
        dp2[i][1] = mul(dp2[i - 1 ][0] , dp[c][1]); 
        dp2[i][1] = add(dp2[i][1] , mul(dp2[i-1][1] , add(dp[c][0] , dp[c][1])));
        dbg(c, dp[c][0], dp[c][1]); 
        dbg(dp2[i][0]  , dp2[i][1]) ;
    }

    return dp2[n][1] ;
}

void dfs(int i , int p , vector<vector<ar<int,2>>>& adj){

    int prod = 1 ; 
    vector<int> childs; 
    for(auto j : adj[i]){
        if (j[0] == p){
            continue; 
        }
        dfs(j[0] , i , adj); 
        prod = mul(prod , add(dp[j[0]][0] , dp[j[0]][1]) ); 
        childs.push_back(j[0]); 
    }

    if (col[i]){
        dp[i][0] = 0 ;
        dp[i][1] =  prod;
        dbg(i, dp[i][0], dp[i][1]);
        return; 
    }

    dp[i][0] = prod; 

    dp[i][1] = get_one(childs); 

    dbg(i , dp[i][0] , dp[i][1]);


    

    

    

    


    

    


}


void solve(){

    int n ; 
    cin >> n ;

    vector<vector<ar<int,2>>> adj (n); 

    int v ; 
    for(int i = 1 ; i <=  n -1 ; ++i){
        cin >> v; 
        adj[i].push_back({v,0}); 
        adj[v].push_back({i,0}); 
    }

    for(int i = 0 ;i  < n ; ++i){
        cin >>  col[i]; 
    }

    dfs(0 , -1, adj); 
    cout << dp[0][1] << "\n";







}




int main()
{

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
