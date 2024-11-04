

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <deque>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

#define ll long long
#define vs vector<string>
#define vl vector<ll>
#define vll vector<vl>
#define all(x) x.begin(), x.end()
#define pl pair<ll, ll>
#define vpl vector<pl>
#define ld long double
#define pb   push_back
#define pob pop_back
#define eb   emplace_back
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define exist(a, x, flag) (flag == 1 ? a.find(x) != a.end() : a.find(x) == a.end())

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

ll numberOfUniqueSubstringsInBinaryString(string s) {
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
    if (n == 1)
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

ll computeXOR(ll n) {
    if (n % 4 == 0)
        return n;

    if (n % 4 == 1)
        return 1;

    if (n % 4 == 2)
        return n + 1;
    return 0;
}


ll mod = 1000000007;

bool check(vl a, ll x) {
    vl arr;
    for (ll el : a) {
        if (el != x)
            arr.pb(el);
    }
    ll l = 0, r = (ll) arr.size() - 1;
    while (l < r) {
        if (arr[l] != arr[r])
            return false;
        l++, r--;
    }
    return true;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vl a(n);
    cin >> a;
    sort(all(a));
    vl take(n, 0);
    ll i = 0;
    while(i < n && a[i] < 0){
        take[i] = 1;
        i += k;
    }
    i = n - 1;
    while(i >= 0 && a[i] > 0){
        take[i] = 1;
        i -= k;
    }
    ll ans = 0;
    ll mx = 0;
    for(i = 0; i < n; i++){
        if(!take[i])
            continue;
        ans += abs(a[i]) * 2;
        mx = max(mx, abs(a[i]));
    }
    cout << ans - mx << '\n';
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
        solve();
}