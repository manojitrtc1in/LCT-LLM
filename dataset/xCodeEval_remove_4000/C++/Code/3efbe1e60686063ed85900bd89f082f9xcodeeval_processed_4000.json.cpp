




































































     for (ll i = 0; i < u; ++i) \
     {                          \
          ll x;                 \
          cin >> x;             \
          v.pb(x);              \
     }

     ll t;     \
     cin >> t; \
     while (t--)



using namespace std;

int digits(ll n)
{
     int k = 0;
     while (n > 0)
     {
          n = n / 10;
          k++;
     }
     return k;
}

ll gcd(ll a, ll b)
{
     if (b == 0)
          return a;
     else
          return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
     return (a * b) / gcd(a, b);
}

ll power(ll a, ll b)
{
     ll sum = 1;
     while (b > 0)
     {
          sum = sum * a;
          b--;
     }
     return sum;
}

ll ncr(ll n, ll r)
{
     ll ans = 1;
     for (ll i = n; i > n - r; i--)
     {
          ans *= i;
     }
     for (ll i = r; i >= 1; i--)
     {
          ans /= i;
     }
     return ans;
}

ll nc2(ll n)
{
     return (n * (n - 1)) / 2;
}

void swap(int *a, int *b)
{
     int temp = *a;
     *a = *b;
     *b = temp;
}

void sum()
{

     string s;
     cin >> s;
     string s1 = s;
     string s2 = "";
     ll n = s.length();
     isortstring(s);
     forll
     {
          if (s1[i] != s[0])
          {
               s2 = s2 + s1[i];
          }
          else
          {
               break;
          }
     }
     ll p = s2.length();
     cout << s[0] << " ";
     for (ll i = 0; i < p; ++i)
     {
          cout << s2[i];
     }
     for (ll i = p + 1; i < n; ++i)
     {
          cout << s1[i];
     }
     cout << endl;
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     tc
     {
          sum();
     }

     return 0;
}
