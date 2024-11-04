

#include<bits/stdc++.h> 
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
ll findGCD(vector<ll> a, ll n) 

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
ll ribbonCut(ll n, ll b, ll c, ll a)
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





vector<bool> dectobin(ll n)
{
	vector<bool> ans;
	while(n != 0)
	{
		ans.push_back(n % 2);
		n /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

ll bintodec(vector<bool> a)
{
	ll ans = 0;
	for(ll i = 0 ; i < a.size() ; i++)
	{
		ans = ans * 2 + (ll)a[i];	
	}
	return ans;
}

vector<bool> process(vector<bool> a, ll d)
{
	vector<bool> ans;
	if(d == 1)
	{
		for(ll i = 0 ; i < a.size() - 1 ; i += 2)
		{
			if(a[i] == 0 && a[i+1] == 0)
			{
				ans.push_back(0);
				ans.push_back(0);
			}
			else if(a[i] == 0 && a[i+1] == 1)
			{
				ans.push_back(1);
				ans.push_back(0);
			}
			else if(a[i] == 1 && a[i+1] == 0)
			{
				ans.push_back(1);
				ans.push_back(1);
			}
			else
			{
				ans.push_back(0);
				ans.push_back(1);
			}
		}
		return ans;
	}
	else if(d == 2)
	{
		for(ll i = 0 ; i < a.size() - 1 ; i += 2)
		{
			if(a[i] == 0 && a[i+1] == 0)
			{
				ans.push_back(0);
				ans.push_back(0);
			}
			else if(a[i] == 0 && a[i+1] == 1)
			{
				ans.push_back(1);
				ans.push_back(1);
			}
			else if(a[i] == 1 && a[i+1] == 0)
			{
				ans.push_back(0);
				ans.push_back(1);
			}
			else
			{
				ans.push_back(1);
				ans.push_back(0);
			}
		}
		return ans;
	}
	return a;
}

int main()
{
	int t;
	cin>>t;
	for(int xyz = 0 ; xyz < t ; xyz ++)
	{
		ll n;
		cin>>n;
		if(n <= 3)
		{
			cout<<n<<endl;
			continue;
		}
		

		ll b = ceil(log2l(n+1));
		if(b % 2 == 1)
		{
			b++;
		}
		ll nd = n - (ll)pow(4, (b-4)/2 + 1) + 1;
		ll d = (nd - 1) % 3;
		

		

		vector<bool> ans(b, 0);
		ans[1] = 1;
		vector<bool> rem;
		rem = dectobin((nd-1)/3); 

		reverse(rem.begin(), rem.end());
		while(rem.size() < b - 2)
		{
			rem.push_back(0);
		}
		reverse(rem.begin(), rem.end());
		
		ll ansi = 2;
		for(ll i = 0 ; i < rem.size() ; i++)
		{
			ans[ansi] = rem[i];
			ansi ++;
		}
		ans = process(ans, d);
		ll ansn = bintodec(ans);
		cout<<ansn<<endl;
	}
	return 0;
}