
















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


































































int m[200200];






ll ans = 0;
int x[100100], y[100100];
map<int, int>xx;
bool vis[100100];
int zx[100100], zy[100100];
signed main()
{
    

   

    inf = 1e9 + 7;
    int _;
    cin >> _;
    while (_--)
    {
        int n;
        cin >> n;
        xx.clear();
        inc(i, 1, n)
            cin >> x[i], xx[x[i]] = i, vis[i] = 0;
        inc(i, 1, n)
            cin >> y[i];
        int q1 = n,q2=1;
        ans = 0;
        inc(i, 1, n)
        {
            if (!vis[i]) {
                if (x[i] == y[i])continue;
 
                    int p = i;
                    int l = 1;
                    zx[p] = q1--;
                    while (!vis[p]) {
                        vis[p] = 1;
                        if (vis[xx[y[p]]]) {
                            zy[p] = zx[xx[y[p]]];
                            ans += abs(zx[p] - zy[p]);
                            p = xx[y[p]];
                        }
                        else {
                            zy[p] = (l % 2 == 1) ? q2++ : q1--;
                            ans += abs(zx[p] - zy[p]);
                            zx[xx[y[p]]] = zy[p];
                            p = xx[y[p]];
                        }
                        l++;
                    }
                    if (l % 2==0)q1++;
            }
        }
        cout << ans << endl;
        
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    return 0;
}
