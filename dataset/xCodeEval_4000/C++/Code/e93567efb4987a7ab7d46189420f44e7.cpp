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
#define int long long
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
 































































































































































signed main () {
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt", "r", stdin);
	

#endif
    _upgrade
    int n, m, tmp, maxLen = 0;
    cin >> n >> m;
    VI len(m), ans(m);
    REP(i, m) {
        cin >> len[i];
        maxLen += len[i];
    }
    if (maxLen < n) {
        cout << -1 << '\n';
        return 0;
    }
    if (m == 1) {
        cout << 1 << '\n';
        return 0;
    }
    int st = 1, extra = maxLen - n, lastColor = 0;
    REP(i, m - 1) {
        

        if (extra > 0) {
            if (st + len[i] - 1 > n) {
                cout << -1 << '\n';
                return 0;
            }
            ans[i] = st;
            st = max(n - maxLen + 1, st + 1);
            maxLen -= len[i];
            extra = maxLen - n + i + 1;
        } else {
            ans[i] = st;
            st += len[i];
        }
        lastColor = max(lastColor, ans[i] + len[i] - 1);
    }
    

    

    

    if (lastColor + len[m - 1] < n || ans[m - 2] + len[m - 1] > n) {
        cout << -1 << '\n';
        return 0;
    } else {
        ans[m - 1] = n - len[m - 1] + 1;
    }
    REP(i, m) cout << ans[i] << ' ';
    cout << '\n'; 
    return 0;
}




