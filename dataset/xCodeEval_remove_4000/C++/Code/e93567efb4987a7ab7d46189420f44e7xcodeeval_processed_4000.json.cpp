
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
 































































































































































signed main () {


    freopen("in.txt", "r", stdin);
	


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




