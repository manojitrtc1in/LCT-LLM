














using namespace std;












ll cnt,n,m,t,ans,ant;
const int N=1e5+10;
const int INF=0x3f3f3f3f;
const ll llINF=0x3f3f3f3f3f3f3f3f;
ll arr[N];
string str;

inline ll read()
{
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}

    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}

    return x*s;
}


void solve()
{
    cin>>n;
    ans=-1;
    rep(i,1,n) cin>>arr[i];
    repr(i,2,n)
        if(arr[i]>1) ans=0;
    if(ans==-1||arr[2]&1&&n==3) 
    {
        cout<<-1<<endl;
        return;
    }
    repr(i,2,n) ans+=arr[i]+1>>1;
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
			    	 				  			      	 				