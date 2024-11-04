
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
using namespace std;
namespace Template {
    #define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
    #define FREOPEN freopen("in.in", "r", stdin);freopen("out.out", "w", stdout)
    #ifdef A_king
    #include "E:\VS\PROJECT\Another\debug.h"
    #else
    #define out(x...) void(0);
    #endif
    #define endl '\n'
    #define pb push_back
    #define pf push_front
    #define len(container) (int)(container).size()
    #define all(container) (container).begin(), (container).end()
    #define all1(container) (container).begin() + 1, (container).end()
    #define rall(container) (container).rbegin(), (container).rend()
    #define rall1(container) (container).rbegin(), (container).rend() - 1
    #define YES cout << "YES" << endl
    #define Yes cout << "Yes" << endl
    #define yes cout << "yes" << endl
    #define NO cout << "NO" << endl
    #define No cout << "No" << endl
    #define no cout << "no" << endl
    const int mod = 998244353;const double PI = acos(-1.0);const double eps = 1e-8;const int inf = 0x3f3f3f3f;const long long INF = 0x3f3f3f3f3f3f3f3f;
    template<typename T> T ksm(T a, long long b) {T res = 1;while (b) {if (b & 1) res *= a;a *= a;b >>= 1;}return res;}
    template<const int MOD = mod> struct Modular {
        int x;
        int Mod(int x) {if (x < 0) x += MOD;if (x >= MOD) x -= MOD;return x;}
        Modular(int x = 0) : x(Mod(x)) {}
        Modular(long long x) : x(Mod(x % MOD)) {}
        int val() const {return x;}
        Modular operator -() const {Modular T(MOD - x);return T;}
        Modular inv() const {assert(x != 0);return ksm(*this, MOD - 2);}
        Modular inverse() const {long long a = x, b = MOD, u = 1, v = 0;while (b) {long long t = a / b;a -= t * b;a ^= b ^= a ^= b;u -= t * v;u ^= v ^= u ^= v;}if (u < 0) u += MOD;return u;}
        Modular &operator *= (const Modular &T) {x = (long long)(x) * T.x % MOD;return *this;}
        Modular &operator += (const Modular &T) {x = Mod(x + T.x);return *this;}
        Modular &operator -= (const Modular &T) {x = Mod(x - T.x);return *this;}
        Modular &operator /= (const Modular &T) {return *this *= T.inverse();}
        Modular &operator ++ (int) {return *this = *this + 1;}
        Modular &operator -- (int) {return *this = *this - 1;}
        bool operator == (const Modular &T) const {return x == T.x;}
        bool operator != (const Modular &T) const {return x != T.x;}
        bool operator <= (const Modular &T) const {return x <= T.x;}
        bool operator >= (const Modular &T) const {return x >= T.x;}
        bool operator < (const Modular &T) const {return x < T.x;}
        bool operator > (const Modular &T) const {return x > T.x;}
        friend Modular operator * (const Modular &T, const Modular &Y) {Modular res = T;res *= Y;return res;}
        friend Modular operator + (const Modular &T, const Modular &Y) {Modular res = T;res += Y;return res;}
        friend Modular operator - (const Modular &T, const Modular &Y) {Modular res = T;res -= Y;return res;}
        friend Modular operator / (const Modular &T, const Modular &Y) {Modular res = T;res /= Y;return res;}
        friend istream &operator >> (istream &in, Modular& T) {long long val;in >> val;T = val;return in;}
        friend ostream &operator << (ostream &os, const Modular& T) {return os << T.x;}
    };
    typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> TRIE;
    template<typename T> using RB = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    template<typename T> using Q = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;

