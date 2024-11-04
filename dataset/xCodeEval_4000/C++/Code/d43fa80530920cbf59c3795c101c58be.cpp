#include <bits/stdc++.h>
using namespace std;


int t;
long long a,n,p,h;

long long getres(long long a,long long n,long long p){
	long long tms=a*n/p;
	if(!tms){
		return max(a,p-a*n);
	}
	return getres(a-p%a,tms-(a*n%p<(p/a-1)*a),a);
}

void solve(){
	scanf("%lld%lld%lld%lld",&a,&n,&p,&h);
	a%=p;
	puts((a*n<p?a:getres(a,n,p))>h?"NO":"YES");
}

int main(){
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}