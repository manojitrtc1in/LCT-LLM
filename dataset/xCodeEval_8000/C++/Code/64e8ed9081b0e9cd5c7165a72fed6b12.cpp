#include<bits/stdc++.h>
using namespace std;



long long b[200002];

int main(){
	int n,ans=0,it=0;
	cin>>n;
	for (int i=0;i<n;i++) scanf("%lld",&b[i]);
	while (it<n) {
		ans++;


		int pr=0,suf=0,val1,val2;
		while (it<n&&b[it]==-1) {
			pr++;
			it++;
		}
		if (it==n) break;
		val1=b[it];
		it++;
		while (it<n&&b[it]==-1) {
			suf++;
			it++;
		}
		if (it==n) break;
		val2=b[it];
		if ((val2-val1)%(suf+1)!=0) continue;
		long long d=(val2-val1)/(suf+1);
		if (val1-d*pr<=0) continue;
		it++;
		while (it<n){
			if (b[it]==-1) {
				if (b[it-1]+d<=0) break;
				b[it]=b[it-1]+d;
				it++;
			}
			else {
				if (b[it]!=b[it-1]+d) break;
				it++;
			}
		}
	}


	cout<<ans<<endl;
}
