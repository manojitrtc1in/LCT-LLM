







#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long 
#define fr(i,s,e) for(int i=s;i<e;++i)
#define fr1(i,s,e) for(int i=s;i>e;--i)
#define p0(a) cout << a <<" "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define INF (ll)1e18 + 100
#define v(d) vector<d>
#define pr pair<int, int>
#define pr1(d1,d2) pair<d1,d2>
#define pb push_back
#define f first
#define s second
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
void debug_arr(vector<int> &a){
	int len = a.size();
	fr(i,0,len){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


const int  mod = 1e9 +7;
const int mod1= 998244353;




void solve(){ 
int n; cin>>n;
v(int) a(n);
int mxsum=0;
fr(i,0,n){
	cin>>a[i];
	if(!(i&1))mxsum+=a[i];
}

if(n==1) {cout<<a[0]<<endl; return;}
if(n==2) {cout<<max(a[0],a[1])<<endl; return;}



v(int) odd; 

v(int) even; 

fr(i,0,n-1){

	even.pb(a[i+1]-a[i]); i++;
}
fr(i,1,n-1){

	odd.pb(-a[i+1]+a[i]); i++;
}






int x,y;
x=y=even[0];
int ans=x;
fr(i,1,even.size()){
	y = max(x+even[i], even[i]);
	ans= max(ans,y);
	x=y;
}

x=y=odd[0];ans=max(ans,y);
fr(i,1,odd.size()){
	y = max(x+odd[i], odd[i]);
	ans=max(ans,y);
	x=y;
}
if(ans<0) ans=0;
 mxsum+=ans;
cout<<mxsum<<endl;  
  return;} 




signed main() {
	

	fast
	int t; cin>>t; while(t--)
	{solve();}
	
	return 0;
}






















