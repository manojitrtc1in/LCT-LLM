









    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)



























































































using namespace std;

const int MOD = 1e9 + 7; 

const int MAX = 1e9 + 5;
const ll INF = 1e18;
const double PI = acos(-1.0);

int msb(ll n)
{
    int ans;
    for (int i = 0; i < 64; i++)
        if (n & (1LL << i))
            ans = i + 1;
    return ans;
}
int SetBit(int n, int X) { return n | (1 << X); }
int ClearBit(int n, int X) { return n & ~(1 << X); }
int ToggleBit(int n, int X) { return n ^ (1 << X); }
bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }
ll powmod(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
    }
    return res;
}




long long operator"" _m(unsigned long long literal) { return literal; }
long double operator"" _cm(unsigned long long literal) { return literal / 100.0; }
long long operator"" _km(unsigned long long literal) { return literal * 1000; }







    {                                            \
        string _s = 
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}




string id0(char &C) { return string(1, C); }
bool vowel(char C)
{
    C = tolower(C);
    return (C == 'a' || C == 'e' || C == 'i' || C == 'o' || C == 'u');
}
string id12(ll S)
{
    stringstream SS;
    SS << S;
    return SS.str();
}
ll id8(string &S)
{
    ll X;
    stringstream SS(S);
    SS >> X;
    return X;
}
vll id9(string &S)
{
    ll Z = len(S);
    vll A(Z);
    rep(i, 0, Z) A[i] = S[i] - '0';
    return A;
}
string id3(vll &A)
{
    ll Z = len(A);
    string S(Z, ' ');
    rep(i, 0, Z) S[i] = A[i] + '0';
    return S;
}
ll id14(ll &X)
{
    string S = id12(X);
    reverse(all(S));
    return id8(S);
}

bool pal(string &S)
{
    ll X = 0, y = len(S);
    for (; X < y / 2; X++)
        if (S[X] != S[y - X - 1])
            return 0;
    return 1;
}
bool pal(string &S, ll X, ll y)
{
    for (; X < y; X++, y--)
        if (S[X] != S[y])
            return 0;
    return 1;
}
string binary(ll X)
{
    string S;
    for (; X; X /= 2)
        S.pb(X % 2 ? '1' : '0');
    reverse(all(S));
    return S;
}
ll decimal(string &S)
{
    ll dm = 0, ct = 1;
    repb(i, len(S) - 1, 0)
    {
        dm += ct * (S[i] == '1');
        ct *= 2;
    }
    return dm;
}

