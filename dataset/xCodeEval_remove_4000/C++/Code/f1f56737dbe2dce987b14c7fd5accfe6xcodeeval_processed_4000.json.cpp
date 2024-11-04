






































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
	bool id1 = 0;

	void id3(int n) {
	  id1 = 1;
	  sieve(n + 1);
	  for (ll i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
	}

	vector<ll> factors(ll n) {
	  if (!id1) {
		cerr << "Bruh, Call id3" << endl;
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

ll n, m, k, q, l, r, x, y, z;
const ll id0 = 1e6 + 3862;
ll a[id0];
ll b[id0];
ll c[id0];
string s, t;
ll ans = 0;

ll bp(ll a, ll b){

    ll res=1;
    while(b>0){
        if(b&1)
		{res=(res*a);
		b--;}
        a=(a*a);
        b>>=1;
    }
    return res;
}

ll ncr(ll n,ll k)
{
	ll ans=1;
	if(k>n-k)
	k=n-k;
	for(ll i=1;i<=k;i++)
	ans*=(n-i+1),ans/=i;
	return ans;
}


ll power(ll x,ll y,ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}

ll id2(ll n,ll r,ll p)
{

    if (r == 0)
		return 1;

    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}


bool isprime(ll x)
{
    ll i=2;
    bool f=false;

    for(i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t;
cin>>t;
ll a,b;
while(t--)
{
	ll n,x;
	cin>>n>>x;
	vi g[n+1];
	

	

	repi(1,n)
	{
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	if(g[x].size()<=1)print("Ayush");
	else
	{
		ll c=0;
		ll cn=0;
		ll turn=0;
		c=g[x].size();
		cn=n-1-g[x].size();
		if(cn%2==0)turn=0;
		else turn=1;

		if(c%2==1)
		{
			ans=turn;
		}
		else ans=!turn;
		if(ans==0)print("Ayush");
		else print("Ashish");
	}
}
  return 0;
}