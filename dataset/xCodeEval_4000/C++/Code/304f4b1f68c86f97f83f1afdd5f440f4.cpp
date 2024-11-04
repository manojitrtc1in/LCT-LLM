#include <bits/stdc++.h>
using namespace std;
#define lp(i,n) for (int i=1;i<=n;++i)

#define PB push_back
#define wl(T) while(T--)

#define P push
#define MP make_pair
#define fr first
#define sc second
#define all(v) (v.begin(),v.end())

int const MOD=1e9+7;
typedef long long ll;

typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
typedef pair<pair<int,int>,int> ppint;
typedef vector< pair <int, pair <int,int>> >vppint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<vint> vvint;
typedef map <string,pair<string,int> > mppsint;
typedef vector <string> vstr;
typedef pair<string,int> pstint;



unordered_map <int,int> mp;

bool cmp(pint p,pint q)
{
    return (p.sc<q.sc);
}
int res[1234][1234];
int n,a[223456];
vvint v;
bool vis[223456];
void dfs(int x)
{
    vis[x]=1;
    for (int i=0; i<v[x].size(); ++i)
    {
        int sn=v[x][i];
        if (!vis[sn])
        {
            dfs(sn);
        }
    }
}
int ans;
int T;
string s;
int fin;
int main()
{
    bool t=0;
    cin >>T;
    while (T--)
    {
        cin >>n;
        cin>>s;
        int ans1=0;
        int ans2=0;
        for (int i=0; i<n; ++i)
        {
            if (s[i]=='>')
            {
                ans1=i;
                break;
            }
        }
        int j=0;
        for (int i=n-1;i>=0;--i)
        {
            if (s[i]=='<')
            {
                ans2=j;
                break;
            }
            j++;
        }
        cout<<min(ans1,ans2)<<endl;

    }

    return 0;
}
































































































