#include <bits/stdc++.h>


using namespace std;


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
 

































































































































VVI paths(2e5 + 5);
VI dist(2e5 + 5), fromSt(2e5 + 5), fromParent(2e5 + 5), par(2e5 + 5);
int cnt = 0;
void travel(int pos) {
    fromSt[pos] = ++cnt;
    for (auto next : paths[pos]) {
        if (par[pos] == next) continue;
        dist[next] = dist[pos] + 1;
        par[next] = pos;
        travel(next);
    }
    fromParent[pos] = ++cnt;
}
bool check(int a, int b) {
    

    return fromSt[b] >= fromSt[a] && fromParent[b] <= fromParent[a];
}
signed main () {
    ios_base::sync_with_stdio(0);
    

    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    REP(i, n - 1) {
        cin >> a >> b;
        a--, b--;
        paths[a].pb(b);
        paths[b].pb(a);
    }
    par[0] = dist[0] = 0;
    travel(0);
    

    

    

    REP(i, m) {
        int end = 0;
        cin >> a;
        VI tmp;
        REP(j, a) {
            cin >> b;
            b--;
            tmp.pb(b);
            if (dist[b] > dist[end]) end = b;
        }
        bool ans = 1;
        

        REP(j, a) {
            if(!check(par[tmp[j]], end)) {
                

                ans = 0;
                break;
            }
        }
        if (ans) cout <<"YES\n";
        else cout << "NO\n";
    }
    return 0;
}


