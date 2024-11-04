




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
#define maxc 1e9
#define pb push_back
#define mp mavarre_pair
#define pii pair<int,int>
#define Tasvarr "v"
#define inf freopen(Tasvarr".inp","r",stdin)
#define ouf freopen(Tasvarr".out","w",stdout)
#define bit(i, X) (x >> i) & 1
#define all(x) (x).begin(), (x).end()

using namespace std;











































































const int maxn = 100005;

int n, check[maxn], k, p, minn[maxn];
vector<int> a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--)
    {
        cin >> n;
        int pos = 0;
        memset(check,0,sizeof(check));
        fill(minn+1,minn + n + 1,1e9);
        for(int i = 1;i <= n;i++) a[i].clear();
        for(int i = 1;i <= n;i++)
        {
            cin >> k;
            for(int j = 1;j <= k;j++) {
                cin >> p;
                a[i].pb(p);
                if(p < minn[i] && !check[p])
                    minn[i] = min(minn[i],p),check[p] = 1;
            }
            if(minn[i] == 1e9 && pos != i) pos = i;
        }
        if(pos == 0) cout << "OPTIMAL" << "\n";
        else {
            cout << "IMPROVE" << "\n";
            cout << pos << " ";
            for(int i = 1;i <= n;i++)
                if(!check[i]) {
                    cout << i << "\n";
                    break;
                    }
        }
    }
}
