



using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef long int l;
typedef long double ld;
extern const int primes[];


string s;cin>>s;int n=s.length();char a[n+1];strcpy(a,s.c_str());





				


				


				

main()
{
	fast;
	ll a,n,b,d,sum=0,ans=0;
	cin>>n>>b>>d;
	for (ll i=0;i<n;i++)
    {
        cin>>a;
        if (a<=b)
            sum+=a;
        if (sum>d)
        {
            ans+=1;
            sum=0;
        }
    }
    cout<<ans;
}

