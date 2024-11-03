#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <climits>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b)-1; i >= (a); --i)
#define trav(a, x) for(auto& a : x)
#define debug(x) cerr << #x << " = " << x << endl;
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

template<typename T>
void read(T& x) {
    cin >> x;
}

template<typename T>
void read(vector<T>& v) {
    for(auto& i : v) {
        read(i);
    }
}

template<typename T>
void write(T x) {
    cout << x;
}

template<typename T>
void write(vector<T>& v) {
    for(auto& i : v) {
        write(i);
        cout << " ";
    }
}

template<typename T>
void writeln(T x) {
    write(x);
    cout << endl;
}

template<typename T>
void writeln(vector<T>& v) {
    write(v);
    cout << endl;
}

template<typename T>
void sort(vector<T>& v) {
    sort(v.begin(), v.end());
}

template<typename T>
void reverse(vector<T>& v) {
    reverse(v.begin(), v.end());
}

template<typename T>
T gcd(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T>
T power(T a, T b) {
    T res = 1;
    while(b > 0) {
        if(b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

template<typename T>
T power(T a, T b, T mod) {
    T res = 1;
    while(b > 0) {
        if(b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

template<typename T>
T modInverse(T a, T mod) {
    return power(a, mod - 2, mod);
}

template<typename T>
T modAdd(T a, T b, T mod) {
    return (a + b) % mod;
}

template<typename T>
T modMul(T a, T b, T mod) {
    return (a * b) % mod;
}

template<typename T>
T modSub(T a, T b, T mod) {
    return (a - b + mod) % mod;
}

template<typename T>
T modDiv(T a, T b, T mod) {
    return modMul(a, modInverse(b, mod), mod);
}

template<typename T>
T modPow(T a, T b, T mod) {
    T res = 1;
    while(b > 0) {
        if(b & 1) {
            res = modMul(res, a, mod);
        }
        a = modMul(a, a, mod);
        b >>= 1;
    }
    return res;
}

template<typename T>
T modFact(T n, T mod) {
    T res = 1;
    for(T i = 1; i <= n; ++i) {
        res = modMul(res, i, mod);
    }
    return res;
}

template<typename T>
T modBinomial(T n, T k, T mod) {
    if(k > n) {
        return 0;
    }
    return modMul(modFact(n, mod), modMul(modInverse(modFact(k, mod), mod), modInverse(modFact(n - k, mod), mod), mod), mod);
}

template<typename T>
T modCatalan(T n, T mod) {
    return modDiv(modBinomial(2 * n, n, mod), n + 1, mod);
}

template<typename T>
T modLucas(T n, T k, T mod) {
    if(k == 0) {
        return 1;
    }
    return modMul(modBinomial(n % mod, k % mod, mod), modLucas(n / mod, k / mod, mod), mod);
}

template<typename T>
T modDerangement(T n, T mod) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return 0;
    }
    return modMul((n - 1), modAdd(modDerangement(n - 1, mod), modDerangement(n - 2, mod), mod), mod);
}

template<typename T>
T modStirlingFirst(T n, T k, T mod) {
    T res = 0;
    for(T i = 0; i <= k; ++i) {
        T temp = modMul(modPow(-1, k - i, mod), modBinomial(k, i, mod), modPow(i, n, mod), modPow(i, n, mod));
        if((k - i) & 1) {
            res = modSub(res, temp, mod);
        } else {
            res = modAdd(res, temp, mod);
        }
    }
    return modMul(res, modInverse(modFact(k, mod), mod), mod);
}

template<typename T>
T modStirlingSecond(T n, T k, T mod) {
    T res = 0;
    for(T i = 0; i <= k; ++i) {
        T temp = modMul(modPow(-1, k - i, mod), modBinomial(k, i, mod), modPow(i, n, mod));
        if((k - i) & 1) {
            res = modSub(res, temp, mod);
        } else {
            res = modAdd(res, temp, mod);
        }
    }
    return modMul(res, modInverse(modFact(k, mod), mod), mod);
}

template<typename T>
T modEuler(T n, T mod) {
    T res = n;
    for(T i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            res = modSub(res, modDiv(res, i, mod), mod);
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1) {
        res = modSub(res, modDiv(res, n, mod), mod);
    }
    return res;
}

template<typename T>
T modPrimitiveRoot(T mod) {
    if(mod == 2) {
        return 1;
    }
    if(mod == 4) {
        return 3;
    }
    T divs[20] = {0};
    divs[0] = 2;
    int cnt = 1;
    T phi = mod - 1;
    T x = phi;
    for(T i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            divs[cnt++] = i;
            while(x % i == 0) {
                x /= i;
            }
        }
    }
    if(x > 1) {
        divs[cnt++] = x;
    }
    for(T res = 2; res <= mod; ++res) {
        bool ok = true;
        for(int i = 0; i < cnt && ok; ++i) {
            ok &= modPow(res, phi / divs[i], mod) != 1;
        }
        if(ok) {
            return res;
        }
    }
    return -1;
}

template<typename T>
T modTonelliShanks(T n, T mod) {
    if(mod == 2) {
        return n;
    }
    if(modPow(n, mod / 2, mod) != 1) {
        return -1;
    }
    if(mod % 4 == 3) {
        return modPow(n, (mod + 1) / 4, mod);
    }
    T s = mod - 1;
    T e = 0;
    while(s % 2 == 0) {
        s >>= 1;
        ++e;
    }
    T nOne = modInverse(n, mod);
    T x = modPow(n, (s + 1) / 2, mod);
    T b = modPow(n, s, mod);
    T g = modPow(2, s, mod);
    while(true) {
        T y = x;
        T r = e;
        while(r > 0) {
            T bs = modPow(b, 1LL << (r - 1), mod);
            bool good = false;
            if(bs == 1) {
                good = true;
            }
            for(int i = 0; i < e - r; ++i) {
                if(bs == mod - 1) {
                    good = true;
                }
                bs = modMul(bs, bs, mod);
            }
            if(!good) {
                y = modMul(y, g, mod);
            }
            g = modMul(g, g, mod);
            r -= 1;
        }
        if(y == 1) {
            return x;
        }
        int j = 0;
        T bs = y;
        while(bs != 1) {
            bs = modMul(bs, bs, mod);
            ++j;
        }
        x = modMul(x, modPow(nOne, 1LL << (e - j - 1), mod), mod);
        b = modMul(b, modPow(nOne, 1LL << (e - j), mod), mod);
        g = modMul(b, b, mod);
        e = j;
    }
    return -1;
}

template<typename T>
T modSum(vector<T>& v, T mod) {
    T res = 0;
    for(auto& i : v) {
        res = modAdd(res, i, mod);
    }
    return res;
}

template<typename T>
T modProduct(vector<T>& v, T mod) {
    T res = 1;
    for(auto& i : v) {
        res = modMul(res, i, mod);
    }
    return res;
}

template<typename T>
T modSum(vector<T>& v) {
    return accumulate(v.begin(), v.end(), 0);
}

template<typename T>
T modProduct(vector<T>& v) {
    return accumulate(v.begin(), v.end(), 1, multiplies<T>());
}

template<typename T>
T modSum(initializer_list<T> v, T mod) {
    return accumulate(v.begin(), v.end(), 0, [&](T a, T b) {
        return modAdd(a, b, mod);
    });
}

template<typename T>
T modProduct(initializer_list<T> v, T mod) {
    return accumulate(v.begin(), v.end(), 1, [&](T a, T b) {
        return modMul(a, b, mod);
    });
}

template<typename T>
T modSum(initializer_list<T> v) {
    return accumulate(v.begin(), v.end(), 0);
}

template<typename T>
T modProduct(initializer_list<T> v) {
    return accumulate(v.begin(), v.end(), 1, multiplies<T>());
}

template<typename T>
T modSum(T a, T b, T mod) {
    return modAdd(a, b, mod);
}

template<typename T>
T modProduct(T a, T b, T mod) {
    return modMul(a, b, mod);
}

template<typename T>
T modSub(T a, T b, T mod) {
    return modSub(a, b, mod);
}

template<typename T>
T modDiv(T a, T b, T mod) {
    return modDiv(a, b, mod);
}

template<typename T>
T modPow(T a, T b, T mod) {
    return modPow(a, b, mod);
}

template<typename T>
T modFact(T n, T mod) {
    T res = 1;
    for(T i = 1; i <= n; ++i) {
        res = modMul(res, i, mod);
    }
    return res;
}

template<typename T>
T modBinomial(T n, T k, T mod) {
    if(k > n) {
        return 0;
    }
    return modMul(modFact(n, mod), modMul(modInverse(modFact(k, mod), mod), modInverse(modFact(n - k, mod), mod), mod), mod);
}

template<typename T>
T modCatalan(T n, T mod) {
    return modDiv(modBinomial(2 * n, n, mod), n + 1, mod);
}

template<typename T>
T modLucas(T n, T k, T mod) {
    if(k == 0) {
        return 1;
    }
    return modMul(modBinomial(n % mod, k % mod, mod), modLucas(n / mod, k / mod, mod), mod);
}

template<typename T>
T modDerangement(T n, T mod) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return 0;
    }
    return modMul((n - 1), modAdd(modDerangement(n - 1, mod), modDerangement(n - 2, mod), mod), mod);
}

template<typename T>
T modStirlingFirst(T n, T k, T mod) {
    T res = 0;
    for(T i = 0; i <= k; ++i) {
        T temp = modMul(modPow(-1, k - i, mod), modBinomial(k, i, mod), modPow(i, n, mod), modPow(i, n, mod));
        if((k - i) & 1) {
            res = modSub(res, temp, mod);
        } else {
            res = modAdd(res, temp, mod);
        }
    }
    return modMul(res, modInverse(modFact(k, mod), mod), mod);
}

template<typename T>
T modStirlingSecond(T n, T k, T mod) {
    T res = 0;
    for(T i = 0; i <= k; ++i) {
        T temp = modMul(modPow(-1, k - i, mod), modBinomial(k, i, mod), modPow(i, n, mod));
        if((k - i) & 1) {
            res = modSub(res, temp, mod);
        } else {
            res = modAdd(res, temp, mod);
        }
    }
    return modMul(res, modInverse(modFact(k, mod), mod), mod);
}

template<typename T>
T modEuler(T n, T mod) {
    T res = n;
    for(T i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            res = modSub(res, modDiv(res, i, mod), mod);
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1) {
        res = modSub(res, modDiv(res, n, mod), mod);
    }
    return res;
}

template<typename T>
T modPrimitiveRoot(T mod) {
    if(mod == 2) {
        return 1;
    }
    if(mod == 4) {
        return 3;
    }
    T divs[20] = {0};
    divs[0] = 2;
    int cnt = 1;
    T phi = mod - 1;
    T x = phi;
    for(T i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            divs[cnt++] = i;
            while(x % i == 0) {
                x /= i;
            }
        }
    }
    if(x > 1) {
        divs[cnt++] = x;
    }
    for(T res = 2; res <= mod; ++res) {
        bool ok = true;
        for(int i = 0; i < cnt && ok; ++i) {
            ok &= modPow(res, phi / divs[i], mod) != 1;
        }
        if(ok) {
            return res;
        }
    }
    return -1;
}

template<typename T>
T modTonelliShanks(T n, T mod) {
    if(mod == 2) {
        return n;
    }
    if(modPow(n, mod / 2, mod) != 1) {
        return -1;
    }
    if(mod % 4 == 3) {
        return modPow(n, (mod + 1) / 4, mod);
    }
    T s = mod - 1;
    T e = 0;
    while(s % 2 == 0) {
        s >>= 1;
        ++e;
    }
    T nOne = modInverse(n, mod);
    T x = modPow(n, (s + 1) / 2, mod);
    T b = modPow(n, s, mod);
    T g = modPow(2, s, mod);
    while(true) {
        T y = x;
        T r = e;