    typedef long long ll;typedef unsigned long long ull;typedef pair<double, double> PDD;typedef pair<ll, ll> PLL;typedef pair<int, int> PII;typedef pair<int, PII> PIII;
    template<typename T> using vc = vector<T>;template<typename T> using vvc = vc<vc<T>>;
    template<typename T> inline T Abs(T a) {if (a < 0) a = -1 * a;return a;}
    template<typename T> T Gcd(const T &a, const T &b) {return b ? Gcd(b, a % b) : a;}
    template<typename T> T Lcm(const T &a, const T &b) {return a / Gcd(a, b) * b;}
    template<typename T> inline void Swap(T &a, T &b) {a ^= b ^= a ^= b;}
    template<typename T> inline bool Max(T &a, const T &b) {return a < b ? a = b, 1 : 0;}template<typename T> inline void Max(T &a, const T &b, const T &c){Max(a, b);Max(a, c);}
    template<typename T> inline bool Min(T &a, const T &b) {return a > b ? a = b, 1 : 0;}template<typename T> inline void Min(T &a, const T &b, const T &c){Min(a, b);Min(a, c);}
    template<typename T> inline T Sum(const vector<T> &x, int pos = 0) {return accumulate(x.begin() + pos, x.end(), 0ll);}
    template<typename T> inline T Maxe(const vector<T> &x, int pos = 0) {return *max_element(x.begin() + pos, x.end());}template<typename T> inline T Maxi(vector<T> x, int pos = 0) {return max_element(x.begin() + pos, x.end()) - x.begin();}
    template<typename T> inline T Mine(const vector<T> &x, int pos = 0) {return *min_element(x.begin() + pos, x.end());}template<typename T> inline T Mini(vector<T> x, int pos = 0) {return min_element(x.begin() + pos, x.end()) - x.begin();}
    template<typename T> inline void Disperse(vc<T> &v) {sort(all(v));v.erase(unique(all(v)), v.end());}
    template<typename T, typename U> istream &operator >> (istream &in, pair<T, U> &Arg) {return in >> Arg.first >> Arg.second;}
    template<typename T> istream &operator >> (istream &in, vc<T> &v) {int n = len(v) - 1;for (int i = 1;i <= n;++ i) in >> v[i];return in;}
    template<typename T> istream &operator >> (istream &in, vvc<T> &v) {int n = len(v) - 1, m = len(v[0]) - 1;for (int i = 1;i <= n;++ i) for (int j = 1;j <= m;++ j) in >> v[i][j];return in;}
    template<typename T> void pv(T a, T b, bool flag = true) {for (auto i = a;i != b;++ i) {if (i == a) cout << *i;else cout << " " << *i;}if (flag) cout << endl;}
    inline int popcount(const long long &x) {return __builtin_popcountll(x);}inline int clz(const long long &x) {return __builtin_clzll(x);}inline int parity(const long long &x) {return __builtin_parityll(x);}
}using namespace Template;
using Z = Modular<>;

const int N = 1e6 + 10, M = 2e6 + 10;
bool __init_solve__ = [](){return false;}();

struct BigInteger {
    static const int BASE = 100000000;

    static const int WIDTH = 8;

    bool sign;

