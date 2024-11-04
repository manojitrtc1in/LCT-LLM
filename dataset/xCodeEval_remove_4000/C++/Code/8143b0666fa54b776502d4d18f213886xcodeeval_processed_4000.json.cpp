














using namespace std;

















ll cnt,n,m,t,ant,c,d;
const int N=2e5+10;
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
        ll a=i%x;
        if(a>=n) continue;
        sum+=arr[a+1];
    }
    

	return sum>=c;
}

void solve()
{
	ll sum=0,maxx=-llINF;
	cin>>n>>c>>d;
	ll l=0,r=1e9;
	rep(i,1,n)
    {
		cin>>arr[i];  
		maxx=max(maxx,arr[i]);
	}
	if(maxx*d<c) 
    {
		cout<<"Impossible"<<endl;
		return;
	}
	if(maxx>=c) {
		cout<<"Infinity"<<endl;
		return;
	}
	sort(arr+1,arr+n+1);
    reverse(arr+1,arr+1+n);
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