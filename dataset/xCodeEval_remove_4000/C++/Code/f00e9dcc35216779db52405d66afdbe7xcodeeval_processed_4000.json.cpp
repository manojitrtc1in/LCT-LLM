

using namespace std;
typedef long long ll;
typedef long double ld;






ll n, k;
ll a[3010], b[3010];
ll sum, zr;
vector<ll> vec;
ll ans = MIN;
ll sum2;

ll getans(void)
{
	vector<ll> w, pl, mi;
	
	for(ll i = 1 ; i <= n ; i++)
	{
		if(!a[i])
			w.push_back(i);
	}
	
	ll ret = MIN;
	
	for(ll i : vec)
	{
		if(i >= 0)
			pl.push_back(i);
		else
			mi.push_back(i);
	}
	
	sort(pl.begin(), pl.end());
	sort(mi.begin(), mi.end());
	
	for(ll i = 0 ; i <= (ll)mi.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() ; j++)
			b[w[i + j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() - i ; j++)
			b[w[i + (ll)pl.size() + j]] = mi[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	for(ll i = 0 ; i <= (ll)pl.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() ; j++)
			b[w[i + j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() - i ; j++)
			b[w[i + (ll)mi.size() + j]] = pl[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	reverse(pl.begin(), pl.end());
	
	for(ll i = 0 ; i <= (ll)mi.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() ; j++)
			b[w[i + j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() - i ; j++)
			b[w[i + (ll)pl.size() + j]] = mi[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	for(ll i = 0 ; i <= (ll)pl.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() ; j++)
			b[w[i + j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() - i ; j++)
			b[w[i + (ll)mi.size() + j]] = pl[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	reverse(pl.begin(), pl.end());
	reverse(mi.begin(), mi.end());
	
	for(ll i = 0 ; i <= (ll)mi.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() ; j++)
			b[w[i + j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() - i ; j++)
			b[w[i + (ll)pl.size() + j]] = mi[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	for(ll i = 0 ; i <= (ll)pl.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() ; j++)
			b[w[i + j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() - i ; j++)
			b[w[i + (ll)mi.size() + j]] = pl[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	reverse(pl.begin(), pl.end());
	
	for(ll i = 0 ; i <= (ll)mi.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() ; j++)
			b[w[i + j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() - i ; j++)
			b[w[i + (ll)pl.size() + j]] = mi[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	for(ll i = 0 ; i <= (ll)pl.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() ; j++)
			b[w[i + j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() - i ; j++)
			b[w[i + (ll)mi.size() + j]] = pl[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	pl.clear();
	mi.clear();
	
	for(ll i : vec)
	{
		if(i > 0)
			pl.push_back(i);
		else
			mi.push_back(i);
	}
	
	sort(pl.begin(), pl.end());
	sort(mi.begin(), mi.end());
	
	for(ll i = 0 ; i <= (ll)mi.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() ; j++)
			b[w[i + j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() - i ; j++)
			b[w[i + (ll)pl.size() + j]] = mi[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	for(ll i = 0 ; i <= (ll)pl.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() ; j++)
			b[w[i + j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() - i ; j++)
			b[w[i + (ll)mi.size() + j]] = pl[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	reverse(pl.begin(), pl.end());
	
	for(ll i = 0 ; i <= (ll)mi.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() ; j++)
			b[w[i + j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() - i ; j++)
			b[w[i + (ll)pl.size() + j]] = mi[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	for(ll i = 0 ; i <= (ll)pl.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() ; j++)
			b[w[i + j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() - i ; j++)
			b[w[i + (ll)mi.size() + j]] = pl[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	reverse(pl.begin(), pl.end());
	reverse(mi.begin(), mi.end());
	
	for(ll i = 0 ; i <= (ll)mi.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() ; j++)
			b[w[i + j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() - i ; j++)
			b[w[i + (ll)pl.size() + j]] = mi[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	for(ll i = 0 ; i <= (ll)pl.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() ; j++)
			b[w[i + j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() - i ; j++)
			b[w[i + (ll)mi.size() + j]] = pl[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	reverse(pl.begin(), pl.end());
	
	for(ll i = 0 ; i <= (ll)mi.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() ; j++)
			b[w[i + j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() - i ; j++)
			b[w[i + (ll)pl.size() + j]] = mi[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	for(ll i = 0 ; i <= (ll)pl.size() ; i++)
	{
		for(ll j = 1 ; j <= n ; j++)
			b[j] = a[j];
		
		for(ll j = 0 ; j < i ; j++)
			b[w[j]] = pl[j];
		
		for(ll j = 0 ; j < (ll)mi.size() ; j++)
			b[w[i + j]] = mi[j];
		
		for(ll j = 0 ; j < (ll)pl.size() - i ; j++)
			b[w[i + (ll)mi.size() + j]] = pl[i + j];
		
		ll minn = 0, maxx = 0;
		ll w = 0;
		
		for(ll j = 1 ; j <= n ; j++)
		{
			w += b[j];
			minn = min(minn, w);
			maxx = max(maxx, w);
		}
		
		ret = max(ret, maxx - minn + 1);
	}
	
	return ret;
}

int main(void)
{
	scanf("%lld %lld", &n, &k);
	
	for(ll i = 1 ; i <= n ; i++)
	{
		scanf("%lld", &a[i]);
		
		sum += a[i];
		sum2 += a[i];
		
		if(!a[i])
			zr++;
	}
	
	if(sum < 0 && zr * k + sum < 0)
	{
		printf("-1");
		return 0;
	}
	
	if(sum > 0 && sum - zr * k > 0)
	{
		printf("-1");
		return 0;
	}
	
	while(1)
	{
		if(sum == 0)
			break;
		
		if(sum < 0 && sum + k >= 0)
		{
			vec.push_back(-sum);
			break;
		}
		
		else if(sum > 0 && sum - k <= 0)
		{
			vec.push_back(-sum);
			break;
		}
		
		if(sum > 0)
		{
			vec.push_back(-k);
			sum -= k;
		}
		
		else
		{
			vec.push_back(k);
			sum += k;
		}
	}
	
	if((ll)vec.size() <= zr)
	{
		ll nam = zr - (ll)vec.size();
		
		for(ll i = 1 ; i <= nam / 2 ; i++)
			vec.push_back(k), vec.push_back(-k);
		
		if(nam & 1)
			vec.push_back(0);
		
		ans = max(ans, getans());
		reverse(a + 1, a + 1 + n);
		ans = max(ans, getans());
		reverse(a + 1, a + 1 + n);
	}
	
	vec.clear();
	
	if(sum2 > 0)
	{
		while(1)
		{
			if(sum2 <= 0)
				break;
			
			sum2 -= k;
			vec.push_back(-k);
		}
		
		if(sum2)
			vec.push_back(-sum2);
	}
	
	else if(sum2 < 0)
	{
		while(1)
		{
			if(sum2 >= 0)
				break;
			
			sum2 += k;
			vec.push_back(k);
		}
		
		if(sum2)
			vec.push_back(-sum2);
	}
	
	if((ll)vec.size() <= zr)
	{
		ll nam = zr - (ll)vec.size();
		
		for(ll i = 1 ; i <= nam / 2 ; i++)
			vec.push_back(k), vec.push_back(-k);
		
		if(nam & 1)
			vec.push_back(0);
		
		ans = max(ans, getans());
		reverse(a + 1, a + 1 + n);
		ans = max(ans, getans());
		reverse(a + 1, a + 1 + n);
	}
	
	printf("%lld", ans < 0 ? -1 : ans);
	return 0;
}