














using namespace std;












ll cnt,n,m,t,ans,ant;
const int N=2e5+10;
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
    rep(i,1,n) cin>>arr[i];
    cnt=ans=0;
    repr(i,1,n)
    {
        ans+=arr[i];
        if(arr[i]) cnt=1;
        if(cnt&&arr[i]==0) ans++;
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
    		 	  		 		  						 		 	  	