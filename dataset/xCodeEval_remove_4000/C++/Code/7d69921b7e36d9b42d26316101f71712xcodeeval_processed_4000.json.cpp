






































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
	bool id0 = 0;

	void id1(int n) {
	  id0 = 1;
	  sieve(n + 1);
	  for (ll i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
	}

	vector<ll> factors(ll n) {
	  if (!id0) {
		cerr << "Call id1 you dope" << endl;
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
id1(100000);
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