    size_t length;
    vector<int> num;
    BigInteger(long long x = 0) { *this = x; }
    BigInteger(const string &x) { *this = x; }
    BigInteger(const BigInteger &x) { *this = x; }
    void cutPreZero() {while (num.back() == 0 && num.size() != 1) {num.pop_back();}}
    void setLength() {cutPreZero();int tmp = num.back();if (tmp == 0) {length = 1;}else {length = (num.size() - 1) * WIDTH;while (tmp > 0) {++ length;tmp /= 10;}}}
    size_t size() const {return length;}
    BigInteger &operator=(long long x) {num.clear();if (x >= 0) sign = true;else {sign = false;x = -x;}do {num.emplace_back(x % BASE);x /= BASE;}while (x > 0);setLength();return *this;}
    BigInteger &operator=(const string &str) {num.clear();sign = (str[0] != '-');int x, len = (str.size() - 1 - (!sign)) / WIDTH + 1;for (int i = 0; i < len; i++) {int End = str.length() - i * WIDTH;int start = max((int) (!sign), End - WIDTH);sscanf(str.substr(start, End - start).c_str(), "%d", &x);num.push_back(x);}setLength();return *this;}
    BigInteger &operator=(const BigInteger &tmp) {num = tmp.num;sign = tmp.sign;length = tmp.length;return *this;}
    BigInteger e(size_t n) const {int tmp = n % WIDTH;BigInteger ans;ans.length = n + 1;n /= WIDTH;while (ans.num.size() <= n) ans.num.push_back(0);ans.num[n] = 1;while (tmp--) ans.num[n] *= 10;return ans * (*this);}
    BigInteger abs() const {BigInteger ans(*this);ans.sign = true;return ans;}
    const BigInteger &operator+() const {return *this;}
    BigInteger operator-() const {BigInteger ans(*this);if (ans != 0) ans.sign = !ans.sign;return ans;}
    BigInteger operator+(const BigInteger &b) const {if (!b.sign) {return *this - (-b);}if (!sign) { return b - (-*this); }BigInteger ans;ans.num.clear();for (int i = 0, g = 0;; i++) {if (g == 0 && i >= num.size() && i >= b.num.size()) break;int x = g;if (i < num.size()) x += num[i];if (i < b.num.size()) x += b.num[i];ans.num.push_back(x % BASE);g = x / BASE;}ans.setLength();return ans;}
    BigInteger operator-(const BigInteger &b) const {if (!b.sign) {return *this + (-b);}if (!sign) { return -((-*this) + b); }if (*this < b) { return -(b - *this); }BigInteger ans;ans.num.clear();for (int i = 0, g = 0;; i++) {if (g == 0 && i >= num.size() && i >= b.num.size()) break;int x = g;g = 0;if (i < num.size()) x += num[i];if (i < b.num.size()) x -= b.num[i];if (x < 0) {x += BASE;g = -1;}ans.num.push_back(x);}ans.setLength();return ans;}
    BigInteger operator*(const BigInteger &b) const {int lena = num.size(), lenb = b.num.size();vector<long long> ansLL;for (int i = 0; i < lena + lenb; i++) ansLL.push_back(0);for (int i = 0; i < lena; i++) {for (int j = 0; j < lenb; j++) {ansLL[i + j] += (long long) num[i] * (long long) b.num[j];}}while (ansLL.back() == 0 && ansLL.size() != 1) ansLL.pop_back();int len = ansLL.size();long long g = 0, tmp;BigInteger ans;ans.sign = (ansLL.size() == 1 && ansLL[0] == 0) || (sign == b.sign);ans.num.clear();for (int i = 0; i < len; i++) {tmp = ansLL[i];ans.num.emplace_back((tmp + g) % BASE);g = (tmp + g) / BASE;}if (g > 0) ans.num.emplace_back(g);ans.setLength();return ans;}
    BigInteger operator/(const long long &b) const {BigInteger c;c.num.clear();for (int i = 0; i < num.size(); i++) {c.num.push_back(0);}long long g = 0;for (int i = num.size() - 1; i >= 0; i--) {c.num[i] = int((num[i] + g * BASE) / b);g = num[i] + g * BASE - c.num[i] * b;}for (int i = num.size() - 1; c.num[i] == 0; i--) {c.num.pop_back();}return c;}
    BigInteger operator/(const BigInteger &b) const {BigInteger aa((*this).abs());BigInteger bb(b.abs());if (aa < bb) return 0;char *str = new char[aa.size() + 1];memset(str, 0, sizeof(char) * (aa.size() + 1));BigInteger tmp;int lena = aa.length, lenb = bb.length;for (int i = 0; i <= lena - lenb; i++) {tmp = bb.e(lena - lenb - i);while (aa >= tmp) {++str[i];aa = aa - tmp;}str[i] += '0';}BigInteger ans(str);delete[]str;ans.sign = (ans == 0 || sign == b.sign);return ans;}
    BigInteger operator%(const long long &b) const {long long ans = 0;for (int i = num.size() - 1; i >= 0; i--)ans = (ans * BASE + num[i]) % b;return ans;}
    BigInteger operator%(const BigInteger &b) const {return *this - *this / b * b;}
    BigInteger &operator++() {*this = *this + 1;return *this;}                       

    BigInteger &operator--() {*this = *this - 1;return *this;}                       

    BigInteger &operator+=(const BigInteger &b) {*this = *this + b;return *this;}    

    BigInteger &operator-=(const BigInteger &b) {*this = *this - b;return *this;}    

    BigInteger &operator*=(const BigInteger &b) {*this = *this * b;return *this;}    

