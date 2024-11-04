














using namespace std;












    int n;    \
    scanf("%d", &n)

    long long int n; \
    scanf("%lld", &n)




















    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;
typedef __int64 ull;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<ull> vul;
typedef vector<string> vst;
typedef vector<bool> vb;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const ld Pi = 3.1415926535;
const long long Mod = 1e9 + 7;
const int N = 1e5 + 9;
const ll inf = (ll)2e18;
const ll ninf = (ll)-2e18;

ll sum = 0, ans = 0, res = 0;

vector<string> id0(string s)
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

bool mahadev(const pair<int, int> &a,
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



signed main()
{
    


    


    

    time_t t1, t2;
    t1 = clock();
    string aux1, aux2, aux3;

    ll T = 1;

    


    For(ZA, 1, T + 1)
    {

        int f = 0, fl1 = 0, fl2 = 0, u = 0, v = 0, w = 0, c1 = 0, c2 = 0, cont = 0, cnt = 0, c3 = 0, auxi = 0, auxj = 0;
        ll mi = inf, le = 0;
        ll ma = ninf, sol = 0;
        string s;
        cin >> s;
        int n = s.len;
        For(i, 0, n)
        {
            c1 += s[i] == '(';
            c2 += s[i] == ')';
            c3 += s[i] == '
        }
        if (c1 - c2 < c3)
        {
            cout << "-1\n";
            ret;
        }

        vi vv;
        int l = 0, r = 0, hi = 0;
        int i = 0;
        int dd=0,ff=0,kk=0;
        while (i < n)
        {
            

            if (s[i] == '(')
            {
                l++;
                i++;
                cntd;
            }
            else if (s[i] == '
            {
                r = l;
                hi = 0;

                while (i < n && s[i] == '
                {
                    hi++;
                    cont++;
                    if (cont == c3)
                    {
                        fl1 = 1;
                        break;
                    }
                    i++;
                }
                


                For(i, 0, hi - 1)
                {
                    vv.pb(1);
                    r -= 1;
                    if (r <= 0)
                    {
                        cout << "-1\n";
                        ret
                    }
                }
                if (fl1)
                {

                    while (i < n)
                    {
                        if (s[i] == '(')
                            {dd++;}
                        else if (s[i] == ')')
                            ff++;
                        
                        i++;
                    }
                    if(dd>ff)
                    {
                        cout << "-1\n";
                        ret
                    }
                    ff-=dd;
                    r-=ff;
                    if (r <= 0)
                    {
                        cout << "-1\n";
                        ret
                    }

                    vv.pb(r);
                    r = 0;
                }
                else
                {
                    vv.pb(1);
                    r -= 1;
                }
                l = r;
                r = 0;
            }

            else if (s[i] == ')')
            {
                l--;
                if (l < 0)
                {
                    cout << "-1\n";
                    ret
                }
                i++;
            }
        }

        if (s[n - 1] == '('||s[0]=='
        {
            cout << "-1\n";
            ret
        }
        if(l>0)
        {
            cout << "-1\n";
            ret
        }
        for (auto v : vv)
        {
            cout << v << "\n";
        }
    }

    

    

    

    

    


    return 0;
}





