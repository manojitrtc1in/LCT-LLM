


using namespace std;
using base = complex<double>;


using namespace __gnu_pbds;









































ll modI(ll a, ll m);
ll gcd(ll a, ll b);
ll powM(ll x, unsigned ll y, unsigned ll m);
void pairsort(int a[], int b[], int n);
void id0(ll a[], ll b[], ll n);
ll logint(ll x, ll y);

ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

ll powM(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    ll p = powM(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}


ll modI(ll a, ll m)
{
    ll m0 = m, y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}






























































ll logint(ll x, ll y)
{
    ll ans = 0;
    ll a = 1;
    for (ll i = 0; i <= x; i++)
    {
        if (x < a)
        {
            return ans;
        }
        ans++;
        a *= y;
    }
    return -1;
}



ll extended(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = extended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
































































































































int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    

    int ntc;
    

    ntc =1;
    REP(tc, 1, ntc + 1)
    {
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        ll n;
        cin>>n;
        cout<<3<<" "<<3<<"\n";
        cout<<((1<<18)-1)<<" "<<(1<<17)<<" "<<0<<"\n";
        cout<<((1<<17)-1)<<" "<<((1<<18)-1)<<" "<<n<<"\n";
        cout<<0<<" "<<0<<" "<<((1<<18)-1)<<"\n";
        
    }
}