




























using namespace std;
typedef long long ll;
using vi = vector<int>;
using pii = pair<ll, ll>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;


int dxtra(int n, vvpii& g, int start, int finish, vi& dist) {
    

    vector<bool>used(n + 1, 0);
    set<pair<int, int>>s;
    dist[start] = 0;
    s.insert({ 0, start });
    while (s.size() > 0) {
        auto it = *s.begin();
        int len = it.first;
        int v = it.second;
        s.erase(*s.begin());
        used[v] = 1;
        for (auto to : g[v]) {
            s.erase({ dist[to.first], to.first });
            dist[to.first] = min(dist[to.first], len + to.second);
            if(!used[to.first])s.insert({dist[to.first], to.first});
        }
    }
    if (dist[finish] == INT_MAX) return -1;
    return dist[finish];
}
int xin() {
    int n;
    cin >> n;
    

    return n;
}
void masIn(int n, int* a) {
    for (int i = 0; i < n; i++) { *a = xin(); a++; }
}
void masIn(vi& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) { a[i] = xin(); }
}


void grafIn(int n, int m, vvpii& g) {
    for (int ix = 0; ix < m; ix++) {
        

        int a, b;
        cin >> a >> b;
        g[a].push_back({b, 1});
        g[b].push_back({a, 1});
    }
}
bool par(vvpii& g, int i, int j) {
    for (auto o : g[i]) if (o.first == j) return true;
    return false;
}
void solve() {
    int res = 0;
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    vvpii g(n + 1);
    grafIn(n, m, g);
    vi distS(n + 1, INT_MAX);
    vi distF(n + 1, INT_MAX);
    

    

    
    int optDist = distS[f];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!par(g, i, j)) {
                if (distS[i] + distF[j] + 1 >= optDist && distS[j] + distF[i] + 1 >= optDist) {
                    res++;
                    

                }
            }
        }
    }
    cout << res;
}
bool id0() {
    string s; cin >> s;
    char c; cin >> c;
    for (int i = 0; i < s.size(); i += 2) if (s[i] == c) { cout << "YES\n"; return 0; }
    cout << "NO\n";
}
struct trip {
    int a;
    int b;
    int c;
};
int32_t main()
{
    int t = xin();
    

    

    while (t--) id0();
}



































