



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

ll modPow(ll x, ll y) {
    ll res = 1;
    x = x % MOD;
    if (x == 0)
        return 0;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
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
    if(n == 2)
        return false;
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




using namespace __gnu_pbds;

template<typename num_t>
using ordered_set = tree<num_t, null_type, greater<num_t>, rb_tree_tag, tree_order_statistics_node_update>;



bool check(ll x){
    for(ll i = 2; i * i <= x; i++){
        if(x % i == 0)
            return true;
    }
    return false;
}

void solve() {
    ll n;
    cin >> n;
    set<ll> s;
    for(ll i = 1; i <= n; i++)
        s.insert(i);
    if(n == 2){
        cout << "? " << 1 << " " << 2 << endl;
        ll k;
        cin >> k;
        if(k == 0){
            cout << "! " << 1 << " " << 2 << endl;
        } else {
            cout << "! " << 2 << " " << 1 << endl;
        }
        return;
    }
    vl ans(n, 0);
    map<ll, ll> inc, dec;
    ll mxI = -1;
    for(ll i = n - 1; i >= 0; i--){
        if(inc.find(i) == inc.end()) {
            cout << "? ";
            for (ll j = 0; j < n; j++) {
                if (j == i) {
                    cout << 3 << " ";
                } else {
                    cout << 2 << " ";
                }
            }
            ll k;
            cin >> k;
            if (k == 0) {
                ans[i] = n;
                mxI = i;
                s.erase(n);
            } else {
                k--;
                inc[i] = k; 

                dec[k] = i; 

            }
        }
        if(dec.find(i) == dec.end()) {
            cout << "? ";
            for (ll j = 0; j < n; j++) {
                if (i == j) {
                    cout << 1 << " ";
                } else {
                    cout << 2 << " ";
                }
            }
            ll k;
            cin >> k;
            if (k == 0) {
                ans[i] = 1;
                s.erase(1);
            } else {
                k--;
                inc[k] = i;
                dec[i] = k;
            }
        }
    }
    ll val = n;
    while(true){
        ll ind = dec[mxI];
        ans[ind] = val - 1;
        if(val == 2)
            break;
        else {
            mxI = ind;
            val--;
        }
    }
    cout << "! ";
    cout << ans << endl;
}

int main() {














        solve();


}