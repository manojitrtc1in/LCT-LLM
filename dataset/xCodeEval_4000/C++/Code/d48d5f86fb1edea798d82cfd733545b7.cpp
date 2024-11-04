




#include <bits/stdc++.h>
#define fil(x) fill(x, x+n+1, 1e9)
#define reset(x) memset(x, 0,sizeof(x))
#define fr(i,a,b) for(int i = (a); i <= (b); i++)
#define FR(i,a,b) for(int i = (a); i < (b); i++)
#define frr(i,a,b) for(int i = (a); i >= (b); i--)
#define F first
#define S second
#define ll long long
#define db double
#define maxn 100005
#define maxc 1e9
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define Task "v"
#define inf freopen(Task".inp","r",stdin)
#define ouf freopen(Task".out","w",stdout)
#define bit(i, X) (x >> i) & 1
#define all(x) (x).begin(), (x).end()

using namespace std;


void Solve()
{
    ll n, k;
    cin >> n >> k;
    if ((n - k)%2 == 0 && n >= k*k)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        Solve();
}
