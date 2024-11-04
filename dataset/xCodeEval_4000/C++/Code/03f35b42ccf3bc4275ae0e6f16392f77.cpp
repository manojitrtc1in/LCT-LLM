#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef long double ld;
#define txt                        \
    freopen("ip.txt", "r", stdin); \
    freopen("op.txt", "w", stdout)
#define a3 INT_MAX
#define i3 INT_MIN
#define a6 INT64_MAX
#define i6 INT64_MIN
#define F first
#define S second
#define pb push_back
#define ln(v) (int)v.size()
#define fo(i, n) for (int i = 0; i < (int)n; i++)
#define rep(i, k, n) for (int i = k < (int)n ? k : k - 1; k < (int)n ? i < (int)n : i >= (int)n; k < (int)n ? i += 1 : i -= 1)
#define quickie                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define deb(x) cout << (#x) << " " << (x) << "\n";
#define newl cout << "\n"
#define all(s) s.begin(), s.end()
#define pi 3.14159265358979323846
#define fp(x) fixed << setprecision(x) <<
#define ub(a, v) upper_bound(a.begin(), arr.end(), v)
#define lb(a, v) lower_bound(a.begin(), arr.end(), v)
#define w(t) while (t--)
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define modulo(S, N) ((S) & (N - 1))
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
#define swp(a, b) std::swap(a, b)
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define trac(...) __f1(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
    

}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
template <typename Arg1>
void __f1(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
    

}
template <typename Arg1, typename... Args>
void __f1(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << "\n";
    __f1(comma + 1, args...);
}
template <typename T, typename... Targs>
void out(T first, Targs... args)
{
    cout << first;
    if constexpr (sizeof...(args) > 0)
    {
        cout << ", ";
        out(args...);
    }
}
template <typename T>
T dist(T a, T b)
{
    if (a < 0 || b < 0)
    {
        if (a < 0 && b < 0)
        {
            return abs(abs(a) - abs(b));
        }
        return abs(a) + abs(b);
    }
    return abs(a - b);
}
template <typename T, typename... Targs>
void in(T &first, Targs &... args)
{
    cin >> first;
    if constexpr (sizeof...(args) > 0)
    {
        in(args...);
    }
}
template <class T>
bool eve(T a)
{
    return !(a & 1);
}
ll mod(ll a)
{
    if (a < 0)
    {
        a += 1000000007;
    }
    return a % 1000000007;
}
ll addmod(ll a, ll b)
{
    return (mod(a) + mod(b)) % 1000000007;
}
ll prodmod(ll a, ll b)
{
    return (mod(a) * mod(b)) % 1000000007;
}
ll e(ll a, ll b)
{
    ll res = 1;
    ll temp = 1;
    if (b == 1)
        return a;
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        res = e(a * a, b / 2);
    else
    {
        res *= a;
        temp = e(a, --b);
    }
    return res * temp;
}
ll emod(ll a, ll b)
{
    ll res = 1;
    ll temp = 1;
    if (b == 1)
        return a;
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        res = emod(prodmod(a, a), b / 2);
    else
    {
        res = prodmod(a, res);
        temp = emod(a, --b);
    }
    return prodmod(res, temp);
}

template <class T>
bool isPrime(T n)
{
    

    if (n <= 1)
        return false;

    

    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}
template <class T>
vi &seive(T NN)
{
    NN++;
    vector<int> *temp = new vector<int>(NN);
    vector<int> &prime = *temp;
    for (ll i = 1; i < NN; i++)
        prime[i] = 1;
    for (int i = 2; i < NN; i++)
    {
        if (prime[i])
        {

            for (ll j = 2 * i; j < NN; j += i)
                if (prime[j])
                    prime[j] = i;
        }
    }
    return prime;
}
template <class T>
void peakValley(vector<T> &arr)
{
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    int n = ln(arr);
    arr.resize(n + 2);
    rotate(arr.begin(), arr.begin() + n + 1, arr.end());
    arr[0] = arr[1];

    bool sign = 1;
    ll sum = 0;
    T lastValley = -1;
    T lastPeak = -1;
    T firstValley = -1;
    T firstPeak = -1;
    bool fp = 1;
    bool fv = 1;
    cout << "all valleys ";
    for (int i = 1; i < n + 2 - 1; i++)
    {
        

        if (arr[i - 1] <= arr[i] and arr[i] >= arr[i + 1])
        {
            

            if (fp)
            {
                firstPeak = arr[i];
                fp = 0;
            }
            sign = 0;
            sum += arr[i];
            lastPeak = arr[i];
        }
        if (arr[i - 1] >= arr[i] and arr[i] <= arr[i + 1])
        {
            

            if (fv)
            {
                firstValley = arr[i];
                fv = 0;
            }
            cout << arr[i] << " ";
            sign = 1;
            sum -= arr[i];
            lastValley = arr[i];
        }
    }
    

    

    

}
template <class T>
void findLocalMaximaMinima(vector<T> arr)
{
    int n = arr.size();
    vector<int> mx, mn;

    if (arr[0] > arr[1])
        mx.push_back(0);

    else if (arr[0] < arr[1])
        mn.push_back(0);

    for (int i = 1; i < n - 1; i++)
    {

        if ((arr[i - 1] > arr[i]) and
            (arr[i] < arr[i + 1]))
            mn.push_back(i);

        else if ((arr[i - 1] < arr[i]) and
                 (arr[i] > arr[i + 1]))
            mx.push_back(i);
    }
    if (arr[n - 1] > arr[n - 2])
        mx.push_back(n - 1);

    else if (arr[n - 1] < arr[n - 2])
        mn.push_back(n - 1);
}
template <class T>
bool ispeak(int i, vector<T> a)
{
    int n = a.size();
    if (i < 0 || i >= n)
        return 0;
    return ((i == 0 || a[i - 1] < a[i]) && ((i == n - 1) || a[i] > a[i + 1]));
}
template <class T>
bool islow(int i, vector<T> a)
{
    int n = a.size();
    if (i < 0 || i >= n)
        return 0;
    return ((i > 0 && i < n - 1 && a[i - 1] > a[i] && a[i + 1] > a[i]));
}
template <class T>
int digits(T a)
{
    vector<long long> dig = {
        0,
        9,
        99,
        999,
        9999,
        99999,
        999999,
        9999999,
        99999999,
        999999999,
        9999999999,
        99999999999,
        999999999999,
        9999999999999,
        99999999999999,
        999999999999999,
        9999999999999999,
        99999999999999999,
        999999999999999999,
        INT64_MAX};
    auto it = lower_bound(dig.begin(), dig.end(), a);
    int idx = (it - dig.begin());
    return idx;
}
template <class T>
int sumint(T n)
{
    int a = 1;
    int su = 0;
    while (n)
    {
        su += n % 10;
        n /= 10;
    }
    return su;
}
template <class T>
void split(char c, T s)
{
    int n = s.size();
    int i = 0;
    while ((cout << s[i], i += 1) && (i < n) && (cout << c << ' '))
        ;
}
template <class T>
ll fib(T a)
{
    return ((a * (a + 1)) / 2);
}

