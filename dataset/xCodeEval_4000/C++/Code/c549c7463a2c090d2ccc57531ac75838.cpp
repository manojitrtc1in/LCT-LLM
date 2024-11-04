
#include<bits/stdc++.h>
#include<stdio.h>
#include<malloc.h>
#include<functional>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<unordered_map>
#include<vector>
#include<queue>
#include<set>
#include<unordered_set>
#include<bitset>
#include<stack>
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(),x.end() 
#define ull unsigned long long
#define inc(i,l,r) for(ll i=l;i<=r;i++)
#define dec(i,l,r) for(ll i=l;i>=r;i--)
#define link(x) for(edge *j=h[x];j;j=j->next)
#define mem(a) memset(a,0,sizeof(a))
#define eps 1e-15
#define succ(x) (1ll<<(x))
#define lowbit(x) (x&(-x))
#define sqr(x) ((x)*(x))
#define mid ((x+y)%inf*q2)
#define pi 3.1415926535897931
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define float double
#define endl "\n"
#define mkp(a,b) make_pair(a,b)
typedef pair<int, int> PII;
inline ll gcd(ll a, ll b) { return b > 0 ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline ll read() { ll f = 1; ll x = 0; char ch = getchar(); while (ch > '9' || ch < '0') { if (ch == '-') f = -1; ch = getchar(); }while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar(); return x * f; }
inline void write(int x) { if (x < 0) { putchar('-'); x = -x; }if (x > 9)write(x / 10); putchar(x % 10 + '0'); }
ll inf;
ll inv(ll x) { return x == 1 ? 1 : (inf - inf / x) * inv(inf % x) % inf; }
ll qpow(ll x, ll t) { return t ? qpow(sqr(x) % inf, t >> 1) * (t & 1 ? x : 1) % inf : 1ll; }























































































































int m[250200];
char mm[200200];
vector<int> g[250200];
int dp[200200];
signed main()
{
    

    IOS;
    inf = 1e9 + 7;
    int _ = 1;
    cin >> _;
    while (_--)
    {
        int n,k;
        cin >> n>>k;
        inc(i, 1, 2*n)
            cin >> m[i];
         int pd = 1;
         sort(m + 1, m + 1 + 2*n);
         inc(i, 1, n)
         {
             if (m[i + n] - m[i] < k)pd = 0;
         }
      if (pd)cout << "YES" << endl;
      else cout << "NO" << endl;
        
         
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    return 0;
}
