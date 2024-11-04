






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
int n, m, k;
cin>>n>>m>>k;

if(!k){

	cout<<(m*(m-1)/2)<<endl;
	fr(i,1,m+1){
		fr(j,i+1,m+1){
			cout<<i<<" "<<j<<endl;
		}
	}

}
else {

	cout<<(m*(m-1)/2)<<endl;
	fr1(i,m,0){
		fr(j,1,i){
			cout<<i<<" "<<j<<endl;
		}
	}


}

 
  
  return;} 




signed main() {
	

	

	{solve();}
	
	return 0;
}





















