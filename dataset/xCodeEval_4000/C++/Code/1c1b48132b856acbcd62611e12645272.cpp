#pragma region template
#pragma clang diagnostic ignored "-Wno-deprecated"
#pragma clang diagnostic ignored "-Werror"


#include <iomanip>
#include <iostream>
#include <cctype>
#include <string>
#include <math.h> 
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <exception>
#include <limits>
#include <new>
#include <typeinfo>
#include <bitset>
#include <deque>
#include <iterator>
#include <numeric>
#include <iosfwd>
#include <ios>
#include <istream>
#include <streambuf>
#include <strstream>
#include <array>
#include <regex>
#include <cassert>
#include <cerrno>
#include <climits>
#include <cfenv>
#include <type_traits>
#include <chrono>
#include <functional>
#include <memory>
#include <memory.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <cwctype>
#include <cwchar>


#include <unordered_set>
using namespace std;
using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::istringstream;
using std::ios;
using std::stringstream;
using ll = long long; using ld = long double;
using ull = unsigned long long; using str = string;
using bl = bool; using db = double;
using ch = char; using sh = short;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef set<ll> sl;
typedef unordered_set<ll> usl;
typedef vector<vector<ll>> vl2;
typedef vector<str> vs;
typedef vector<ch> vc;
typedef vector<pair<ll, ll>> vp;
typedef map<ll, str> mls;
typedef map<str, str> mss;
typedef map<ll, ll> mll;
typedef map<str, ll> msl;
typedef map<ch, ll> mcl;
typedef stack<ll> stl;
typedef queue<ll> ql;
typedef deque<ll> dq;
typedef priority_queue<ll> pq;
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define ULLONG_MAX 18446744073709551615
#define LL_MAX LLONG_MAX
#define up(initial, n, step) for(ll i = (ll)(initial);i < (ll)(n);i+=(ll)(step))
#define up2(initial, n, step) for(ll j = (ll)(initial);j < (ll)(n);j+=(ll)(step))
#define down(initial, n, step) for(ll i = (ll)(initial) - 1;i >= (ll)(n);i-=(ll)(step))
#define forCond(initial, cond, step) for(ll i = (initial);cond;i+=(step))
#define all(x) (x).begin(), (x).end()
#define floor(a) (ll)a
#define vget(v) for(auto& element : v) element = get();
#define vcin(v) for(auto& element : v)cin >> (element);
#define YES(a) ((a)?"YES":"NO")
#define Yes(a) ((a)?"Yes":"No")
#define yes(a) ((a)?"yes":"no")
#define stop return 0;
#define rev(s) reverse((s).begin(), (s).end());
#define sortCol(v, v2, col) sort(v, v[(col)] < v2[(col)])
#define vsort(v) sort(v.begin(), v.end())
#define pb(a) push_back((a));
#define vpushf(v, a) (v).insert((v).begin(), (a))
#define vsum(v) accumulate(v.begin(), v.end(), 0)
#define vavg(v) accumulate(v.begin(), v.end(), 0) / v.size()
#define vremoveDupe(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
#define vrand(v) (v).random_shuffle(v.begin(), v.end());
#define vfind(v, val) find(all((v)), val)
#define spush(s, a) (s).insert((a));
#define stTop(s) (s).top();
#define toStr(s) to_string((s))
#define throwErr(s) throw invalid_argument(s);
#define setdecimal(n) cout << fixed << setprecision((n))
#define fillAsc(v, start) iota((v).begin(), (v).end(), (start));
#define isPerm is_permutation
#define nextPerm next_permutation
#define prevPerm prev_permutation
#define tc \
  ll t = get();  \
  while (t--)
#define tcin \
  ll t;\
  cin >> t;\
  while(t--)
#define varConcat(a, b) a##b
#define setup ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define foreach(a, v) for(auto& a : v)
#define skip continue
auto _ = NULL;

