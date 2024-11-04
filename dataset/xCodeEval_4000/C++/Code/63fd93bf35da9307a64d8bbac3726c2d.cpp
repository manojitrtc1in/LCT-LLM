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
main(){
	int T=1;
	cin>>T;
	while(T--){
		cin>>n;
		bool check=true;
		for(i=1;i<=n;i++){
			cin>>x;
			bool ok=false;
			for(j=1;j<=i;j++){
				if(x%(j+1)!=0){
					ok=true;
					break;
				}
			}
			if(ok==0)
				check=0;
		}
		if(check)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}

