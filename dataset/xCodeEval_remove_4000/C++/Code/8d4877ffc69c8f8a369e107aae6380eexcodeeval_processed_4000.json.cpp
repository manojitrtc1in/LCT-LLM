
















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


































































int m[550200];
int f[500200];
int dep[200200];
char mm[200200];
int in[200200], out[200200];
vector<int> g[250200];


ll ans = 0;
bool cmp(int a, int b)
{
    return dep[a] < dep[b];
}
void dfs(int wz, int b)
{
    dep[wz] = dep[b] + 1;
    f[wz] = b;
    for (auto p : g[wz])
    {
        if (p != b) {
            dfs(p, wz);
        }
    }
}

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
        set<PII>b;
        set<PII>a;
        inc(i, 1, n)
        {
            f[i] = 0;
            cin >> m[i];
           PII c;
                c = PII(i / (m[i] + 1) + 1,i) ;
      
                b.insert(c);

            
        }
        auto q = b.begin();
        inc(i, 1, n)
        {
            while (q != b.end()&&(*q).first<=i)
            {
                a.insert(PII((m[(*q).second]? (*q).second /m[(*q).second]:n),(*q).second));
                q++;
            }
            f[(*a.begin()).second] = i;
            a.erase(a.begin());
        }
        inc(i, 1, n)cout << f[i] << " \n"[i == n];

        
         
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    return 0;
}