const str alphabet = "abcdefghijklmnopqrstuvwxyz";
const str upAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const ll Mod = 998244353;
const ll Mod2 = pow(10, 9) + 7;
const ll Mod3 = pow(10, 9);
const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const ll pow5Len = pow(10, 5) + 1;
const ll pow11Len = pow(10, 10) + 1;
str toLower(str s)
{
    str result = "";
    for (auto& c : s)result += tolower(c);
    return result;
}
str toUpper(str s) {
    str result = "";
    for (auto& c : s)result += toupper(c);
    return result;
}
ld TAN(ld degree) { return tan(degree * PI / 180.0); };ld SIN(ld degree) { return sin(degree * PI / 180.0); };ld COS(ld degree) { return cos(degree * PI / 180.0); };
ld ATAN(ld len){return atan(len) * 180 / PI;}ld ASIN(ld len) { return asin(len) * 180 / PI; }ld ACOS(ld len) { return acos(len) * 180 / PI; }
ll lexOrder(str s, str s2) { if (s == s2) { return 0; stop; } if (s.length() <= s2.length()) { for (int i = 0; i < s.length(); i++) { if (s[i] < s2[i]) { return -1; stop; } else if (s[i] > s2[i]) { return 1; stop; } } return -1; } else { for (int i = 0; i < s2.length(); i++) { if (s[i] > s2[i]) { return -1; stop; } else if (s[i] < s2[i]) { return 1; stop; } } return 1; } }
ll binarySearch(vl v, ll val) { ll l = 0, m, h = v.size() - 1; while (l <= h && val != -1) { m = (l + h) / 2; if (val < v[m]) h = m - 1; else if (val > v[m]) l = m + 1; else return m; }return -1; }
ll binarySearch2(int arr[], int l, int r, int x) { while (l <= r) { int m = l + (r - l) / 2; if (arr[m] == x) return m; else if (arr[m] < x) l = m + 1; else r = m - 1; }return -1; }
ll revBinarySearch(vector<int> v, int X) { int start = 0, end = v.size() - 1; while (start <= end) { int mid = start + (end - start) / 2; if (X == v[mid]) return mid; else if (X < v[mid]) start = mid + 1; else end = mid - 1; } return -1; }
bl isNumber(const str& st) { for (ch const& c : st) if (isdigit(c) == 0) return false; return true; }
ll getMonth(str m) { m = toLower(m); if (m == "january") return 1; else if (m == "february") return 2; else if (m == "March") return 3; else if (m == "April") return 4; else if (m == "May") return 5; else if (m == "June") return 6; else if (m == "July") return 7; else if (m == "August") return 8; else if (m == "Sepember") return 9; else if (m == "October") return 10; else if (m == "November") return 11; return 12; }
bl isLeapYear(int n) { return (n % 4 == 0 ? n % 100 == 0 && n % 400 == 0 ? true : n % 100 != 0 ? true : false : false); }
bl sortcol(const vector<int>& v, const vector<int>& v2, int col) { return v[col] < v2[col]; }
bl cmp(pair<str, ll>& a, pair<str, ll>& b) { if (a.second == b.second) { for (ll i = 0; i < min(a.first.length(), b.first.length()); i++) { if (a.first[i] < b.first[i])return 0; else if (a.first[i] > b.first[i])return 1; } } return a.second < b.second; }
ll getIndex(vl v, ll K) { auto it = find(v.begin(), v.end(), K); if (it != v.end()) return it - v.begin(); return -1; }
ll getIndexArr(int arr[], int n) { size_t Size = sizeof(arr) / sizeof(int); int* end = arr + Size; int* result = find(arr, end, n); if (result != end) return distance(arr, result); return -1; }
ll gcd(ll a, ll b) {
    while (b) b ^= a ^= b ^= a %= b;
    return a;
}
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll search(ll x, ll t[], ll len) {
    ll* base = t;
    while (len > 1) {
        int half = len / 2;
        base = (base[half] < x ? &base[half] : base);
        len -= half;
    }
    return *(base + (*base < x));
}
bl islower(str s) { for (const auto& c : s) { if (c > 'z' || c < 'a') return false; } return true; }
bl ishigher(str s) { for (const auto& c : s) { if (c > 'Z' || c < 'A') return false; } return true; }
ll ascSum(ll n) { return n * (n + 1) / 2; }
ll len(str s) { return s.length(); }
ll fib(ll num) { const ld f = sqrt(5); return (pow(1 + f, num) - pow(1 - f, num)) / (pow(2, num) * f); }

