














using namespace std;












ll cnt,n,m,t,ans,ant;
const int N=2e5+10;
const int INF=0x3f3f3f3f;
const ll llINF=0x3f3f3f3f3f3f3f3f;
ll arr[N],sum[N];
pair<ll,ll>p[N];
string str;

inline ll read()
{
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}

    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}

    return x*s;
}


void solve() {
    ll n,z=0,f=0,k=0;
    cin>>n;
    

    

	rep(i,1,n) 
    {
		cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
		if (arr[i] == 1)z++;
		else f++;
    }
	if (z == f)
    {
		cout<<n<<endl;
		rep(i,1,n) cout << i << " " << i << endl;
		return;
	}
	if (n&1)
    {
		cout<<-1<<endl;
		return;
	}	
	if (z > f) 
    {
		repr(i,1,n) 
        {
			if(arr[i+1]==1) 
            {
				p[++k].first =i,p[k].second=i+1;
				z--;
                f++;
				i++;
			}
			else p[++k].first = i, p[k].second = i ;
			if (z == f) break;
		}
	}
	else {
		rep(i,1,n-1) 
        {
			if(arr[i+1]==-1) 
            {
				p[++k].first = i,p[k].second=i+1;
				f--;
                z++;
				i++;
			}
			else p[++k].first = i, p[k].second = i;
			if(z==f)break;
		}
	}
	cout<< k+n-p[k].second<<endl;
	rep(i,1,k) cout << p[i].first << " " << p[i].second << endl;
	rep(i,p[k].second+ 1, n) cout <<i<< " " << i << endl;
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