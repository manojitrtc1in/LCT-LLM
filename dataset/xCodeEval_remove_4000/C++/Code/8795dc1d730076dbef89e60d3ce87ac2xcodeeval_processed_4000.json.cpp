
   








   

   


 








































































































 






 
using namespace std;
using namespace __gnu_pbds;
   

























   
typedef pair < int, int > pii;
typedef pair < char, int > pci;
typedef pair < pii, int > ppii;
typedef pair < ll, ll > pll;
typedef pair < ull, ull > puu;
typedef pair < int, string > pis;
typedef pair < string, int > psi;
typedef map < int, int > mii;
typedef map < int, int > mii;
typedef map < int, char > mic;
typedef map < string, int > msi;
typedef map < string, string > mss;
typedef map < char, int > mci;
typedef map < char, ll > mcl;
typedef map < ll, ll > mll;
typedef map < pii, int > mpii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < char > vc;
typedef vector < ll > vll;
typedef vector < pii > vpii;
typedef vector < pll > vpll;
typedef vector < pis > vpis;
typedef map < int, vpii > mivpi;
typedef set < int > si;
typedef set < char > sc;
typedef set < ll > sll;
typedef set< pair < ull, ull > > spuu;
typedef set< pii > spii;
typedef priority_queue< ll > pqll;
   
const int N = 1e6+7;
const int M = 60;
const int MAXK = 1e5+3;
const int Candy = 1e6+3;


const int mod = 998244353;


const ll INF = 1e18;
const double PI = 3.1415926535897932384626433;
const ld EPS = 1e-12;
   
   
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
   
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
   
char getChar() { char c = 0; while (c <= ' ') cin >> c; return c; }
   
inline ll fast_pow(ll a, ll b){
    ll res = a, ret = 1;
    while(b>0){
        if(b%2)
            ret = (ret*res)%mod;
        res = (res*res)%mod;
        b/=2;
    }
    return ret;
}
   
inline ll fact(ll n){
    int f = 1;
    forl(i, 2, n) f = f * i % mod;
    return f;
}
   
 
 
   
inline ll factmod(ll n, ll p) {
    ll res = 1;
    while(n > 1){
        res = (res * ((n / p) % 2 ? p - 1 : 1)) % p;
        for(ll i = 2; i <= n % p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}
   
inline ll Cnk(ll n, ll r){
    r = min(r, n - r);
    ll ans = 1;
    ford(i, n, n - r + 1) ans = (ans * i) % mod;
    forl(i, 1, r) ans = (ans * fast_pow(i, mod - 2)) % mod;
    return ans;
}

int t;
string s;

int main(){
    SpeedForce
    cin >> t;
    while(t--){
        cin >> s;
        int id = 0;
        int n = sz(s);
        while(s[id] == s[n - id - 1] && id <= n / 2) id++;
        if(id > n / 2){
            id--;
            string str = s.substr(0, id);
            cout << str;
            if(n & 1) cout << s[id];
            reverse(all(str));
            cout << str << '\n';
            continue;
        }
        string t = s.substr(id, n - 2 * id), g = t;
        reverse(all(g));
        n = sz(t);
        
        __int128 P = 31; 
        __int128 h[n + 1], deg[n + 1];
        h[0] = 0, deg[0] = 1;
        for (int i = 0; i < n; i++) {
            h[i + 1] = h[i] * P + t[i] - 'a';
            deg[i + 1] = deg[i] * P;
        }
        auto get_hash = [&]( int l, int r ){ 

            return h[r + 1] - h[l] * deg[r - l + 1];
        };
        __int128 h1[n + 1], deg1[n + 1];
        h1[0] = 0, deg1[0] = 1;
        for (int i = 0; i < n; i++) {
            h1[i + 1] = h1[i] * P + g[i] - 'a';
            deg1[i + 1] = deg1[i] * P;
        }
        auto id0 = [&]( int l, int r ){ 

            return h1[r + 1] - h1[l] * deg1[r - l + 1];
        };
        
        int le = 0;
        string mx = "";
        
        for(int i = 0; i < n; i++){
            if(get_hash(0, i) == id0(n - i - 1, n - 1) && i + 1 > le) le = i + 1;
        }
        
        mx = t.substr(0, le);
        
        for(int i = 0; i < n; i++){
            if(id0(0, i) == get_hash(n - i - 1, n - 1) && i + 1 > le) le = i + 1;
        }
        
        if(sz(mx) < le){
            mx = g.substr(0, le);
        }
        string str = s.substr(0, id);
        cout << str + mx;
        reverse(all(str));
        cout << str << '\n';
    }
    return (!false && !true) || ((ll)((ll)(1713 + 2377 + 1464) * (ll)(1713 + 2377 + 1464) * (ll)(1713 + 2377 + 1464)) != (ll)(171323771464));
}