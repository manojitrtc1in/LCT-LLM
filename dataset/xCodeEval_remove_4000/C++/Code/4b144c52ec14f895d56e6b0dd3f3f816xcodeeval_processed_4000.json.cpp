






















































































using namespace std;
inline void cmax(int &a,int b){
	a=max(a,b);
}
inline void cmin(int &a,int b){
	a=min(a,b);
}
const int Maxn=1005;
int Gt(int x){
	int ans=0;
	while (x!=1){
		int y=0;
		int z=x;
		while (z){
			y++;
			z-=z&-z;
		}
		x=y;
		ans++;
	}
	return ans;
}
const long long mod=1e9+7;
long long fact[Maxn];
long long qp(long long x,long long p){
	if (p==1) return x;
	if (p%2==0){
		LL y=qp(x,p/2);
		return y*y%mod;
	}
	else{
		LL y=qp(x,p/2);
		return y*y%mod*x%mod;
	}
}
LL inv(LL x){
	return qp(x,mod-2);
}
LL c(LL a,LL b){
	if (b>a || b<0) return 0LL;
	return fact[a]*inv(fact[b])%mod*inv(fact[a-b])%mod;
}
int main(){
	fact[0]=1;
	for (int i=1;i<Maxn;i++) fact[i]=fact[i-1]*i%mod;
	string n;
	cin>>n;
	int k;
	cin>>k;
	if (k==0){
		printf("1\n");
		return 0;
	}
	if (k==1){
		printf("%d\n",n.size()-1);
		return 0;
	}
	vector<int> pos;
	for (int i=1;i<=1000;i++){
		if (Gt(i)==k-1){
			pos.pb(i);
		}
	}
	LL ans=0;
	for (int i=0;i<pos.size();i++){
		int cur1=0;
		for (int j=0;j<n.size();j++){
			if (n[j]=='1'){
				ans+=c(n.size()-j-1,pos[i]-cur1);
				ans%=mod;
				cur1++;
			}
			else{
				;
			}
		}
		if (cur1==pos[i]) ans++;
		ans%=mod;
	}
	printf("%I64d\n",ans);
	return 0;
}