template <class T>
ll nC2(T a)
{
    return ((a * (a - 1)) / 2);
}

template <class T>
vector<T> &divisors(T n)
{
    vector<T> *res = new vector<T>;
    vector<T> &ret = *res;
    int R = sqrt(n);
    ret.resize(R);
    int start = 0;
    int end = R - 1;
    for (int i = 2; i <= R; i++)
    {
        if (n % i == 0)
        {
            ret[start] = i;
            start++;
            T etc = n / i;
            if (etc != i)
            {
                ret[end] = etc;
                end--;
            }
        }
    }
    int s = INT_MAX;
    int en = -1;
    for (int i = 0; i < R; i++)
    {
        if (!ret[i])
        {
            s = min(s, i);
            en = i;
        }
    }
    if (en - s >= 0)
        ret.erase(ret.begin() + s, ret.begin() + en + 1);
    return ret;
}
template <class T>
void pvec(vector<T> &vec)
{
    for (auto c : vec)
        cout << c << " ";
}
ll strsum(string s)
{
    ll ret = 0;
    rep(i, ln(s), 0)
    {
        ret += s[i] - '0';
    }
    return ret;
}
bool isPalindrome(string str)
{
    int l = 0;
    int h = ln(str) - 1;

    while (h > l)
    {
        if (str[l++] != str[h--])
        {

            return 0;
        }
    }
    return 1;
}
string addstr(string a, string b)
{
    ll m = ln(a);
    ll n = ln(b);
    ll z = max(n, m);
    string c = string(z, '0');
    bool carry = 0;
    while (n > 0 || m > 0)
    {
        int t = ((m - 1 >= 0) ? (a[m - 1] - '0') : 0) + ((n - 1 >= 0) ? (b[n - 1] - '0') : 0) + carry;
        carry = (t > 9) ? 1 : 0;
        z--;
        c[z] = '0' + (t % 10);
        n--;
        m--;
    }
    if (carry)
        c = "1" + c;
    return c;
}
template <class T>
bool ith(T a, int b)
{
    return ((a & ((ll)1 << (b - 1))));
}
template <class T>
vector<ll> &presum(vector<T> a)
{
    vector<ll> *temp = new vector<ll>(ln(a));
    vector<ll> &ret = *temp;
    ll sum = 0;
    fo(i, ln(a))
    {
        sum += a[i];
        ret[i] = sum;
    }
    return ret;
}
template <class T>
vector<ll> &postsum(vector<T> a)
{
    vector<ll> *temp = new vector<ll>(sz(a));
    vector<ll> &ret = *temp;
    ll sum = 0;
    rep(i, sz(a), 0)
    {
        sum += a[i];
        ret[i] = sum;
    }
    return ret;
}

int no1(string &s)
{
    int cnt = 0;
    fo(i, ln(s))
    {
        if (s[i] == '1')
        {
            cnt++;
        }
    }
    return cnt;
}










void solve(int &test)
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    vector<int> b(n);
    int ans = i3;
    int on = 0;
    fo(i, ln(s))
    {
        if (s[i] == '1')
        {
            on++;
        }
    }
    fo(i, n)
    {
        cin >> a[i];
        cin >> b[i];
    }
    fo(i, 1001)
    {
        fo(j, n)
        {
            if (i >= b[j] and (i == b[j] or (i - b[j]) % a[j] == 0))
            {
                if (s[j] == '1')
                {
                    s[j] = '0';
                }
                else
                {
                    s[j] = '1';
                }
            }
        }
        ans = max(ans, no1(s));
    }
    cout << ans;
}


int main()
{
    quickie;
    

#ifdef amit
    freopen("ip.txt", "r", stdin);
#endif
    int a = 0;
    int f = 1;
    int test;
    test = a;
    if (test)
        cin >> test;
    else
        test = 1;
    while (test--)
    {
        solve(test);
        newl;
    }
    

    return 0;
}