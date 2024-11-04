
#define JaiShreeRam







#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

using ll = long long;
using ld = long double;
using ull = __int64;
using st = string;

#define For(i, a, b) for (int i = a; i < b; i++)
#define Forl(i, size) for (int i = 0; i < size; i++)
#define Forr(i, size) for (int i = size - 1; i >= 0; i--)
#define ForR(i, a, b) for (int i = a; i >= b; i--)

#define cntd continue;
#define pb push_back
#define contd continue;
#define clr(a) memset(a, 0, sizeof(a));
#define all(c) (c).begin(), (c).end()
#define len length()
#define size size()
#define mp make_pair
#define fi first
#define se second
#define ret return 0;
#define NIL -1

#define en cout << "\n";
#define endl "\n"
#define sqrt sqrtl

#define beg begin()
#define rbeg rbegin()

#define ram(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define sita(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<ull> vull;
typedef vector<string> vst;
typedef vector<bool> vb;
typedef vector<char> vch;
typedef vector<ld> vld;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const ld Pi = 3.1415926535;
const long long Mod = 1e9 + 7;
const int N = 1e5 + 9;
const ll inf = (ll)2e18;
const ll ninf = (ll)-2e18;
const ll sInf = (ll)2e9;
const ll sNinf = (ll)-2e9;
const ld epsilon = (ld)1e-12;

ll sum = 0, ans = 0;
string res{};

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

#ifdef JaiShreeRam
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

bool mahadev(const pair<int, int> &a,
             const pair<int, int> &b)
{
    if (a.se == b.se)
        return (a.fi < b.fi);

    return (a.se < b.se);
}

template <class T>
bool ckmin(T &a, T &b)
{
    bool B = a > b;
    a = min(a, b);
    return B;
}
template <class T>
bool ckmax(T &a, T &b)
{
    bool B = a < b;
    a = max(a, b);
    return B;
}

ld getDist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
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

set<ll> fac;
void allFactors(ll n)
{
    for (ll i = 1; i <= sqrt(n); i++)
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
    fac.insert(n);
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
    ll temp;
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
    if (n == 0)
        return (ull)0;
    if (n < r)
        return ull(0);
    if (n == r)
        return (ull)1;

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

ld angleClock(int hour, int minutes)
{
    long double hourAngle = (ld)((hour % 12) + minutes * (ld)1.0 / (ld)60) * (ld)30;
    long double minutesAngle = (ld)minutes * (ld)6;
    long double a = abs((ld)hourAngle - (ld)minutesAngle);
    long double b = (ld)360 - (ld)a;
    return a < b ? a : b;
}

int cntDig(ll n)
{
    return floor(log10(abs(n)) + 1);
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


string s[N][4];
int k;
string rs[]={"aaaa","aabb","abba","abab","NO"};
string rhyme(int n)
{string a[4];int pk=k;
int f=0;
    For(i,0,4)
    {pk=k;
        ForR(j,s[n][i].len-1,0)
        {
            if (s[n][i][j] == 'a' || s[n][i][j] == 'e' || s[n][i][j] == 'i' || s[n][i][j] == 'o' || s[n][i][j] == 'u' )
            {
                pk-=1;
                if(!pk)
                {
                    a[i]=s[n][i].substr(j);
                    

                    f+=1;
                    break;
                }
            }
        }
    }
    if(f<4)return rs[4];
    if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])
    {
        return rs[0];
    }
    if(a[0]==a[1]&&a[2]==a[3])
    {
        return rs[1];
    }
    if (a[0] == a[3] && a[1] == a[2])
    {
        return rs[2];
    }
    if (a[0] == a[2] && a[1] == a[3])
    {
        return rs[3];
    }
    return rs[4];
}
signed main()
{
    boost

        


        

        string aux1{},
        aux2{}, aux3{};

    ll T = 1;

    


    For(_____, 1, T + 1)
    {

        int f = 0, fl1 = 0, fl2 = 0, u = 0, v = 0, w = 0, c1 = 0, c2 = 0, cont = 0, cnt = 0, c3 = 0, auxi = 0, auxj = 0;
        ll mi = inf, le = 0;
        ll ma = ninf, sol = 0;

        int n;
        cin>>n>>k;
        For(i,0,n)
        {
            For(j,0,4)cin>>s[i][j];
        }
        set<string> S;
        For(i,0,n)
        {
            string pp = rhyme(i);
            if(pp==rs[4])
            {
                cout << rs[4]<<endl;
                ret
            }
            if(pp==rs[0]){cntd;}
            if(S.find(pp)==S.end())
            {
                S.insert(pp);
                if(S.size>=2)
                {
                    cout<<rs[4]<<endl;ret
                }
            }
            

            
            
        }
        if(S.size==0)cout<<rs[0]<<endl;
        else
        {
            cout<<*(S.rbegin())<<endl;
        }
        

    }

    return 0;
}





