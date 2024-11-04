
   








   

   


 








































































































 






 
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

int t, ans[N * 2];
string s;

int solve(string s){
    string t = s;
    reverse(t.begin(), t.end());
    string r = s + "." + t;
    for (int i = 1; i < sz(r); i++){
        int last = ans[i - 1];
        while(last > 0 && r[i] != r[last]){
            last = ans[last - 1];
        }
        ans[i] = last + (r[i] == r[last] ? 1 : 0);
    }
    return ans[sz(r) - 1];
}

int main(){
    SpeedForce
    cin >> t;
    while(t--){
        cin >> s;
        string a = "", b = "";
        int l = 0, r = sz(s) - 1;
        while(l < r){
            if(s[l] == s[r]) l++, r--;
            else break;
        }
        a = s.substr(0, l);
        b = a;
        reverse(all(b));
        int x = 0, y = 0;
        string str = "";
        for(int i = l; i <= r; i++){
            str += s[i];
        }
        x = solve(str);
        reverse(all(str));
        y = solve(str);
        if(x > y){
            a += s.substr(l, x);
        }
        else{
            for(int i = r - y + 1; i <= r; i++) a += s[i];
        }
        cout << a + b << '\n';
    }
    return (!false && !true) || ((ll)((ll)(1713 + 2377 + 1464) * (ll)(1713 + 2377 + 1464) * (ll)(1713 + 2377 + 1464)) != (ll)(171323771464));
}