

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
#define MOD (ll) 1000000007

ll inf = 100000000000000007;

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

ll mod = 100000000;

bool valid(ll x, ll y, ll n, ll m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

ll nok(ll x, ll y) {
    return x * y / __gcd(x, y);
}

vector<long long> extended_euclid_gcd(long long a, long long b) {

    long long s = 0; long long old_s = 1;
    long long t = 1; long long old_t = 0;
    long long r = b; long long old_r = a;

    while(r != 0) {
        long long quotient = old_r/r;
        long long temp = r;
        r = old_r - quotient*r;
        old_r = temp;
        temp = s;
        s = old_s - quotient*s;
        old_s = temp;
        temp = t;
        t = old_t - quotient*t;
        old_t = temp;
    }
    vector<long long> result;
    result.push_back(old_r);
    result.push_back(old_s);
    result.push_back(old_t);
    return result;
}

void solve() {
    ll u, v;
    cin >> u >> v;




































    cout << -(u * u) << " " << v * v << '\n';
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {


        solve();
    }
}