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
#define hot              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define err2(x,y)		 cout<<#x"="<<x<<" "#y"="<<y<<endl
#define err3(x,y,z) 	 cout<<#x"="<<x<<" "#y"="<<y<<" "#z"="<<z<<endl

































































































 


		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

 
 







































































































































































































































































































































































































void split(const string& s, char delim,vector<string>& v) {
    auto i = 0;
    auto pos = s.find(delim);
    if(pos==string::npos)
    {
    	v.push_back(s);
    }
    while (pos != string::npos) {
      v.push_back(s.substr(i, pos-i));
      i = ++pos;
      pos = s.find(delim, pos);

      if (pos == string::npos)
         v.push_back(s.substr(i, s.length()));
    }
}

int main(){
	int n;
	cin>>n;
	int a[n+3]={0},p[n+2]={0},s[n+2]={0};
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		p[i]=p[i+1];
		if(a[i]==0)p[i]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)ans+=1ll*p[i];
	}
	cout<<ans<<'\n';
	return 0;
	
}
