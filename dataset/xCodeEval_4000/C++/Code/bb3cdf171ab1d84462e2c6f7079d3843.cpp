#include <bits/stdc++.h>
using namespace std;


int n,m,p;
int a[10005],b[100005],B;
int c[10005];
int cnt[10005];

inline int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}

inline int ksmii(int a,int b){
	if(!b){
		return 1;
	}
	int f=ksmii(a,b>>1);
	f=1LL*f*f%p;
	if(b&1){
		f=1LL*f*a%p;
	}
	return f;
}

int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	B=p-1;
	for(int i=1;i<=m;i++){
		scanf("%d",b+i);
		B=gcd(B,b[i]);
	}
	int pp=p-1;
	vector<int> ins;
	for(int i=1;i*i<p;i++){
		if(pp%i==0){
			ins.push_back(i);
			if(i*i!=pp){
				ins.push_back(pp/i);
			}
		}
	}
	sort(ins.begin(),ins.end());
	for(int i=1;i<=n;i++){
		for(int j:ins){
			if(ksmii(a[i],1LL*B*j%pp)==1){
				c[i]=j;
				break;
			}
		}
	}
	sort(c+1,c+n+1);
	int N=unique(c+1,c+n+1)-c-1;
	int ans=0;
	for(int i=1;i<=N;i++){
		cnt[i]=c[i];
		for(int j=1;j<i;j++){
			if(c[i]%c[j]==0){
				cnt[i]-=cnt[j];
			}
		}
		ans+=cnt[i];
	}
	printf("%d\n",ans);
	return 0;
}
