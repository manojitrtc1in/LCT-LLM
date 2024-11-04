
using namespace std;





























typedef long long ll;
typedef double db;
typedef unsigned uint;
typedef unsigned long long ull;
typedef unordered_map<int, int> umapII;


typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<VVB> VVVB;
typedef vector<umapII> VumapII;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<VVLL> VVVLL;
typedef vector<VVVLL> VVVVLL;
typedef vector<db> VD;
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
typedef vector<VVVI> VVVVI;
typedef vector<VVVVI> VVVVVI;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 

int id3(string&a) {
    stringstream x(a);
    int b;
    x >> b;
    return b;
}
void readI(int& a) {
    cin >> a;
}
void readI(int& a, int&b) {
    cin >> a >> b;
}
void readI(int& a, int&b, int&c) {
    cin >> a >> b >> c;
}
VI readVI(int n) {
    VI a(n);
    REP(i, n) cin >> a[i];
    return a;
}
VVI id2(int n, int m) {
    VVI a(n, VI(m));
    REP(i, n) a[i] = readVI(m);
    return a;
}
VLL id4(ll n) {
    VLL a(n);
    REP(i, n) cin >> a[i];
    return a;
}
VVLL id0(ll n, ll m) {
    VVLL a(n, VLL(m));
    REP(i, n) a[i] = id4(m);
    return a;
}

void print(VI& a) {
    for (auto el : a) {
        cout << el << ' ';
    }
    cout << '\n';
}

void print(VI& a, int n) {
    int cnt = 0;
    for (auto el : a) {
        if (cnt++ == n) break;
        cout << el << ' ';
    }
    cout << '\n';
}
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll INFF = id1;
const db EPS = 1e-9;
const db PI = acos(-1.0); 

const int moveX[] = {-1, 0, 1, 0};
const int moveY[] = {0, 1, 0, -1};























































































































      


























void findWeight(int par, int cur, VI&weights, VVI&paths, VI&pars) {
    int curAns = 0;
    pars[cur] = par;
    for (auto el : paths[cur]) {
        if (el == par) continue;
        findWeight(cur, el, weights, paths, pars);
        curAns += weights[el];
    }
    weights[cur] = curAns + 1;
}
int checkMax(int cur, VI&weights, VVI&paths, VI&pars) {
    int maxi = weights[1] - weights[cur];
    for (auto el : paths[cur]) {
        if (el == pars[cur]) continue;
        maxi = max(maxi, weights[el]);
    }
    return maxi;
}
void go () {
    int n, a, b, x, y;
    cin >> n;
    VVI paths(n + 5);
    VI weights(n + 5, 0), pars(n + 5, 0);
    REP(i, n - 1) {
        cin >> a >> b;
        x = a;
        y = b;
        paths[a].pb(b);
        paths[b].pb(a);
    }
    findWeight(0, 1, weights, paths, pars);
    VVI centroid(n + 5);
    int maxi = n;
    REP1(i, n + 1) {
        int curIdx = checkMax(i, weights, paths, pars);
        maxi = min(maxi, curIdx);
        centroid[curIdx].pb(i);
    }
    if (centroid[maxi].size() > 1) {
        a = centroid[maxi][0];
        b = centroid[maxi][1];
        if (centroid[maxi].size() > 2) {
            while(1) {
                a = a + 1;
            }
        }
        VB vis(n + 5, 0);
        queue <int> bfs;
        int x;
        swap(a, b);
        bfs.push(a);
        while(!bfs.empty()) {
            int cur = bfs.front();
            bfs.pop();
            if (vis[cur] || cur == b) continue;
            

            vis[cur] = 1;
            x = cur;
            if (paths[x].size() == 1) {
                cout << x << ' ' << paths[x][0] << '\n';
                cout << b << ' ' << x << '\n';
                return;
            }
            for (auto el : paths[cur]) {
                bfs.push(el);
            }
        }
        REP(i, n + 5) vis[i] = 0;
        swap(a, b);
        bfs.push(a);
        while(!bfs.empty()) {
            int cur = bfs.front();
            bfs.pop();
            if (vis[cur] || cur == b) continue;
            

            vis[cur] = 1;
            x = cur;
            if (paths[x].size() == 1) {
                cout << x << ' ' << paths[x][0] << '\n';
                cout << b << ' ' << x << '\n';
                return;
            }
            for (auto el : paths[cur]) {
                bfs.push(el);
            }
        }
        while(1) {
            a = a + 1;
        }
    } else {
        cout << x << ' ' << y << '\n';
        cout << x << ' ' << y << '\n';
        

    }
}



signed main () {



    freopen("in.txt", "r", stdin);



    _upgrade
    int T = 1;
    cin >> T;
    while(T--) go();
    return 0;
}

