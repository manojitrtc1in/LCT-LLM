
  		
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<int>
#define vl vector<long long>
#define endl "\n"
#define endline cout<<"\n"
const int M=1e9+7;
#define Y cout<<"YES\n"
#define N cout<<"NO\n"
#define all(x) (x).begin(), (x).end()
#define R return
#define prajwal_rayal ios_base::sync_with_stdio(false);cin.tie(NULL);
ll nxt(){ll x;cin >> x;return x;}
string nxts(){string x;cin >> x;return x;}
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]"<<endl;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#define deb(x...) cout << #x << " = ["; _print(x)





ll t=1;



void solve()
{
	
	ll n,q;
	cin>>n>>q;
	vl v(n+1);
	for (int i = 1; i <= n; ++i)
	{
		cin>>v[i];
	}
	ll ind=-1;
	for (int i = 1; i <= n; ++i)
	{
		if(v[i]==n)
		{
			ind=i;
		}
	}
	

	vl vp(n+1,0); ll maxi=v[1]; set<ll>s;
	for (int i = 2; i <= n; ++i)
	{
		if(v[i]>maxi)
		{
			maxi=v[i];
			vp[i]=1;
			s.insert(i);
		}
	}
	if(v[1]>v[2])
	{
		vp[1]=1;
		s.insert(1);
	}
	

	

	



	while(q--)
	{
		ll i,k ;
		cin>>i>>k;
		if(i>ind)
		{
			cout<<0<<endl;
			continue;
		}
		if(i==ind)
		{
			if(i==1 || i==2)
			{
				cout<<k<<endl;
			}
			else
			{
				cout<<max(0ll,k-i+2)<<endl;
			}
			continue;
		}
		if(i<ind)
		{	

			if(vp[i]==0)
			{
				cout<<0<<endl;
				continue;
			}
			
			if(i==1)
			{
				auto it=s.upper_bound(i);
				ll p=*it;
				

			  cout<<min(p-2,k)<<endl;
			  continue;
			}
			k=max(0ll,k-i+2);
			

			

				auto it=s.upper_bound(i);
				ll p=*it;
				cout<<min(k,p-i)<<endl;
				continue;
			

			
			
		}
	}
}


int main(){prajwal_rayal;t=1;cin>>t;while(t--)solve();}
