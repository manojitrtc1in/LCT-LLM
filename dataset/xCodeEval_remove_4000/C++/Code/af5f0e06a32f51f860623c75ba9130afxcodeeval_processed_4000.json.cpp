


























using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;







const ll inf = (ll)1e18 + 7;
ld eps = 1e-9;
ll mod = 1e9 + 7;

const ll b = 31;
const ll m1 = 1e9 + 7;
const ll m2 = 1e9 + 1;

struct hsh {
    vector <pair <ll, ll> > h;
    vector <pair <ll, ll> > p;
    vector <pair <ll, ll> > h1;
    vector <pair <ll, ll> > p1;
    ll n, i, j;
    void build_hsh(string& s) {
        n = s.size();
        h.resize(n + 1);
        p.resize(n + 1);
        p[0] = { 1,1 };
        for (i = 0; i < n; i++) {
            h[i + 1].first = (h[i].first * b + (s[i] - 'a' + 1)) % m1;
            h[i + 1].second = (h[i].second * b + (s[i] - 'a' + 1)) % m2;
            p[i + 1].first = (p[i].first * b) % m1;
            p[i + 1].second = (p[i].second * b) % m2;
        }
    }
    pair <ll, ll> get_h(ll l, ll r) {
        return { (h[r + 1].first - (h[l].first * p[r - l + 1].first) % m1 + m1) % m1 , (h[r + 1].second - (h[l].second * p[r - l + 1].second) % m2 + m2) % m2 };
    }
};

signed main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, i, j, c = 0;
        char el;
        cin >> n >> m;
        vector <vector <ll> > a(n, vector <ll>(m));
        vector <vector <ll> > b(n, vector <ll>(m, 1));
        b[0][0] = 0;
        vector <vector <ll> > de;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> el;
                a[i][j] = el - '0';
            }
        }
        if (a[0][0] == 1) {
            cout << -1 << endl;
        }
        else {
            for (i = 0; i < n; i++) {
                for (j = m - 1; j > 0; j--) {
                    if (a[i][j] == 1) {
                        de.push_back({ i + 1, j, i + 1, j + 1 });
                    }
                }
            }
            for (i = n - 1; i > 0; i--) {
                if (a[i][0] == 1) {
                    de.push_back({ i, j + 1, i + 1,j + 1 });
                }
            }
            cout << de.size() << endl;
            for (i = 0; i < de.size(); i++) {
                for (j = 0; j < 4; j++) {
                    cout << de[i][j] << " ";
                }
                cout << endl;
            }
        }
        
    }
    

}


