





#include<bits/stdc++.h>

#define ll long long int
#define str string
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define vvi vector<vector<ll>>
#define vi vector<ll>
#define mapii map<ll,ll>
#define mapvi map<vector<ll>,ll>
#define mapiv map<ll,vector<ll>>
#define all(a) (a).begin(),(a).end()
#define tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define toupper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define show(arr,n) for(ll i=0;i<n;i++)cout<<arr[i]<<" ";
#define pii pair<ll,ll>
#define itr vector<ll>::iterator
#define repi(x,n) for(ll i=x;i<n;++i)
#define repid(x,n) for(ll i=x;i>=n;--i)
#define repj(x,n) for(ll j=x;j<n;++j)
#define repjd(x,n) for(ll j=x;j>=n;--j)
#define print2(x,y) cout<<x<<" "<<y<<'\n'
#define print3(x,y,z) cout<<x<<" "<<y<<" "<<z<<'\n'
#define input(x) cin>>x
#define input2(x,y) cin>>x>>y
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define M 1000000007
#define S 200005
#define E6 1000000

const ll INF = 1ll<<60;


using namespace std;


namespace number_theory {

	bool prime[15000105];
	void sieve(int n) {
	  for (ll i = 0; i <= n; i++) prime[i] = 1;
	  for (ll p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
		  for (ll i = p * p; i <= n; i += p)
			prime[i] = false;
		}
	  }
	  prime[1] = prime[0] = 0;
	}

	vector<ll> primelist;
	bool __primes_generated__ = 0;

	void genprimes(int n) {
	  __primes_generated__ = 1;
	  sieve(n + 1);
	  for (ll i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
	}

	vector<ll> factors(ll n) {
	  if (!__primes_generated__) {
		cerr << "Call genprimes you dope" << endl;
		exit(1);
	  }
	  vector<ll> facs;

	  for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
		if (n % primelist[i] == 0) {
		  while (n % primelist[i] == 0) {
			n /= primelist[i];
			facs.push_back(primelist[i]);
		  }
		}
	  }
	  if (n > 1) {
		facs.push_back(n);
	  }
	  

	  return facs;
	}
}

using namespace number_theory;

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t;
cin>>t;
ll a;
genprimes(100000);
while(t--)
{
	ll n;
	cin>>n;
	vi v=factors(n);
	mapii mp;
	for(ll i:v)
	{
		mp[i]+=1;
	}
	ll ans=0;
	ll val;
	for(auto x:mp)
	{
		if(x.ss>ans)
		{
			ans=x.ss;
			val=x.ff;
		}
	}
	print(ans);
	repi(0,ans-1)
	{
		cout<<val<<" ";
	}
	ll val2;
	ll ans2=1;
	for(auto x:mp)
	{
		if(x.ff!=val)
		{
			repi(0,x.ss)
			{
				ans2*=x.ff;
			}
		}
	}
	ans2*=val;
	cout<<ans2<<endl;
}
  return 0;
}
