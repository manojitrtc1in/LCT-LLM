   
#include<bits/stdc++.h>
#include<set>
#include<unordered_map>
using namespace std;


#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define link(x) for(edge *j=h[x];j;j=j->next)
#define mem(a) memset(a,0,sizeof(a))
#define ll long long
#define int ll
#define eps 1e-8
#define succ(x) (1ll<<(x))
#define lowbit(x) (x&(-x))
#define sqr(x) ((x)*(x))
#define mid ((x+y)/2)
#define pi 3.1415926535897931
typedef pair<int, int> PII;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#pragma warning(disable :4996)
#define mod 998244353  
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










































































































































