#include<stdio.h>
#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
#define M 1000000007
#define ff first
#define ss second
bool possible(int n, vector<ll> a, int k)
{
	for(ll i = 0 ; i < n ; i++)
	{
		if(a[i] < i / k)
		{
			return false;
		}
	}
	
	return true;
}
ll cont_substr(vector<ll> t, ll n, ll k)
{
	vector<ll> ans;
	for(ll i = 1 ; i + k < t.size() ; i++)
	{
		ans.push_back(t[i + k] - t[i-1] - 1);
	}
	ans.push_back(t[k]);
	ans.push_back(n - t[t.size() - k - 1] - 1);
	return *max_element(ans.begin(), ans.end());
}
bool ok(ll* lc, ll* rc, ll l, ll r)
{
	if(*rc < l || r < *lc)
	{
		return false;
	}
	else
	{
		if(*lc < l)
		{
			*lc = l;
		}
		if(*rc > r)
		{
			*rc = r;
		}
		return true;
	}
}


vector<ll> dp(101, -1);
ll compute(ll n, ll k)
{
	if(n == 0)
	{
		return 1;
	}
	ll ans = 0;
	for(ll i = 1 ; i <= k ; i++)
	{
		if(n - i >= 0)
		{
			if(dp[n-i] == -1)
			{
				dp[n-i] = compute(n-i, k) % M;
			}
			ans = (ans%M + dp[n-i]%M)%M;

		}
	}
	return ans%M;
}
int main()
{
	ll n;
	cin>>n;
	vector<ll> a(n), b(n);
	ll nd = 1e6 + 1;
	vector<ll> c(nd, 0);
	vector<pair<ll, ll> > temo(n);
	for(ll i = 0 ; i < n ; i++)
	{
		cin>>a[i]>>b[i];
		temo[i].ff = a[i];
		temo[i].ss = b[i];
		c[a[i]] = b[i];
	}
	sort(temo.begin(), temo.end());
	for(ll i = 0 ; i <  n ; i++)
	{
		a[i] = temo[i].ff;
		b[i] = temo[i].ss;
	}
	vector<ll> dp(nd, 0);
	dp[nd-1] = c[nd-1] != 0 ? 1 : 0;
	for(ll i = nd - 2 ; i >= 0 ; i--)
	{
		dp[i] = dp[i+1] + (c[i] != 0 ? 1 : 0);
	}
	vector<ll> pade(n, 0);
	for(ll i = 0 ; i < n ; i++)
	{
		ll temp = a[i] - b[i];
		if( temp < 0 )
		{
			temp = 0;
		}
		pade[i] = dp[temp] - dp[a[i]];
	}
	

	vector<ll> next(nd, 0);
	ll j = n - 1;
	for(ll i = nd - 1 ; i >= 0 ; i--)
	{
		if(j >= 0 && a[j] < i)
		{
			next[i] = j;
		}
		else if(j < 0)
		{
			next[i] = 0;
		}
		else
		{
			j--;
			i++;
		}
	}
	

	vector<ll> dp_pade(n, 0);
	dp_pade[0] = 0;
	for(ll i = 1 ; i < n ; i++)
	{
		ll t = a[i] - b[i]; 

		if(t < 0)
		{
			t = 0;
		}
		dp_pade[i] = pade[i] + dp_pade[next[t]];
	}
	ll ans = n + 1;
	for(ll i = 0 ; i < n ; i++)
	{
		ans = min(ans, dp_pade[i] + n - i - 1);
	}
	
	cout<<ans;
	return 0;
}



