


using namespace std; 
typedef long long int ll;
ll nCr(ll n, ll k) 
{ 
    ll C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  

  
    for (ll i = 1; i <= n; i++) 
    { 
        

        

        for (ll j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 
struct node
{
	int x;
	int r;
	int iq;
};
bool sorte(struct node a,struct node b)
{
	return a.x<b.x;
}
vector<ll> mark(ll p, vector<ll> a,  ll n)
{
    for(ll i=2;i*p<n;i++)
    {
        a[i*p]=1;
    }
    return a;
}
vector<ll> sieve(vector<ll> a, ll n)
{
	a[0]=1;
	a[1]=1;
    for(ll i=2;i<sqrt(n);i++)
    {
        if(a[i]==0)
        {
            a=mark(i,a,n);
        }
    }
    return a;
}
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}
ll id1(vector<ll> a, ll n) 

{
    ll result = a[1]-a[0]; 
    for (ll i = 1; i+1 < n; i++) 
    {
    	if(a[i+1]-a[0]>result)
    	{
    		result = gcd(a[i+1]-a[0], result);
		}
		else
		{
			result = gcd(result ,a[i+1]-a[0]);
		}
    	
	}  
    return result; 
} 
ll id0(ll n, ll b, ll c, ll a)
{
	vector<ll> dp(n+1);
	dp[0]=0;
	for(ll i=1;i<=n;i++)
	{
		ll x,y,z;
		x=y=z=-1;
		if(i>=a)
		{
			x=dp[i-a];
		}
		if(i>=b)
		{
			y=dp[i-b];
		}
		if(i>=c)
		{
			z=dp[i-c];
		}
		if(x==-1 &&y==-1 && z==-1)
		{
			dp[i]=-1;
		}
		else
		{
			dp[i]=max(max(x,y),z)+1;
		}
	}
	return dp[n];
}
ll fact(ll n)
{
	ll p=1;
	for(ll i=2;i<=n;i++)
	{
		p=p*i;
	}
	return p;
}
ll modInverse(ll A,ll M)
{
    A=A%M;
    for(ll B=1;B<M;B++)
        if(((A*B)%M)==1)
            return B;
}






















ll ifok(ll x)
{
	while(x % 2 == 0)
	{
		x /= 2;
	}
	while(x % 3 == 0)
	{
		x /= 3;
	}
	return x;
}

bool equal(stack<ll> a, vector<ll> b)
{
	if(a.size() != b.size())
	{
		return 0;
	}
	ll n = a.size();
	for(ll i = 0 ; i < n ; i++)
	{
		ll t = a.top();
		a.pop();
		if(t != b[i])
		{
			return 0;
		}
	}
	return 1;
}

void operate(stack<ll>& a, stack<ll>& b)
{
	ll ad = a.top();
	ll bd = b.top();
	a.pop();
	b.pop();
	stack<ll> temp;
	if(ad > bd)
	{
		while(!a.empty())
		{
			temp.push(a.top());
			a.pop();
		}
		a.push(ad);
		a.push(bd);
		while(!temp.empty())
		{
			a.push(temp.top());
			temp.pop();
		}
	}
	else 

	{
		while(!b.empty())
		{
			temp.push(b.top());
			b.pop();
		}
		b.push(bd);
		b.push(ad);
		while(!temp.empty())
		{
			b.push(temp.top());
			temp.pop();
		}
	}
	return;
}
bool finf(ll p,vector<ll> a ,ll n)
{
	vector<ll> dp(n+1, 0);
	for(ll i = 0 ; i < n ; i++)
	{
		dp[a[i]]++;
	}
	bool ans = false;
	ll ansi = 0;
	ll maxi = p;
	for(ll i = 1 ; i <= n ; i++)
	{
		if(dp[i] >= p)
		{
			if(dp[i] >= maxi)
			{
				maxi = dp[i];
				ans = true;
				ansi = i;
			}
		}
	}
	if(ans == false)
	{
		return ans;
	}
	ll f = 0;
	ll pc = p;
	for(ll i = 1 ; i <= n ; i++)
	{
		if(p > 0)
		{
			if(i != ansi && dp[i] != 0 || dp[i] > pc)
			{
				p--;
			}
		}
		else
		{
			f = 1;
			break;
		}
	}
	if(f == 1 || p <= 0)
	{
		return true;
	}
	return false;
}




int main()
{
	ll t;
	cin>>t;
	for(ll xyz = 0 ; xyz < t ; xyz ++)
	{
		ll n;
		cin>>n;
		vector<ll> a(n+1);
		for(ll i = 1 ; i <= n ; i++)
		{
			cin>>a[i];
		}
		vector<vector<ll> > dp(27, vector<ll> (n+1));
		for(ll p = 1 ; p <= 26 ; p++)
		{
			for(ll i = 0 ; i <= n ; i++)
			{
				if(i == 0)
				{
					dp[p][i] = 0;
				}
				else
				{
					dp[p][i] = dp[p][i-1] + (a[i] == p ? 1 : 0);
				}
			}
		}
		ll ans = 1;
		for(ll i = 1 ; i <= n ; i++)
		{
			for(ll j = i ; j <= n ; j++)
			{
				ll max1 = 0;
				ll max2 = 0;
				for(ll p = 1 ; p <= 26 ; p++)
				{
					max1 = max(max1, min(dp[p][i] - dp[p][0] , dp[p][n] - dp[p][j]) );
					max2 = max(max2, dp[p][j] - dp[p][i] );
				}
				ans = max(ans, 2 * max1 + max2);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}