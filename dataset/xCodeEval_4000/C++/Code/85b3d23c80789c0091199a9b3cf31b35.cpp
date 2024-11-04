#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
const int f2[40]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};

map<int ,int > m;

int n,q;

int main(){
	cin>>n>>q;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		m[tmp]++;
	}
	for(int x=0;x<q;x++){
		int tmp,ans=0;
		cin>>tmp;
		for(int i=30;i>=0;i--){
			int delta=tmp/f2[i];
			delta=min(delta,m[f2[i]]);
			tmp-=delta*f2[i];
			ans+=delta;
		}
		if(tmp!=0) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
