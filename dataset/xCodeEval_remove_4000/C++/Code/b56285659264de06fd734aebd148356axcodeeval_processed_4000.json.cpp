
















using namespace std;
typedef long long ll;

















typedef pair<int, int> PII;
inline ll gcd(ll a, ll b) { return b > 0 ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline ll read() { ll f = 1; ll x = 0; char ch = getchar(); while (ch > '9' || ch < '0') { if (ch == '-') f = -1; ch = getchar(); }while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar(); return x * f; }
inline void write(int x) { if (x < 0) { putchar('-'); x = -x; }if (x > 9)write(x / 10); putchar(x % 10 + '0'); }
ll inf;
ll inv(ll x) { return x == 1 ? 1 : (inf - inf / x) * inv(inf % x) % inf; }
ll qpow(ll x, ll t) { return t ? qpow(sqr(x) % inf, t >> 1) * (t & 1 ? x : 1) % inf : 1ll; }
int sx[5] = { 0,0,1,-1 };
int zy[5] = { 1,-1,0,0 };






























































int m[1200200];






ll ans = 0;
int x[1000100], y[1001000];
signed main()
{
    

   

    inf = 1e9 + 7;
    int _;
    cin >> _;
    while (_--)
    {
        int a, b;
        cin >> a >> b;
        inc(i, 0, a*b)x[i] = 0;
        inc(i, 0, b)y[i] = 0;
        string str;
        cin >> str;
        int xx = 0, yy = 0;
        m[0] = -1;
        inc(i, 0, a * b - 1)
        {
            if(i)m[i] = m[i - 1];
            if (str[i] == '1')m[i] = i;
            if (!y[i % b] && str[i] == '1')y[i % b] = 1, yy++;
            if (i >= b)
            {
                x[i] = x[i - b];
            }
            x[i] += (m[i] > i - b)&&m[i]>=0;
            xx = x[i];
            cout << xx + yy << " \n"[i == a * b - 1];
        }
      
        
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    return 0;
}
