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
#define eps 1e-8
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
