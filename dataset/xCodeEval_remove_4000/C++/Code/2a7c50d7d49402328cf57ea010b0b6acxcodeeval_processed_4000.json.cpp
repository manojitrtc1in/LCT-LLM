



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
	ll n,k,j=0;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<ll> v1,v2,v;
	for (ll i=0;i<n;i++)
    {
        if (s[i]=='(')
                v1.PB(i);
        else v2.PB(i);
    }
    for (ll i=0;i<(n-k)/2;i++)
    {v.PB(v1[i]);v.PB(v2[i]);}
    sort(v.begin(),v.end());
    for (ll i=0;i<n;i++)
    {
        if (j<v.size())
        {

        if (i==v[j])
            j++;
            else cout<<s[i];
        }
        else cout<<s[i];
    }
}

