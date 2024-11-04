
















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






























































int m[5050];






ll ans = 0;

 int c[5050],n;
 int m2[5050][5050];
 int m3[5050][5050];
int id0(int x) {
    int ans = 0;
    while (x > 0) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

void update1(int x, int value) {
    while (x <= n) {
        c[x] += value;
        x += lowbit(x);
    }
}

signed main()
{
    

   

    inf = 1e9 + 7;
    int _;
    cin >> _;
    while (_--)
    {
        

        cin >> n;
        inc(i, 1, n) {
            cin >> m[i]; 
        }
        inc(i, 1, n)c[i] = 0;
        inc(i, 1, n-2)
        {
            if(i>1)
            inc(k, i + 1, n - 1)
                m2[k][i] = id0(m[k] - 1);
            update1(m[i], 1);
        }
        inc(i, 1, n)c[i] = 0;
        dec(i, n, 2)
        {
            if(i<n)
            inc(k, 1,i-1)
                m3[k][i] = id0(m[k] - 1);
            update1(m[i], 1);
        }
        ans = 0;
        inc(i, 2, n - 2)
        {
            inc(k, i + 1, n - 1)
            {
                ans += m2[k][i] * m3[i][k];
            }
        }
        cout << ans<< endl;
        
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    return 0;
}
