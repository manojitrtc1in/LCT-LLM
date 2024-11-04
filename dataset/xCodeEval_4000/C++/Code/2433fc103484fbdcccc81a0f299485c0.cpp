#include <bits/stdc++.h>
using namespace std;






































































































































#define fr first
#define sc second
#define int long long
int a,b,c,n,m,i,j,k,x,h,y,cnt=0,sum=0;
void solve(){
	cin>>n>>h;
	vector<int> vec(n);
	for(i=0;i<n;i++)
		cin>>vec[i];
	int l=0,r=1e18;
	while(l<=r){
		int m=(l+r)/2;
		int res=0;
		for(i=0;i<n-1;i++){
			res+=min(vec[i+1]-vec[i],m);
		}
		res+=m;
		if(res>h)
			r=m-1;
		else if(res<h)
			l=m+1;
		else{
			cout<<m<<endl;
			return;
		}	
	}
	cout<<l<<endl;
}
main(){
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
}

