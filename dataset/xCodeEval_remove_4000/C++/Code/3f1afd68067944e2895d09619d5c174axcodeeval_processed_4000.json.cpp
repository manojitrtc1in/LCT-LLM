



using namespace std;



    ios::sync_with_stdio(0); \
    cin.tie(0);























    for (int i = 0, entry; i < n and cin >> entry; i++) \
        s.emplace(entry);

    for (auto &i : s) \
        cout << i << " ";

    for (auto &i : d) \
        cin >> i;

    for (auto &i : d)     \
        cout << i << " "; \
    cout << '\n';

    for (auto &[f, s] : mp) \
        cout << f << "  " << s << "\n";

    while (!s.empty())          \
    {                           \
        cout << s.top() << " "; \
        s.pop();                \
    }                           \
    cout << '\n';




    int t;    \
    cin >> t; \
    while (t--)














template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};
template <typename T>
void Unique(T &a) { a.erase(unique(a.begin(), a.end()), a.end()); }


long long gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


long long lcm(long long a, long long b)
{
    if (a > b)
        return (a / gcd(a, b)) * b;
    else
        return (b / gcd(a, b)) * a;
}








using namespace std;

bool isPrime(ll n)
{
    if (n == 2)
    {
        return true;
    }
    if (n < 2 || n % 2 == 0)
    {
        return false;
    }
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}


vector<bool> primes((1e6 + 1), true);
void sieven(int n)
{
    primes[0] = primes[1] = false;
    for (ll i = 2; i <= n + 1; i++)
    {
        if (primes[i])
        {
            for (ll j = i * i; j <= n + 1; j += i)
                primes[j] = false;
        }
    }
}

int mod = 1e9 + 7;


long long fastPower(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


long long fastPower(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


bool id0(int n)
{
    return (ceil(log2(n)) == floor(log2(n)));
}



vl p;
void dv(ll x)
{
    for (ll j = 2; (j * j) <= x; j++)
    {
        if (x % j == 0)
        {
            p.pb(j);
            if (j != (x / j))
                p.pb(x / j);
        }
    }
}


bool check(string s)
{
}
void pf(int n)
{
    while (n % 2 == 0)
    {
        p.pb(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            p.pb(i);
            n = n / i;
        }
    }
    if (n > 2)
        p.pb(n);
}
int check(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
const double PI = 3.14159265359, EPS = 1e-9;
const int N = 100005, M = 202, Mod = 1000000007, OO = 1000000000;
int rec(string s, int size)
{
    if (size - 1 == 0)
    {
        return check(s[size - 1]);
    }

    return check(s[size - 1]) + rec(s, size - 1);
}

void solve()
{

    int n;
    cin >> n;
    if (n & 1)
    {
        cout << 1 << sp;
        for (int i = 2; i <= n; i+=2)
        {
            cout << i + 1 << sp << i << sp;
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= n; i += 2)
        {
            cout << i +1<< sp << i  << sp;
        }
        cout << endl;
    }
    

    

    

}

int main()
{
    fast
        tc
        solve();
    return 0;
}