ll vColSum(vl2 v, ll col) { ll sum = 0; for (const auto& x : v)sum += x[col]; return sum; }
ll mapMaxElement(mll x) { mll::iterator best = max_element(x.begin(), x.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b)->bool { return a.second < b.second; }); return best->second; }
ll mapMaxElement(msl x) { msl::iterator best = max_element(x.begin(), x.end(), [](const pair<str, ll>& a, const pair<str, ll>& b)->bool { return a.second < b.second; }); return best->second; }
bl isPrime(ll n) { if (n == 1)return 0; for (ll i = 2; i <= sqrt(n); i++) if (!(n % i))return 0; return 1; }
vl eratosthenesSieve(ll limit) { vl prime(limit + 1); for (ll i = 2; i <= limit; i++)prime[i] = 1; for (ll p = 2; p * p <= limit; p++)if (prime[p])for (ll i = p * p; i <= limit; i += p)prime[i] = 0; return prime; }
bl ispow2(ll i) { return i && (i & -i) == i; }
bl isPal(str s) { str s2 = s; rev(s2); return s2 == s; }
bl isParenthesis(str s) { ll p = 0; for (const auto& t : s) { if (t == '(')p++; else if (t == ')') { p--; if (p < 0)  return false; } }return p == 0; }
ll mul(ll x, ll res[], ll res_size);
str factorial(ll n) { str result = ""; ll res[1000]; res[0] = 1; ll res_size = 1; for (ll x = 2; x <= n; x++) res_size = mul(x, res, res_size); for (ll i = res_size - 1; i >= 0; i--)result += toStr(res[i]); return result; }
ll mul(ll x, ll res[], ll res_size) { ll carry = 0; for (ll i = 0; i < res_size; i++) { ll prod = res[i] * x + carry; res[i] = prod % 10; carry = prod / 10; }while (carry) { res[res_size] = carry % 10; carry = carry / 10; res_size++; }return res_size; }
ld squareRoot(ld n) {
    ld x = 1;
    while (abs(x * x - n) > EPS) x = (x + n / x) / 2;
    return x;
}
auto vmin = [](vl v) {return *min_element(all(v)); };
auto vmax = [](vl v) {return *max_element(all(v)); };
auto multiply = [](ll n, ll n2) {ll result = 0; while (n2 > 0) { if (n2 & 1)  result += n; n = n << 1; n2 = n2 >> 1; } return result; };


inline ll get(void) { ch t = getchar(); ll x = 0, neg = 0; while ((t < 48 || t>57) && t != '-') t = getchar(); if (t == '-') { neg = 1; t = getchar(); } while (t >= 48 && t <= 57) { x = (x << 3) + (x << 1) + t - 48; t = getchar(); } if (neg) x = -x; return x; }
inline void out(ll x, ll mode = 1) { ch a[20]; a[0] = '0'; ll i = 0, j; if (x < 0) { putchar('-'); x = -x; }if (x == 0) putchar('0'); while (x) { a[i++] = x % 10 + 48; x /= 10; } for (j = i - 1; j >= 0; j--) putchar(a[j]); putchar(mode ? '\n' : ' '); }
class BigInt {
    string digits;
public:
    BigInt(unsigned long long n = 0);
    BigInt(string&);
    BigInt(const char*);
    BigInt(BigInt&);

    

