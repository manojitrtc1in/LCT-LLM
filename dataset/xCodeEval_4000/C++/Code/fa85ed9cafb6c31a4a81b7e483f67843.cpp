







#include <bits/stdc++.h>
using namespace std;


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




int n,k;string s,ans;
void solve(){ 
cin>>n>>k>>s;

fr(i,0,n){
	ans+=s[i%k];
}

if(ans<s){
	fr1(i,k-1,-1){
		if((s[i]=='9')){s[i] = '0'; }
		else {s[i] = (s[i]+1); break;}
	}
}
cout<<n<<endl;
fr(i,0,n){
	cout<<s[i%k];
}
cout<<endl;
  
  return;} 




signed main() {
	

	fast
	

	{solve();}
	
	return 0;
}






