string id20(const string &a)
{
    string s = a;
    reverse(s.begin(), s.end());
    s = a + "%" + s;
    int c = 0;
    vector<int> pref(2 * ((int)a.size()) + 2);
    for (int i = 1; i < s.size(); i++)
    {
        while (c != 0 && s[i] != s[c])
            c = pref[c - 1];
        if (s[i] == s[c])
            c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}

int id17(string n)
{
    string num = n;
    int dec_value = 0;
    int base = 1;
    int len = num.length() - 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
string id18(string a, string b)
{
    string s = "";
    while (a.size() < b.size())
    {
        a = '0' + a;
    }
    while (a.size() > b.size())
    {
        b = '0' + b;
    }
    ll c = 0;
    for (ll i = a.size() - 1; i >= 0; i--)
    {
        c += (a[i] - '0') + (b[i] - '0');
        s = char((c % 10) + '0') + s;
        c /= 10;
    }
    while (c > 0)
    {
        s = char((c % 10) + '0') + s;
        c /= 10;
    }
    return s;
}
ll id11(string digits)
{
    ll num, total = 0;
    for (int i = 0; i < digits.length(); i++)
    {
        num = digits.at(i) - '0';
        assert(0 <= num && num <= 9);
        total += num;
    }
    return total;
}
ll id1(ll n)
{
    ll sum = 0;
    while (1)
    {
        if (n < 10)
        {
            sum += n;
            break;
        }
        else
        {
            sum += n % 10;
            n /= 10;
        }
    }
    return sum;
}




int sum() { return 0; }
template <typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }
ll vsum(vll v, ll s, ll e)
{
    ll S = 0;
    rep(i, s, e) S += v[i];
    return S;
}
ll _sum_(vll &V)
{
    ll S = 0;
    for (ll X : V)
        S += X;
    return S;
}
ll _min_(vll &V)
{
    ll M = V[0];
    for (ll X : V)
        M = min(M, X);
    return M;
}
ll _max_(vll &V)
{
    ll M = V[0];
    for (ll X : V)
        M = max(M, X);
    return M;
}
ll id2(vll &V)
{
    ll G = 0;
    for (ll X : V)
        G = lcm(G, X);
    return G;
}
ll id10(vll &V)
{
    ll G = 0;
    for (ll X : V)
        G = __gcd(G, X);
    return G;
}
ll id13(vll &V)
{
    ll G = 0;
    for (ll X : V)
        G ^= X;
    return G;
}
vll id4(vll &V)
{
    vll O;
    for (ll X : V)
        if (X % 2)
            O.pb(X);
    return O;
}
vll _even_(vll &V)
{
    vll E;
    for (ll X : V)
        if (!(X % 2))
            E.pb(X);
    return E;
}










sim > T power(T X, ll y)
{
    T A = (T)1;
    for (; y; y >>= 1, X = (X * X))
        if (y & 1)
            A = (A * X);
    return A;
}
sim > T powerm(T X, ll y, ll M = MOD)
{
    T A = (T)1;
    for (; y; y >>= 1, X = (X * X) % M)
        if (y & 1)
            A = (A * X) % M;
    return A;
}
sim > T inv(T X, ll mod = MOD) { return powerm(X, mod - 2, mod); }

bool id5(ll x) { return x && (!(x & (x - 1))); }
bool id7(long double x)
{
    long double sr = sqrt(x);
    return ((sr - floor(sr)) == 0);
}
ll digNO(ll num) { return floor(log10(num)) + 1; }
int id6(int n)
{
    int lo = 0, hi = n;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (mid * mid <= n)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo - 1;
}
ll fib(ll n)
{
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}
bool primeCheck(long long n)
{
    if (n % 2 == 0)
        return false;
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll gcd(ll n1, ll n2)
{
    while (n1 != n2)
    {
        if (n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    return n1;
}
ll LCM(ll n1, ll n2)
{
    ll m = max(n1, n2);
    do
    {
        if (m % n1 == 0 && m % n2 == 0)
            return m;
        else
            ++m;
    } while (true);
}

sim > T nc2(T X)
{
    if (X < 2)
        return 0;
    return (X * (X - 1)) / 2;
}
ll nck(ll X, ll K)
{
    if (X < K)
        return 0;
    ll A = 1;
    K = min(K, X - K);
    rep(i, 0, K) A *= (X - i), A /= (i + 1);
    return A;
}
sim > ld dis(T x1, T y1, T x2, T y2) { return sqrt((ld)(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }




ll fact(ll num)
{
    ll fac = 1;
    while (num != 1)
    {
        fac = fac * num;
        num--;
    }
    return fac;
}
vll fac_help(ll X)
{
    vll V;
    for (ll i = 1; i * i <= X; i++)
    {
        if (X % i == 0)
        {
            V.pb(i);
            if (X / i != i)
                V.pb(X / i);
        }
    };
    return V;
}
vll factors(ll X)
{
    vll V = fac_help(X);
    sort(all(V));
    return V;
}
void prime_help(ll &X, ll y, vll &V)
{
    if (X % y == 0)
        V.pb(y);
    while (X % y == 0)
        X /= y;
}
vll primeFac(ll X)
{
    vll V;
    prime_help(X, 2, V);
    for (ll i = 3; i * i <= X; i += 2)
        prime_help(X, i, V);
    if (X != 1)
        V.pb(X);
    return V;
}
vll id15(ll L)
{
    vb PR(L += 5, 1);
    vll V;
    for (ll i = 2; i * i < L; i++)
        if (PR[i])
            repi(j, i * i, L + 1, i) PR[j] = 0;
    rep(i, 2, L - 5) if (PR[i]) V.pb(i);
    return V;
}
vb id19(ll L)
{
    vb PR(L += 5, 1);
    for (ll i = 2; i * i < L; i++)
        if (PR[i])
            repi(j, i * i, L + 1, i) PR[j] = 0;
    PR[1] = 0;
    return PR;
}

vll input(vll v, ll n)
{
    wh(n--)
    {
        ll a;
        cin >> a;
        v.eb(a);
    }
    return v;
}
void prnt(vll v)
{
    ll n = v.size();
    for (ll i = 0; i < n; i++)
        cout << v[i] << " \n"[i == n - 1];
}

bool compare(const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; }

const int Max = 1e8;
int status[(Max >> 5) + 2];
bool Check(int n, int pos) { return (bool)(n & (1 << pos)); }
int Set(int n, int pos) { return n = n | (1 << pos); }
vector<ll> primes;
void id16()
{
    int sqrtN = sqrt(Max);
    for (int i = 3; i <= sqrtN; i += 2)
    {
        if (Check(status[i >> 5], (i & 31)) == 0)
        {
            for (int j = i * i; j <= Max; j += (i << 1))
            {
                status[j >> 5] = Set(status[j >> 5], (j & 31));
            }
        }
    }
    primes.push_back(2);
    for (ll i = 3; i <= Max; i += 2)
        if (Check(status[i >> 5], i & 31) == 0)
            primes.push_back(i);
}
int exp(int x, unsigned int y, int p){
    int res=1; x=x%p;
    while(y>0){
        if (y&1) res= (res*x)%p; y=y>>1; x=(x*x)%p;
    }
    return res;
}
ll divSum(ll n)
{

int s=0;
    int sq = sqrt(n);
    int inv = exp(2,MOD-2,MOD);
    for (int i = 1; i <= sq; i++) {
        int x = (n/i - n/(i+1))%MOD;
        int r = n/i, l = n/(i+1) + 1;
        s = ( s + x*((l+r)%MOD)%MOD*inv%MOD*i%MOD)%MOD;
    }
    for (int i = 1; i <= n/(sq+1); i++) {
        s = (s + n/i*i) % MOD;
    }

    return s;
}


int main()
{


    ll a, b, i, d, o, c, g, e, r, j, k, l, f = 0, h = 0, ttt = 0, m, n, q, p, t, w, cnt;
    string s, s1;
    char cc;
    sf1(ttt);
    while (ttt--)
    {
        cin>>a>>b;
        vll v;
            c=a;
            for(i=1;i<=a;i++)
            {
                v.pb(i);
            }
        if(a%2==0)
        {
            k=(a/2)-1;
        }
        else k=(a/2);
        if(b==0)
        {
            for(i=0;i<a;i++)
            {
                cout<<v[i]<<" ";

            }
            cout<<endl;
        }
        else if(b>k || a<=2) cout<<-1<<endl;
        else
        {

            j=1;
            for(i=0;i<b;i++)
            {
                v.insert(v.begin()+j,c);
                j+=2;
                c--;
            }
            for(i=0;i<a;i++)
            {
                cout<<v[i]<<" ";

            }
            cout<<endl;

        }



    }

    rt;
}
