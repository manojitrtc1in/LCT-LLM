



using namespace std;












































typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;
typedef pair<string, string> pairs;
typedef pair<ll, ll> pii;

template<typename T1, typename T2>


istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }

template<typename T>


istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it: v)cin >> it;
    return istream;
}

template<typename T1, typename T2>


ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }

template<typename T>


ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it: c) cout << it << " ";
    return ostream;
}


ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    gcd(b % a, a);
    return 0;
}


ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1}; 

int dy[] = {0, 1, -1, 0, -1, 1, 1, -1}; 

int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};


using namespace std;

















bool isPrime(ll n) {
    if (n == 2) {
        return true;
    }
    if (n < 2 || n % 2 == 0) {
        return false;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void lb(vector<int> v, int low, int high, int x) {
    int s = low;
    int e = high - 1;
    while (s <= e) {
        int m = s + (e - s) / 2;
        if (v[m] < x) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    if (s < high) {
        cout << s << " " << v[s] << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
}

int up(vector<int> &v, int l, int h, int element) {
    int ans = -1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (v[mid] <= element) {
            l = mid + 1;
            ans = l;
        } else {
            h = mid - 1;
        }
    }
    return ans;
}

vector<bool> primes((1e6 + 1), true);

void sieven(int n) {
    primes[0] = primes[1] = false;
    for (ll i = 2; i <= n + 1; i++) {
        if (primes[i]) {
            for (ll j = i * i; j <= n + 1; j += i)
                primes[j] = false;
        }
    }
}

int mod = 1e9 + 7;

long long fastPower(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long fastPower(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

bool id0(int n) {
    return (ceil(log2(n)) == floor(log2(n)));
}


void solve() {
    int n, m;
    cin >> n >> m;
    char v[n][m];
    for (int i=0;i<n;i++){
        for (int j= 0;j<m;j++){
            cin>>v[i][j];
        }
    }

    int res = INT_MAX;
    int ans = 0;
    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < m; k++) {
                ans += abs(v[i][k] - v[j][k]);
            }
            res = min(ans, res);
             ans = 0;
        }
    }
    cout << res << endl;
}



int main() {
    fast
    tc solve();
    return 0;
}
