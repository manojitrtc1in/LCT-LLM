

















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
char mm[200200];
vector<int> g[250200];


ll ans = 0;
signed main()
{
    

    IOS;
    inf = 1e9 + 7;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        
        set<char>st;
        int n;
       

        cin >> mm;
        int l = strlen(mm);
        ans = 1;
        inc(i, 0, l - 1)
        {
            if(st.count(mm[i])||st.size()<3)st.insert(mm[i]);
            else {
                ans++;
                st.clear();
                st.insert(mm[i]);
            }
        }
        cout << ans<< endl;
        
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    return 0;
}