    friend void divide_by_2(BigInt& a);
    friend bool Null(const BigInt&);
    friend int Length(const BigInt&);
    int operator[](const int)const;
    BigInt& operator=(const BigInt&);
    BigInt& operator++();
    BigInt operator++(int temp);
    BigInt& operator--();
    BigInt operator--(int temp);
    friend BigInt& operator+=(BigInt&, const BigInt&);
    friend BigInt operator+(const BigInt&, const BigInt&);
    friend BigInt operator-(const BigInt&, const BigInt&);
    friend BigInt& operator-=(BigInt&, const BigInt&);
    friend bool operator==(const BigInt&, const BigInt&);
    friend bool operator!=(const BigInt&, const BigInt&);
    friend bool operator>(const BigInt&, const BigInt&);
    friend bool operator>=(const BigInt&, const BigInt&);
    friend bool operator<(const BigInt&, const BigInt&);
    friend bool operator<=(const BigInt&, const BigInt&);
    friend BigInt& operator*=(BigInt&, const BigInt&);
    friend BigInt operator*(const BigInt&, const BigInt&);
    friend BigInt& operator/=(BigInt&, const BigInt&);
    friend BigInt operator/(const BigInt&, const BigInt&);
    friend BigInt operator%(const BigInt&, const BigInt&);
    friend BigInt& operator%=(BigInt&, const BigInt&);
    friend BigInt& operator^=(BigInt&, const BigInt&);
    friend BigInt operator^(BigInt&, const BigInt&);
    friend BigInt sqrt(BigInt& a);
    friend ostream& operator<<(ostream&, const BigInt&);
    friend istream& operator>>(istream&, BigInt&);
    friend BigInt NthCatalan(int n);
    friend BigInt NthFibonacci(int n);
    friend BigInt Factorial(int n);
};
BigInt::BigInt(string& s) {
    digits = "";
    ll n = s.size();
    down(n-1,0,1) {
        if (!isdigit(s[i])) throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(unsigned long long nr) {
    do {
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}
BigInt::BigInt(const char* s) {
    digits = "";
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (!isdigit(s[i])) throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(BigInt& a) {digits = a.digits;}
bl Null(const BigInt& a) {return (a.digits.size() == 1 && a.digits[0] == 0);}
int Length(const BigInt& a) {return a.digits.size();}
int BigInt::operator[](const int index)const {
    if (digits.size() <= index || index < 0) throw("ERROR");
    return digits[index];
}
bl operator==(const BigInt& a, const BigInt& b) { return a.digits == b.digits;}
bl operator!=(const BigInt& a, const BigInt& b) {return !(a == b);}
bl operator<(const BigInt& a, const BigInt& b) {
    int n = Length(a), m = Length(b);
    if (n != m) return n < m;
    while (n--) if (a.digits[n] != b.digits[n]) return a.digits[n] < b.digits[n];
    return false;
}
bool operator>(const BigInt& a, const BigInt& b) { return b < a;}
bool operator>=(const BigInt& a, const BigInt& b) { return !(a < b);}
bool operator<=(const BigInt& a, const BigInt& b) { return !(a > b);}

BigInt& BigInt::operator=(const BigInt& a) {
    digits = a.digits;
    return *this;
}
BigInt& BigInt::operator++() {
    int i, n = digits.size();
    for (i = 0; i < n && digits[i] == 9; i++)
        digits[i] = 0;
    if (i == n)
        digits.push_back(1);
    else
        digits[i]++;
    return *this;
}
BigInt BigInt::operator++(int temp) {
    BigInt aux;
    aux = *this;
    ++(*this);
    return aux;
}

BigInt& BigInt::operator--() {
    if (digits[0] == 0 && digits.size() == 1)
        throw("UNDERFLOW");
    int i, n = digits.size();
    for (i = 0; digits[i] == 0 && i < n; i++)
        digits[i] = 9;
    digits[i]--;
    if (n > 1 && digits[n - 1] == 0)
        digits.pop_back();
    return *this;
}
BigInt BigInt::operator--(int temp) {
    BigInt aux;
    aux = *this;
    --(*this);
    return aux;
}

BigInt& operator+=(BigInt& a, const BigInt& b) {
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if (m > n)
        a.digits.append(m - n, 0);
    n = Length(a);
    for (i = 0; i < n; i++) {
        if (i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if (t)
        a.digits.push_back(t);
    return a;
}
BigInt operator+(const BigInt& a, const BigInt& b) {
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}

BigInt& operator-=(BigInt& a, const BigInt& b) {
    if (a < b) throw("UNDERFLOW");
    int n = Length(a), m = Length(b), i, t = 0, s;
    for (i = 0; i < n; i++) {
        if (i < m) s = a.digits[i] - b.digits[i] + t;
        else s = a.digits[i] + t;
        if (s < 0) s += 10,t = -1;
        else t = 0;
        a.digits[i] = s;
    }
    while (n > 1 && a.digits[n - 1] == 0)
        a.digits.pop_back(),
        n--;
    return a;
}
BigInt operator-(const BigInt& a, const BigInt& b) {
    BigInt temp;
    temp = a;
    temp -= b;
    return temp;
}

BigInt& operator*=(BigInt& a, const BigInt& b)
{
    if (Null(a) || Null(b)) {
        a = BigInt();
        return a;
    }
    int n = a.digits.size(), m = b.digits.size();
    vector<int> v(n + m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            v[i + j] += (a.digits[i]) * (b.digits[j]);
        }
    n += m;
    a.digits.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++)
    {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.digits[i] = v[i];
    }
    for (int i = n - 1; i >= 1 && !v[i]; i--)
        a.digits.pop_back();
    return a;
}
BigInt operator*(const BigInt& a, const BigInt& b) {
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
}

BigInt& operator/=(BigInt& a, const BigInt& b) {
    if (Null(b)) throw("Arithmetic Error: Division By 0");
    if (a < b) {
        a = BigInt();
        return a;
    }
    if (a == b) {
        a = BigInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Length(a), m = Length(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--) {
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t; cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a.digits.resize(cat.size());
    for (i = 0; i < lgcat; i++)
        a.digits[i] = cat[lgcat - i - 1];
    a.digits.resize(lgcat);
    return a;
}
BigInt operator/(const BigInt& a, const BigInt& b) {
    BigInt temp;
    temp = a;
    temp /= b;
    return temp;
}

BigInt& operator%=(BigInt& a, const BigInt& b) {
    if (Null(b)) throw("Arithmetic Error: Division By 0");
    if (a < b) {
        a = BigInt();
        return a;
    }
    if (a == b) {
        a = BigInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Length(a), m = Length(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--) {
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t; cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a = t;
    return a;
}
BigInt operator%(const BigInt& a, BigInt& b) {
    BigInt temp;
    temp = a;
    temp %= b;
    return temp;
}

BigInt& operator^=(BigInt& a, const BigInt& b) {
    BigInt Exponent, Base(a);
    Exponent = b;
    a = 1;
    while (!Null(Exponent)) {
        if (Exponent[0] & 1)
            a *= Base;
        Base *= Base;
        divide_by_2(Exponent);
    }
    return a;
}
BigInt operator^(BigInt& a, BigInt& b) {
    BigInt temp(a);
    temp ^= b;
    return temp;
}

void divide_by_2(BigInt& a) {
    int add = 0;
    for (int i = a.digits.size() - 1; i >= 0; i--) {
        int digit = (a.digits[i] >> 1) + add;
        add = ((a.digits[i] & 1) * 5);
        a.digits[i] = digit;
    }
    while (a.digits.size() > 1 && !a.digits.back()) a.digits.pop_back();
}
BigInt sqrt(BigInt& a) {
    BigInt left(1), right(a), v(1), mid, prod;
    divide_by_2(right);
    while (left <= right) {
        mid += left;
        mid += right;
        divide_by_2(mid);
        prod = (mid * mid);
        if (prod <= a) {
            v = mid;
            ++mid;
            left = mid;
        }
        else {
            --mid;
            right = mid;
        }
        mid = BigInt();
    }
    return v;
}
BigInt NthCatalan(int n) {
    BigInt a(1), b;
    for (int i = 2; i <= n; i++) a *= i;
    b = a;
    for (int i = n + 1; i <= 2 * n; i++) b *= i;
    a *= a;
    a *= (n + 1);
    b /= a;
    return b;
}

BigInt NthFibonacci(int n) {
    BigInt a(1), b(1), c;
    if (!n)
        return c;
    n--;
    while (n--) {
        c = a + b;
        b = a;
        a = c;
    }
    return b;
}
BigInt Factorial(int n) {
    BigInt f(1);
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}
istream& operator>>(istream& in, BigInt& a) {
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (!isdigit(s[i])) throw("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const BigInt& a) {
    for (int i = a.digits.size() - 1; i >= 0; i--) cout << (short)a.digits[i];
    return cout;
}


ull fastPow(ull b, ull power) {
    ull result = 1;
    while (power > 0) {
        if (power % 2 == 1) result = (result * b);
        b = (b * b);
        power /= 2;
    }
    return result;
}
ull fastPowMod(ull b, ull power, ull mod) {
    b %= mod;
    ull result = 1;
    while (power > 0) {
        if (power % 2 == 1) result = (result * b) % mod;
        b = (b * b) %mod;
        power /= 2;
    }
    return result;
}
#pragma endregion
auto leetCode(vector<int>& nums, int k) {

}
str seq(str s, ll n, ll max) {
    if (n == max + 1)return s;
    return seq(n==1?"1":s + " " + toStr(n) + " " + s, n + 1, max);
}
int main(void) {
    setup; 

    tc{
         ll n = get(), sum = n, maxOcc = 0;
         map<ll, ll> m;
     up(0, n, 1) {
         ll input = get();
         m[input]++;
     }
     foreach(p, m)maxOcc = max(maxOcc, p.second);
     ll ans = 0;
     while (maxOcc < n) {
         int d = min(n - maxOcc, maxOcc);
         ans += 1 + d;
         maxOcc += d;
     }
     cout << ans << '\n';
    }
    stop;
}

















