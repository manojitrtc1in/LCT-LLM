#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <bitset>
#include <cassert>
#include <climits>
#include <ctime>
#include <complex>
#include <numeric>
#include <fstream>
#include <functional>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define fo(i,a,b) for(int i=(a);i<=(b);i++)
#define foe(i,a,b) for(int i=(a);i>=(b);i--)
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define fill(a,b) memset(a,b,sizeof(a))
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl '\n'
#define F first
#define S second
#define ll long long
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define pq priority_queue<int>
#define pql priority_queue<int,vi,greater<int> >
#define MOD 1000000007
#define MOD2 998244353
#define INF 1000000000000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

template<typename T>
void printv(const vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

template<typename T>
void printvv(const vector<vector<T>>& vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void printset(const set<T>& s) {
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

template<typename T>
void printmap(const map<T, T>& m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

template<typename T>
void printarray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
void printmatrix(T arr[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
T gcd(T a, T b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

template<typename T>
T lcm(T a, T b) {
    return (a * b) / gcd(a, b);
}

template<typename T>
T modpow(T base, T exp, T modulus) {
    base %= modulus;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

template<typename T>
T modinv(T a, T m) {
    return modpow(a, m - 2, m);
}

template<typename T>
T add(T a, T b, T mod) {
    return (a % mod + b % mod) % mod;
}

template<typename T>
T sub(T a, T b, T mod) {
    return (a % mod - b % mod + mod) % mod;
}

template<typename T>
T mul(T a, T b, T mod) {
    return (a % mod * b % mod) % mod;
}

template<typename T>
T divi(T a, T b, T mod) {
    return (a % mod * modinv(b, mod)) % mod;
}

template<typename T>
T expo(T a, T b, T mod) {
    T res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a, mod);
        }
        a = mul(a, a, mod);
        b >>= 1;
    }
    return res;
}

template<typename T>
T fact(T n, T mod) {
    T res = 1;
    for (T i = 2; i <= n; i++) {
        res = mul(res, i, mod);
    }
    return res;
}

template<typename T>
T nCr(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    T numerator = fact(n, mod);
    T denominator = mul(fact(r, mod), fact(n - r, mod), mod);
    return divi(numerator, denominator, mod);
}

template<typename T>
T nPr(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    T numerator = fact(n, mod);
    T denominator = fact(n - r, mod);
    return divi(numerator, denominator, mod);
}

template<typename T>
T nCrLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrLucas(n / mod, r / mod, mod), nCr(ni, ri, mod), mod);
}

template<typename T>
T nCrMod(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrMod(n / mod, r / mod, mod), nCr(ni, ri, mod), mod);
}

template<typename T>
T nCrModLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModLucas(n / mod, r / mod, mod), nCrMod(ni, ri, mod), mod);
}

template<typename T>
T nCrModFact(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T numerator = fact(n, mod);
    T denominator = mul(fact(r, mod), fact(n - r, mod), mod);
    return divi(numerator, denominator, mod);
}

template<typename T>
T nCrModFactLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModFactLucas(n / mod, r / mod, mod), nCrModFact(ni, ri, mod), mod);
}

template<typename T>
T nCrModFactModLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModFactModLucas(n / mod, r / mod, mod), nCrModFact(ni, ri, mod), mod);
}

template<typename T>
T nCrModFactModFactLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModFactModFactLucas(n / mod, r / mod, mod), nCrModFactModLucas(ni, ri, mod), mod);
}

template<typename T>
T nCrModFactModFactModLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModFactModFactModLucas(n / mod, r / mod, mod), nCrModFactModFactLucas(ni, ri, mod), mod);
}

template<typename T>
T nCrModFactModFactModFactLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModFactModFactModFactLucas(n / mod, r / mod, mod), nCrModFactModFactModLucas(ni, ri, mod), mod);
}

template<typename T>
T nCrModFactModFactModFactModLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModFactModFactModFactModLucas(n / mod, r / mod, mod), nCrModFactModFactModFactLucas(ni, ri, mod), mod);
}

template<typename T>
T nCrModFactModFactModFactModFactLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModFactModFactModFactModFactLucas(n / mod, r / mod, mod), nCrModFactModFactModFactModLucas(ni, ri, mod), mod);
}

template<typename T>
T nCrModFactModFactModFactModFactModLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModFactModFactModFactModFactModLucas(n / mod, r / mod, mod), nCrModFactModFactModFactModFactLucas(ni, ri, mod), mod);
}

template<typename T>
T nCrModFactModFactModFactModFactModFactLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModFactModFactModFactModFactModFactLucas(n / mod, r / mod, mod), nCrModFactModFactModFactModFactModLucas(ni, ri, mod), mod);
}

template<typename T>
T nCrModFactModFactModFactModFactModFactModLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModFactModFactModFactModFactModFactModLucas(n / mod, r / mod, mod), nCrModFactModFactModFactModFactModFactLucas(ni, ri, mod), mod);
}

template<typename T>
T nCrModFactModFactModFactModFactModFactModFactLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModFactModFactModFactModFactModFactModFactLucas(n / mod, r / mod, mod), nCrModFactModFactModFactModFactModFactModLucas(ni, ri, mod), mod);
}

template<typename T>
T nCrModFactModFactModFactModFactModFactModFactModLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModFactModFactModFactModFactModFactModFactModLucas(n / mod, r / mod, mod), nCrModFactModFactModFactModFactModFactModLucas(ni, ri, mod), mod);
}

template<typename T>
T nCrModFactModFactModFactModFactModFactModFactModFactLucas(T n, T r, T mod) {
    if (r > n) {
        return 0;
    }
    if (n == 0 && r == 0) {
        return 1;
    }
    T ni = n % mod;
    T ri = r % mod;
    return mul(nCrModFactModFactModFactModFactModFactModFactModFactLucas(n / mod, r / mod, mod), nCrModFactModFactModFactModFactModFactModFactLucas(ni, ri, mod), mod);
}

template<typename T>
