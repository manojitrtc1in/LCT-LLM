














using namespace std;












ll cnt,n,t,ans,ant;
const int N=1e5+10;
const int INF=0x3f3f3f3f;
const ll llINF=0x3f3f3f3f3f3f3f3f;
ll arr[N];
ll h[]={00,01,02,03,04,05,10,11,12,13,14,15,20,21,22,23};
ll m[]={00,10,20,30,40,50,01,11,21,31,41,51,02,12,22,32};
string str;

inline ll read()
{
    char c = getchar();int x = 0,s = 1;
    while(c < '0' || c > '9') {if(c == '-') s = -1;c = getchar();}

    while(c >= '0' && c <= '9') {x = x*10 + c -'0';c = getchar();}

    return x*s;
}

ll check(ll x,ll y)
{
    repr(i,0,16)
        if(x==h[i]&&y==m[i]) return 1;
    return 0;
}

void solve()
{
    ll hh,mm,k,h1,m1,h_,m_;
    scanf("%lld:%lld%lld",&hh,&mm,&k);
    h1=hh;
    m1=mm;
    ans=0;
    ans+=check(h1,m1);

    h_=k/60;
    m_=k-h_*60;
    while(1)
    {
        h1+=h_;
        m1+=m_;
        if(m1>=60) 
        {
            h1++;
            m1-=60;
        }
        if(h1>=24) h1-=24;
        if(h1==hh&&m1==mm) break;
        ans+=check(h1,m1);
    }
    cout<<ans<<endl;
    return;
}

int main()
{
    

    

    

	

	

    cin>>t;
    while(t--)
        solve();
    return 0;
}
	 	   			 	 				 			 	  		 	  	