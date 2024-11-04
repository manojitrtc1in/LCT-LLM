


#include <bits/stdc++.h>
using namespace std;

#define For(i, a, b) for (int i = a; i < b; i++)
#define Forl(i, size) for (int i = 0; i < size; i++)
#define Forr(i, size) for (int i = size - 1; i >= 0; i--)
#define ForR(i, a, b) for (int i = a; i >= b; i--)
#define s(n) scanf("%d", &n)
#define p(n) printf("%d\n", n)
#define ps(n) printf("%s\n", n)
#define cntd continue;
#define sd(n) \
    int n;    \
    scanf("%d", &n)
#define sl(n)        \
    long long int n; \
    scanf("%lld", &n)
#define pb(n) push_back(n)
#define contd continue;
#define clr(a) memset(a, 0, sizeof(a));
#define all(c) (c).begin(), (c).end()
#define len length()
#define size size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
typedef __int64 ull;
#define ret return 0;
#define PI 3.14159265
#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
const long long Mod = 1e9 + 7;
typedef long long ll;
typedef long double ld;



typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vst;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll sum = 0, ans = 0, res = 0;



vector<string> vec_splitter(string s)
{
    s += ',';
    vector<string> res;
    while (!s.empty())
    {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(vector<string> __attribute__((unused)) args, __attribute__((unused)) int idx) { cerr << endl; }
void debug_out(
    vector<string> __attribute__((unused)) args,
    __attribute__((unused)) int idx,
    __attribute__((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
    if (idx > 0)
        cerr << ", ";
    else
        cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss;
    ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#define watch(x) cout << (#x) << " is " << (x) << endl;




#define XOX




#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>>
{
    static_assert(D >= 1, "Vector dimension must be greater than zero!");
    template <typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...))
    {
    }
};
template <typename T>
struct Vec<1, T> : public vector<T>
{
    Vec(int n = 0, const T &val = T()) : vector<T>(n, val)
    {
    }
};

bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    if (a.se == b.se)
        return (a.fi < b.fi);

    return (a.se < b.se);
}




bool isPrime(ll num)
{
    bool flag = true;
    if (num == 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
set<ull> fac;
void allFactors(ull n)
{
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            fac.insert(i);
            if (i != n / i)
            {
                fac.insert(n / i);
            }
        }
    }
}







ll findSum(ll a[], int l, int r)
{
    ll sum = 0;
    For(i, l, r)
    {
        sum += a[i];
    }
    return sum;
}







vector<pair<int, int>> vec1; 

void primeFactors(ll n)
{
    int c1 = 0;
    

    while (n % 2 == 0)
    {
        

        n = n / 2;
        c1++;
    }
    if (c1)
        vec1.pb(mp(2, c1));
    c1 = 0;
    

    

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        c1 = 0;
        

        while (n % i == 0)
        {
            


            n = n / i;
            c1++;
        }
        if (c1)
            vec1.pb(mp(i, c1));
    }
    c1 = 0;
    

    

    if (n > 2)
        vec1.pb(mp(n, 1));
}






ll power(int x, unsigned int y)
{
    int temp;
    if (y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}



ll power(ll x, ll y, ll p)
{
    ll res = 1; 


    x = x % p; 

               


    if (x == 0)
        return 0; 


    while (y > 0)
    {
        

        if (y & 1)
            res = (res * x) % p;

        

        y = y >> 1; 

        x = (x * x) % p;
    }
    return res;
}




ull nCr(ll n, ll r)
{
    ull p = 1;
    ull k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
            p /= m;
            k /= m; 

            n--;
            r--;
        }
    }
    else
        p = 1;

    return p;
}






ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}






unsigned int countBits(ll n, int specify)
{
    unsigned int count = 0, total = 0;
    if (n == 0)
    {
        if (specify == 1)
            return 0;
        else
            return 1;
    }
    while (n)
    {
        total += 1;
        count += n & 1;
        n >>= 1;
    }
    if (specify == 1)
        return count;
    else
        return (total - count);
}




















































































































































































































































































void scar(ll a[], int n, int param = 0)
{
    if (param == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
    }
}




signed main()
{
    


    


    

    string aux1, aux2, aux3;

    ll T = 1;

    


    For(ZA, 1, T + 1)
    {

        int f = 0, fl1 = 0, fl2 = 0, u = 0, v = 0, w = 0, c1 = 0, c2 = 0, cont = 0, cnt = 0, c3 = 0, auxi = 0, auxj = 0;
        ll mi = INT_MAX, le = 0;
        ll ma = INT_MIN, sol = 0;
        int n;
        cin >> n;
        ll a[n];
        scar(a, n);
        string s;
        cin >> s;
        ma = 0;
        ll pref[n];

        For(i, 0, n)
        {
            if (!i)
            {
                if (s[i] == 'A')
                {
                    pref[i] = 0;
                }
                else
                {
                    pref[i] = a[i];
                }
            }
            else if (s[i] == 'A')
            {
                pref[i] = pref[i - 1];
            }
            else if (s[i] == 'B')
            {
                pref[i] = pref[i - 1] + a[i];
            }
        }
        ll suff[n];
        ForR(i, n - 1, 0)
        {
            if (i == n - 1)
            {
                if (s[i] == 'A')
                {
                    suff[i] = 0;
                }
                else
                {
                    suff[i] = a[i];
                }
            }
            else if (s[i] == 'A')
            {
                suff[i] = suff[i + 1];
            }
            else if (s[i] == 'B')
            {
                suff[i] = suff[i + 1] + a[i];
            }
        }
        ans = 0;
        For(i, 0, n)
        {
            if (s[i] == 'A')
            {
                sum += a[i];
            }
            else if (s[i] == 'B')
            {
                sum -= a[i];
            }
          ma=max(ma,sum);
            ans = max(ans, max(sum, 0ll) + suff[i]);
            

        }
        sum = 0;
        ForR(i, n - 1, 0)
        {
            if (s[i] == 'A')
            {
                sum += a[i];
            }
            else if (s[i] == 'B')
            {
                sum -= a[i];
            }
            ma=max(ma,sum);
            ans = max(ans, max(0ll, sum) + pref[i]);
            

        }
        cout << suff[0]+ma << endl;
    }

    return 0;
}





