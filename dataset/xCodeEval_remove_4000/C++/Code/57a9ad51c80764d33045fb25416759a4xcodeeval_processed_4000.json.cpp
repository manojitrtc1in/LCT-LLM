




using namespace std;





















template<typename T>
vector<T> &operator--(vector<T> &v) {
    for (auto &i : v) --i;
    return v;
}

template<typename T>
vector<T> &operator++(vector<T> &v) {
    for (auto &i : v) ++i;
    return v;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i : v) is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i : v) os << i << ' ';
    return os;
}

template<typename T, typename U>
pair<T, U> &operator--(pair<T, U> &p) {
    --p.first;
    --p.second;
    return p;
}

template<typename T, typename U>
pair<T, U> &operator++(pair<T, U> &p) {
    ++p.first;
    ++p.second;
    return p;
}

template<typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}

template<typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> p) {
    os << p.first << ' ' << p.second;
    return os;
}

template<typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) { return mp(a.first - b.first, a.second - b.second); }

template<typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) { return mp(a.first + b.first, a.second + b.second); }

template<typename T, typename U>
void umin(T &a, U b) { if (a > b) a = b; }

template<typename T, typename U>
void umax(T &a, U b) { if (a < b) a = b; }

ll id0(string s) {
    ll mod = 1000000007, zeros = 0, ones = 0;
    for (auto ch : s)
        if (ch == '1')
            ones = (zeros + ones + 1) % mod;
        else
            zeros = (zeros + ones) % mod;
    return (ones + zeros + (zeros || s[0] == '0')) % mod;
}

ll modPow(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll modProd(ll x, ll y, ll p) {
    ll ans = 0;
    for (ll i = 1; i <= y; i++) {
        ans = (ans + x) % p;
    }
    return ans;
}

ll gcd(ll a, ll b) {
    while (a && b) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

bool prime(ll n) {
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

ll fact(ll x, ll mod) {
    ll ans = 1;
    for (ll i = 2; i <= x; i++) {
        ans = (ans * i) % mod;
    }
    return ans;
}

struct Point {
    ll x, y;
};

bool slope(Point a, Point b, Point c) {
    ll dy1 = a.y - b.y;
    ll dx1 = a.x - b.x;
    ll dx2 = b.x - c.x;
    ll dy2 = b.y - c.y;
    return (dy1 * dx2 == dx1 * dy2);
}

ll probs(ll x) {
    return (x * (x + 1)) / 2;
}

ll id1(ll n) {
    if (n % 4 == 0)
        return n;

    if (n % 4 == 1)
        return 1;

    if (n % 4 == 2)
        return n + 1;
    return 0;
}

bool check(vl a, ll n, map<ll, ll> mp) {
    for (ll i = 1; i <= n; i++) {
        if (mp[i] != a[i - 1])
            return false;
    }
    return true;
}
ll pow10(int n) {
    return n <= 0 ? 1 : 10 * pow10(n - 1);
}

void solve() {
    int N;
    int64_t K;
    cin >> N >> K;
    K++;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    A.push_back(18);
    int64_t ans = 0;

    for (int i = 0; i < N; i++) {
        int64_t most = pow10(A[i + 1] - A[i]) - 1;
        int64_t take = min(most, K);
        K -= take;
        ans += take * pow10(A[i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {


        solve();
    }
}
