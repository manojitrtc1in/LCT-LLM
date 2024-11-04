














using namespace std;

















ll cnt,n,m,t,ans,ant;
const int N=2e5+10;
const int INF=0x3f3f3f3f;
const ll llINF=0x3f3f3f3f3f3f3f3f;
ll arr[N],f[N],te[N],pos[N];
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
    R n>>m;
    

    

    

    ans=ant=cnt=0;
    f[0]=te[0]=0;
    rep(i,1,n) 
    {
        R arr[i];
        f[i]=f[i-1]+arr[i];
        te[i]=max(te[i-1],arr[i]);
    }
    

    rep(i,1,m) 
    {
        R cnt;
        ans=upper_bound(te+1,te+1+n,cnt)-te-1;
        cout<<f[ans]<<' ';
        

        

    }
    ln
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
  	 	   		 	   		 	 			 				