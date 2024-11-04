#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int,int> > vpi;
typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update > pbds;

#define ft               first
#define sd               second
#define sf1(c)           scanf("%d",&c)
#define sf2(c1,c2)       scanf("%d%d",&c1,&c2)
#define sf3(c1,c2,c3)    scanf("%d%d%lld",&c1,&c2,&c3)
#define pf(c)            printf("%lld ",c)
#define pof              pop_front
#define pob              pop_back
#define sz(a)            int((a).size())
#define pb               push_back
#define all(c)           (c).begin(),(c).end()
#define tr(c,i)          for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)     ((c).find(x) != (c).end())
#define cpresent(c,x)    (find(all(c),x) != (c).end())
#define rep(i,a,b)       for(int i=a;i<=b;i++)
#define mp               make_pair
#define mod              1000000007ll
#define hot              ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define err2(x,y)		 cout<<#x"="<<x<<" "#y"="<<y<<endl
#define err3(x,y,z) 	 cout<<#x"="<<x<<" "#y"="<<y<<" "#z"="<<z<<endl

































































































 


		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

 
 






































































































































































































































































































































































































































ll n,m;

int main()
{
	int n,k;
	cin>>n;
	ll a[n+2]={0},pref[n+2]={0};
	map<ll,int> m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]=i;
	}
	cin>>k;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pref[i]=a[i]+pref[i-1];
	}
	ll sum=0;
	for(int i=2;i<=k;i++)
	{
		sum=sum+a[i]*(i-1)-pref[i-1];
	}
	ll ans=sum;
	int st=1,en=k,l=1,r=k+1;
	while(r<=n){
		sum=sum + a[l]*(r-l-1)-(pref[r-1]-pref[l]);
		l++;
		sum=sum+a[r]*(r-l)-(pref[r-1]-pref[l-1]);
		
		

		if(sum<ans)
		{
			ans=sum;
			st=l,en=r;
		}	
		r++;	
	}
	for(int i=st;i<=en;i++)
	{
		cout<<m[a[i]]<<' ';
	}
	cout<<'\n';
	return 0;
}