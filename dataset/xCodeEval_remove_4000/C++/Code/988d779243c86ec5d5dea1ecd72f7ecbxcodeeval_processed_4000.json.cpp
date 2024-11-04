   



using namespace std;














typedef pair<int, int> PII;



ll inf;
ll qpow(ll x, ll t) { return t ? qpow(sqr(x) % inf, t >> 1) * (t & 1 ? x : 1) % inf : 1ll; }
inline int gcd(int a, int b) { while (b ^= a ^= b ^= a %= b); return a; }
int getSum(int a, int b) { return a ^ b + (a & b) << 1; }
inline int read() {  

    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}



int n[1000], m[1000];
int dp[1000][1000];
signed main()
{
   
    int a, b, c;
    cin >> a >> b >> c; 
    n[a] = b;
    inc(i, 0, a - 1)
    {
        cin >> n[i];
    }
    inc(i, 0, a - 1)
    {
        cin >> m[i];
      
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] =0;
    inc(i, 1, a)
    {
        inc(k, i, a)
        {
            inc(g, i - 1, k - 1)
                dp[k][i] = min(dp[k][i], dp[g][i - 1] + m[g] * (n[k] - n[g]));
        }
    }
    int ans = 1e10;
    inc(i,a-c, a)
        ans = min(ans, dp[a][i]);
    cout << ans<< endl;
    return 0;
}










































































































































