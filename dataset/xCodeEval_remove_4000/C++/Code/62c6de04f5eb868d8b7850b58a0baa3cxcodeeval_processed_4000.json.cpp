































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



unsigned int fact(int n) {
    unsigned int sum = 1;
    for (int i = 1; i <= n; i++)sum *= i;
    return sum;
}
void solve() {
    int n = xin();
    string s; cin >> s;
    bool f = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        
        
        if (s[i] == '0' && s[i + 1] == '0') res+=2;
        else if (s[i] == '0' && s[i + 1] == '1' && s[i + 2] == '0') res++;
    }
    cout << res<<endl;
}

struct trip {
    int a;
    int b;
    int c;
};
int32_t main()
{
    int t = xin();
    

    

    

    while (t--) solve();
}



































