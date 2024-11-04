














using namespace std;












ll cnt,n,m,t,ans,ant,pnum,nnum;
const int N=2e5+10;
const int INF=0x3f3f3f3f;
const ll llINF=0x3f3f3f3f3f3f3f3f;
ll arr[N],sumx[N],sumy[N];
pair<ll,ll>p[N];
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
	nnum=pnum=0;
	rep(i,1,n)
	{
		cin>>arr[i];
		if(arr[i]==1) pnum++;
		else nnum++; 
	}
	if(pnum==nnum)
	{
		cout<<n<<endl;
		rep(i,1,n) cout<<i<<' '<<i<<endl;
		return;
	}else if(n&1)
	{
		cout<<-1<<endl;
		return;
	}
	cnt=ant=ans=0;
	if(pnum>nnum)
	{
		repr(i,1,n)
		{
			if(arr[i+1]==1)
			{
				pnum--;
				nnum++;
				sumy[++cnt]=i+1;
				sumx[cnt]=i;
				i++;
			}else sumy[++cnt]=i, sumx[cnt]=i;
			if(pnum==nnum) break;
		}
	}else
	{
		repr(i,1,n)
		{
			if(arr[i+1]==-1)
			{
				nnum--;
				pnum++;
				sumy[++cnt]=i+1;
				sumx[cnt]=i;
				i++;
			}else sumy[++cnt]=i, sumx[cnt]=i;
			if(pnum==nnum) break;
		}
	}
	

	cout<<cnt+(n-sumy[cnt])<<endl;
	rep(i,1,cnt) cout<<sumx[i]<<' '<<sumy[i]<<endl;
	rep(i,sumy[cnt]+1,n) cout<<i<<' '<<i<<endl;

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