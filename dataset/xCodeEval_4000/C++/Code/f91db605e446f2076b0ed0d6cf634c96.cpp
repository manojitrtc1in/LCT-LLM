





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
#define bruh main

const ll INF = 1ll<<60;


using namespace std;




namespace number_theory {
	ll gcd(ll x, ll y) {
	  if (x == 0) return y;
	  if (y == 0) return x;
	  return gcd(y, x % y);
	}
	bool isprime(ll n) {
	  if (n <= 1) return false;
	  if (n <= 3) return true;

	  if (n % 2 == 0 || n % 3 == 0) return false;

	  for (ll i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i+2) == 0)
		  return false;

	  return true;
	}

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
	  sort(facs.begin(), facs.end());
	  return facs;
	}

	vector<ll> getdivs(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        divs.push_back(i);
        divs.push_back(n / i);
      }
    }

    

    return divs;
  }
}

using namespace number_theory;
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

ll ncrModPFermat(ll n,ll r,ll p)
{

    if (r == 0)
		return 1;

    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}





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

int bruh(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n;
ll q;
str s;
cin>>n>>q;
cin>>s;
ll cans=0;
ll i=0;
mapii mp;
while(i<n)
{
	if(s[i]=='a')
	{
		if(i+2<n)
		{
			if(s[i+1]=='b' and s[i+2]=='c')
			{

				mp[i]=1;
				mp[i+2]=1;
				mp[i+1]=1;
				cans+=1;
				i+=2;
			}
			else i+=1;
		}
		else
		{
			i+=1;
		}
	}
	else
	{
		i+=1;
	}
}

while(q--)
{
	ll pos;
	char c;
	cin>>pos>>c;
	pos-=1;
	ll ans=0;
	if(s[pos]==c)ans=cans;
	else
	{
		if(mp[pos]==1)
		{
			if(s[pos]=='a')
			{
				mp[pos]=0;
				mp[pos+1]=0;
				mp[pos+2]=0;
				cans-=1;
				if(c=='a')
				{
					if(pos+2<n)
					{
						if(s[pos+1]=='b' and s[pos+2]=='c')
						{
							mp[pos]=1;
							mp[pos+1]=1;
							mp[pos+2]=1;
							cans+=1;
						}
					}
				}
				if(c=='b')
				{
					

					

					

					


					if(pos+1<n and pos-1>=0)
					{
						if(s[pos-1]=='a' and s[pos+1]=='c')
						{
							mp[pos]=1;
							mp[pos+1]=1;
							mp[pos-1]=1;
							cans+=1;
						}
					}
				}
				if(c=='c')
				{
					

					

					

					


					if(pos-2>=0)
					{
						if(s[pos-1]=='b' and s[pos-2]=='a')
						{
							mp[pos]=1;
							mp[pos-1]=1;
							mp[pos-2]=1;
							cans+=1;
						}
					}
				}
			}
			if(s[pos]=='b')
			{
				

				

				

				

				mp[pos-1]=0;
				mp[pos]=0;
				mp[pos+1]=0;
				cans-=1;
				if(c=='a')
				{
					if(pos+2<n)
					{
						if(s[pos+1]=='b' and s[pos+2]=='c')
						{
							mp[pos]=1;
							mp[pos+1]=1;
							mp[pos+2]=1;
							cans+=1;
						}
					}
				}
				if(c=='b')
				{
					

					

					

					


					if(pos+1<n and pos-1>=0)
					{
						if(s[pos-1]=='a' and s[pos+1]=='c')
						{
							mp[pos]=1;
							mp[pos+1]=1;
							mp[pos-1]=1;
							cans+=1;
						}
					}
				}
				if(c=='c')
				{
					

					

					

					


					if(pos-2>=0)
					{
						if(s[pos-1]=='b' and s[pos-2]=='a')
						{
							mp[pos]=1;
							mp[pos-1]=1;
							mp[pos-2]=1;
							cans+=1;
						}
					}
				}
			}
			if(s[pos]=='c')
			{
				mp[pos-1]=0;
				mp[pos-2]=0;
				mp[pos]=0;
				cans-=1;
				

				

				

				

				

				

				

				

				if(c=='a')
				{
					if(pos+2<n)
					{
						if(s[pos+1]=='b' and s[pos+2]=='c')
						{
							mp[pos]=1;
							mp[pos+1]=1;
							mp[pos+2]=1;
							cans+=1;
						}
					}
				}
				if(c=='b')
				{
					

					

					

					


					if(pos+1<n and pos-1>=0)
					{
						if(s[pos-1]=='a' and s[pos+1]=='c')
						{
							mp[pos]=1;
							mp[pos+1]=1;
							mp[pos-1]=1;
							cans+=1;
						}
					}
				}
				if(c=='c')
				{
					

					

					

					


					if(pos-2>=0)
					{
						if(s[pos-1]=='b' and s[pos-2]=='a')
						{
							mp[pos]=1;
							mp[pos-1]=1;
							mp[pos-2]=1;
							cans+=1;
						}
					}
				}
			}
		}
		else
		{
			
			if(s[pos]=='a')
			{
			
				if(c=='a')
				{
					if(pos+2<n)
					{
						if(s[pos+1]=='b' and s[pos+2]=='c')
						{
							mp[pos]=1;
							mp[pos+1]=1;
							mp[pos+2]=1;
							cans+=1;
						}
					}
				}
				if(c=='b')
				{
					

					

					

					


					if(pos+1<n and pos-1>=0)
					{
						if(s[pos-1]=='a' and s[pos+1]=='c')
						{
							mp[pos]=1;
							mp[pos+1]=1;
							mp[pos-1]=1;
							cans+=1;
						}
					}
				}
				if(c=='c')
				{
					

					

					

					


					if(pos-2>=0)
					{
						if(s[pos-1]=='b' and s[pos-2]=='a')
						{
							mp[pos]=1;
							mp[pos-1]=1;
							mp[pos-2]=1;
							cans+=1;
						}
					}
				}
			}
			if(s[pos]=='b')
			{
				

				

				

				

			
				
				if(c=='a')
				{
					if(pos+2<n)
					{
						if(s[pos+1]=='b' and s[pos+2]=='c')
						{
							mp[pos]=1;
							mp[pos+1]=1;
							mp[pos+2]=1;
							cans+=1;
						}
					}
				}
				if(c=='b')
				{
					

					

					

					


					if(pos+1<n and pos-1>=0)
					{
						if(s[pos-1]=='a' and s[pos+1]=='c')
						{
							mp[pos]=1;
							mp[pos+1]=1;
							mp[pos-1]=1;
							cans+=1;
						}
					}
				}
				if(c=='c')
				{
					

					

					

					


					if(pos-2>=0)
					{
						if(s[pos-1]=='b' and s[pos-2]=='a')
						{
							mp[pos]=1;
							mp[pos-1]=1;
							mp[pos-2]=1;
							cans+=1;
						}
					}
				}
			}
			if(s[pos]=='c')
			{
				

				

				

				

				

				

				

				

				if(c=='a')
				{
					if(pos+2<n)
					{
						if(s[pos+1]=='b' and s[pos+2]=='c')
						{
							mp[pos]=1;
							mp[pos+1]=1;
							mp[pos+2]=1;
							cans+=1;
						}
					}
				}
				if(c=='b')
				{
					

					

					

					


					if(pos+1<n and pos-1>=0)
					{
						if(s[pos-1]=='a' and s[pos+1]=='c')
						{
							mp[pos]=1;
							mp[pos+1]=1;
							mp[pos-1]=1;
							cans+=1;
						}
					}
				}
				if(c=='c')
				{
					

					

					

					


					if(pos-2>=0)
					{
						if(s[pos-1]=='b' and s[pos-2]=='a')
						{
							mp[pos]=1;
							mp[pos-1]=1;
							mp[pos-2]=1;
							cans+=1;
						}
					}
				}
			}
	}
	ans=cans;
}
	s[pos]=c;
	print(ans);
}

  return 0;
}