    BigInteger &operator/=(const long long &b) {*this = *this / b;return *this;}     

    BigInteger &operator/=(const BigInteger &b) {*this = *this / b;return *this;}    

    BigInteger &operator%=(const long long &b) {*this = *this % b;return *this;}     

    BigInteger &operator%=(const BigInteger &b) {*this = *this % b;return *this;}    

    bool operator<(const BigInteger &b) const {if (sign && !b.sign) {return false;}else if (!sign && b.sign) {return true;}else if (!sign && !b.sign) {return -b < -*this;}if (num.size() != b.num.size()) return num.size() < b.num.size();for (int i = num.size() - 1; i >= 0; i--)if (num[i] != b.num[i]) return num[i] < b.num[i];return false;}

    bool operator>(const BigInteger &b) const {return b < *this;}                    

    bool operator<=(const BigInteger &b) const {return !(b < *this);}                

    bool operator>=(const BigInteger &b) const {return !(*this < b);}                

    bool operator!=(const BigInteger &b) const {return b < *this || *this < b;}      

    bool operator==(const BigInteger &b) const {return !(b < *this) && !(*this < b);}

    bool operator||(const BigInteger &b) const {return *this != 0 || b != 0;}        

    bool operator&&(const BigInteger &b) const {return *this != 0 && b != 0;}        

    bool operator!() {return (bool) (*this == 0);}                                   

    friend ostream &operator<<(ostream &out, const BigInteger &x) {if (!x.sign) out << '-';out << x.num.back();for (int i = x.num.size() - 2; i >= 0; i--) {char buf[10];sprintf(buf, "%08d", x.num[i]);for (int j = 0; j < strlen(buf); j++) out << buf[j];}return out;}
    friend istream &operator>>(istream &in, BigInteger &x) {string str;in >> str;size_t len = str.size();int start = 0;if (str[0] == '-') start = 1;if (str[start] == '\0') return in;for (int i = start; i < len; i++) {if (str[i] < '0' || str[i] > '9') return in;}x.sign = !start;x = str.c_str();return in;}
    BigInteger pow(int n) {BigInteger ans = 1, base = *this;while (n) {if (n & 1) ans = ans * base;base = base * base;n >>= 1;}return ans;}
    BigInteger pow(BigInteger n, BigInteger md) {BigInteger ans = 1, base = *this;if (n == 0) return ans % md;while (n != 1) {if (n % 2 == 1) ans = ans * base % md;base = base * base % md;n /= 2;}ans = ans * base % md;return ans;}
};
#define int long long
bool multicase = true;
void solve(int group_Id) {
    int n, m, x, sum = 0;
    cin >> n >> m;
    vc<int> a(n + 1), s(n + 1), maxx(n + 1);
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        maxx[i] = max(maxx[i - 1], s[i]);
    }
    sum = s[n];
    while (m --) {
        cin >> x;
        

        

        

        if (sum <= 0) {
            auto t = lower_bound(all1(maxx), x);
            if (t == maxx.end()) cout << -1 << " ";
            else cout << t - maxx.begin() - 1 << " ";
            continue;            
        }
        

        

        

        

        int l = 0, r = 2e9;
        while (l < r) {
            int mid = l + r >> 1;
            if ((__int128_t)mid * sum + maxx[n] >= x) r = mid;
            else l = mid + 1;
        } 
        int res = l * n;
        res += lower_bound(all1(maxx), x - l * sum) - maxx.begin();
        cout << res - 1 << " ";
    }
    cout << endl;
}

signed main(signed argc, char const *argv[])
{
#ifdef A_king
    FREOPEN;
    auto clock_start = chrono::high_resolution_clock::now();
    cerr << __FILE__ << ", " << __DATE__ << ", " << __TIME__ << endl;
#endif
    IOS;
    cout << fixed << setprecision(16);
    int T_case = 1;
    if (multicase) cin >> T_case;
    for (int i = 1;i <= T_case;i ++) solve(i);
#ifdef A_king
    auto clock_end = chrono::high_resolution_clock::now();
    cerr << "Run Time: " << chrono::duration_cast<chrono::milliseconds>(clock_end - clock_start).count() << " ms" << endl;
#endif
    return 0;
}