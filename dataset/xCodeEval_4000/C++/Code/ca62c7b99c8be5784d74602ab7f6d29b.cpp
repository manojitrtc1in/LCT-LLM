#include <bits/stdc++.h>
using namespace std;






































































































































int binpow (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		int b = binpow (a, n/2);
		return b * b;
	}
}
#define fr first
#define sc second
#define int long long
int a,b,c,n,m,i,j,k,x,y,cnt=0,sum=0,res=0;
void solve(){
	cin>>n;
	vector<int> vec(n),ar(n);
	for(i=0;i<n;i++){
		cin>>vec[i];
	}
	sort(vec.begin(),vec.end());
	for(i=0;i<n;i++){
		cin>>ar[i];
	}
	sort(ar.begin(),ar.end());
	cnt=0;
	for(i=0;i<n;i++){
		if(ar[i]>=vec[i] && ar[i]<=vec[i]+1){
			cnt++;
		}
	}
	if(cnt==n)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
}
main(){
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
}

