


using namespace std;



 







int main()
{
	
	ll t;
	cin>>t;
	while(t--)
	{
		

		

		

		

		ll n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		ll ms[2]={-1,-1},me[2]={-1,-1};
		for(ll i=0;i<n;++i)
		{
			me[s[i]-'0']=i;
			if(ms[s[i]-'0']==-1)
				ms[s[i]-'0']=i;
		}
		while(q--)
		{
			ll l,r;
			cin>>l>>r;
			l--;
			r--;
			if(ms[s[l]-'0']<l||me[s[r]-'0']>r)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
}