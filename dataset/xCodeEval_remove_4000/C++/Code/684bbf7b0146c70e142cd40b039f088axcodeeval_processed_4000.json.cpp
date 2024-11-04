
using namespace std;



















typedef long long ll;
typedef double d;
typedef unsigned uint;
typedef unsigned long long ull;
typedef unordered_map<int, int> umapII;


typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<umapII> VumapII;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<d> VD;
typedef set<int> SI;
typedef set<string> SS;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<PII> VPI;
typedef vector<VPI> VVPI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
 
const int MOD = int(1e9) + 7;
const int INF = INT_MAX;
const ll INFF = id0;
const d EPS = 1e-9;
const d PI = acos(-1.0); 

const int moveX[] = {-1, 0, 1, 0};
const int moveY[] = {0, 1, 0, -1};


















































































































































void go() {
    ll n, mod, ans = 1, tmp = 1, count = 0;
    cin >> n >> mod;   
    

    for (int i=0;;i++){
        int cur;
        if (tmp > n) break;
        if ((tmp<<1) <= n) cur = tmp;
        else cur = n - (tmp) + 1;
        tmp<<=1;
        ans = ans * (cur + 1) % mod;
    }
    cout << (ans + mod - 1) % mod << '\n';
    return;
}
int main () {



    freopen("in.txt", "r", stdin);



    _upgrade
    int T;
    cin >> T;
    while(T--) go();
    return 0;
}




