

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define endl '\n'
 
#define G G.O.K.U_Instinct
#define R REX27
#define C C-_-Devil_Code 
#define Y Yashwant_170301
#define L All the above are living Gods 


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