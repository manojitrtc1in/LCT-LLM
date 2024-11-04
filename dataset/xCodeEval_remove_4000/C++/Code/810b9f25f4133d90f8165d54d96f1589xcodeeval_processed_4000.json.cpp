















using namespace std;
typedef long long ll;

















typedef pair<int, int> PII;
typedef pair<double, double> PDD;
inline ll gcd(ll a, ll b) { return b > 0 ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline ll read() { ll f = 1; ll x = 0; char ch = getchar(); while (ch > '9' || ch < '0') { if (ch == '-') f = -1; ch = getchar(); }while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar(); return x * f; }
inline void write(int x) { if (x < 0) { putchar('-'); x = -x; }if (x > 9)write(x / 10); putchar(x % 10 + '0'); }
ll inf;
ll inv(ll x) { return x == 1 ? 1 : (inf - inf / x) * inv(inf % x) % inf; }
ll qpow(ll x, ll t) { return t ? qpow(sqr(x) % inf, t >> 1) * (t & 1 ? x : 1) % inf : 1ll; }























































































































int m[250200];




int dp[200200];
ll ans = 0;

signed main()
{
    

    IOS;
    inf = 1e9 + 7;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        int n;
        cin >> n;
        inc(i, 1, n)
        {
            cin >> m[i];
        }
        dec(i, n - 1, 1)
        {
            int q = m[i + 1];
            dec(k, i, 1)
            {
               
                int p = m[k];
                m[k] = q - m[k];
                q = p;
                if (p == 0) {
                    sort(m + k , m + 1 + i);
                    break;
                }
                if (k == 1) {
                    sort(m + 1, m + 1 + i);
                }
            }
        }
        cout << m[1] << endl;
       
        
         
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    return 0;
}
