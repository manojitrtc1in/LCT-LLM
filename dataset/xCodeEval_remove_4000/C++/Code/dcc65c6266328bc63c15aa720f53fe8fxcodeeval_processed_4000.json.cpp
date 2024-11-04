











using namespace std;
bool preceed(pair<string, int> x, pair<string, int> y)
{
 
   if (x.second != y.second)
      return x.second > y.second;
   return y.first > x.first;
}
bool id0(ll n)
{
	if(n==1)
		return false;
	else if(n==2||n==3)
		return true;
	else
	{
		for(ll i=2;i*i<=n;++i)
		{
			if(n%i==0)
				return false;
		}
	}
	return true;
}
ll gcd(ll a, ll b)
{
	if (b == 0)
	 return a;
	return gcd(b, a%b);
}
ll lcm(ll a ,ll b)
{
	return b*(a/(gcd(a,b)));
}
ll id1(ll n)
{
	set<ll>st;
	set<ll>::iterator it;
	for(ll i=1;i*i<=n;++i)
	{
		if(n%i==0)
		{
			st.insert(i);
			st.insert(n/i);
		}
	}
	ll sum =0 ;
	for(it=st.begin();it!=st.end();++it)
		sum+=*it;

	return sum;
}
ll product(ll l,ll r,ll mod)
{
	ll ans = r;
	for(ll i = r-1;i>=l;--i)
	{
		ans*=i;
		ans%=mod;
	}
	return ans;
}
void id2()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int a[109];
int main()
{
	id2();
	int t;
	cin>>t;
			const int size = 1e5+1;;
		string str[size];
	while(t--)
	{
		map<string,int>mp;
		int n,nn=0;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>str[i];
			mp[str[i]]++;
		}
		while(n--)
		{
			string rem="",ch="";
			bool f =false;
			for(size_t i=0;i<str[nn].size();++i)
			{
				ch+=str[nn][i];
			rem = str[nn].substr(i+1,str[nn].size()-ch.size());
				if(mp[ch]>0&&mp[rem]){
					f = true;
					break;
				}
			}
			if(f)
				cout<<"1";
			else
				cout<<"0";
			nn++;
		}
		cout<<"\n";
	}
}	