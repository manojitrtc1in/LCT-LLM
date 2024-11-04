












































#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int q1[50],q2[50];
int main(){
	ll T,n,k,m;
	long long ans,cou;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>m;
		if(n==1) ans=0;
		else if(n==2) ans=m;
		else ans=m*2;
		cout<<ans<<'\n';
	}
}


























