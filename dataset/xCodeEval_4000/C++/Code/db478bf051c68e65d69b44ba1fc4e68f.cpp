
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long
#define endl "\n"
#define R cin>>
#define S second
#define F first
#define ln cout<<endl;
#define rep(i, a, b) for (ll i = (a); i <= (b); i++)
#define repr(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (ll i = (b); i >= (a); i--)
#define rrepr(i, a, b) for (ll i = (b); i > (a); i--)
#define mem(a) memset((a),0,sizeof (a));
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define debug cout<<"here!"<<endl;

ll cnt,n,m,t,ant,c,d;
const int N=2e6+10;
const int INF=0x3f3f3f3f;
const ll llINF=0x3f3f3f3f3f3f3f3f;
ll arr[N],ans[N];
string str;

inline ll read()
{
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}

    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}

    return x*s;
}

bool check(ll x)
{
	ll sum=0,i;
    
	for(i=0;i<d;i++)
	{
        ll aa=i%x;
        if(aa>=n) continue;
        sum+=arr[aa];
    }
	return sum>=c;
}

void solve()
{
	ll sum=0,maxx=-llINF;
	cin>>n>>c>>d;
	ll l=0,r=1e9;
	repr(i,0,n)
		cin>>arr[i];
	sort(arr,arr+n);
    reverse(arr,arr+n);
    ans[0]=0;
	rep(i,1,n) ans[i]=ans[i-1]+arr[i];
	ll p=-1;
	while(l<=r)
    {
		ll mid=l+r>>1;
		if(check(mid+1))
        {
			p=mid;
			l=mid+1;
		} else r=mid-1;
	}
    if(p==-1) cout<<"Impossible"<<endl;
    else if(p>=1e8) cout<<"Infinity"<<endl;
	else cout<<p<<endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    

    

    cin>>t;
    while(t--)
        solve();
    return 0;
}