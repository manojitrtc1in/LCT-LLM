














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
    str.clear();
    ans=0;
    cin>>n>>m;
    rep(i,1,n) cin>>arr[i];
    rrep(i,1,n)
    {
        if(ans>=arr[i]) 
        {
            str.push_back('1');
            continue;
        }
        if(ans<arr[i]&&m) 
        {
            ans++;
            m--;
            str.push_back('1');
        }else str.push_back('0');
    }
    reverse(str.begin(),str.end());
    cout<<str<<endl;
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
    					 	   			  	     	 	 	