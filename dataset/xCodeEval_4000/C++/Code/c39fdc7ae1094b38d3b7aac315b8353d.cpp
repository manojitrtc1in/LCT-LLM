#include <bits/stdc++.h>
using namespace std;



#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORB(i, a, b) for (int i = a - 1; i >= b; i--)
#define REP(i, a) for (int i = 0; i < a; i++)
#define REP1(i, a) for (int i = 1; i < a; i++)
#define REPB(i, a) for (int i = a - 1; i >= 0; i--)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define umap unordered_map
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PQ priority_queue
#define Q queue

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
const ll INFF = INT64_MAX;
const d EPS = 1e-9;
const d PI = acos(-1.0); 

const int moveX[] = {-1, 0, 1, 0};
const int moveY[] = {0, 1, 0, -1};


















































































































































void go() {
    ll n, mod, ans = 1, tmp = 1, count = 0;
    cin >> n >> mod;   
    n++;
    while (tmp<<1 <= n) tmp<<=1, count++;
    n-=tmp;
    tmp = 1;
    bool a = 0;
    REP(i, count) {
        ans = ans * (tmp + 1) % mod;
        tmp *= 2;
    }  
    ans = ans * (n + 1) % mod;
    cout << (ans % mod + mod - 1) % mod << '\n';
    return;
}
int main () {

#ifdef ONLINE_JUDGE
#else
    freopen("in.txt", "r", stdin);


#endif
    _upgrade
    int T;
    cin >> T;
    while(T--) go();
    return 0;
}



