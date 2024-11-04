














using namespace std;












ll cnt,n,m,t,ans,ant;
const int N=2e5+10;
const int INF=0x3f3f3f3f;
const ll llINF=0x3f3f3f3f3f3f3f3f;
ll arr[N];
ll c[N];
string str;

inline ll read()
{
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}

    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}

    return x*s;
}

inline ll lowbit(const ll _)
{
    return _&(-_);
}

inline void insert(ll t,ll d)

{
    for(;t<=n;t+=lowbit(t)) c[t]+=d; 

}

inline ll getSum(ll t) 

{
    ll sum=0;
    for(;t;t-=lowbit(t)) sum+=c[t]; 

    return sum;
}

void solve()
{
    

    cin>>n;
    rep(i,1,n) cin>>arr[i];
    memset(c,0,sizeof c);
    ans=0;
    rrep(i,1,n)
    {
        ans+=getSum(arr[i]);
        

        insert(arr[i],1);
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    

    

	cin.tie(0);
	cout.tie(0);
    cin>>t;
    while(t--)
        solve();
    return 0;
}
	 		       				 	 					