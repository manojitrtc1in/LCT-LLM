




#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>








using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef float ff;
typedef double lf;
typedef long double llf;

typedef complex<ull> cull;
typedef complex<ff> cff;


typedef complex<lf> cllf;

const double eps = 1e-6;
const int int_inf = 2 * 1e9;
const ll ll_inf = 8 * 1e18;
const llf PI = acosl(-1.0);

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second






template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

istream& operator >> (istream& in, pii& i) {
    in >> i.first >> i.second;
    return in;
}

template<class T>
istream& operator >> (istream& in, vector<T>& a) {
    for (auto& i : a) {
        in >> i;
    }
    return in;
}

template<class T>
ostream& operator << (ostream& out, vector<T>& a) {
    for (auto i : a) {
        out << i << " ";
    }
    return out;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (ull)rng() % B;
}

template<typename T>
int64_t merge_sort(T* v, T* aux, int l, int r) {
    if (r <= l + 1) return 0;
    int m = (l + r) / 2;
    int64_t res = merge_sort(v, aux, l, m) + merge_sort(v, aux, m, r);
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        aux[k++] = v[i] <= v[j] ? v[i++] : (res += m - i, v[j++]);
    }
    while (i < m) aux[k++] = v[i++];
    while (j < r) aux[k++] = v[j++];
    while (l < r) {
        v[l] = aux[l];
        ++l;
    }
    return res;
}
template<typename T>
int64_t count_inversions(std::vector<T> v) {
    std::vector<T> aux(v.size());
    return merge_sort(v.data(), aux.data(), 0, v.size());
}

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(llf t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }




ll gcd(ll a, ll b) { if (b > a) { return gcd(b, a); } if (b == 0) { return a; } return gcd(b, a % b); }
ll expo(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }
void extendgcd(ll a, ll b, ll* v) { if (b == 0) { v[0] = 1; v[1] = 0; v[2] = a; return; } extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return; } 

ll mminv(ll a, ll b) { ll arr[3]; extendgcd(a, b, arr); return arr[0]; } 

ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
void swap(int& x, int& y) { int temp = x; x = y; y = temp; }
ll combination(ll n, ll r, ll m, ll* fact, ll* ifact) { ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m; }
void google(int t) { std::cout << "Case #" << t << ": "; }
vector<int> sieve(int n) { int* arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) { vect.push_back(i); for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1; } return vect; }
ll mod_add(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m) { a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m; }  

ll phin(ll n) { ll number = n; if (n % 2 == 0) { number /= 2; while (n % 2 == 0) n /= 2; } for (ll i = 3; i * i <= n; i += 2) { if (n % i == 0) { while (n % i == 0)n /= i; number = (number / i * (i - 1)); } } if (n > 1)number = (number / n * (n - 1)); return number; } 





const int MOD = 998244353;

ll fact[35];

ll powmod(ll a, ll b, ll p) {
    a %= p;
    if (a == 0) return 0;
    ll product = 1;
    while (b > 0) {
        if (b & 1) {    

            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    

    }
    return product;
}

ll inv(ll a, ll p) {
    return powmod(a, p - 2, p);
}

ll nCk(ll n, ll k, ll p) {
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n - k], p)) % p;
}

const int MAXA = 2 * 1e5 + 7;

int global_cnt = 0;

ll dp[MAXA];
int cnt[MAXA], total[MAXA];
int lp[MAXA];
int primes[MAXA / 10];
int isprime[MAXA];




bool can(int a, int b) {
    if (b == a) {
        return true;
    }
    if (2 * b >= a) {
        return false;
    }
    return true;
}

struct event {
    int a, b, c;
    bool good = false;
    event(int aa, int bb, int cc, bool q) {
        a = aa;
        b = bb;
        c = cc;
        good = q;
    }
};

