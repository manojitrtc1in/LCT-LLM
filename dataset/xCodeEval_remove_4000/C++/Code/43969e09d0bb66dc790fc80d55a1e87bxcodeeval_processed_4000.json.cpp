

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
void a_offset(T& A, int off = -1){for (auto& x : A) {x += off;}}
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





bool id4 = 0; 

bool id0 =  0; 









const int PN = 1e5 + 10; 

vector<bool> is_prime (PN+ 1 , true); 

void preprocess (){

    int n= PN; 
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}







void solve(){


    preprocess();



    int n ; 
    cin >> n  ;

    int ans= 1 ;

    vector<int> id3,  id5; 

    int killed = 0 ;

    for(int i = 2, en =  min(n, 317) ; i <= en; ++i){
        if (is_prime[i]){
            id3.push_back(i); 
        }
    }
    

    for(int i = 318  ; i <= n; ++i){
        if (is_prime[i]){
    
            id5.push_back(i); 
        }
    }


    int op = 0; 

    bool f = false; 

    
    for(int p : id3){
        int mul = 1; 
        while(true) {
            if (mul *p > n){
                break; 
            }
            int rem1 , rem2  ; 
           
            
            cout << "B "<< (mul * p) <<endl; 
            cin >> rem1 ; 
            cout << "A "<< (mul * p) <<endl;
            op += 2; 
            
            cin >> rem2;
            
            killed +=  rem1 - rem2 ; 



            if(rem2){
                mul *= p; 
            }
            else{
                break; 
            } 

        }
        ans *= mul; 
        

    }


    dbg(ans, killed); 



    int cnt = 0;
    int block_sz  = 100; 

    int rem; 

    bool found = false; 

    while(cnt < sz(id5) && !found){

        
        cout << "B "<< id5[cnt] << endl; 
        cin >> rem; 
        killed += rem; 
        


        if (((cnt % block_sz ) == block_sz - 1) || (cnt == sz(id5) - 1)){
            
            int rem2 ;
            cout << "A "<< 1 << endl; 
            cin >> rem2;
            int alive_d = n -  killed ; 

            bool good = (rem2  == (alive_d + 1));
            if (good ){
                
            
                int en = cnt; 

                int st =  (cnt/block_sz) * block_sz; 
                

                for(int i = st; i <= en; ++i){
                    cout << "A "<< id5[i] << endl; 
                    cin >> rem; 
                    assert(rem <= 1); 
                    if (rem){
                        ans *=  id5[i];
                        found = true;
                        break; 
                    } 
                }

                assert(found);
           


            }

            

            

            

        }


        ++cnt; 
    }

    cout << "C " << ans << endl ; return; 

    





    

    








}




int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    

    int T = 1 ;

    if (id4){
        id0 =  true; 
    }

    if(id0){
        cin >> T;
    }


    for (int t = 1; t <= T; ++t) {
        if(t == 1){
            

            

            

        }
        if(id4)
            cout << "Case 
        solve();
    }


    

    

    

    

    



    

    return 0;
}


