

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

ll mod = 1000000007;

bool check(vl a){
}

void solve() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll x = 0, y = 0;
    ll mxX = x, mxY = y;
    ll mnX = x, mnY = y;
    for(ll i = 0; i < (int) s.size(); i++) {
        ll probX = x, probY = y;
        if (s[i] == 'L')
            probX--;
        else if (s[i] == 'R')
            probX++;
        else if (s[i] == 'U')
            probY--;
        else if (s[i] == 'D')
            probY++;
        ll a = mxX, b = mxY, c = mnX, d = mnY;
        a = max(a, probX);
        b = max(b, probY);
        c = min(c, probX);
        d = min(d, probY);
        if (abs(probX) >= m || abs(probY) >= n || abs(c) + a >= m || abs(d) + b >= n)
            break;
        x = probX, y = probY;
        mxX = max(mxX, x), mxY = max(mxY, y);
        mnX = min(mnX, x), mnY = min(mnY, y);
    }
    if(mxY == 0 && mnY == 0){
        cout << 1 << " ";
    } else if(mxY != 0 && mnY != 0){
        cout << abs(mnY) + 1 << " ";
    } else if(mxY == 0){
        cout << abs(mnY) + 1 << " ";
    } else {
        cout << n - mxY << " ";
    }
    if(mxX == 0 && mnX == 0){
        cout << 1 << '\n';
    } else if(mxX != 0 && mnX != 0){
        cout << abs(mnX) + 1 << '\n';
    } else if(mxX == 0){
        cout << abs(mnX) + 1 << '\n';
    } else {
        cout << m - mxX << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {


        solve();
    }










}