void solve() {
    int n;
    cin >> n;
    int x = n / 3;
    int fr = 0;
    int fr_ind = 0;
    int en = 0;
    int en_ind = 0;
    vector<event> p;
    p.reserve(x);
    for (int i = 1; i <= x; ++i) {
        cout << "? " << i << " " << i + x << " " << i + 2 * x << '\n';
        fflush(stdout);
        int c;
        cin >> c;
        if (c == 1) {
            fr = i - 1;
        }
        else {
            en = i - 1;
        }
        p.push_back(event(i, i + x, i + 2 * x, (c == 1)));
    }

    for (int i = 0; i < 1; ++i) {
        event f = p[fr], e = p[en];
        bool flag1, flag2, flag3;
        cout << "? " << f.a << " " << f.b << " " << e.a << '\n';
        fflush(stdout);
        cin >> flag1;
        cout << "? " << f.a << " " << f.b << " " << e.b << '\n';
        fflush(stdout);
        cin >> flag2;
        cout << "? " << f.a << " " << f.b << " " << e.c << '\n';
        fflush(stdout);
        cin >> flag3;
        if (!flag1 || !flag2 || !flag3) {
            fr_ind = p[fr].c;
        }
        else {
            fr_ind = p[fr].a;
        }
    }

    for (int i = 0; i < 1; ++i) {
        event f = p[fr], e = p[en];
        bool flag1, flag2, flag3;
        cout << "? " << e.a << " " << e.b << " " << f.a << '\n';
        fflush(stdout);
        cin >> flag1;
        cout << "? " << e.a << " " << e.b << " " << f.b << '\n';
        fflush(stdout);
        cin >> flag2;
        cout << "? " << e.a << " " << e.b << " " << f.c << '\n';
        fflush(stdout);
        cin >> flag3;
        if (flag1 || flag2 || flag3) {
            en_ind = p[en].c;
        }
        else {
            en_ind = p[en].a;
        }
    }


    vector<bool> isgood(n + 1, 1);

    for (int i = 0; i < x; ++i) {
        event cur_event = p[i];
        if (!cur_event.good) {
            bool flag1, flag2;
            cout << "? " << cur_event.a << " " << cur_event.b << " " << fr_ind << '\n';
            fflush(stdout);
            cin >> flag1;
            cout << "? " << cur_event.a << " " << cur_event.c << " " << fr_ind << '\n';
            fflush(stdout);
            cin >> flag2;
            if (!flag1 && !flag2) {
                isgood[cur_event.a] = 0;
                isgood[cur_event.b] = 0;
                isgood[cur_event.c] = 0;
                continue;
            }
            if (flag1 && flag2) {
                isgood[cur_event.a] = 1;
                isgood[cur_event.b] = 0;
                isgood[cur_event.c] = 0;
                continue;
            }
            if (!flag1 && flag2) {
                isgood[cur_event.a] = 0;
                isgood[cur_event.b] = 0;
                isgood[cur_event.c] = 1;
                continue;
            }
            if (flag1 && !flag2) {
                isgood[cur_event.a] = 0;
                isgood[cur_event.b] = 1;
                isgood[cur_event.c] = 0;
                continue;
            }
        }
        else {
            bool flag1, flag2;
            cout << "? " << cur_event.a << " " << cur_event.b << " " << en_ind << '\n';
            fflush(stdout);
            cin >> flag1;
            cout << "? " << cur_event.a << " " << cur_event.c << " " << en_ind << '\n';
            fflush(stdout);
            cin >> flag2;
            if (!flag1 && !flag2) {
                isgood[cur_event.a] = 0;
                isgood[cur_event.b] = 1;
                isgood[cur_event.c] = 1;
                continue;
            }
            if (flag1 && flag2) {
                isgood[cur_event.a] = 1;
                isgood[cur_event.b] = 1;
                isgood[cur_event.c] = 1;
                continue;
            }
            if (!flag1 && flag2) {
                isgood[cur_event.a] = 1;
                isgood[cur_event.b] = 0;
                isgood[cur_event.c] = 1;
                continue;
            }
            if (flag1 && !flag2) {
                isgood[cur_event.a] = 1;
                isgood[cur_event.b] = 1;
                isgood[cur_event.c] = 0;
                continue;
            }
        }

    }

    int cnt = 0;
    cout << "! ";
    for (int i = 1; i <= n; ++i) {
        if (!isgood[i]) {
            ++cnt;
        }
    }
    cout << cnt << ' ';
    for (int i = 1; i <= n; ++i) {
        if (!isgood[i]) {
            cout << i << " ";
        }
    }
    cout << '\n';
    fflush(stdout);
    return;
}

signed main() {
    

    

    

    

    

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}